using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                int N = int.Parse(Console.ReadLine());
                string[] s = Console.ReadLine().Split();
                int[] bffs = s.Select<string, int>(bff => int.Parse(bff)).ToArray();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWorkHard(N, bffs)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWorkHard(int N, int[] bffs)
        {
            for (int i = 0; i < N; i++)
            {
                bffs[i] = bffs[i] - 1;
            }

            int longestcycle = 0;

            for (int i = 0; i < N; i++)
            {
                bool[] visited = new bool[N];
                int pos = i;
                visited[i] = true;
                int len = 1;
                do
                {
                    pos = bffs[pos];
                    if (visited[pos]) break;
                    visited[pos] = true;
                    len++;
                } while (pos != i);
                if (pos == i) longestcycle = Math.Max(longestcycle, len);
            }

            if (longestcycle == N) return N.ToString();

            List<int>[] children = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                children[i] = new List<int>();
            }
            for (int i = 0; i < N; i++)
            {
                children[bffs[i]].Add(i);

            }

            bool[] used = new bool[N];
            bool work = false;
            int ret = 0;
            do
            {
                bool[] used2 = new bool[N];
                work = false;
                for (int i = 0; i < N; i++)
                {
                    int pos = i;
                    bool fail = false;
                    used2[pos] = true;
                    int len = 1;
                    do
                    {
                        bool loopback = false;
                        int lastpos = pos;
                        pos = bffs[pos];
                        len++;
                        if (used[pos])
                        {
                            fail = true;
                            break;
                        }
                        if (bffs[pos] == lastpos)
                        {
                            loopback = true;
                        }
                        else if (used2[pos])
                        {
                            fail = true;
                            break;
                        }
                        used2[pos] = true;

                        if (loopback)
                        {
                            len += Depth(pos, used, used2, children);
                            MarkAll(pos, used, used2, children);
                            len += Depth(i, used, used2, children);
                            MarkAll(i, used, used2, children);
                            for (int j = 0; j < N; j++)
                            {
                                if (used2[j]) used[j] = true;
                            }
                            ret += len;
                            work = true;
                            break;
                        }

                    } while (true);
                }
            } while (work);

            return Math.Max(longestcycle, ret).ToString();

        }

        private int Depth(int node, bool[] used, bool[] used2, List<int>[] children)
        {
            int maxDepth = 0;
            foreach (var child in children[node])
            {
                if (!used[child] && !used2[child])
                {
                    maxDepth = Math.Max(maxDepth, 1 + Depth(child, used, used2, children));
                }
            }
            return maxDepth;
        }

        private void MarkAll(int node, bool[] used, bool[] used2, List<int>[] children)
        {
            foreach (var child in children[node])
            {
                if (!used[child] && !used2[child])
                {
                    MarkAll(child, used, used2, children);
                }
            }
            used2[node] = true;
        }

        private string DoWork(int N, int[] bffs)
        {
            for (int i = 0; i < N; i++)
            {
                bffs[i] = bffs[i] - 1;
            }

            int ret = 0;

            for (int j = 0; j < 1 << N; j++)
            {
                List<int> kids = new List<int>();
                for (int i = 0; i < N; i++)
                {
                    if ((1 << i & j) != 0) kids.Add(i);
                }
                int M = kids.Count;
                int[] kds = kids.ToArray();
                do
                {
                    bool good = true;
                    for (int i = 0; i < M; i++)
                    {
                        int left = (i + M - 1) % M;
                        int right = (i + 1) % M;
                        if (kds[left] != bffs[kds[i]] && kds[right] != bffs[kds[i]])
                        {
                            good = false;
                            break;
                        }
                    }

                    if (good) ret = Math.Max(ret, M);
                } while (bNextPermutation(kds));
            }

            return ret.ToString();
        }

        private bool bNextPermutation(int[] a)
        {
            // Find first reversal, return false if there is none
            int i = a.Length - 2;
            if (i < 0) return false;
            while (a[i] >= a[i + 1])
            {
                i -= 1;
                if (i == -1)
                {
                    System.Array.Sort(a);
                    return false;
                }
            }

            // Find first element greater than reversal
            int j = a.Length - 1;
            while (a[j] <= a[i]) { j -= 1; }

            // Swap
            int aTemp = a[j];
            a[j] = a[i];
            a[i] = aTemp;

            // Reverse remainder
            System.Array.Reverse(a, i + 1, a.Length - i - 1);
            return true;
        }

    }
}
