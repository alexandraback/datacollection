using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        class TData
        {
            public int Tn;
            public uint B;
            public ulong M;
            public bool Result = false;
            public bool[,] ResultMatrix;

            public ulong Solve(ulong cur, int v, HashSet<int> ex)
            {
                return 0;
            }
        }
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            var cases = Enumerable.Range(1, t)
                .Select(x =>
                {
                    var bm = Console.ReadLine().Split(' ').Select(ulong.Parse).ToArray();
                    return new TData {B = (uint)bm[0], M = bm[1], Tn = x};
                })
                .ToArray();
            Parallel.ForEach(cases, cs =>
            {
                ulong total = 0;
                cs.ResultMatrix = new bool[cs.B+1,cs.B+1];
                for (var i = 1; i < cs.B; ++i)
                    cs.ResultMatrix[i, cs.B] = true;
                ++total;
                if (total == cs.M)
                    goto end;
                for (var start = 1; start < cs.B; ++start)
                    for (var middle = start + 1; middle < cs.B; ++middle)
                    {
                        cs.ResultMatrix[start, middle] = true;
                        ++total;
                        if (total == cs.M)
                            goto end;
                    }
                end:
                cs.Result = cs.M == total;
            });
            foreach (var cs in cases.OrderBy(x => x.Tn))
            {
                Console.WriteLine("Case #{0}: {1}", cs.Tn, cs.Result ? "POSSIBLE" : "IMPOSSIBLE");
                if (cs.Result)
                {
                    for (var i = 1; i <= cs.B; ++i)
                    {
                        for (var j = 1; j <= cs.B; ++j) 
                            Console.Write(cs.ResultMatrix[i,j] ? "1" : "0");
                        Console.WriteLine();
                    }
                }
            }
        }
    }
}
