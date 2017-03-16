using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static List<int[]> pairs = new List<int[]> { new[] { 0, 1 }, new[] { 0, 2 }, new[] { 1, 2 } };

    static int CountDup(List<int[]> xs) {
        int cnt = 0;
        foreach (var p in pairs) {
            var d = new int[3, 3];

            for (int i = 0; i < xs.Count; i++) {
                int a = xs[i][p[0]];
                int b = xs[i][p[1]];

                d[a, b]++;
                cnt = Math.Max(cnt, d[a, b]);
            }
        }
        return cnt;
    }

    static void Calc(int J, int P, int S, int K) {
        var xs = new List<int[]>();

        for (int i = 0; i < J; i++) {
            for (int j = i; j < P; j++) {
                for (int k = j; k < S; k++) {
                    xs.Add(new[] { i, j, k });
                }
            }
        }

//        Console.WriteLine("cnt = " + xs.Count);

        int bestLen = 0;
        List<int[]> best = null;

        for (int i = 0; i < (1 << xs.Count); i++) {

            var ls = new List<int[]>();
            for (int j = 0; j < xs.Count; j++) {
                if ((i & (1 << j)) != 0) {
                    ls.Add(xs[j]);
                }
            }

            int cnt = CountDup(ls);
            if (cnt <= K) {
                if (bestLen < ls.Count) {
                    bestLen = ls.Count;
                    best = ls;
                }
            }
        }

        Console.WriteLine(bestLen);
        foreach (int[] a in best) {
            Console.WriteLine(string.Join(" ", a.Select(e => e + 1)));
        }
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            var xs = ReadInts();
            Console.Write("Case #{0}: ", i+1);
            Calc(xs[0], xs[1], xs[2], xs[3]);
        }
    }
}
