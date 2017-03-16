using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;

namespace ConsoleApplication1
{
    public static class _
    {
        public static T[] Times<T>(this int count, Func<T> f) { return Enumerable.Repeat(0, count).Select(x => f()).ToArray(); }
    }

    public class Program
    {
        Queue<Queue<string>> chunks = new Queue<Queue<string>>();
        void ReadChunks(TextReader tr) { string l; while ((l = tr.ReadLine()) != null) chunks.Enqueue(new Queue<string>(l.Split(' '))); }
        string rc() { var q = chunks.Peek(); if (q.Count == 1) chunks.Dequeue(); return q.Dequeue(); }
        int ri() { return int.Parse(rc()); }
        double rd() { return double.Parse(rc(), CultureInfo.InvariantCulture); }
        string rl() { return string.Join(" ", chunks.Dequeue()); }
        void swap<T>(ref T a, ref T b) { var x = a; a = b; b = x; }

        public static void Main() { new Program().Solve(); }
        void Solve()
        {
            using (var sr = new StreamReader("B-small-attempt0.in"))
            using (var sw = new StreamWriter("out.txt"))
            {
                ReadChunks(sr);

                var tCase = ri();

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    int A = ri(), B = ri(), K = ri();

                    long sum = 0;
                    for (int i = 0; i < A; ++i)
                        for (int j = 0; j < B; ++j)
                            if ((i & j) < K)
                                ++sum;


                    sw.WriteLine("Case #{0}: {1}", tiCase, sum);
                }
            }
        }
    }
}