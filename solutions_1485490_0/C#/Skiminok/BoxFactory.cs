#define SMALL
//#define LARGE

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
    internal class BoxFactory
    {
        private const string ProblemLetter = "C";
#if SMALL
        private const string ProblemType = "small";
#elif LARGE
        private const string ProblemType = "large";
#endif

        private static void Main(string[] args) {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (var reader = new StreamReader(string.Format("{0}-{1}.in", ProblemLetter, ProblemType)))
            using (var writer = new StreamWriter(string.Format("{0}-{1}.out", ProblemLetter, ProblemType))) 
            checked {
                new BoxFactory { reader = reader, writer = writer }.Run();
            }
        }

        private TextReader reader;
        private TextWriter writer;
        private int test;

        class Data {
            public Tuple<long, int>[] First;
            public Tuple<long, int>[] Second;
            public Data(Tuple<long, int>[] first, Tuple<long, int>[] second) {
                First = first;
                Second = second;
            }
        }

        private void Run() {
            int testNumber = ReadInt();
            for (test = 1; test <= testNumber; test++) {
                var data = ReadInput();

                if (data.First.Length == 1) {
                    long ans = GetSingleCase(data);
                    WriteAnswer(ans);
                    continue;
                }

                if (data.First.Length == 2) {
                    long ans;
                    if (data.First[0].Item2 == data.First[1].Item2) {
                        data.First[0] = Tuple.Create(data.First[0].Item1 + data.First[1].Item1, data.First[0].Item2);
                        ans = GetSingleCase(data);
                        WriteAnswer(ans);
                        continue;
                    }
                    ans = GetDoubleCase(data);
                    WriteAnswer(ans);
                    continue;
                }

                if (data.First[0].Item2 == data.First[1].Item2 && data.First[1].Item2 == data.First[2].Item2) {
                    data.First[0] = Tuple.Create(data.First[0].Item1 + data.First[1].Item1 + data.First[2].Item1,
                                                 data.First[0].Item2);
                    long ans = GetSingleCase(data);
                    WriteAnswer(ans);
                    continue;
                }

                if (data.First[0].Item2 == data.First[1].Item2) {
                    data.First[0] = Tuple.Create(data.First[0].Item1 + data.First[1].Item1, data.First[0].Item2);
                    data.First[1] = data.First[2];
                    long ans = GetDoubleCase(data);
                    WriteAnswer(ans);
                    continue;
                }

                if (data.First[1].Item2 == data.First[2].Item2) {
                    data.First[1] = Tuple.Create(data.First[2].Item1 + data.First[1].Item1, data.First[1].Item2);
                    long ans = GetDoubleCase(data);
                    WriteAnswer(ans);
                    continue;
                }

                long best = 0;
                for (int i = 0; i < data.Second.Length; i++) {
                    long firstCount = i == 0
                                          ? 0
                                          : Math.Min(data.First[0].Item1,
                                                     data.Second.Take(i).Where(t => t.Item2 == data.First[0].Item2)
                                                         .Select(t => t.Item1).Sum());
                    long bestSuffix = Math.Min(data.First[1].Item1,
                                               data.Second.Skip(i).Where(t => t.Item2 == data.First[1].Item2)
                                                   .Select(t => t.Item1).Sum());
                    for (int j = i; j < data.Second.Length; j++) {
                        long secondCount = j == i
                                               ? 0
                                               : Math.Min(data.First[1].Item1,
                                                          data.Second.Take(j).Skip(i).Where(
                                                              t => t.Item2 == data.First[1].Item2)
                                                              .Select(t => t.Item1).Sum());
                        long thirdCount = Math.Min(data.First[2].Item1,
                                                   data.Second.Skip(j).Where(
                                                       t => t.Item2 == data.First[2].Item2)
                                                       .Select(t => t.Item1).Sum());
                        bestSuffix = Math.Max(bestSuffix, secondCount + thirdCount);
                    }
                    best = Math.Max(best, firstCount + bestSuffix);
                }

                if (data.First[0].Item2 == data.First[2].Item2) {
                    long split = Math.Min(data.First[0].Item1 + data.First[2].Item1,
                                          data.Second.Where(t => t.Item2 == data.First[0].Item2).Select(t => t.Item1).
                                              Sum());
                    best = Math.Max(best, split);
                    /*for (int i = 0; i < data.Second.Length; ++i) {
                        if (data.Second[i].Item2 != data.First[0].Item2) continue;
                        long before = i == 0
                                          ? 0
                                          : Math.Min(data.First[0].Item1,
                                                     data.Second.Take(i).Where(t => t.Item2 == data.First[0].Item2)
                                                         .Select(t => t.Item1).Sum());
                        long after = i == data.Second.Length - 1
                                         ? 0
                                         : Math.Min(data.First[2].Item1,
                                                    data.Second.Skip(i + 1).Where(
                                                        t => t.Item2 == data.First[2].Item2)
                                                        .Select(t => t.Item1).Sum());
                        long restFirst = Math.Max(0, data.First[0].Item1 - before);
                        long restSecond = Math.Max(0, data.First[2].Item1 - after);
                        long middle = Math.Min(restFirst + restSecond, data.Second[i].Item1);
                        best = Math.Max(best, before + middle + after);
                    }*/
                }

                if (best == 0) {
                    if (data.Second.Any(t => data.First.Select(f => f.Item2).Contains(t.Item2)))
                        Console.WriteLine("ALARM: {0}", test);
                }
                if (best > data.First.Select(t => t.Item1).Sum())
                    Console.WriteLine("ALARM: {0}", test);
                if (best > data.Second.Select(t => t.Item1).Sum())
                    Console.WriteLine("ALARM: {0}", test);
                WriteAnswer(best);
            }
        }

        private long GetDoubleCase(Data data) {
            int firstType = data.First[0].Item2, secondType = data.First[1].Item2;
            long best = Math.Min(data.First[0].Item1,
                                 data.Second.Where(t => t.Item2 == firstType).Select(t => t.Item1).Sum());
            for (int i = 0; i < data.Second.Length; i++) {
                long before = i == 0
                                  ? 0
                                  : Math.Min(data.First[0].Item1,
                                             data.Second.Take(i).Where(t => t.Item2 == firstType)
                                                 .Select(t => t.Item1).Sum());
                long after = Math.Min(data.First[1].Item1,
                                      data.Second.Skip(i).Where(t => t.Item2 == secondType)
                                          .Select(t => t.Item1).Sum());
                best = Math.Max(best, before + after);
            }
            return best;
        }

        private long GetSingleCase(Data data) {
            return Math.Min(data.First[0].Item1,
                            data.Second.Where(t => t.Item2 == data.First[0].Item2)
                                .Select(t => t.Item1).Sum());
        }

        private void WriteAnswer(long answer) {
            writer.WriteLine("Case #{0}: {1}", test, answer);
        }

        private Data ReadInput() {
            var line = ReadInts();
            int n = line[0], m = line[1];
            var a = ReadLongs();
            var b = ReadLongs();
            var first = new Tuple<long, int>[n];
            var second = new Tuple<long, int>[m];
            for (int i = 0; i < n; i++) {
                first[i] = Tuple.Create(a[2 * i], (int) a[2 * i + 1]);
            }
            for (int i = 0; i < m; i++) {
                second[i] = Tuple.Create(b[2 * i], (int) b[2 * i + 1]);
            }
            return new Data(first, second);
        }

        private int ReadInt() {
            return int.Parse(reader.ReadLine());
        }

        private int[] ReadInts() {
            return
                reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse).ToArray();
        }

        private long[] ReadLongs() {
            return
                reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(long.Parse).ToArray();
        }

        private string[] ReadStringsLine() {
            return reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
