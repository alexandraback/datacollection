using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round1B
{
    public class A
    {
        private void Run()
        {
            // small only
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                int n = int.Parse(Console.ReadLine().Trim());

                var dp = Enumerable.Repeat(int.MaxValue, n + 1).ToArray();
                dp[1] = 1;
                for (int i = 1; i < n; i++)
                {
                    dp[i + 1] = Math.Min(dp[i + 1], dp[i] + 1);

                    var s = i.ToString().ToCharArray();
                    Array.Reverse(s);
                    int next = int.Parse(new string(s));
                    if (next <= n)
                    {
                        dp[next] = Math.Min(dp[next], dp[i] + 1);
                    }
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(dp[n]);
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new A().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
