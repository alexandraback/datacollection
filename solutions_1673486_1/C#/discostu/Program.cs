using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using System.Globalization;

namespace PasswordProblem {
  public class Program {
    static void Main(string[] args) {
      string inputfile;
      if (args.Count() == 0) {
        inputfile = "test.in";
      } else {
        inputfile = args[0];
      }

      Solve(new StreamReader(inputfile),
        (args.Count() > 1 ? new StreamWriter(args[1]) : new StreamWriter(Console.OpenStandardOutput())));
      Console.WriteLine("."); Console.ReadLine();
    }

    private static void Solve(StreamReader reader, StreamWriter writer) {
      string[] firstLine = reader.ReadLine().Split(" ".ToCharArray());
      int N = int.Parse(firstLine[0]);
      writer.AutoFlush = true;

      for (int i = 1; i <= N; i++) {
        var p = new Program();
        writer.WriteLine("Case #{0}: {1}", i, p.SolveCase(reader));
      }

      writer.Close();
      reader.Close();
    }

    private string SolveCase(StreamReader reader) {
      Thread.CurrentThread.CurrentCulture = new CultureInfo("en-us");
      string[] tokens = reader.ReadLine().Split(" ".ToCharArray());

      int A = int.Parse(tokens[0]); // number of characters typed
      int B = int.Parse(tokens[1]); // number of total number of chars

      tokens = reader.ReadLine().Split(" ".ToCharArray());
      double[] p = new double[A];

      double[] products = new double[A];
      double product = 1.0;
      for (int i = 0; i < A; i++) {
        p[i] = double.Parse(tokens[i]);
        product *= p[i];
        products[i] = product;
      }

      double evRetry = 2 + B;
      double evCont = (product * (B - A + 1)) + ((1 - product) * (B - A + 1 + B + 1));
      double minEv = Math.Min(evRetry, evCont);

      double[] evBacksp = new double[A];
      for (int i = A-1; i > 0; i--) {
        int keyStrokesPositive = B - A + 1 + (A - i) * 2;
        //int keyStrokesNegative = (A - i) * 2 + B + 3;
        int keyStrokesNegative = keyStrokesPositive + B + 1;

        evBacksp[i] = (products[i - 1] * keyStrokesPositive) + ((1 - products[i - 1]) * keyStrokesNegative);
        minEv = Math.Min(minEv, evBacksp[i]);
      }

      return string.Format("{0:0.000000}", minEv);
    }

    /*
    private string SolveCase(StreamReader reader) {
      Thread.CurrentThread.CurrentCulture = new CultureInfo("en-us");
      string[] tokens = reader.ReadLine().Split(" ".ToCharArray());

      int A = int.Parse(tokens[0]); // number of characters typed
      int B = int.Parse(tokens[1]); // number of total number of chars

      tokens = reader.ReadLine().Split(" ".ToCharArray());
      double[] p = new double[A];

      double pWrong = 0.0m;
      double product = 1;

      double evRetry = 0.0m;
      double[] evBackspace = new double[A];
      double evKeepTypeing = 0.0m;

      int keystrokesRetry = 2 + B - A;
      int[] keystrokesBackspace = new int[A];

      double[] pWrongArr = new double[A];
      evBackspace[0] = double.MaxValue;

      for (int i = 0; i < A; i++) {
        p[i] = double.Parse(tokens[i]);
        product *= p[i];
        pWrong = 1 - product;

        keystrokesRetry++;
        keystrokesBackspace[i] = B - A + 1 + (A - i) * 2;

        //evBackspace[i] = pWrong * keystrokesBackspace[i];
      }

      evRetry = pWrong * keystrokesRetry;
      evKeepTypeing = product * (B - A + 1);

      product = 1.0m;
      for (int i = A - 1; i > 0; i--) {
        product *= p[i];
        pWrong = 1 - product;
        evBackspace[i] = (pWrong * B) + keystrokesBackspace[i];
      }

      double result = 0.0m;

      double minEv = double.MaxValue;
      for (int i = 0; i < A; i++) {
        if (evBackspace[i] < minEv) {
          result = keystrokesBackspace[i];
          minEv = evBackspace[i];
        }
      }
      if (evRetry < minEv) {
        result = keystrokesRetry;
        minEv = evRetry;
      }


      return result.ToString();
    }
     * */
  }
}
