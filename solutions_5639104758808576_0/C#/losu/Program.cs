using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace StandingOvation
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
        var line = Helper.GetLine();
        int smax = Helper.GetInteger(line, 0);

        string digits = line.Split()[1];

        Debug.Assert(digits.Length == smax + 1);

        int friendsCounter = 0;
        int peopleStanding = 0;

        for (int i = 0; i < smax + 1; i++)
        {
          string digit = digits[i].ToString();
          int nofSi = Convert.ToInt32(digit);
          peopleStanding += nofSi;
          Debug.Assert(peopleStanding >= i);

          if (peopleStanding == i)
          {
            peopleStanding++;
            friendsCounter++;
          }
        }

        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, friendsCounter));
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
