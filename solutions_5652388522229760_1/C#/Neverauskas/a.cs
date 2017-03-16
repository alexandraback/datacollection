using System;
using System.Collections.Generic;
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
            var i = cin.NextInt();
            if (i == 0)
            {
                Console.WriteLine("INSOMNIA");
                return;
            }

            var set = new HashSet<char>();
            var n = 0;
            for (var j = 1;; j++)
            {
                n += i;
                Array.ForEach(n.ToString().ToCharArray(), x => set.Add(x));
                if (set.Count == 10)
                {
                    Console.WriteLine(n);
                    break;
                }
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