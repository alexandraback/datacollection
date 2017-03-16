using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    internal class Template
    {
        private static readonly Scanner cin = new Scanner();
        private const string fileName = "B-small-attempt0";

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
            var c = cin.NextString();
            var j = cin.NextString();
            var q = c.Count(x => x == '?') + j.Count(x => x == '?');
            var num = 0;
            var diff = int.MaxValue;
            var cs = string.Empty;
            var js = string.Empty;
            while (true)
            {
                var str = num.ToString();
                if (str.Length > q)
                {
                    break;
                }
                str = new string('0', q - str.Length) + str;
                var idx = 0;
                var cc = c.ToCharArray();
                var jj = j.ToCharArray();
                for (var i = 0; i < cc.Length; i++)
                {
                    if (cc[i] == '?')
                    {
                        cc[i] = str[idx];
                        idx++;
                    }
                }
                for (var i = 0; i < jj.Length; i++)
                {
                    if (jj[i] == '?')
                    {
                        jj[i] = str[idx];
                        idx++;
                    }
                }
                var ccc = new string(cc);
                var jjj = new string(jj);

                var c4 = int.Parse(ccc);
                var j4 = int.Parse(jjj);

                var d = Math.Abs(c4 - j4);
                if (d < diff)
                {
                    diff = d;
                    cs = ccc;
                    js = jjj;
                }
                num++;
            }
            Console.Write(cs);
            Console.Write(" ");
            Console.WriteLine(js);
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