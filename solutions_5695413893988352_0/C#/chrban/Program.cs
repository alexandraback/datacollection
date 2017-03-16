using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using __CURRENT_PROBLEM__ = _2016_round1b.B;

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
            var best = (string)null;
            var bd = long.MaxValue;

            for (var x = 0; x < 1000000; x++)
            {
                var sx = x.ToString().PadLeft(6, '0');
                if (sx[0] != '0' && c[0] != '?') continue;
                if (sx[1] != '0' && (c.Length < 2 || c[1] != '?')) continue;
                if (sx[2] != '0' && (c.Length < 3 || c[2] != '?')) continue;
                if (sx[3] != '0' && j[0] != '?') continue;
                if (sx[4] != '0' && (j.Length < 2 || j[1] != '?')) continue;
                if (sx[5] != '0' && (j.Length < 3 || j[2] != '?')) continue;

                var cs = "" + (c[0] == '?' ? sx[0] : c[0]);
                var js = "" + (j[0] == '?' ? sx[3] : j[0]);
                if (c.Length > 1)
                {
                    cs += c[1] == '?' ? sx[1] : c[1];
                    js += j[1] == '?' ? sx[4] : j[1];
                }
                if (c.Length > 2)
                {
                    cs += c[2] == '?' ? sx[2] : c[2];
                    js += j[2] == '?' ? sx[5] : j[2];
                }
                var ds = cs + " " + js;
                var dd = Math.Abs(long.Parse(cs) - long.Parse(js));
                if (dd == bd && ds.CompareTo(best) < 0 || dd < bd)
                {
                    bd = dd;
                    best = ds;
                }
            }

            return best;
        }
    }

    public class C
    {
        public object Solve(Func<string> read)
        {
            throw new NotImplementedException();
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
