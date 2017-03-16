using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

#if true
namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            string numCaseStr = Console.ReadLine();
            int numCase = int.Parse(numCaseStr);

            for (int c = 0; c < numCase; c++)
            {
                string output = SolveCase(c);

                Console.WriteLine("Case #" + (c + 1) + ": " + output);
                Debug.WriteLine("Case #" + (c + 1) + ": " + output);
            }
        }

        static string SolveCase(int c)
        {
            string input = Console.ReadLine();
            string[] inputs = input.Split(' ');

            int N = int.Parse(inputs[0]);
            int[] s = new int[N];
            int X = 0;
            double[] m = new double[N];

            for (int i = 0; i < N; i++)
            {
                s[i] = int.Parse(inputs[i+1]);
                X += s[i];
                m[i] = 0.0f;
            }

            // better be sort, but i dont have much time to implement

            for (int i = 0; i < N; i++)
            {
                int M = N; // count greater score than i
                int Y = X;

                double limit = (X + Y) / (double)M;

                for (int j = 0; j < N; j++)
                {
                    if (i != j && s[j] > limit)//s[i])
                    {
                        M -= 1;
                        Y -= s[j];
                    }
                }

                limit = (X + Y) / (double)M;

                if (s[i] >= limit)
                    m[i] = 0;
                else
                    m[i] = 100.0 * (limit - s[i]) / (double)X;
            }

            string output = "";

            for (int i = 0; i < N; i++)
            {
                output += m[i].ToString("0.000000");
                if (i != N - 1) output += " ";
            }

            return output;
        }
    }
}
#endif
