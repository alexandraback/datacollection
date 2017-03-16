using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    private static StreamReader reader;

    static bool Solve()
    {
        string[] ss = reader.ReadLine().Split();
        int n = int.Parse(ss[0]), m = int.Parse(ss[1]);

        int[, ] height = new int[n, m];
        foreach (int i in Enumerable.Range(0, n))
        {
            ss = reader.ReadLine().Split();
            foreach (int j in Enumerable.Range(0, m))
                height[i, j] = int.Parse(ss[j]);
        }

        List<int> imax = Enumerable.Range(0, n)
            .Select(i => Enumerable.Range(0, m).Select(j => height[i, j]).Max())
            .ToList();
        List<int> jmax = Enumerable.Range(0, m)
            .Select(j => Enumerable.Range(0, n).Select(i => height[i, j]).Max())
            .ToList();

        return (
            from i in Enumerable.Range(0, n)
            from j in Enumerable.Range(0, m)
            select height[i, j] == Math.Min(imax[i], jmax[j])
            ).All(x => x);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(0, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i + 1, Solve() ? "YES" : "NO");
    }
}
