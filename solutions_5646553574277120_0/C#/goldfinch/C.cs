using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1C
{
    class C
    {
         public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                int[] pars =
                    lines[i*2 + 1].Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(int.Parse)
                        .ToArray();

                int C = pars[0], D = pars[1], V = pars[2];

                int[] have = lines[i*2 + 2].Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(int.Parse)
                        .ToArray();

                HashSet<long> all = new HashSet<long>();

                bool[] map = new bool[100000];
                map[0] = true;
                for (int a = 0; a < C; a++)
                {
                    for (int q = 0; q < have.Length; q++)
                    {
                        for (int w = map.Length - 1; w >= 0; w--)
                            if (map[w])
                                map[w + have[q]] = true;
                    }
                }


                int ans = 0;

                long cur = 1;
                for (; cur <= V;)
                {
                    if (!map[cur])
                    {
                        ans++;
                        for (int w = map.Length - 1; w >= 0; w--)
                        if (map[w])
                            for (int q = 0; q < have.Length; q++)
                            {
                                map[w + cur] = true;
                            }

                        cur = cur * C + cur - 1;
                    }
                    else
                    {
                        cur++;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", (i + 1), ans);
                res[i] = string.Format("Case #{0}: {1}", (i + 1), ans);


            }
            return res;
        }
    }
}
