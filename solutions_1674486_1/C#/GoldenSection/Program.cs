using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("a.in");
            StreamWriter outFile = new StreamWriter("a.out");


            int csCnt = Convert.ToInt32(inFile.ReadLine());
            for (int csId = 1; csId <= csCnt; csId++)
            {
                int n = Convert.ToInt32(inFile.ReadLine());
                bool[,] graph = new bool[n, n];
                List<int>[] next = new List<int>[n];
                for (int i = 0; i < n; i++)
                {
                    string[] spt = inFile.ReadLine().Split();
                    next[i] = new List<int>();
                    for (int j = 1; j < spt.Length; j++)
                    {
                        next[i].Add(Convert.ToInt32(spt[j]) - 1);
                        graph[i, Convert.ToInt32(spt[j]) - 1] = true;
                    }
                }

                List<int> tSort = getTopSort(next, n);

                int[,] cnt = new int[n, n];
                foreach (int i in tSort)
                {
                    foreach (int np in next[i])
                    {
                        cnt[i, np] += 1;
                        for (int j = 0; j < n; j++)
                        {
                            cnt[j, np] += cnt[j, i];
                            if (cnt[j, np] > 2) cnt[j, np] = 2;
                        }
                    }
                }

                bool flag = false;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (cnt[i, j] > 1) flag = true;

                outFile.WriteLine("Case #{0}: {1}", csId, (flag ? "Yes" : "No"));

            }

            inFile.Close();
            outFile.Close();

        }

        static List<int> getTopSort(List<int>[] next, int n)
        {
            List<int> ret = new List<int>();
            int[] deg = new int[n];

            for (int i = 0; i < n; i++)
                foreach (int j in next[i]) deg[j]++;

            List<int> que = new List<int>();
            for (int i = 0; i < n; i++)
                if (deg[i] == 0) que.Add(i);
            int head = 0;

            while (head < que.Count)
            {
                ret.Add(que[head]);
                foreach (int i in next[que[head]])
                {
                    deg[i]--;
                    if (deg[i] == 0) que.Add(i);
                }
                head++;
            }

            return ret;
        }
    }
}
