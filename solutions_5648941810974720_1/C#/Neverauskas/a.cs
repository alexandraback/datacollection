using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "A-large";

        private static void Main()
        {
            Console.SetIn(new StreamReader(string.Format(@"D:\Contests\GoogleCodeJam\{0}.in", fileName)));
            Console.SetOut(new StreamWriter(string.Format(@"D:\Contests\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
            var t = cin.NextInt();
            for (var c = 1; c <= t; c++)
            {
                Console.Write("Case #{0}: ", c);
                Solve();
            }
        }

        private static void Solve()
        {
            var s = cin.NextString();
            var count = new int[26];
            foreach (var c in s)
            {
                count[c - 'A']++;
            }
            var nums = new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            var zeros = count['Z' - 'A'];
            for (var i = 0; i < nums[0].Length; i++)
            {
                count[nums[0][i] - 'A'] -= zeros;
            }
            var twos = count['W' - 'A'];
            for (var i = 0; i < nums[2].Length; i++)
            {
                count[nums[2][i] - 'A'] -= twos;
            }
            var sixes = count['X' - 'A'];
            for (var i = 0; i < nums[6].Length; i++)
            {
                count[nums[6][i] - 'A'] -= sixes;
            }
            var sevens = count['S' - 'A'];
            for (var i = 0; i < nums[7].Length; i++)
            {
                count[nums[7][i] - 'A'] -= sevens;
            }
            var eights = count['G' - 'A'];
            for (var i = 0; i < nums[8].Length; i++)
            {
                count[nums[8][i] - 'A'] -= eights;
            }
            var threes = count['H' - 'A'];
            for (var i = 0; i < nums[3].Length; i++)
            {
                count[nums[3][i] - 'A'] -= threes;
            }
            var fours = count['U' - 'A'];
            for (var i = 0; i < nums[4].Length; i++)
            {
                count[nums[4][i] - 'A'] -= fours;
            }
            var ones = count['O' - 'A'];
            for (var i = 0; i < nums[1].Length; i++)
            {
                count[nums[1][i] - 'A'] -= ones;
            }
            var fives = count['F' - 'A'];
            for (var i = 0; i < nums[5].Length; i++)
            {
                count[nums[5][i] - 'A'] -= fives;
            }
            var nines = count['I' - 'A'];
            for (var i = 0; i < zeros; i++)
            {
                Console.Write(0);
            }
            for (var i = 0; i < ones; i++)
            {
                Console.Write(1);
            }
            for (var i = 0; i < twos; i++)
            {
                Console.Write(2);
            }
            for (var i = 0; i < threes; i++)
            {
                Console.Write(3);
            }
            for (var i = 0; i < fours; i++)
            {
                Console.Write(4);
            }
            for (var i = 0; i < fives; i++)
            {
                Console.Write(5);
            }
            for (var i = 0; i < sixes; i++)
            {
                Console.Write(6);
            }
            for (var i = 0; i < sevens; i++)
            {
                Console.Write(7);
            }
            for (var i = 0; i < eights; i++)
            {
                Console.Write(8);
            }
            for (var i = 0; i < nines; i++)
            {
                Console.Write(9);
            }
            Console.WriteLine();
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