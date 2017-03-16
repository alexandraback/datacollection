using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace Subsets
{
  class Program
  {
    public static HelperClass Helper { get; private set; }
    static void Main(string[] args)
    {
      Helper = new HelperClass();

      for (int iTestcase = 0; iTestcase < Helper.NofTestcases; iTestcase++)
      {
        Helper.StartTestCase(iTestcase);
        int[] intLine = Helper.GetIntArray(Helper.GetLine());
        int n = intLine[0];

        int[] input = new int[n];

        for (int i = 0; i < n; i++)
        {
          input[i] = intLine[i + 1];
        }

        List<int> sums = new List<int>((int)Math.Pow(2, 20));
        sums.Add(0);
        int resultSum = 0;

        for (int i = 0; i < n; i++)
        {
          int nofSums = sums.Count;
          for (int j = 0; j < nofSums; j++)
          {
            int newSum = sums[j] + input[i];
            if (sums.Contains(newSum))
            {
              resultSum = newSum;
              break;
            }
            sums.Add(newSum);
          }

          if (resultSum != 0)
            break;
        }

        if (resultSum != 0)
        {
          int binaryIndex1 = sums.IndexOf(resultSum);
          int binaryIndex2 = sums.Count;

          string result1 = "";
          string result2 = "";

          for (int i = 0; i < n; i++)
          {
            if (binaryIndex1 % 2 == 1)
            {
              result1 += input[i].ToString() + " ";
            }
            binaryIndex1 /= 2;
          }
          result1 = result1.Substring(0, result1.Length - 1);

          for (int i = 0; i < n; i++)
          {
            if (binaryIndex2 % 2 == 1)
            {
              result2 += input[i].ToString() + " ";
            }
            binaryIndex2 /= 2;
          }
          result2 = result2.Substring(0, result2.Length - 1);

          Helper.WriteOutput(String.Format("Case #{0}:", iTestcase + 1));
          Helper.WriteOutput(result1);
          Helper.WriteOutput(result2);
        }
        else
        {
          Helper.WriteOutput(String.Format("Case #{0}:", iTestcase + 1));
          Helper.WriteOutput("Impossible");
        }
      }

      Helper.WriteOutputFile();
    }
  }

  #region Helper Class
  /// <summary>
  /// Prepared helper class for Google Code Jam.
  /// </summary>
  public class HelperClass
  {
    public string InputFileName { get; private set; }
    public const string InputDirectory = @"D:\E_CSharp\GoogleCodeJam\";

    public string[] InputLines { get; private set; }
    public List<string> OutputLines { get; set; }

    public Stopwatch TestCaseStopWatch { get; private set; }

    public int NofTestcases { get; private set; }

    public int CurLineNo { get; set; }

    public HelperClass()
    {
      ReadInputLines();
      OutputLines = new List<string>();

      NofTestcases = GetInteger(InputLines[0], 0);
      CurLineNo = 1;
      TestCaseStopWatch = new Stopwatch();
    }

    public void ReadInputLines()
    {
      string[] files = Directory.GetFiles(InputDirectory, "*.in");

      if (files.Length != 1)
        throw new Exception("No file or more than one input file in directory.");

      InputFileName = Path.GetFileNameWithoutExtension(files[0]);

      InputLines = File.ReadAllLines(files[0]);
    }

    public void StartTestCase(int testcase)
    {
      Console.WriteLine("Test case no {0} started...\r\n", testcase);
      TestCaseStopWatch.Reset();
      TestCaseStopWatch.Start();
    }
    public void WriteOutput(string content)
    {
      TestCaseStopWatch.Stop();
      Console.WriteLine("Test case finished after {0} milliseconds.\r\n", TestCaseStopWatch.ElapsedMilliseconds);
      OutputLines.Add(content);
    }
    public void WriteOutputFile()
    {
      File.WriteAllLines(Path.Combine(InputDirectory, InputFileName + ".out"), OutputLines.ToArray());
    }

    public string GetLine()
    {
      return InputLines[CurLineNo++];
    }

    public int GetInteger(string line, int index)
    {
      string[] elements = line.Split();
      return Convert.ToInt32(elements[index]);
    }

    public int[] GetIntArray(string line)
    {
      string[] elements = line.Split();
      int n = elements.Length;
      int[] array = new int[n];
      for (int i = 0; i < n; i++)
      {
        array[i] = Convert.ToInt32(elements[i]);
      }
      return array;
    }

    public long GetLong(string line, int index)
    {
      string[] elements = line.Split();
      return Convert.ToInt64(elements[index]);
    }

    public long[] GetLongArray(string line)
    {
      string[] elements = line.Split();
      int n = elements.Length;
      long[] array = new long[n];
      for (int i = 0; i < n; i++)
      {
        array[i] = Convert.ToInt64(elements[i]);
      }
      return array;
    }

  }
  #endregion
}
