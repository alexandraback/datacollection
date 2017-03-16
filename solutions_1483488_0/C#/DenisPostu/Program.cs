using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.C
{
    class Program
    {
        static void Main(string[] args)
        {
            var worker = new Worker();

            using(var reader = new StreamReader("d:/c.txt"))
            {
                using(var writer = new StreamWriter("d:/cout.txt"))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var pairs = reader.ReadLine().Split().Select(s => int.Parse(s)).ToList();
                        var result = worker.CountPairs(pairs[0], pairs[1]);
                        writer.WriteLine(string.Format("Case #{0}: {1}", c, result));
                        Console.WriteLine(string.Format("Case #{0}: {1}", c, result));
                    }
                }
            }
            
        }
    }

    class Worker
    {
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

        public int CountPairs(int n, int a, int b)
        {
            r = 0;
            s = n.ToString();
            d = s.Length;
            for (int i = 0; i <= d; i++)
            {
                int m = int.Parse(s.Substring(d - i, i) + s.Substring(0, d - i));
                if (a <= n && n < m && m <= b)
                {
                    pair = string.Format("{0}.{1}", n, m);
                    if(!list.Contains(pair))
                    {
                       list.Add(pair);
                       r++;
                    }
                    
                }
            }

            return r;
        }

    }
}
