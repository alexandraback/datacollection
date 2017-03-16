using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Helper;

namespace ProblemA
{
    public class Solver
    {
        public int GCD(int a, int b)
        {
            while (b != 0)
            {
                var t = a;
                a = b;
                b = t % b;
            }
            return Math.Abs(a);
        }

        public int GetPower(int b)
        {
            for (int i = 0;; i++)
            {
                if (b == 1)
                {
                    return i;
                }

                if ((b & 1) == 1)
                {
                    return -1;
                }
                b /= 2;
            }
        }

        public String Solve(String input)
        {
            var sb = new StringBuilder();
            var reader = new InputReader(input);
            var T = reader.NextInt();
            for (int i = 0; i < T; i++)
            {
                var pq = reader.NextString().Split('/');
                var P = int.Parse(pq[0]);
                var Q = int.Parse(pq[1]);
                var gcd = GCD(P, Q);
                P /= gcd;
                Q /= gcd;

                var p = GetPower(Q);

                sb.Append("Case #");
                sb.Append("" + (i + 1));
                sb.Append(": ");

                if (p == -1)
                {
                    sb.Append("impossible");
                }
                else
                {
                    p = 0;
                    while (P < Q)
                    {
                        p++;
                        P*=2;
                    }
                    sb.Append(p);
                }
                sb.AppendLine();
            }

            return sb.ToString();
        }
    }


    public class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = "example.in";
            const string filename = "A-small-attempt1.in";
            string outFile = filename.Replace(".in", ".out");
            var result = new Solver().Solve(File.ReadAllText(filename));
            Console.Write(result);
            File.WriteAllText(outFile, result);
        }
    }
}
