using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace A
{
    class Program
    {
        
        static Random rand = new Random();
        static int[] root;

        static int GetRoot(int a)
        {
            int p = a;
            while (root[p] != p)
                p = root[p];

            root[a] = p;
            return p;
        }

        static void Connect(int a, int b)
        {
            int ra = GetRoot(a);
            int rb = GetRoot(b);

            if (ra == rb)
                return;

            if (rand.Next() % 2 == 0)
                root[ra] = rb;
            else
                root[rb] = ra;
        }

        static bool Solve(List<int>[] m)
        {
            int N = m.Length;
            root = new int[N];
            for (int i = 0; i < N; i++)
                root[i] = i;

            for (int i = 0; i < N; i++)
            {
                foreach (var x in m[i])
                    Connect(i, x);
            }

            for (int i = 0; i < N; i++)
                GetRoot(i);

            foreach (var r in root.Distinct())
            {
                int vc = 0;
                int ec = 0;
                // for every root count num of vertices and edges
                for (int i = 0; i < N; i++)
                {
                    if (root[i] != r)
                        continue;
                    vc++;
                    ec += m[i].Count;                    
                }

                if (ec >= vc)
                    return true;
            }

            return false;
        }

        static bool Solve2(List<int>[] m)
        {
            int N = m.Length;

            for (int i = 0; i < N; i++)
                m[i].Sort();

            bool[,] a = new bool[N, N];
            for(int i = 0; i < N; i++)
                foreach (var x in m[i])
                {
                    a[i, x] = true;
                }


            for (int k = 0; k < N; k++)
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        if (a[i, k] && a[k, j])
                            a[i, j] = true;

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    for (int p = 0; p < N; p++)
                        for (int q = 0; q < N; q++)
                        {
                            if (i == j || i == p || i == q)
                                continue;
                            if (j == p || j == q)
                                continue;
                            if (p == q)
                                continue;

                            if (m[i].BinarySearch(j) < 0 || m[i].BinarySearch(p) < 0)
                                continue;

                            if (a[j, q] && a[p, q])
                                return true;
                        }

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    for (int p = 0; p < N; p++)
                        {
                            if (i == j || i == p)
                                continue;
                            if (j == p)
                                continue;

                            if (m[i].BinarySearch(j) < 0 || m[i].BinarySearch(p) < 0)
                                continue;

                            if (a[j, p])
                                return true;
                        }

            return false;
        }

        static int _N;
        static List<int>[] _m;
        static SortedSet<int>[] accessible;

        static SortedSet<int> GetAccessible(int p)
        {
            if (accessible[p] != null)
                return accessible[p];

            accessible[p] = new SortedSet<int>();
            accessible[p].Add(p);
            foreach (var x in _m[p])
                accessible[p].UnionWith(GetAccessible(x));

            return accessible[p];
        }

        static bool Solve3(List<int>[] m)
        {
            _m = m;
            _N = _m.Length;

            int N = m.Length;
            accessible = new SortedSet<int>[N];


            for (int i = 0; i < N; i++)
            {
                int ec = 0;
                SortedSet<int> s = GetAccessible(i);
                foreach (var x in s)
                    ec += m[x].Count;

                if (ec >= s.Count)
                    return true;
            }

            return false;
        }

        static void st()
        {
            List<int>[] m = new List<int>[1000];
            for (int i = 0; i < 1000; i++)
                m[i] = new List<int>();

            for (int i = 0; i < 1000 - 1; i++)
            {
                m[i].Add(i + 1);
            }

            Solve3(m);
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            //for (int i = 0; i < 10; i++) st();
            //return;


            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                List<int>[] m = new List<int>[N];

                for (int i = 0; i < N; i++)
                {
                    m[i] = new List<int>();
                    string[] line = Console.ReadLine().Split();
                    int Mi = int.Parse(line[0]);
                    for (int j = 0; j < Mi; j++)
                        m[i].Add(int.Parse(line[j + 1]) - 1);
                }

                //bool s1 = Solve(m);
                //bool s2 = Solve2(m);
                bool s3 = Solve3(m);
                //if (s3 != s2)
                //{
                //    Console.WriteLine("!!!!! {0}", N);
                //}
                Console.WriteLine("Case #{0}: {1}", t, s3 ? "Yes" : "No");
            }
        }
    }
}
