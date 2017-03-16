using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace BoxFactory
{
  class Program
  {
    public static HelperClass Helper { get; private set; }

    static long[] line1Counts;
    static int[] line1Types;
    static long[] line2Counts;
    static int[] line2Types;
    static List<State> states;

    static void Main(string[] args)
    {
      Helper = new HelperClass();

      for (int iTestcase = 0; iTestcase < Helper.NofTestcases; iTestcase++)
      {
        Helper.StartTestCase(iTestcase);
        int[] intLine = Helper.GetIntArray(Helper.GetLine());

        int nofLine1 = intLine[0];
        int nofLine2 = intLine[1];

        line1Counts = new long[nofLine1];
        line1Types = new int[nofLine1];
        line2Counts = new long[nofLine2];
        line2Types = new int[nofLine2];

        long[] line1Content = Helper.GetLongArray(Helper.GetLine());
        for (int i = 0; i < nofLine1; i++)
        {
          line1Counts[i] = line1Content[2 * i];
          line1Types[i] = (int)line1Content[2 * i + 1];
        }
        long[] line2Content = Helper.GetLongArray(Helper.GetLine());
        for (int i = 0; i < nofLine2; i++)
        {
          line2Counts[i] = line2Content[2 * i];
          line2Types[i] = (int)line2Content[2 * i + 1];
        }

        states = new List<State>();

        long result = GetPoints(0, line1Counts[0], 0, line2Counts[0], 0);
        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, result));
      }

      Helper.WriteOutputFile();
    }

    static long GetPoints(int line1Index, long line1Remaining, int line2Index, long line2Remaining, long currentPoints)
    {
      long points = currentPoints;

      #region type is equal
      if (line1Types[line1Index] == line2Types[line2Index])
      {
        if (line1Remaining > line2Remaining)
        {
          points += line2Remaining;
          line1Remaining -= line2Remaining;
          line2Index++;
          if (line2Index == line2Counts.Length)
            return points;
          line2Remaining = line2Counts[line2Index];
        }
        else if (line1Remaining < line2Remaining)
        {
          points += line1Remaining;
          line2Remaining -= line1Remaining;
          line1Index++;
          if (line1Index == line1Counts.Length)
            return points;
          line1Remaining = line1Counts[line1Index];
        }
        else  //equal
        {
          points += line1Remaining;
          line1Index++;
          line2Index++;
          if (line1Index == line1Counts.Length || line2Index == line2Counts.Length)
            return points;
          line1Remaining = line1Counts[line1Index];
          line2Remaining = line2Counts[line2Index];
        }
        return GetPoints(line1Index, line1Remaining, line2Index, line2Remaining, points);
      }
      #endregion

      List<State> sameIndexStates = new List<State>();
      foreach (State st in states)
      {
        if (st.Line1Index == line1Index && st.Line2Index == line2Index)
          sameIndexStates.Add(st);
      }

      bool bestToContinueLine1 = true;
      foreach (State st in sameIndexStates)
      {
        if (st.FilledBoxes >= points + line2Remaining)
          bestToContinueLine1 = false;
        if (st.FilledBoxes >= points && st.Line2Remaining >= line2Remaining)
          bestToContinueLine1 = false;
      }

      bool bestToContinueLine2 = true;
      foreach (State st in sameIndexStates)
      {
        if (st.FilledBoxes >= points + line1Remaining)
          bestToContinueLine2 = false;
        if (st.FilledBoxes >= points && st.Line1Remaining >= line1Remaining)
          bestToContinueLine2 = false;
      }

      if (bestToContinueLine1 || bestToContinueLine2)
      {
        State state = new State();
        state.Line1Index = line1Index;
        state.Line2Index = line2Index;
        state.FilledBoxes = currentPoints;
        state.Line1Remaining = line1Remaining;
        state.Line2Remaining = line2Remaining;
        states.Add(state);
      }

      long newPoints1 = 0;
      long newPoints2 = 0;

      if (bestToContinueLine1)
      {
        int newLine1Index = line1Index + 1;
        if (newLine1Index < line1Counts.Length)
        {
          newPoints1 = GetPoints(newLine1Index, line1Counts[newLine1Index], line2Index, line2Remaining, points);
        }
      }
      if (bestToContinueLine2)
      {
        int newLine2Index = line2Index + 1;
        if (newLine2Index < line2Counts.Length)
        {
          newPoints2 = GetPoints(line1Index, line1Remaining, newLine2Index, line2Counts[newLine2Index], points);
        }
      }

      return Math.Max(newPoints1, newPoints2);
    }
  }

  public class State
  {
    public int Line1Index { get; set; }
    public int Line2Index { get; set; }
    public long FilledBoxes { get; set; }
    public long Line1Remaining { get; set; }
    public long Line2Remaining { get; set; }
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
