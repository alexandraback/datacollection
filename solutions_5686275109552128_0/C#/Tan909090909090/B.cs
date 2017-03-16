using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_QualificationRound
{
    public class B
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                int d = int.Parse(Console.ReadLine().Trim());
                var ps = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();

                int res = int.MaxValue;
                int max = ps.Max();
                for (int normalCount = 1; normalCount <= max; ++normalCount)
                {
                    int temp = normalCount;
                    for (int i = 0; i < ps.Length; ++i)
                    {
                        int p = ps[i];
                        if (p % normalCount == 0)
                        {
                            temp += (p / normalCount) - 1;
                        }
                        else
                        {
                            temp += (p / normalCount);
                        }
                    }

                    if (res > temp) { res = temp; }
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(res);
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
