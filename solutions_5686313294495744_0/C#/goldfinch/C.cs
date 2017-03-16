using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14.R1B
{
    
    using System.Globalization;
    using System.Runtime.Remoting.Channels;
    using System.Security.Policy;

    class C
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            int line = 1;

            for (int test = 0; test < cases; test++)
            {
                string s = lines[line++];
                int n = int.Parse(s);
                this.first = new string[n];
                this.second = new string[n];
                for (int i = 0; i < n; i++)
                {
                    string[] all = lines[line++].Split(' ');
                    this.first[i] = all[0];
                    this.second[i] = all[1];
                }

                this.memo = new int[1<<n];
                for (int i = 0; i < this.memo.Length; i++)
                    this.memo[i] = -1;
                int r = Calc(0);

                Console.WriteLine("Case #{0}: {1}", (test + 1), r);
                res[test] = string.Format("Case #{0}: {1}", (test + 1), r);


            }
            return res;
        }

        private string[] first;
        private string[] second;


        private int[] memo;

        int Calc(int mask)
        {
            if (this.memo[mask] != -1)
                return this.memo[mask];

            int res = 0;
            for (int i = 0; i < this.first.Length;i++)
            {
                if ((mask & (1 << i)) == 0)
                {

                    bool okf = false, oks = false;
                    for (int j = 0; j < this.first.Length; j++)
                    {
                        if (j != i && (mask & (1 << j)) == 0)
                        {
                            if (this.first[i] == this.first[j])
                                okf = true;
                            if (this.second[i] == this.second[j])
                                oks = true;
                        }
                    }
                    if (okf && oks)
                    {
                        int t = Calc(mask | (1 << i));
                        res = Math.Max(res, t + 1);
                    }
                }
            }
            return this.memo[mask] = res;
        }
    }
}
