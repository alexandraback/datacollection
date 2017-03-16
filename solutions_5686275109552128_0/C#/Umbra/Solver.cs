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
            int d = ReadInt();
            int[] p = new int[1010];
            int maxP = 0;
            for (int i = 0; i < d; i++)
            {
                var x = ReadInt();
                p[x]++;
                maxP = Math.Max(maxP, x);
            }

            int bestTime = maxP;
            int spCount = 0;
            while (spCount < bestTime && maxP > 9)
            {
                p[maxP / 2]++;
                p[(maxP + 1) / 2]++;
                p[maxP]--;
                spCount++;
                while (maxP > 0 && p[maxP] == 0)
                {
                    maxP--;
                }
                bestTime = Math.Min(bestTime, spCount + maxP);
            }

            var p2 = new int[10];
            for (int i = 0; i < 10; i++)
            {
                p2[i] = p[i];
            }
            var spCount2 = spCount;
            var maxP2 = maxP;

            while (spCount < bestTime)
            {
                if (maxP != 9)
                {
                    p[maxP / 2]++;
                    p[(maxP + 1) / 2]++;
                }
                else
                {
                    p[6]++;
                    p[3]++;
                }
                p[maxP]--;
                spCount++;
                while (maxP > 0 && p[maxP] == 0)
                {
                    maxP--;
                }
                bestTime = Math.Min(bestTime, spCount + maxP);
            }

            while (spCount2 < bestTime)
            {
                p2[maxP2 / 2]++;
                p2[(maxP2 + 1) / 2]++;
                p2[maxP2]--;
                spCount2++;
                while (maxP2 > 0 && p2[maxP2] == 0)
                {
                    maxP2--;
                }
                bestTime = Math.Min(bestTime, spCount2 + maxP2);
            }

            Writer.WriteLine("Case #{0}: {1}", caseNumber, bestTime);
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
