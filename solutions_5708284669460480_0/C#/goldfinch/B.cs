using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1C
{
    using System.Data.SqlTypes;

    internal class B
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int i = 0; i < cases; i++)
            {
                int[] pars =
                    lines[i*3 + 1].Split(new char[1] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(int.Parse)
                        .ToArray();

                int K = pars[0], L = pars[1], S = pars[2];

                string letters = lines[i * 3 + 2];
                string target = lines[i * 3 + 3];

                int to = 1;
                for (int j = 0; j < S; j++)
                    to *= K;

                char[] typed = new char[S];
                int[] freq = new int[S+1];
                int max = 0;
                for (int j = 0; j < to; j++)
                {
                    int t = j;
                    for (int q = 0; q < S; q++)
                    {
                        typed[q] = letters[t % K];
                        t /= K;
                    }

                    int times = 0;
                    for (int q = 0; q+target.Length-1 < S; q++)
                    {
                        bool ok = true;
                        for(int w = 0;w<target.Length && q+w<typed.Length;w++)
                            if (typed[q + w] != target[w])
                            {
                                ok = false;
                                break;
                            }
                        if (ok)
                            times++;
                    }
                    freq[times]++;
                    max = Math.Max(times, max);
                }

                double ans = 0;
                if (max > 0)
                {
                    ans = max;
                    for (int j = 1; j < freq.Length; j++)
                        ans -= (double)j * freq[j] / to;
                }

                Console.WriteLine("Case #{0}: {1}", (i + 1), ans);
                res[i] = string.Format("Case #{0}: {1}", (i + 1), ans);


            }
            return res;
        }
    }
}
