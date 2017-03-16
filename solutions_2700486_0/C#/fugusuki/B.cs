using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    public double Solve(int N, int X, int Y)
    {
        X = Math.Abs(X);
        if (N < 6)
        {
            if (X + Y == 0) return 1;
            if (X + Y != 2 || Y == 2) return 0;
            if (X == 2 && Y == 0) return N == 1 ? 0 : N == 2 ? 0.5 : N == 3 ? 0.75 : 1;
            if (X == 1 && Y == 1) return N <= 2 ? 0 : N == 3 ? 0.25 : N == 4 ? 0.5 : 1;
            return 0;
        }
        else if (N < 15)
        {
            if (X + Y <= 2) return 1;
            if (X + Y != 4 || Y == 4) return 0;
            if (N - Y >= 11) return 1;
            return 1 - (double)(1 << (Y + 1)) / (1 << (N - 6));
        }
        else
        {
            if (X + Y <= 4) return 1;
            if (X + Y != 6 || Y == 6) return 0;
            return 1 - (double)(1 << (Y + 1)) / (1 << (N - 15));
        }
    }

    static double Combination(long n, long r)
    {
        if (n - r < r) r = n - r;
        long ret = 1;
        for (long i = 1; i <= r; i++) ret = ret * (n - i + 1) / i;
        return ret;
    }

    static IEnumerable<string> Output()
    {
        var args = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new B().Solve(args[0], args[1], args[2]).ToString();
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray()));
}
}