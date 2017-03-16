using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    public int Solve(int A, int[] motes)
    {
        if (A == 1) return motes.Length;
        Array.Sort(motes);
        return Enumerable.Range(0, motes.Length + 1).Min(i =>
        {
            int a = A;
            int c = 0;
            foreach (int m in motes.Take(motes.Length - i))
            {
                while (a <= m) { a += a - 1; c++; }
                a += m;
            }
            return i + c;
        });
    }

    static IEnumerable<string> Output()
    {
        var args = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new A().Solve(args[0], Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToString();
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray()));
}
}