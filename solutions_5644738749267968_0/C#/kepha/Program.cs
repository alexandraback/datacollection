using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.In.ReadLine());
            int N = 0;
            string[] rawtemp = new string[4];
            double[] raw1, raw2;

            for (int t = 1; t <= T; t++)
            {
                N = Convert.ToInt32(Console.In.ReadLine());
                raw1 = new double[N];
                raw2 = new double[N];
                rawtemp = Console.In.ReadLine().Split(' ');
                for (int i = 0; i < N; i++)
                {
                    raw1[i] = Convert.ToDouble(rawtemp[i].Replace(".", ","));
                }
                rawtemp = Console.In.ReadLine().Split(' ');
                for (int i = 0; i < N; i++)
                {
                    raw2[i] = Convert.ToDouble(rawtemp[i].Replace(".", ","));
                }

                Console.Out.WriteLine(Solver.solve(t, raw1, raw2, N));    
            }
        }
    }

    public class Solver
    {
        public static string solve(int number, double[] raw1, double[] raw2, int N)
        {
            string toReturn = "Case #" + number + ": ";

            Array.Sort(raw1);
            Array.Sort(raw2);

            int score = 0;
            int index = N - 1;
            for (int i = N - 1; i >= 0; i--)
            {
                if (raw2[i] < raw1[index])
                {
                    score++;
                    index--;
                }
            }
            toReturn += score+" ";

            index = N - 1;
            score = 0;
            for (int i = N-1; i >= 0; i--)
            {
                if (raw2[index] > raw1[i]) index--;
                else score++;
            }
            toReturn += score;

            return  toReturn;
        }
    }
}
