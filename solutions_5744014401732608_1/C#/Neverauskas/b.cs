using System;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "B-large";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Debug.WriteLine(c);
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static Random random = new Random();

        private static void Solve()
        {
            var b = cin.NextInt();
            var m = cin.NextLong();
            var matrix = new int[b, b];
            for (var i = 0; i < 100000; i++)
            {
                memo = new long[60];
                for (var j = 0; j < memo.Length; j++)
                {
                    memo[j] = -1;
                }
                for (var j = 0; j < b - 1; j++)
                {
                    for (var k = j + 1; k < b; k++)
                    {
                        var val = random.Next() % 2;
                        matrix[j, k] = val;
                    }
                }
                var ways = Count(matrix, b, 0);
                if (ways == m)
                {
                    Console.WriteLine("POSSIBLE");
                    Print(matrix, b);
                    return;
                }
            }
            Console.WriteLine("IMPOSSIBLE");
        }

        private static long[] memo;

        private static long Count(int[,] matrix, int b, int p)
        {
            if (p == b - 1)
            {
                return 1;
            }
            if (memo[p] != -1)
            {
                return memo[p];
            }
            var count = 0L;
            for (var i = p + 1; i < b; i++)
            {
                if (matrix[p, i] == 1)
                {
                    count += Count(matrix, b, i);
                }
            }
            memo[p] = count;
            return count;
        }

        private static void Print(int[,] matrix, int b)
        {
            for (var i = 0; i < b; i++)
            {
                for (var j = 0; j < b; j++)
                {
                    Console.Write(matrix[i, j]);
                }
                Console.WriteLine();
            }
        }
    }

    internal class Scanner
    {
        private string[] s = new string[0];
        private int i;
        private readonly char[] cs = { ' ' };

        public string NextString()
        {
            if (i < s.Length) return s[i++];
            var line = Console.ReadLine() ?? string.Empty;
            if (line == string.Empty)
            {
                return NextString();
            }
            s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 1;
            return s.First();
        }

        public double NextDouble()
        {
            return double.Parse(NextString());
        }

        public int NextInt()
        {
            return int.Parse(NextString());
        }

        public long NextLong()
        {
            return long.Parse(NextString());
        }
    }
}