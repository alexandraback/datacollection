using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using __CURRENT_PROBLEM__ = _2016_round1b.C;

// https://code.google.com/codejam/contest/11254486/dashboard
namespace _2016_round1b
{
    public class A
    {
        private static readonly string[] N = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
        public object Solve(Func<string> read)
        {
            var s = read();
            var d = s.GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());
            var cts = new int[10];
            cts[0] = Greedy(d, 0);
            cts[2] = Greedy(d, 2);
            cts[4] = Greedy(d, 4);
            cts[6] = Greedy(d, 6);
            cts[8] = Greedy(d, 8);
            cts[5] = Greedy(d, 5);
            cts[1] = Greedy(d, 1);
            cts[7] = Greedy(d, 7);
            cts[3] = Greedy(d, 3);
            cts[9] = Greedy(d, 9);

            return string.Join("", cts.SelectMany((c, i) => Enumerable.Repeat($"{i}", c)));
        }

        private static int Greedy(Dictionary<char, int> d, int i)
        {
            var ct = N[i].Min(c => d.ContainsKey(c) ? d[c] : 0);
            if (ct > 0)
            {
                foreach (var c in N[i]) d[c] -= ct;
            }
            return ct;
        }
    }

    public class B
    {
        public object Solve(Func<string> read)
        {
            var s = read().Some<string>();
            var c = s[0];
            var j = s[1];

            for (var i = 0; i < c.Length; i++)
            {
                if (c[i] != '?' && j[i] != '?') continue;

            }

            //while ((c + j).IndexOf('?') != -1)
            //{
            //    var cg = c.Replace('?', '0');
            //    var jg = j.Replace('?', '0');
            //    var diff = cg.CompareTo(jg);
            //    if (diff == 0) return cg + " " + jg;
            //    if (diff < 0)
            //    {
            //        var ix = c.IndexOf('?');
            //        if (ix == -1) return cg + " " + jg;
            //        var n = 1;
            //        for (; n < 9 && Repl(cg, ix, n).CompareTo(jg) < 0; n++) ;
            //        c = Repl(c, ix, (char) ('0' + n));
            //    }
            //    else
            //    {
            //        var ix = j.IndexOf('?');
            //        if (ix == -1) return cg + " " + jg;
            //        var n = 1;
            //        for (; n < 9 && Repl(jg, ix, n).CompareTo(cg) < 0; n++) ;
            //        j = Repl(j, ix, (char)('0' + n));
            //    }
            //}
            return c + " " + j;
        }

        private string Repl(string s, int ix, int n)
        {
            return s.Substring(0, ix) + (char)('0' + n) + s.Substring(ix + 1);
        }
    }

    public class C
    {
        public object Solve(Func<string> read)
        {
            var n = read().One<int>();
            var ll = read.Many<string>(n);
            var best = 0;
            var mx = (int)Math.Pow(2, n);
            for (var i = 0; i < mx; i++)
            {
                var barr = new BitArray(n);
                for (var j = 0; j < n; j++) barr[j] = (i >> j)%2 == 1;
                var good = ll.Where((sa, ix) => barr[ix]).ToArray();
                var bad = ll.Where((sa, ix) => !barr[ix]).ToArray();
                if (bad.Length > best && bad.All(sa => good.Any(g => g[0] == sa[0]) && good.Any(g => g[1] == sa[1])))
                    best = bad.Length;
            }

            return best;
        }
    }

    public static class Util
    {
        public static T One<T>(this string s) => (T)Convert.ChangeType(s, typeof(T));
        public static T[] Some<T>(this string s) => s.Split(' ').Select(One<T>).ToArray();
        public static T[][] Many<T>(this Func<string> read, int rows)
            => Enumerable.Range(1, rows).Select(_ => read().Some<T>()).ToArray();
    }

    public class Program
    {
        public static void Main()
        {
            const int buf = 1024 * 1024;
            using (var reader = new StreamReader(Console.OpenStandardInput(buf), Console.InputEncoding, false, buf))
            {
                using (var writer = new StreamWriter(new FileStream("output.txt", FileMode.Create)))
                {
                    var cases = reader.ReadLine().One<int>();
                    for (var i = 0; i < cases; i++)
                    {
                        var result = new __CURRENT_PROBLEM__().Solve(reader.ReadLine);
                        var output = $"Case #{i + 1}: {result}";
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.WriteLine(output);
                        Console.ResetColor();
                        writer.WriteLine(output);
                    }
                    Console.ReadLine();
                }
            }
        }
    }
}
