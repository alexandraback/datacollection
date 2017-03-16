using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ReadWriteTemplate
{
    public class Solver
    {
        private static void SolveCase(int caseNumber)
        {
            int x = ReadInt();
            int r = ReadInt();
            int c = ReadInt();

            if (x >= 8)
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "RICHARD");
                return;
            }

            if ((r * c) % x != 0)
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "RICHARD");
                return;
            }

            if ((x + 1) / 2 > Math.Min(r, c))
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "RICHARD");
                return;
            }

            if (x > Math.Max(r, c))
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "RICHARD");
                return;
            }

            var gcd = Gcd(Math.Min(r, c), x);
            if (gcd > 1 && x >= 2 * Math.Min(r, c))
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "RICHARD");
                return;
            }

            Writer.WriteLine("Case #{0}: {1}", caseNumber, "GABRIEL");
        }

        public static int Gcd(int a, int b)
        {
            return b != 0 ? Gcd(b, a % b) : a;
        }

        public static void Solve()
        {
            var n = ReadInt();
            for (int i = 0; i < n; i++)
            {
                SolveCase(i + 1);
            }
        }

        public static void Main()
        {
            //Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");

            Solve();

            Reader.Close();
            Writer.Close();
        }

        #region Read/Write

        private static TextReader Reader;

        private static TextWriter Writer;

        private static Queue<string> CurrentLineTokens = new Queue<string>();

        private static string[] ReadAndSplitLine()
        {
            return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static string ReadToken()
        {
            while (CurrentLineTokens.Count == 0)
                CurrentLineTokens = new Queue<string>(ReadAndSplitLine());
            return CurrentLineTokens.Dequeue();
        }

        public static int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        public static long ReadLong()
        {
            return long.Parse(ReadToken());
        }

        public static double ReadDouble()
        {
            return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
        }

        public static int[] ReadIntArray()
        {
            return ReadAndSplitLine().Select(int.Parse).ToArray();
        }

        public static long[] ReadLongArray()
        {
            return ReadAndSplitLine().Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
        }

        public static int[][] ReadIntMatrix(int numberOfRows)
        {
            int[][] matrix = new int[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadIntArray();
            return matrix;
        }

        public static string[] ReadLines(int quantity)
        {
            string[] lines = new string[quantity];
            for (int i = 0; i < quantity; i++)
                lines[i] = Reader.ReadLine().Trim();
            return lines;
        }

        public static void WriteArray<T>(IEnumerable<T> array)
        {
            Writer.WriteLine(string.Join(" ", array));
        }

        #endregion
    }
}
