using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Linq;

class Problem
{
    private static StreamReader reader;

    static string Solve()
    {
        string[] ss = reader.ReadLine().Split();
        int n = int.Parse(ss[1]);

        int pow = 1 << n;
        List<List<int>> available = Enumerable.Range(0, pow).Select(x => new List<int> ()).ToList();
        available[0] = reader.ReadLine().Split().Select(x => int.Parse(x)).ToList();
        List<int> t = new List<int> ();

        foreach (int i in Enumerable.Range(0, n))
        {
            ss = reader.ReadLine().Split();
            t.Add(int.Parse(ss[0]));

            List<int> mine = ss.Skip(2).Select(x => int.Parse(x)).ToList();
            int w = 1 << i;
            foreach (int j in Enumerable.Range(0, w))
                available[j + w] = available[j].Concat(mine).ToList();
        }

        foreach (int i in Enumerable.Range(0, pow))
            foreach (int l in Enumerable.Range(0, n).Where(j => (i & (1 << j)) > 0) )
                available[i].Remove(t[l]);


        List<List<int>> edges = Enumerable.Range(0, pow).Select(x => new List<int> ()).ToList();
        List<List<int>> backEdges = Enumerable.Range(0, pow).Select(x => new List<int> ()).ToList();
        bool[] seen = new bool[pow];
        foreach (int i in Enumerable.Range(0, pow)) seen[i] = false;
        seen[0] = true;

        LinkedList<int> q = new LinkedList<int>();
        for (q.AddFirst(0); q.Count > 0; q.RemoveFirst())
        {
            int u = q.First();
            foreach (int j in Enumerable.Range(0, n)
                     .Where(x => (u & (1 << x)) == 0 && available[u].Any(y => y == t[x])))
            {
                int nu = u + (1 << j);
                if ((u & (1 << j)) > 0)
                    Console.WriteLine("This is Weird");
                backEdges[nu].Add(u);
                edges[u].Add(j);
                if (!seen[nu])
                {
                    seen[nu] = true;
                    q.AddLast(nu);
                }
            }
        }

        if (!seen[pow - 1]) return "IMPOSSIBLE";

        bool[] seen2 = new bool[pow];
        foreach (int i in Enumerable.Range(0, pow)) seen2[i] = false;
        seen2[pow - 1] = true;
        for (int i = pow - 1; i >= 0; i--) if (seen2[i])
            foreach (int j in backEdges[i])
                seen2[j] = true;

        List<int> res = new List<int>();
        int v = 0;
        foreach (int kk in Enumerable.Range(0, n))
        {
            int best = edges[v].Where(x => seen2[(1 << x) | v] && (v & (1 << x)) == 0).Min();
            res.Add(best + 1);
            v |= 1 << best;
        }

        return string.Join(" ", res);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        reader = new StreamReader(bs);

        foreach (int i in Enumerable.Range(0, int.Parse(reader.ReadLine())))
            Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
    }
}
