using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CJ
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("input.txt");
            StreamWriter output = new StreamWriter("output.txt");

            int Count = int.Parse(input.ReadLine());

            for (int i = 0; i < Count; i++)
            {
                string[] line = input.ReadLine().Split(new char[] { ' ' });

                int A = int.Parse(line[0]);
                int B = int.Parse(line[1]);

                double[] p = new double[A];

                line = input.ReadLine().Split(new char[] { ' ' });

                for (int j = 0; j < A; j++)
                {
                    p[j] = double.Parse(line[j]);
                }

                double sol = Solve(A, B, p);

                Debug.WriteLine("Case #" + (i + 1) + ": " + sol);
                output.WriteLine("Case #" + (i + 1) + ": " + sol);
            }


            input.Close();
            output.Close();
        }

        static double Solve(int A, int B, double[] p)
        {
            List<double> sols = new List<double>();

            sols.Add(B + 2);

            for (int i = 0; i <= A; i++)
            {
                double cp = 1;

                for (int j = 0; j < A - i; j++)
                {
                    cp *= p[j];
                }

                double exp = (B - A + 1 + i + i) * cp + (B - A + 1 + i + i + B + 1) * (1 - cp);
                Debug.WriteLine(exp);
                sols.Add(exp);
            }

            return sols.Min();
        }
    }
}
