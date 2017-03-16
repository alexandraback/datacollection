using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class FashionPolice : AbstractSolver
    {
        private int J, P, S, K;

        protected override object Solve(System.IO.StreamReader input)
        {
            J = NextInt();
            P = NextInt();
            S = NextInt();
            K = NextInt();
            var all = GenerateAllPossibleOutfits().ToArray();



            var JP = new int[J + 1, P + 1];
            var JS = new int[J + 1, S + 1];
            var PS = new int[P + 1, S + 1];

            List<int[]> bestResult = new List<int[]>();



            for (int i = 0; i < 10000; i++)
            {
                var result = new List<int[]>();
                randomize(all, i);
                foreach (var arr in all)
                {
                    var triple = arr;
                    int j = triple[0];
                    int p = triple[1];
                    int s = triple[2];

                    if (JP[j, p] >= K || JS[j, s] >= K || PS[p, s] >= K)
                    {
                        //nothing - exceeded
                    }
                    else
                    {
                        JP[j, p]++;
                        JS[j, s]++;
                        PS[p, s]++;
                        result.Add(arr);
                    }
                }
                if (result.Count > bestResult.Count)
                {
                    bestResult = result;
                }
            }

            return bestResult.Count + "\n" + string.Join("\n", bestResult.Select(x => string.Join(" ", x)));
        }

        private void randomize<T>(T[] arr, int seed)
        {
            var r = new Random(seed);
            for (int i = 0; i < arr.Length; i++)
            {
                int k = i + r.Next(arr.Length - i);
                var tmp = arr[i];
                arr[i] = arr[k];
                arr[k] = tmp;
            }

        }


        private List<int[]> GenerateAllPossibleOutfits()
        {
            var result = new List<int[]>();
            for (int s = 1; s <= S; s++)
                for (int p = 1; p <= P; p++)
                    for (int j = 1; j <= J; j++)
                    {
                        result.Add(new[] { j, p, s });
                    }
            return result;
        }

    }
}
