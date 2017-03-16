using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int TESTCASES; TESTCASES = int.Parse(Console.ReadLine());

            for (int CASE = 1; CASE <= TESTCASES; CASE++)
            {
                string[] input;
                input = Console.ReadLine().Split(' ');
                int A = int.Parse(input[0]);
                int B = int.Parse(input[1]);

                input = Console.ReadLine().Split(' ');
                double[] p = new double[A];
                for (int i = 0; i < p.Length; i++)
                {
                    p[i] = double.Parse(input[i]);
                }

                for (int i = 1; i < p.Length; i++)
                    p[i] = p[i] * p[i - 1];

                double ret = 1 + B + 1;
                for (int bs = 0; bs < A; bs++)
                {
                    double ok = p[A - bs - 1] * ( bs + bs + (B - A) + 1);
                    double ng = (1 - p[A - bs - 1]) * (bs + bs + (B - A) + 1 + B + 1);
                    if (ok + ng < ret) ret = ok + ng;
                }

                Console.WriteLine("Case #" + CASE + ": " + ret);
            }
        }
    }
}
