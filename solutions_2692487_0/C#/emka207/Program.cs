using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ13_1B_A1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int nc = 1; nc <= T; nc++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                int A = int.Parse(ss[0]);
                int N = int.Parse(ss[1]);
                int[] m = new int[N];
                ss = Console.ReadLine().Split(' ');
                for (int i = 0; i < N; i++) m[i] = int.Parse(ss[i]);
                Array.Sort(m);

                List<int> M = new List<int>(m);
                //while (M.Count > 0 && M[0] < A)
                //{
                //    A += M[0];
                //    M.RemoveAt(0);
                //}

                Console.WriteLine("Case #{0}: {1}", nc, solve(A, M, 0));
            }
        }

        private static int solve(int A, List<int> list, int idx)
        {
            while (idx < list.Count && list[idx] < A)
            {
                A += list[idx];
                idx++;
            }

            if (list.Count == idx) return 0;

            int min = list.Count-idx;
            int cnt = 0;

            if (A == 1 && min > 0) return min;
            while(list[idx]>=A)
            {
                A += A - 1;
                cnt++;
            }

            return Math.Min(min, cnt + solve(A + list[idx], list, idx + 1));
        }
    }
}
