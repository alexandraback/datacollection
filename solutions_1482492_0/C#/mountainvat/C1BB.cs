using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    public class C1BB
    {
        private string mInputFile = @"E:\work\codejam2012\data\1C\B-small-attempt0.in";

        static void Main(string[] args)
        {
            var p = new C1BB();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (StreamWriter sw = new StreamWriter(mInputFile + ".out"))
            using (StreamReader sr = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(sr.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    RunTest(i + 1, sr, sw);
                }
            }
        }

        private int[] ReadIntsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings(StreamReader sr)
        {
            string line = null;
            while ((line = sr.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private double[] ReadDecsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => double.Parse(x)).ToArray();
        }

        private void RunTest(int testNum, StreamReader sr, StreamWriter sw)
        {
            var decs = ReadDecsFromLine(sr);
            double d = decs[0];
            int n = (int)decs[1];
            int a = (int)decs[2];
            var t = new double[n];
            var x = new double[n];
            var ac = new double[a];

            for (int  i =0; i < n; i++)
            {
                decs = ReadDecsFromLine(sr);
                t[i] = decs[0];
                x[i] = decs[1];
            }
            decs = ReadDecsFromLine(sr);
            for (int i = 0; i < a; i++)
                ac[i] = decs[i];

            sw.WriteLine("Case #{0}:", testNum);
            for (int i = 0; i < a; i++)
            {
                if (n == 1)
                {
                    sw.WriteLine(Solve1(d, t, x, ac[i]));
                }
                else if (n == 2)
                {
                    sw.WriteLine(Solve2(d, t, x, ac[i]));
                }
                else
                {
                    sw.WriteLine("0");
                }
            }
        }

        private double Solve1(double d, double[] t, double[] x, double ac)
        {
            return Math.Sqrt(2*d/ac);
        }

        private double Solve2(double d, double[] t, double[] x, double ac)
        {
            if (x[0] >= d)
                return Math.Sqrt(2 * d / ac);
            double v = (x[1] - x[0])/(t[1] - t[0]);
            //solving: 0.5*ac*t ^ 2 = x0 + v*t;

            double A = 0.5*ac;
            double B = -v;
            double C = -x[0];

            double delta = Math.Sqrt(B*B - 4*A*C);
            double r1 = (-B + delta)/(2*A);
            double r2 = (-B - delta) / (2 * A);

            double r = r2 >= 0 ? r2 : r1;
            double dd = 0.5*ac*r*r;
            
            if (dd >= d) return Math.Sqrt(2*d/ac);
            return r + (d-dd) / v;
        }
    }

}
