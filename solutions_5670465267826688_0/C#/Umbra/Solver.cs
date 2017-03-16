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
            int l = ReadInt();
            int x = ReadInt();
            var s = ReadToken();

            var total = new Num('1');
            for (int i = 0; i < l * (x % 4); i++)
            {
                total.Mult(s[i % l]);
            }
            if (!(total.Value == '1' && !total.Positive))
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, "NO");
                return;
            }

            var limit = Math.Min(x * l, 12 * l);

            int index = 0;
            for (int count = 0; count < 2; count++)
            {
                var ch = count == 0 ? 'i' : 'j';
                var num = new Num('1');
                var nextFound = false;
                while (index < limit)
                {
                    num.Mult(s[index % l]);
                    if (num.Eq(ch))
                    {
                        nextFound = true;
                        index++;
                        break;
                    }
                    index++;
                }

                if (!nextFound)
                {
                    Writer.WriteLine("Case #{0}: {1}", caseNumber, "NO");
                    return;
                }
            }

            Writer.WriteLine("Case #{0}: {1}", caseNumber, "YES");
        }

        public struct Num
        {
            public Num(char value) : this()
            {
                Value = value;
                Positive = true;
            }

            public bool Eq(char ch)
            {
                return Value == ch && Positive;
            }

            public void Mult(char ch)
            {
                if (Value == '1')
                {
                    Value = ch;
                    return;
                }
                if (Value == 'i')
                {
                    if (ch == 'i')
                    {
                        Value = '1';
                        Positive = !Positive;
                    }
                    if (ch == 'j')
                    {
                        Value = 'k';
                    }
                    if (ch == 'k')
                    {
                        Value = 'j';
                        Positive = !Positive;
                    }
                    return;
                }
                if (Value == 'j')
                {
                    if (ch == 'i')
                    {
                        Value = 'k';
                        Positive = !Positive;
                    }
                    if (ch == 'j')
                    {
                        Value = '1';
                        Positive = !Positive;
                    }
                    if (ch == 'k')
                    {
                        Value = 'i';
                    }
                    return;
                }
                if (Value == 'k')
                {
                    if (ch == 'i')
                    {
                        Value = 'j';
                    }
                    if (ch == 'j')
                    {
                        Value = 'i';
                        Positive = !Positive;
                    }
                    if (ch == 'k')
                    {
                        Value = '1';
                        Positive = !Positive;
                    }
                    return;
                }
            }

            public char Value;
            public bool Positive;
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
