using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    int Solve(long[][] DHM)
    {
        var DM = DHM.SelectMany(dhm=>Enumerable.Range(0, (int)dhm[1]).Select(i=>new long[]{dhm[0], dhm[2] + i})).ToArray();
        var times = DM.Select(dm => Enumerable.Range(1, DM.Length).Select(i => (360 * i - dm[0]) * dm[1]).ToArray()).ToArray();
        return Math.Min(DM.Length - 1, times.Max(time1 => times.Sum(time2 => time1 == time2 ? 0 : time2.Skip(1).Count(t => t <= time1[0]))));
    }

    static IEnumerable<string> Output()
    {
        var N = int.Parse(Console.ReadLine());
        yield return new C().Solve(Enumerable.Range(0, N).Select(r => Console.ReadLine().Split(' ').Select(long.Parse).ToArray()).ToArray()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}