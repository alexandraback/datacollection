using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "C-large";

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
            var nn = cin.NextInt();
            var jj = cin.NextInt();

            Console.WriteLine();
            var counter = 0;
            var s = 1 << (nn - 3);
            var n = 1 << (nn - 2);
            for (var i = s; i < n; i++)
            {
                var num = new List<int> { 1};
                var ii = i;
                while (ii > 0)
                {
                    num.Add(ii % 2);
                    ii /= 2;
                }
                num.Add(1);

                var divs = new List<int>();
                for (var b = 2; b <= 10; b++)
                {
                    var val = new BigInteger();
                    var mult = new BigInteger(1);
                    for (var j = 0; j < num.Count; j++)
                    {
                        val += num[j]*mult;
                        mult *= b;
                    }
                    if (val%2 == 0)
                    {
                        divs.Add(2);
                    }
                    else
                    {
                        for (var j = 3; j * j <= val && j < 1000; j += 2)
                        {
                            if (val % j == 0)
                            {
                                divs.Add(j);
                                break;
                            }
                        }
                    }
                    if (divs.Count + 1 < b)
                    {
                        break;
                    }
                }

                if (divs.Count == 9)
                {
                    counter++;
                    num.Reverse();
                    foreach (var item in num)
                    {
                        Console.Write(item);
                    }
                    foreach (var item in divs)
                    {
                        Console.Write(" " + item);
                    }
                    Console.WriteLine();
                    if (counter >= jj)
                    {
                        return;
                    }
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