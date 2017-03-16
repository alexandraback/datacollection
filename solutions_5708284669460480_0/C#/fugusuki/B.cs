using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    double Solve(int S, string keyboard, string target)
    {
        int ret = 0;
        int max = 0;
        int[] current = new int[S];
        while(current[0] < keyboard.Length)
        {
            int c = Enumerable.Range(0, S - target.Length + 1).Count(i=>current.Skip(i).Take(target.Length).Zip(target, (j, t) => keyboard[j] == t).All(b => b));
            max = Math.Max(max, c);
            ret += c;
            for (int i = current.Length - 1; i >= 0; i--)
            {
                if (i==0 || current[i] < keyboard.Length - 1) { current[i]++; break; }
                else current[i] = 0;
            }
        }
        return max - (double)ret/Math.Pow(keyboard.Length, S);
    }

    static IEnumerable<string> Output()
    {
        var KLS =  Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        yield return new B().Solve(KLS[2], Console.ReadLine(), Console.ReadLine()).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}