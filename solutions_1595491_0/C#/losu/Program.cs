using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace Dancing
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
        int s = intLine[1];
        int p = intLine[2];

        int[] totalPoints = new int[n];
        for (int i = 0; i < n; i++)
        {
          totalPoints[i] = intLine[3 + i];
        }

        int nofGoogler = 0;
        int nofGooglerSurprising = 0;

        for (int i = 0; i < n; i++)
        {
          if (GetBestResult(totalPoints[i], false) >= p)
            nofGoogler++;
          if (GetBestResult(totalPoints[i], true) >= p)
            nofGooglerSurprising++;
        }
        int surprisingNeeded = nofGooglerSurprising - nofGoogler;
        int result = nofGoogler + Math.Min(s, surprisingNeeded);

        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, result));
      }

      Helper.WriteOutputFile();
    }

    static int GetBestResult(int sum, bool surprising)
    {
      if (sum == 0)
        return 0;
      if (sum == 1)
        return 1;
      if (sum >= 28)
        return 10;

      int mod = sum % 3;

      if (surprising)
      {
        if (mod == 0 || sum == 1)
          return (int)((double)sum / 3 + 1);
        else  //if (mod == 2)
          return (int)((double)sum / 3 + 2);
      }
      else
      {
        if (mod == 0)
          return sum / 3;
        else
        {
          return sum / 3 + 1;
        }
          
      }
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
