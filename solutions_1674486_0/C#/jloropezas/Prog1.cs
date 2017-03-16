using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1
{
    public class Q1
    {
        public List<int>[] path;
        List<int> hit;
        int N;

        public Q1(int N)
        {
            this.N = N;
            path = new List<int>[N];
            hit = new List<int>();
        }

        void find(int i, int hash)
        {
            int h = hash ^ i ;
            if (i == N)
            {
                if (!hit.Contains(h)) hit.Add(h);
                return;
            }
            foreach (var c in path[i-1])
            {
                find(c, h);
                if (hit.Count >= 2) return;
            }
        }

        public string Answer()
        {
            find(1, 0);
            if (hit.Count >= 2) return "Yes";
            return "No";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int N = int.Parse(Console.ReadLine()) ;
                var q = new Q1(N);
                for (int n = 0; n < N; n++)
                {
                    q.path[n] = (from x in Console.ReadLine().Split(' ') select int.Parse(x) ).ToList();
                    q.path[n].RemoveAt(0);
                }
                Console.WriteLine(string.Format("Case #{0}: {1}", t + 1, q.Answer()));
            }
        }
    }
}
