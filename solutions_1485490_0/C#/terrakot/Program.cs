using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;

namespace GoogleJam
{
    public static class AA
    {
        public static IEnumerable<IEnumerable<T>> Chunk<T>(this IEnumerable<T> source, int chunksize)
        {
            while (source.Any())
            {
                yield return source.Take(chunksize);
                source = source.Skip(chunksize);
            }
        }

        public static Int64 Solve(int N, int M, Int64[] ni, Int64[] mi, bool merge = true)
        {
            if (ni.Length < 6)
                ni = ni.Concat(new Int64[] {0,0,0,0}).Take(6).ToArray();
            var amountsN = ni.Where((l, i) => i%2 == 0).ToArray();
            var modelsN = ni.Where((l, i) => i % 2 == 1).ToArray();
            var amountsM = mi.Where((l, i) => i % 2 == 0).ToArray();
            var modelsM = mi.Where((l, i) => i % 2 == 1).ToArray();

            Int64 res = 0;

            for (int firstSplit = 0; firstSplit <= M; firstSplit++)
                for (int secondSplit = firstSplit; secondSplit <= M; secondSplit++)
                {
                    var fistSeg = Calc(amountsM.Take(firstSplit), modelsM.Take(firstSplit), amountsN[0], modelsN[0]);
                    var secondSeg = Calc(amountsM.Skip(firstSplit).Take(secondSplit - firstSplit),
                                         modelsM.Skip(firstSplit).Take(secondSplit - firstSplit), amountsN[1],
                                         modelsN[1]);
                    var thirdSeg = Calc(amountsM.Skip(secondSplit), modelsM.Skip(secondSplit), amountsN[2], modelsN[2]);
                    res = Math.Max(res, fistSeg + secondSeg + thirdSeg);
                }

            if (!merge)
                return res;

            Int64[] mergedni = GenMerge(ni);

            if (mergedni == null)
                return res;

            return Math.Max(res, Solve(N, M, mergedni, mi, false));
        }

        private static long[] GenMerge(long[] ni)
        {
            var merges = new List<long[]>();
            if (ni[1] == ni[3] && ni[1] == ni[5])
            {
                return new long[] {ni[0] + ni[2] + ni[4], ni[1]};
            }
            if (ni[1] == ni[3])
                return new long[] { ni[0] + ni[2], ni[1], ni[4], ni[5] };
            if (ni[3] == ni[5])
                return new long[] { ni[0] , ni[1], ni[2] + ni[4], ni[5] };
            if (ni[1] == ni[5])
                return new long[] {ni[0] + ni[4], ni[1]};
            return null;
        }

        private static Int64 Calc(IEnumerable<long> amounts, IEnumerable<long> models, long amount, long model)
        {
            var ams  = amounts.ToArray();
            var ms = models.ToArray();
            Int64 sum = 0;
            for (int i = 0; i < ams.Length; i++)
            {
                if (ms[i] == model)
                    sum += ams[i];
            }
            return Math.Min(sum, amount);
        }
    }


    class Program
    {

        static void Main(string[] args)
        {

            var tr = new StreamReader(@"C:\GJ\input.in");
            using (var tw = new StreamWriter(@"C:\GJ\output.out"))
            {
                int testCount = int.Parse(tr.ReadLine());
                for (int i = 0; i < testCount; i++)
                {
                    // var ints = tr.ReadLine().Split().Select(int.Parse);
                    // var strs = tr.ReadLine().Split();
                    // CultureInfo.InvariantCulture
                    var ints = tr.ReadLine().Split().Select(int.Parse).ToArray();
                    var N = ints[0];
                    var M = ints[1];
                    var Ni = tr.ReadLine().Split().Select(Int64.Parse).ToArray();
                    var Mi = tr.ReadLine().Split().Select(Int64.Parse).ToArray();

                    tw.WriteLine(string.Format("Case #{0}: {1}", i + 1, AA.Solve(N, M, Ni, Mi)));
                }
            }
        }
    }
}
