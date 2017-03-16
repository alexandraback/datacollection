using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        public static void Main()
        {
            int T = ReadInt();
            for (int t = 1; t <= T; t++)
            {
                double[] line = ReadDoubles();
                double C = line[0];
                double F = line[1];
                double X = line[2];

                double result = Resolve(C, F, X);
                Console.WriteLine("Case #{0}: {1}", t, String.Format("{0:0.0000000}", result));
            }
        }

        // Init 2 cookies per sec.
        // double C: price of Cookie Farm
        // double F: extra cookies per sec.
        // double X: needed cookies
        public static double Resolve(double C, double F, double X)
        {
            int    Round = 0;
            double BestTime = X / 2;
            while (true)
            {
                double CurrentTime = X / (2 + ((++Round) * F));
                for (int i = 0; i < Round; i++)
                    CurrentTime += C / (2 + (i * F));

                if (CurrentTime > BestTime)
                    return BestTime;

                BestTime = CurrentTime;
            }

            return -1;
        }

        #region Library

        static string ReadLine()
        {
            return Console.ReadLine();
        }

        static string[] ReadWords()
        {
            return ReadLine().Split();
        }

        static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        static long ReadLong()
        {
            return Int64.Parse(ReadLine());
        }

        static int[] ReadInts()
        {
            return Array.ConvertAll(ReadWords(), int.Parse);
        }

        static long[] ReadLongs()
        {
            return Array.ConvertAll(ReadWords(), Int64.Parse);
        }

        static double ReadDouble()
        {
            return Double.Parse(ReadLine(), System.Globalization.NumberStyles.AllowExponent | System.Globalization.NumberStyles.Number);
        }

        static double[] ReadDoubles()
        {
            return Array.ConvertAll(ReadWords(), double.Parse);
        }

        #endregion
    }
}
