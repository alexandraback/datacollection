using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJamQ1
{
    class Problem3
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("p3.in");
            StreamWriter fout = new StreamWriter("p3.out");

            int t = int.Parse(fin.ReadLine());

            for (int tn = 0; tn < t; tn++)
            {
                string inp = fin.ReadLine();
                string[] inps = inp.Split(new char[] {' '});

                int min = int.Parse(inps[0]);
                int max = int.Parse(inps[1]);
                int len = (int)Math.Log10(min) + 1;

                int cnt = 0;
                for (int n = min; n <= max; n++)
                {
                    List<int> ls = new List<int>();
                    for (int k = 1; k < len; k++)
                    {
                        int f = (int)Math.Pow(10.0, k);
                        int f2 = (int)Math.Pow(10.0, len - k);

                        int m = (n % f) * f2 + n / f;
                        int mLen = (int)Math.Log10(m) + 1;

                        if (mLen < k) continue;
                        if (m > n && m <= max)
                        {
                            if (!ls.Contains(m))
                            {
                                ls.Add(m);
                                cnt++;
                            }
                        }
                    }
                }

                fout.WriteLine("Case #{0}: {1}", tn + 1, cnt);
            }

            fin.Close();
            fout.Close();
        }
    }
}
