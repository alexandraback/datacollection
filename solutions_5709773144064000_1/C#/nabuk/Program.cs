using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public class Program
    {
        private static Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        private static void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        private static string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        private static int ri() { return int.Parse(rc()); }
        private static double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        private static string rl() { return string.Join(" ", chunks.Dequeue()); }
        private static void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main()
        {
            using (var sr = new StreamReader("B-large.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var t = ri();

                for (var ti = 1; ti <= t; ++ti)
                {
                    double C = rd(), F = rd(), X = rd();

                    double from = 0.0;
                    double rate = 2.0;
                    double best = X / rate;

                    while (true)
                    {
                        from = from + C / rate;
                        rate += F;
                        var temp = from + X / rate;
                        if (temp > best)
                            break;

                        best = temp;
                    }

                    sw.WriteLine("Case #{0}: {1}", ti, best.ToString("0.0000000", CultureInfo.InvariantCulture));
                }

            }
        }
    }
}