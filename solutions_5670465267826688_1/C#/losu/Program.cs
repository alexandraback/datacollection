using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;
using System.Collections;

namespace Dijkstra
{
  class Program
  {
    public static HelperClass Helper { get; private set; }

    private static Dictionary<QMult, string> _Hashtable;

    static void Main(string[] args)
    {
      Helper = new HelperClass();
      SetupHashTable();

      for (int iTestcase = 0; iTestcase < Helper.NofTestcases; iTestcase++)
      {
        Helper.StartTestCase(iTestcase);
        long[] longArray = Helper.GetLongArray(Helper.GetLine());
        int l = (int)longArray[0];
        long x = longArray[1];

        string baseTerm = Helper.GetLine();

        string currentResult = "1";
        string ijk = "ijkx";
        int currentResultIndex = 0;

        string currentRequest = ijk[currentResultIndex].ToString();

        long repeatIndex = 0;
        for (repeatIndex = 0; repeatIndex < x; repeatIndex++)
        {
          if (currentResultIndex == 3)
            break;

          if (repeatIndex == 16)
            break;

          for (int baseIndex = 0; baseIndex < l; baseIndex++)
          {
            currentResult = _Hashtable[new QMult(currentResult, baseTerm[baseIndex])];

            if (currentResult == currentRequest)
            {
              currentResultIndex++;
              currentRequest = ijk[currentResultIndex].ToString();
              currentResult = "1";
            }
          }
        }

        if (currentResultIndex == 3 && repeatIndex < x)
        {
          long nofRemainingRepetitions = x - repeatIndex;
          nofRemainingRepetitions = (nofRemainingRepetitions % 4);  // x*x*x*x = 1 for all possible x

          string baseTermResult = MultiplyTerm(baseTerm);
          for (int remainingIndex = 0; remainingIndex < nofRemainingRepetitions; remainingIndex++)
          {
            currentResult = Multiply(currentResult, baseTermResult);
          }
        }

        string result = (currentResultIndex == 3 && currentResult == "1") ? "YES" : "NO";

        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, result));
      }

      Helper.WriteOutputFile();
    }

    public static string MultiplyTerm(string term)
    {
      string result = "1";
      foreach (char val in term)
      {
        result = _Hashtable[new QMult(result, val)];
      }
      return result;
    }

    public static string Multiply(string q1, string q2)
    {
      bool q2Neg = (q2[0] == '-');
      char q2Abs = (q2Neg ? q2[1] : q2[0]);
      string resultA = _Hashtable[new QMult(q1, q2Abs)];

      if (!q2Neg)
        return resultA;
      else
      {
        if (resultA[0] == '-')
          return resultA.Substring(1);
        else
          return "-" + resultA;
      }
    }

    public static void SetupHashTable()
    {
      Dictionary<QMult, string> hashtable = new Dictionary<QMult,string>();
      hashtable.Add(new QMult("1", '1'), "1");
      hashtable.Add(new QMult("1", 'i'), "i");
      hashtable.Add(new QMult("1", 'j'), "j");
      hashtable.Add(new QMult("1", 'k'), "k");

      hashtable.Add(new QMult("i", '1'), "i");
      hashtable.Add(new QMult("i", 'i'), "-1");
      hashtable.Add(new QMult("i", 'j'), "k");
      hashtable.Add(new QMult("i", 'k'), "-j");

      hashtable.Add(new QMult("j", '1'), "j");
      hashtable.Add(new QMult("j", 'i'), "-k");
      hashtable.Add(new QMult("j", 'j'), "-1");
      hashtable.Add(new QMult("j", 'k'), "i");

      hashtable.Add(new QMult("k", '1'), "k");
      hashtable.Add(new QMult("k", 'i'), "j");
      hashtable.Add(new QMult("k", 'j'), "-i");
      hashtable.Add(new QMult("k", 'k'), "-1");

      hashtable.Add(new QMult("-1", '1'), "-1");
      hashtable.Add(new QMult("-1", 'i'), "-i");
      hashtable.Add(new QMult("-1", 'j'), "-j");
      hashtable.Add(new QMult("-1", 'k'), "-k");

      hashtable.Add(new QMult("-i", '1'), "-i");
      hashtable.Add(new QMult("-i", 'i'), "1");
      hashtable.Add(new QMult("-i", 'j'), "-k");
      hashtable.Add(new QMult("-i", 'k'), "j");

      hashtable.Add(new QMult("-j", '1'), "-j");
      hashtable.Add(new QMult("-j", 'i'), "k");
      hashtable.Add(new QMult("-j", 'j'), "1");
      hashtable.Add(new QMult("-j", 'k'), "-i");

      hashtable.Add(new QMult("-k", '1'), "-k");
      hashtable.Add(new QMult("-k", 'i'), "-j");
      hashtable.Add(new QMult("-k", 'j'), "i");
      hashtable.Add(new QMult("-k", 'k'), "1");

      _Hashtable = hashtable;
    }
  }

  public struct QMult
  {
    public readonly string Q1;
    public readonly char Q2;
    public QMult(string q1, char q2)
    {
      Q1 = q1;
      Q2 = q2;
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
