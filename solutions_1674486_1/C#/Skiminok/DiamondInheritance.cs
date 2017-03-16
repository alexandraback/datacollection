//#define SMALL
#define LARGE

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace CodeJam2012 {
    internal class DiamondInheritance
    {
        private const string ProblemLetter = "A";
#if SMALL
        private const string ProblemType = "small";
#elif LARGE
        private const string ProblemType = "large";
#endif

        private static void Main(string[] args) {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (var reader = new StreamReader(string.Format("{0}-{1}.in", ProblemLetter, ProblemType)))
            using (var writer = new StreamWriter(string.Format("{0}-{1}.out", ProblemLetter, ProblemType)))
                new DiamondInheritance { reader = reader, writer = writer }.Run();
        }

        private TextReader reader;
        private TextWriter writer;
        private int test;

        private List<int> topSort = new List<int>();

        private void Run() {
            int testNumber = ReadInt();
            for (test = 1; test <= testNumber; test++) {
                var graph = ReadInput();
                int n = graph.Length;
                bool[] was = new bool[n];
                topSort = new List<int>();
                for (int i = 0; i < n; i++) {
                    if (!was[i]) {
                        was[i] = true;
                        topSortDFS(graph, was, i);
                    }
                }
                topSort.Reverse();

                bool isDiamond = false;
                was = new bool[n];
                for (int i = 0; i < n; i++) {
                    int v = topSort[i];
                    if (!was[v]) {
                        bool[] tree = new bool[n];
                        tree[v] = true;
                        isDiamond |= dfs(graph, tree, v);
                        for (int j = 0; j < n; j++) {
                            if (tree[j])
                                was[j] = true;
                        }
                    }
                    if (isDiamond) break;
                }

                string answer = isDiamond ? "Yes" : "No";
                WriteAnswer(answer);
            }
        }

        private bool dfs(List<int>[] graph, bool[] was, int v) {
            for (int i = 0; i < graph[v].Count; i++) {
                int to = graph[v][i];
                if (!was[to]) {
                    was[to] = true;
                    if (dfs(graph, was, to))
                        return true;
                }
                else return true;
            }
            return false;
        }

        private void topSortDFS(List<int>[] a, bool[] was, int v) {
            for (int i = 0; i < a[v].Count; i++) {
                int to = a[v][i];
                if (!was[to]) {
                    was[to] = true;
                    topSortDFS(a, was, to);
                }
            }
            topSort.Add(v);
        }

        private void WriteAnswer(string answer) {
            writer.WriteLine("Case #{0}: {1}", test, answer);
        }

        private List<int>[] ReadInput() {
            int n = ReadInt();
            var ans = new List<int>[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new List<int>();
            }
            for (int i = 0; i < n; i++) {
                var parents = ReadInts().Skip(1);
                foreach (var parent in parents) {
                    ans[parent - 1].Add(i);
                }
            }
            return ans;
        }

        private int ReadInt() {
            return int.Parse(reader.ReadLine());
        }

        private int[] ReadInts() {
            return
                reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse).ToArray();
        }

        private string[] ReadStringsLine() {
            return reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
