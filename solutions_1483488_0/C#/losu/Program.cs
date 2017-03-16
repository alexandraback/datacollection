using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace RecycledNumbers
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
        int a = intLine[0];
        int b = intLine[1];

        int nofDigitsA = (int)Math.Floor(Math.Log10(a)) + 1;
        int nofDigitsB = (int)Math.Floor(Math.Log10(b)) + 1;

        int nofDigits = nofDigitsA;
        int startNum = a;
        int endNum = 0;

        int result = 0;

        while (nofDigits <= nofDigitsB)
        {
          if (nofDigits == nofDigitsB)
            endNum = b;
          else
            endNum = (int)Math.Pow(10, nofDigitsB) - 1;

          result += GetNofPairs(startNum, endNum, nofDigits);

          nofDigits++;
          startNum = (int)Math.Pow(10, nofDigits - 1);
        }

        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, result));
      }

      Helper.WriteOutputFile();
      Console.ReadKey();
    }

    private static int GetNofPairs(int startNum, int endNum, int nofDigits)
    {
      int result = 0;
      for (int i = startNum; i <= endNum; i++)
      {
        result += GetNofPairFromSingleNumber(i, endNum, nofDigits);
      }
      return result;
    }

    private static int GetNofPairFromSingleNumber(int num, int endNum, int nofDigits)
    {
      int result = 0;
      List<int> pairs = new List<int>();

      Queue<int> digits = GetDigitArr(num);

      for (int i = 1; i < nofDigits; i++)
      {
        int d = digits.Dequeue();
        digits.Enqueue(d);

        int pair = GetIntOfDigits(digits);
        if (pair > num && pair <= endNum)
        {
          if (!pairs.Contains(pair))
          {
            pairs.Add(pair);
            result++;
          }
        }
      }

      return result;
    }

    public static Queue<int> GetDigitArr(int n)
    {
      var digits = new Queue<int>();

      for (; n != 0; n /= 10)
        digits.Enqueue(n % 10);

      return digits;
    }

    public static int GetIntOfDigits(Queue<int> digits)
    {
      int num = 0;
      int multiplier = 1;
      foreach (int d in digits)
      {
        num += d * multiplier;
        multiplier *= 10;
      }
      return num;
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
