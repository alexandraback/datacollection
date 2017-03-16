using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Data;
using System.Numerics;

class ProblemA : GCJ
{
    int a, n;
    List<int> ss;
    int[] s;

    public override void Input(int testcase)
    {
        base.Input(testcase);
        string[] str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
        a = int.Parse(str[0]);
        n = int.Parse(str[1]);
        ss = new List<int>();
        str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
        for (int i = 0; i < n; i++)
            ss.Add(int.Parse(str[i]));
        ss.Sort();
        s = ss.ToArray();

        Dictionary<int, int>[] dp = new Dictionary<int, int>[2];
        dp[1] = new Dictionary<int, int>();
        dp[1][a] = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = i % 2;
            int pre = (i + 1) % 2;

            dp[cur] = new Dictionary<int, int>();
            foreach (int k in dp[pre].Keys)
            {
                if (k > s[i])
                {
                    if (dp[cur].ContainsKey(k + s[i]) == false)
                        dp[cur][k + s[i]] = dp[pre][k];
                    else
                        dp[cur][k + s[i]] = Math.Min(dp[cur][k + s[i]], dp[pre][k]);
                }
                else if (k > 1)
                {
                    int num = 0;
                    int sz = k;
                    while (sz <= s[i])
                    {
                        num++;
                        sz = sz * 2 - 1;
                    }
                    if (dp[cur].ContainsKey(sz + s[i]) == false)
                        dp[cur][sz + s[i]] = dp[pre][k] + num;
                    else
                        dp[cur][sz + s[i]] = Math.Min(dp[cur][sz + s[i]], dp[pre][k] + num);
                }
                if (dp[cur].ContainsKey(k) == false)
                    dp[cur][k] = dp[pre][k] + 1;
                else
                    dp[cur][k] = Math.Min(dp[cur][k], dp[pre][k] + 1);
            }
        }

        int ans = (n - 1) % 2;
        int ret = int.MaxValue;
        foreach (int k in dp[ans].Keys)
            if (dp[ans][k] < ret)
                ret = dp[ans][k];

        sw.WriteLine(" " + ret);
        Console.WriteLine(" " + ret);
    }
}