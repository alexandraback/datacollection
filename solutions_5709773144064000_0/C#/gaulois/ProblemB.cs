
#define TRACE

using System;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Problem
    {
        public double c;
        public double f;
        public double x;
    }

    class MainClass
    {
        static double Solve(Problem m)
        {
            double tNow = 0.0;
            double rate = 2.0;
            double cNow = 0.0;
            double tElapsed = 0.0;
            // double epsilon = 1e-7;

            while (true)
            {
                //System.Console.WriteLine(tNow);

                double tWinNoBuy = tNow + (m.x - cNow) / rate;
                double tWinBuy = double.MaxValue;

                if (cNow >= m.c)
                {
                    tWinBuy = tNow + (m.x - (cNow - m.c)) / (rate + m.f);
                }

                // Pick choice and walk
                if (tWinBuy < tWinNoBuy)
                {
                    rate += m.f;
                    cNow -= m.c;

                    double tBef = tNow;
                    tNow = tNow + (m.c - cNow) / rate;
                    tElapsed = tNow - tBef;

                    if(tNow >= tWinBuy)
                    {
                        return tWinBuy;
                    }
                }
                else
                {
                    double tBef = tNow;
                    tNow = tNow + (m.c - cNow) / rate;
                    tElapsed = tNow - tBef;

                    if (tNow >= tWinNoBuy || tElapsed == 0.0)
                    {
                        return tWinNoBuy;
                    }
                }

                // Win points --> this is pre-calculated!
                cNow = m.c;
            }

            return -1.0;
        }

        static List<Problem> ReadProblems(string file)
        {
            List<Problem> problems = new List<Problem>();

            string[] lines = System.IO.File.ReadAllLines(file);

            int nProbs = int.Parse(lines[0]);
            for (int i = 1; i < lines.Length; ++i)
            {
                Problem problem = new Problem();

                string[] N = lines[i].Split(' ');

                problem.c = double.Parse(N[0].Trim());
                problem.f = double.Parse(N[1].Trim());
                problem.x = double.Parse(N[2].Trim());

                problems.Add(problem);
            }

            // Trace.Assert (nProbs == problems.Count);

            return problems;
        }

        public static void Main(string[] args)
        {
            Trace.Listeners.Add(new ConsoleTraceListener());

            string filename = "../../B-small-attempt0.in";
            //string filename = "../../C-small-practice.in";
            //string filename = "../../C-large-practice.in";

            List<Problem> problems = ReadProblems(filename);

            int i = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var problem in problems)
            {
                double res = Solve(problem);

                string s = string.Format("Case #{0}: {1:F10}", i + 1, res);

                Console.WriteLine(s);
                sb.Append(s);
                sb.Append("\n");

                ++i;
            }

            System.IO.File.WriteAllText(filename.Replace(".in", ".out"), sb.ToString());
        }
    }
}
