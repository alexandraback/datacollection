using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Recycled
{
    class Program
    {
        internal static int[] ReadIntArray(StreamReader r)
        {
            var line = r.ReadLine();
            if (line == null)
                return null;
            var sa = line.Split(' ');
            var ia = new int[sa.Length];
            for (int i = 0; i < sa.Length; i++)
                ia[i] = int.Parse(sa[i]);
            return ia;

        }

        static int Main(string[] args)
        {
            try
            {
                using (var r = new StreamReader(args[0]))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 1; i <= t; i++)
                    {
                        var p = new Problem(r);
                        int result = p.Solve();
                        Console.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception");
                Console.WriteLine(ex);
                return -1;
            }
            return 0;
        }
    }

    internal class Problem
    {
        
        private int _a;
        private int _b;

        private const int Max = 2000000;
        //private const int Max = 2222;

        private static readonly List<int>[] Cache = InitCache();

        private static List<int>[] InitCache()
        {
            var cache = new List<int>[Max + 1];
            int i;
            for (i = 0; i <= Max; i++)
                cache[i] = null;
            for (i = 1; i <= Max; i++)
            {
                if (cache[i] != null)
                    continue;
                var all = All(i, Max);
                foreach (var k in all)
                {
                    cache[k] = all;
                }
            }
            /*
            Console.WriteLine("[Cache]");
            for (i = 1; i <= Max; i++)
            {
                if (cache[i].Count > 1)
                    Console.WriteLine("{0}: {1}", i,
                        cache[i].Aggregate("", (all, next) => all + ", " + next.ToString(), (r => r.Substring(2))));
            }
            Console.WriteLine("========");
            Console.WriteLine();
            */
            return cache;
        }

        public Problem(StreamReader r)
        {
            var ab = Program.ReadIntArray(r);
            _a = ab[0];
            _b = ab[1];
        }

        public int Solve()
        {
            var pairs = new Dictionary<string, bool>();
            for (int i = _a; i <= _b; i++)
            {
                var all = Cache[i];
                var numbers = all.Where(m => ((m >= _a) && (m <= _b))).OrderBy(m => m).ToArray();
                int l = numbers.Length;
                if (l <= 1) 
                    continue;
                for (int p = 0; p < (l - 1); p++)
                {
                    for (int q = p + 1; q < l; q++)
                    {
                        string pair = string.Format("{0},{1}", numbers[p], numbers[q]);
                        pairs[pair] = true;
                    }
                }
            }
            /*
            Console.WriteLine();
            Console.WriteLine("[{0}, {1}]", _a, _b);
            foreach (var pair in pairs)
            {
                Console.WriteLine(pair.Key);
            }            
            Console.WriteLine();
            */
            return pairs.Count;
        }

        private static List<int> All(int n, int max)
        {
            var all = new Dictionary<int, int>();
            all[n] = n;
            string s = n.ToString();
            int l = s.Length;
            int p;
            for (int i = 0; i < (l - 1); i++)
            {
                s = string.Format("{0}{1}", s.Substring(1), s[0]);
                if (s[0] != '0')
                {
                    p = int.Parse(s);
                    if ((p <= max) && !all.ContainsKey(p))
                        all[p] = p;
                }
            }
            return new List<int>(all.Keys.OrderBy(m => m));
        }
    }
}
