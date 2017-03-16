using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static int CalcPathCount_1(int node, int goal, int n, bool[,] g, int[] memo) {
        if (node == goal) return 1;

        if (memo[node] != -1) return memo[node];

        int cnt = 0;
        for (int i = node+1; i < n; i++) {
            if (g[node, i]) {
                cnt += CalcPathCount_1(i, goal, n, g, memo);
            }
        }

        return memo[node] = cnt;
    }

    static int CalcPathCount(int n, bool[,] g) {
        int start = 0;
        var memo = new int[n];
        for (int i = 0; i < memo.Length; i++)
            memo[i] = -1;
        return CalcPathCount_1(start, n-1, n, g, memo);
    }

    static void Calc(int B, int M) {
        var xs = new List<Tuple<int, int>>(); // <from, to>
        for (int i = 0; i < B; i++) {
            for (int j = i+1; j < B; j++) {
                xs.Add(Tuple.Create(i, j));
            }
        }

        for (int i = 0; i < (1 << xs.Count); i++) {
            var g = new bool[B, B];

            for (int j = 0; j < xs.Count; j++) {
                if ((i & (1 << j)) != 0) {
                    var t = xs[j];
                    g[t.Item1, t.Item2] = true;
                }
            }

            int n = CalcPathCount(B, g);
            if (n == M) {
                Console.WriteLine("POSSIBLE");
                for (int j = 0; j < B; j++) {
                    for (int k = 0; k < B; k++) {
                        Console.Write("{0}", g[j, k] ? 1 : 0);
                    }
                    Console.WriteLine();
                }
                return;
            }
        }


        Console.WriteLine("IMPOSSIBLE");
    }

    static void Main() {
        int t = ReadInt();
        for (int i = 0; i < t; i++) {
            var xs = ReadInts();
            int B = xs[0], M = xs[1];
            Console.Write("Case #{0}: ", i+1);
            Calc(B, M);
        }
    }
}
