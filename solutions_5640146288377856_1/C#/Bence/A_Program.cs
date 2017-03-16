using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A_Problem
{
    class A_Program
    {
        public static Int64 Solve()
        {
            Int64[] Row1 = ReadLongs();

            Int64 R = Row1[0];
            Int64 C = Row1[1];
            Int64 W = Row1[2];

            return ((Int64)Math.Floor((double)C / W) * R) + (W - 1) + ((((C - (Int64)Math.Floor((double)C / W) * W)) > 0) ? 1 : 0);
        }

        static void Main(string[] args)
        {
            int T = ReadInt();
            for (int t = 1; t <= T; t++)
                Console.WriteLine("Case #{0}: {1}", t, Solve().ToString());
        }

        #region Library

        public static string ReadLine()
        {
            return Console.ReadLine().Trim();
        }

        public static string[] ReadLines(int quantity)
        {
            string[] lines = new string[quantity];
            for (int i = 0; i < quantity; i++)
                lines[i] = ReadLine().Trim();
            return lines;
        }

        public static string[] ReadWords()
        {
            //return ReadLine().Trim().Split(default(string[]), StringSplitOptions.RemoveEmptyEntries);
            return ReadLine().Trim().Split();
        }

        public static Int64[] ReadPars()
        {
            return Array.ConvertAll(ReadLine().Trim().Split('/'), Int64.Parse);
        }

        public static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        public static int[] ReadInts()
        {
            return Array.ConvertAll(ReadWords(), int.Parse);
        }

        public static int[][] ReadIntMatrix(int numberOfRows)
        {
            int[][] matrix = new int[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadInts();
            return matrix;
        }

        public static Int64 ReadLong()
        {
            return Int64.Parse(ReadLine());
        }

        public static Int64[] ReadLongs()
        {
            return Array.ConvertAll(ReadWords(), Int64.Parse);
        }

        public static Int64[][] ReadLongMatrix(int numberOfRows)
        {
            Int64[][] matrix = new Int64[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadLongs();
            return matrix;
        }

        public static double ReadDouble()
        {
            return Double.Parse(ReadLine(), System.Globalization.NumberStyles.AllowExponent | System.Globalization.NumberStyles.Number);
        }

        public static double[] ReadDoubles()
        {
            return Array.ConvertAll(ReadWords(), double.Parse);
        }

        public static double[][] ReadDoubleMatrix(int numberOfRows)
        {
            double[][] matrix = new double[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadDoubles();
            return matrix;
        }

        #endregion
    }
}
