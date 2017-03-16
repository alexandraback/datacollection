using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    long Solve(int N)
    {
        var x = N % 10 == 0 ? 1 : 0;
        if(x==1) N--;
        if (N < 20) return N + x;
        if (N < 100) return 11 + Math.Min(N-11, N%10 - 1 + N / 10 - 1 + 1) + x;
        if (N < 1000) return 30 + Math.Min(N - 101, (N % 100) - 1 + N / 10 - 1 + 1) + x;
        if (N < 10000) return 139 + Math.Min(N-1001, (N % 100) - 1 + N / 100 - 1 + 1) + x;
        if (N < 100000) return 1148 + Math.Min(N - 10001, (N % 1000) - 1 + N / 100 - 1 + 1) + x;
        return 11157 + Math.Min(N - 100001, (N % 1000) - 1 + N / 1000 - 1 + 1) + x;
    }

    static IEnumerable<string> Output()
    {
        yield return new A().Solve(int.Parse(Console.ReadLine())).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}