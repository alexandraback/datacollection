using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;

class Program
{
    private static StreamReader _reader;
    private static StreamWriter _writer;

    static Program()
    {
        _reader = new StreamReader(@"C:\CodeJam.Round1A\data\input.txt");
        _writer = new StreamWriter(@"C:\CodeJam.Round1A\data\output.txt", false);
        _writer.AutoFlush = true;
    }

    public static void Main()
    {
        var testCount = int.Parse(_reader.ReadLine());
        for (int testN = 1; testN <= testCount; testN++)
        {
            var pars = _reader.ReadLine().Split().Select(p => Convert.ToInt32(p)).ToArray();

            var c = pars[0];
            var d = pars[1];
            var v = pars[2];

            var denoms = _reader.ReadLine().Split().Select(p => Convert.ToInt32(p)).ToArray();

            var missingSums = GetMissingSums(denoms, v);
            if (missingSums.Any())
            {
                var subsOfMissing = SubSetsOf(missingSums, 0).OrderBy(s => s.Count()).ToArray();
                foreach (var subOfMissing in subsOfMissing)
                {
                    var finalDenoms = denoms.Union(subOfMissing).ToArray();
                    var stillMissing = GetMissingSums(finalDenoms, v);
                    if (!stillMissing.Any())
                    {
                        _writer.WriteLine("Case #{0}: {1}", testN, subOfMissing.Count());
                        break;
                    }
                }
            }
            else
            {
                _writer.WriteLine("Case #{0}: {1}", testN, 0);
            }
        }
    }

    private static int[] GetMissingSums(int[] denoms, int v)
    {
        var res = SubSetsOf(denoms, 0).Where(x => x.Any()).Select(x => x.ToArray()).ToArray();

        var sums = res.Select(x => x.Sum()).Distinct().ToArray();

        var missingSums = Enumerable.Range(1, v).Except(sums).ToArray();
        return missingSums;
    }

    public static IEnumerable<IEnumerable<T>> SubSetsOf<T>(IEnumerable<T> source, int level)
    {
        if (!source.Any() || level > 10)
            return Enumerable.Repeat(Enumerable.Empty<T>(), 1);

        var first = source.Take(1);

        var inner = SubSetsOf(source.Skip(1), level + 1);
        var all = inner.Select(first.Concat);

        return all.Concat(inner);
    }
}