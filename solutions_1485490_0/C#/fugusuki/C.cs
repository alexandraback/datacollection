using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    public long Solve(Tuple<long,long>[] A, Tuple<long,long>[] B)
    {
        var bbb = B.Where(b=>A.Any(a=>a.Item2==b.Item2)).ToArray();
        var bb = new List<Tuple<long, long>>();
        for (int i = 0; i < bbb.Length-1; i++)
        {
            if (i == 0) bb.Add(bbb[0]);
            if (bbb[i].Item2 == bbb[i + 1].Item2) bb[bb.Count - 1] = Tuple.Create(bb[bb.Count - 1].Item1 + bbb[i + 1].Item1, bbb[i + 1].Item2);
            else bb.Add(bbb[i + 1]);
        }
        int[] s1=null, s2=null;
        if(A.Length==1) return Math.Max(A[0].Item1,bb.Where(x=>x.Item2==A[0].Item2).Sum(x=>x.Item1));
        s1 = bb.Select((t, i) => new { t = t, i = i }).Where(x => x.t.Item2 == A[0].Item2).Select(x => x.i).ToArray();
        if(bb.Count>2) s2 = bb.Select((t, i) => new { t = t, i = i }).Where(x => x.t.Item2 == A[1].Item2).Select(x => x.i).ToArray();

        long max=0;
        for (int i = 0; i < s1.Length; i++)
        {
            long temp = 0;
            if(s2==null) {
                for (int k = 0; k < bb.Count; k++)
			{
                    if(bb[k].Item2==(k<=s1[i]?A[0]:A[1]).Item2) temp+= bb[k].Item1;
			}
            }
            else
            for (int j = 0; j < s2.Length; j++)
            {
                if (s2[j] < s1[i]) continue;
                for (int k = 0; k < bb.Count; k++)
                {
                    if (bb[k].Item2 == (k <= s1[i] ? A[0] : k <= s2[j] ? A[1] : A[2]).Item2) temp += bb[k].Item1;
                }
            }
            max = Math.Max(max, temp);
        }
        return max;
    }


    static IEnumerable<string> Output() {
        Console.ReadLine();
        yield return new C().Solve(Read().ToArray(),Read().ToArray()).ToString(); 
    }
    static IEnumerable<Tuple<long, long>> Read()
    {
        var s = Console.ReadLine().Split(' ').Select(ss=>Convert.ToInt64(ss)).ToArray();
        for (int i = 0; i < s.Length; i+=2)
            yield return Tuple.Create(s[i], s[i + 1]);
    }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}

