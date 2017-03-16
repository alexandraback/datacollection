using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.C
{
    class Program
    {
        static int UpperBound = 2000000;

        static void Main(string[] args)
        {
            var worker = new Worker();

            worker.Precompute(1, UpperBound);
            Console.WriteLine("Precomputation completed..");

            using(var reader = new StreamReader("d:/C-large.in"))
            {
                using(var writer = new StreamWriter("d:/cout.txt"))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var pairs = reader.ReadLine().Split().Select(s => int.Parse(s)).ToList();
                        //var result = worker.CountPairs(pairs[0], pairs[1]);
                        var result2 = worker.CountPrecomputedPairs(pairs[0], pairs[1]);
                        writer.WriteLine(string.Format("Case #{0}: {1}", c, result2));
                        Console.WriteLine(string.Format("Case #{0}/{2}: {1}", c, /*result,*/ result2, cases));
                    }
                }
            }

            Console.ReadKey();
        }
    }

    class Worker
    {
        Dictionary<int, List<int>> memo = new Dictionary<int, List<int>>();
        HashSet<string> list = new HashSet<string>();
        int k, d, r, pairs;
        string s, pair;

        public int CountPairs(int a, int b)
        {
            list.Clear();
            pairs = 0;
            for (int i = a; i <= b; i++)
            {
                pairs += CountPairs(i, a, b);
            }
            return pairs;
        }

        public int CountPrecomputedPairs(int a, int b)
        {
            var r = 0;
            for (var n = a; n <= b; n++)
            {
                r += memo[n].Count(m => IsValidPair(a, b, n, m));
            }
            return r;
        }

        public IEnumerable<int> GetPairs(int n, int a, int b)
        {
            s = n.ToString();
            d = s.Length;
            for (int i = 0; i <= d; i++)
            {
                int m = int.Parse(s.Substring(d - i, i) + s.Substring(0, d - i));
                if (IsValidPair(a, b, n, m))
                {
                    yield return m;
                }
            }
        }

        private bool IsValidPair(int a, int b, int n, int m)
        {
            return a <= n && n < m && m <= b;
        }

        public int CountPairs(int n, int a, int b)
        {
            var r = 0;
            var pairs = GetPairs(n, a, b);

            pairs.ToList().ForEach(p =>
            {
                var pair = string.Format("{0}.{1}", n, p);
                if (!list.Contains(pair))
                {
                    list.Add(pair);
                    r++;
                }
                else
                {

                }
            });

            return r;
        }

        public void Precompute(int a, int b)
        {
            for (int i = a; i <= b; i++)
            {
                memo[i] = GetPairs(i, a, b).Distinct().ToList();    
            }
        }
    }
}
