using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P3
{
    /*
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1

Case #1: 1
1 1 1
Case #2: 4
1 1 2
1 2 3
1 2 1
1 1 1
Case #3: 2
1 1 2
1 1 1
Case #4: 2
1 1 3
1 2 1

         */
    class Program
    {
        static void Main(string[] args)
        {
            //System.Diagnostics.Debugger.Launch();

            var e1 = int.Parse(Console.ReadLine());
            for (int f1 = 1; f1 <= e1; f1++)
            {
                string resp = string.Empty;
                var e2 = Console.ReadLine().Split(' ').Select(str => int.Parse(str)).ToArray();

                int j = e2[0];
                int p = e2[1];
                int s = e2[2];
                int k = e2[3];

                int[] limit = new int[10000];
                int total = 0;
                List<int> options = new List<int>();

                for (int jx = 1; jx <= j; jx++)
                {
                    for (int px = 1; px <= p; px++)
                    {
                        for (int sx = 1; sx <= s; sx++)
                        {
                            int t=100 * (jx - 1) + 10 * (px - 1) + (sx - 1);
                            if (limit[121 * jx + 11 * px] == k || limit[121 * jx + sx] == k || limit[11 * px + sx] == k)
                            {
                                continue;
                            }

                            limit[121 * jx + 11 * px]++;
                            limit[121 * jx + sx]++;
                            limit[11 * px + sx]++;

                            total++;

                            options.Add(100 * (jx-1) + 10 * (px-1) + (sx-1));
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", f1, total);
                foreach (int i in options)
                {
                    Console.WriteLine(string.Format("{0} {1} {2}", 1 + (i / 100), 1 + (i % 100 / 10), 1 + (i % 10)));
                }
            }
        }
    }
}
