using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    int Solve(int C, int V, List<int> denominations)
    {
        var pre = denominations.Count;
        if (V == 1) return 0;
        if (!denominations.Contains(1)) denominations.Add(1);
        if (!denominations.Contains(2)) denominations.Add(2);

        var ok = new bool[V + 1];
        ok[0] = true;
        foreach (var d in denominations)
        {
            for (int i = V; i >= 0; i--) if (ok[i] && i + d <= V) ok[i + d] = true;
        }

        while (ok.Any(o => !o))
        {
            for (int d = 0; d < ok.Length; d++)
            {
                if (ok[d]) continue;
                else
                {
                    denominations.Add(d);
                    var maxd = d;
                    for (int i = V; i >= 0; i--) if (ok[i] && i + maxd <= V) ok[i + maxd] = true;
                }
                break;
            }

            //int maxd = -1;
            //int maxv = -1;
            //foreach(int d in Enumerable.Range(1, V).Except(denominations))
            //{
            //    var v = Enumerable.Range(0, V - d + 1).Count(i => ok[i] && !ok[i + d]);
            //    if (v > maxv)
            //    {
            //        maxd = d;
            //        maxv = v;
            //    }
            //}
            //denominations.Add(maxd);
            //for (int i = V; i >= 0; i--) if (ok[i] && i + maxd <= V) ok[i + maxd] = true;
        }
        return denominations.Count - pre;
    }

    static IEnumerable<string> Output()
    {
        var CDV = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new C().Solve(CDV[0], CDV[2], Console.ReadLine().Split(' ').Select(int.Parse).ToList()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}