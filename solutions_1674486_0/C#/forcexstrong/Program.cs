using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace CodeJammer
{
    class Program
    {

        bool dfs(int[,] arr,int r, int N)
        {
            if (marked.Contains(r))
                return true;

            marked.Add(r);

            for (int i = 0; i < N; i++)
                if (arr[r, i] == 1)
                {
                    bool dva = dfs(arr, i, N);
                    if (dva)
                        return true;
                }
            return false;
        }

        List<int> marked = new List<int>();
        public void Solve()
        {
            int T = ReadInt();
            for (int c = 1; c <= T; ++c)
            {
                bool same = false;
                int N = ReadInt();
                int[,] arr = new int[N, N];
                for (int i = 0; i < N; i++)
                {
                    List<int> row = ReadInts();
                    for (int j = 1; j < row.Count; j++)
                        arr[i, row[j] - 1] = 1;
                }

                arr = transpose(arr, N);
                for (int i = 0; i < N && !same; i++)
                {
                    marked.Clear();
                    same = false;
                    for (int j = 0; j < N; j++)
                    {
                        if (arr[i, j] == 1)
                        {
                            same|=dfs(arr, j, N);
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", c, same ? "Yes" : "No"); 
            }
        }

        private int[,] transpose(int[,] arr, int N)
        {
            int[,] t = new int[N, N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    t[i, j] = arr[j, i];

            return t;
        }

        #region Tester
        /// <summary>
        /// Run this to test the algo
        /// </summary>
        public void TestCode()
        {
            Console.WriteLine(GCD(15, 20));
        }
        #endregion

        #region Helpers
        private bool Verify(int val, int min, int max)
        {
            return val >= min && val <= max;
        }

        int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }
        string ReadString()
        {
            return Console.ReadLine();
        }
        List<int> ReadInts()
        {
            string[] fields = Console.ReadLine().Split(' ');
            List<int> ints = new List<int>();
            foreach (string f in fields)
                ints.Add(int.Parse(f));

            return ints;
        }
        IEnumerable<string> AllSubstrings(string s)
        {
            for (int i = 1; i <= s.Length; ++i)
            {
                for (int j = 0; j < s.Length - i + 1; ++j)
                {
                    yield return s.Substring(j, i);
                }
            }
        }

        int LexComparer(string s1, string s2)
        {
            if (s1 == s2)
                return 0;

            if (string.IsNullOrEmpty(s1))
                return -1;
            if (string.IsNullOrEmpty(s2))
                return 1;

            for (int i = 0; i < s1.Length && i < s2.Length; ++i)
            {
                char c1 = s1[i], c2 = s2[i];
                if (c1 == c2)
                    continue;

                return c1.CompareTo(c2);
            }
            return s1.Length > s2.Length ? -1 : 1;
        }
        int GCD(int i, int j)
        {
            if (i == 0)
                return j;

            return GCD(j % i, i);
        }
        #endregion
        static void Main(string[] args)
        {
            Program p = new Program();
            //p.TestCode();
            p.Solve();
        }
    }
}
