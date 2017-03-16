using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    public double[] Solve(int[] J)
    {
        double avg = 2d * J.Sum() / J.Count();
        var JJ = J.Where(j => j < avg);
        return J.Select(j => j >= avg ? 0 : Math.Max(0, 1d *(J.Sum()+JJ.Sum()) / JJ.Count() - j)/J.Sum() * 100).ToArray();
    }

    static IEnumerable<string> Output()
    {
        var inputs = Console.ReadLine().Split().Select(s => Convert.ToInt32(s)).ToArray();
        yield return new A().Solve(inputs.Skip(1).ToArray()).Aggregate("", (a, d) => a + d.ToString() + " ");
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}