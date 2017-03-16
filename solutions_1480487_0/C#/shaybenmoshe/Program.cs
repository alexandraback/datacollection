using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SafetyInNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            /*double[] t = Solve(3, new int[] { 24, 30, 21 });
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(t[i]);
            }
            t = Solve(5, new int[] { 0, 0, 0, 0, 50 });
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(t[i]);
            }*/

            TextReader tr = new StreamReader("A-small-attempt3.in");
            TextWriter tw = new StreamWriter("A-small-attempt3.out");

            int T = int.Parse(tr.ReadLine());

            for (int k = 0; k < T; k++)
            {
                string[] data = tr.ReadLine().Split(' ');
                int N = int.Parse(data[0]);
                int[] J = new int[N];
                for (int i = 0; i < N; i++)
                    J[i] = int.Parse(data[i + 1]);

                double[] Y = Solve(N, J);

                string s = "Case #" + (k + 1) + ":";
                for (int i = 0; i < N; i++)
                    s += " " + Y[i] * 100;

                tw.WriteLine(s);
            }

            tr.Close();
            tw.Close();
        }

        static double[] Solve(int N, int[] J)
        {
            int[] Jsorted = (int[])(J.Clone());
            Array.Sort(Jsorted);

            double[] Y = new double[N];

            double X = 0;
            for (int i = 0; i < N; i++)
                X += J[i];

            for (int i = 0; i < N; i++)
            {
                double k = 1, Xt = J[i];
                bool skip = false;
                for (int j = 0; j < N; j++)
                {
                    if (!skip && J[i] == Jsorted[j])
                    {
                        skip = true;
                        continue;
                    }
                    if (Jsorted[j] >= (X + Xt) / k)
                    {
                        break;
                    }
                    Xt += Jsorted[j];
                    k++;
                }

                Y[i] = Math.Max(0, ((X + Xt) - J[i] * k) / (k * X));
            }

            return Y;
        }

        static double[] SolveOLD(int N, int[] J)
        {
            int a = 0, b = 0;

            double X = 0;

            double[] Y = new double[N];

            for (int i = 0; i < N; i++)
                X += J[i];

            for (int i = 0; i < N; i++)
                Y[i] = Math.Max(0, (2 * X - J[i] * N) / (N * X));

            return Y;
        }
    }
}
