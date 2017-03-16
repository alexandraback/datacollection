using System;
using System.Collections.Generic;
using System.Linq;

class A
{

    Dictionary<int, bool[]> dic;

    public bool Solve(int[][] input)
    {
        dic = new Dictionary<int, bool[]>();
        for (int i = 0; i < input.Length; i++)
        {
            if(Solve(i, i, input)) return true;
        }
        return false;
    }
    public bool Solve(int root, int i, int[][] input)
    {
        if (root == i)
        {
            if (!dic.ContainsKey(root)) dic[root] = new bool[input.Length + 1];
        }

        if (input[i].Length == 0) return false;
        foreach (int ii in input[i])
        {
            if (dic[root][ii-1]) return true;
            dic[root][ii-1] = true;
            if (Solve(root, ii-1, input)) return true;
        }

        return false;
    }

    static IEnumerable<string> Output() { yield return new A().Solve(Read().Take(Convert.ToInt32(Console.ReadLine())).ToArray()) ? "Yes" : "No"; }
    static IEnumerable<int[]> Read() { while(true) yield return Console.ReadLine().Split(' ').Skip(1).Select(s => Convert.ToInt32(s)).ToArray(); }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}

