using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012
{
    internal static class Program
    {
        private static string readln() { return Console.ReadLine(); }
        private static void println(string s) { Console.WriteLine(s); }
        private static void print(string s) { Console.Write(s); }
        class cell
        {
            public int Item1 { get; set; }
            public bool Item2 { get; set; }
        }
        private static void Main()
        {
            var T = int.Parse(readln());
            var n = T;
            while(n-->0)
            {
                var ar = readln().Split(' ');
                var N = int.Parse(ar[0]);
                var ilist = ar.Skip(1).Select(_ => new cell { Item1 = int.Parse(_), Item2 = true }).ToArray();
                var b = ilist.OrderByDescending(_ => _.Item1).ToArray();
                int all = ilist.Sum(_ => _.Item1);
                var ilist_length = ilist.Length;
                double allall = all * 2;
                var s = allall / ilist_length;
                var ilistMax = b.FirstOrDefault();
                while (ilistMax != null && ilistMax.Item1 > s && ilist_length > 0)
                {
                    ilistMax.Item2 = false;
                    ilist_length--;
                    allall -= ilistMax.Item1;

                    s = allall / ilist_length;
                    ilistMax = b.FirstOrDefault(_ => _.Item2);
                }
                print(string.Format("Case #{0}:", T - n));
                for (int i = 0; i < ilist.Length; i++)
                {
                    if (ilist[i].Item2)
                        print(string.Format(" {0:F6}", (s - ilist[i].Item1) * 100.0 / all));
                    else
                        print(string.Format(" {0:F6}", 0.0));
                }
                Console.WriteLine();
            }
        }
    }
}
