using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    int Solve(int R, int C, int W)
    {
        return (C / W) * R + (W - 1) + (C % W == 0 ? 0 : 1);
    }

    static IEnumerable<string> Output()
    {
        var RCW = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new A().Solve(RCW[0], RCW[1], RCW[2]).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}