using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace Diamond
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
        int n = Helper.GetInteger(Helper.GetLine(), 0);

        List<int[]> classes = new List<int[]>();
        classes.Add(null);

        for (int iClass = 0; iClass < n; iClass++)
        {
          string line = Helper.GetLine();
          int mi = Helper.GetInteger(line, 0);
          int[] inherited = new int[mi];
          int[] all = Helper.GetIntArray(line);
          for (int i = 0; i < mi; i++)
          {
            inherited[i] = all[i + 1];
          }
          classes.Add(inherited);
        }

        List<int> classesInPaths = new List<int>(n);

        //assemble paths
        bool result = false;
        for (int iClass = 1; iClass <= n; iClass++)
        {
          classesInPaths.Clear();
          if (CheckAndAdd(classesInPaths, iClass, classes))
          {
            result = true;
            break;
          }
        }

        string strResult = result ? "Yes" : "No";

        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, strResult));
      }

      Helper.WriteOutputFile();
    }

    private static bool CheckAndAdd(List<int> classesInPaths, int newClass, List<int[]> classes)
    {
      if (classesInPaths.Contains(newClass))
        return true;

      classesInPaths.Add(newClass);

      int[] inherits = classes[newClass];

      for (int i = 0; i < inherits.Length; i++)
      {
        int inherit = inherits[i];
        if (CheckAndAdd(classesInPaths, inherit, classes))
          return true;
      }

      return false;
    }

    private static bool CheckPathStartWith(List<List<int>> paths, int classIndex)
    {
      for (int i = 0; i < paths.Count; i++)
      {
        List<int> path = paths[i];
        if (path[0] == classIndex)
          return true;
      }
      return false;
    }

    private static bool CheckPathContains(List<List<int>> paths, int classIndex)
    {
      for (int i = 0; i < paths.Count; i++)
      {
        List<int> path = paths[i];
        for (int iInherit = 0; iInherit < path.Count; iInherit++)
        {
          if (path[iInherit] == classIndex)
            return true;
        }
      }
      return false;
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
