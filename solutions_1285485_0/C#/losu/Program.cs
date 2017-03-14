using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Numerics;
using System.Drawing;
using VectorClass;

namespace Mirrors
{
  class Program
  {
    public static HelperClass Helper { get; private set; }
    static void Main(string[] args)
    {
      Helper = new HelperClass();

      Vector2D_Dbl testVec1 = new Vector2D_Dbl(50, 1);
      Vector2D_Dbl testVec2 = new Vector2D_Dbl(49, 1);
      double testAngle1 = GetAngle(testVec1);
      double testAngle2 = GetAngle(testVec2);
      double angleTolerance = 0.0001 * Math.Abs(testAngle1 - testAngle2);

      for (int iTestcase = 0; iTestcase < Helper.NofTestcases; iTestcase++)
      {
        Helper.StartTestCase(iTestcase);
        int[] intLine = Helper.GetIntArray(Helper.GetLine());
        int h = intLine[0];
        int w = intLine[1];
        int d = intLine[2];
        string[] lines = new string[h];
        for (int ih = 0; ih < h; ih++)
        {
          lines[ih] = Helper.GetLine();
        }

        Vector2D_Dbl me = null;  //2D Vector class available in NuGet

        for (int ih = 0; ih < h; ih++)
        {
          if (lines[ih].Contains("X"))
          {
            double y = ih - 0.5;
            double x = lines[ih].IndexOf('X') - 0.5;
            me = new Vector2D_Dbl(x, y);
          }
        }

        w -= 2;
        h -= 2;

        int nofMirrorsWidth = d / w + 4;
        int nofMirrorsHeight = d / h + 4;

        double doubleStepX = 2 * w;
        double oneStepX = doubleStepX - 2 * me.X;

        double doubleStepY = 2 * h;
        double oneStepY = doubleStepY - 2 * me.Y;

        List<Vector2D_Dbl> viewDirections = new List<Vector2D_Dbl>();
        List<double> angles = new List<double>();

        for (int iw = -nofMirrorsWidth; iw <= nofMirrorsWidth; iw++)
        {
          double x = Math.Floor((double)iw / 2) * doubleStepX + (Math.Abs(iw) % 2) * oneStepX;

          for (int ih = -nofMirrorsHeight; ih <= nofMirrorsHeight; ih++)
          {
            double y = Math.Floor((double)ih / 2) * doubleStepY + (Math.Abs(ih) % 2) * oneStepY;
            Vector2D_Dbl viewDirection = new Vector2D_Dbl(x, y);
            double length = GetLength(viewDirection);
            if (length <= d && length > 0)
            {
              double angle = GetAngle(viewDirection);
              bool containsAngle = false;
              foreach (double a in angles)
              {
                if (Math.Abs(angle - a) < angleTolerance)
                {
                  containsAngle = true;
                  break;
                }
              }
              if (!containsAngle)
              {
                angles.Add(angle);
                viewDirections.Add(viewDirection);
              }
            }
          }
        }

        int result = viewDirections.Count;
        Helper.WriteOutput(String.Format("Case #{0}: {1}", iTestcase + 1, result));
      }

      Helper.WriteOutputFile();
    }

    private static double GetAngle(Vector2D_Dbl vec)
    {
      return Math.Atan2(vec.Y, vec.X);
    }

    private static double GetLength(Vector2D_Dbl viewDirection)
    {
      return Math.Sqrt(viewDirection.X * viewDirection.X + viewDirection.Y * viewDirection.Y);  
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
