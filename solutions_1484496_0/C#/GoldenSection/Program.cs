using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace B
{
    class Program
    {
        static List<int> list;
        static int[] flag;
        static int n;
        static bool succ;

        static List<int> ans1, ans2;

        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("b.in");
            StreamWriter outFile = new StreamWriter("b.out");

            int csCnt = Convert.ToInt32(inFile.ReadLine());

            for (int csId = 1; csId <= csCnt; csId++)
            {
                string[] spt = inFile.ReadLine().Split();
                n = Convert.ToInt32(spt[0]);
                list = new List<int>();
                for (int i = 1; i <= n; i++) list.Add(Convert.ToInt32(spt[i]));

                succ = false;
                flag = new int[n];

                dfs(1, list[0], 0, 0);

                outFile.WriteLine("Case #{0}:", csId);
                if (!succ)
                {
                    outFile.WriteLine("Impossible");
                }
                else
                {
                    outFile.Write(ans1[0]);
                    for (int i = 1; i < ans1.Count; i++) outFile.Write(" {0}", ans1[i]);
                    outFile.WriteLine();

                    outFile.Write(ans2[0]);
                    for (int i = 1; i < ans2.Count; i++) outFile.Write(" {0}", ans2[i]);
                    outFile.WriteLine();
                }
            }


            inFile.Close();
            outFile.Close();
        }

        static void dfs(int k, int sum0, int sum1, int sum2)
        {
            if (succ) return;

            if (sum0 > 0 && sum0 == sum1) recordAns(k, 0, 1);
            else if (sum0 > 0 && sum0 == sum2) recordAns(k, 0, 2);
            else if (sum1 > 0 && sum1 == sum2) recordAns(k, 1, 2);

            if (succ || k >= n) return;

            flag[k] = 0;
            dfs(k + 1, sum0 + list[k], sum1, sum2);

            flag[k] = 1;
            dfs(k + 1, sum0, sum1 + list[k], sum2);

            flag[k] = 2;
            dfs(k + 1, sum0, sum1, sum2 + list[k]);

        }

        static void recordAns(int k, int p, int q)
        {
            succ = true;

            ans1 = new List<int>();
            ans2 = new List<int>();

            for (int i = 0; i < k; i++)
                if (flag[i] == p) ans1.Add(list[i]);
                else if (flag[i] == q) ans2.Add(list[i]);
        }
    }
}
