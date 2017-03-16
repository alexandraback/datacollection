using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ31
{
    public class Problem
    {
        public Problem()
        {
            var pathname = "Sample.txt";

            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        string result = string.Empty;
                        string line = sr.ReadLine();
                        string[] pq = line.Split(new char[] { '/' });
                        long p = long.Parse(pq[0]);
                        long q = long.Parse(pq[1]);

                        long pgcd = PGCD(p, q);
                        long sq = q / pgcd;
                        long sp = p/pgcd;

                        if (!isPossible(sq))
                        {
                            result = "impossible";
                        }
                        else
                        {
                            int maxGen = 0;
                            while (sq>1)
                            {
                                sq/=2;
                                maxGen++;
                            }
                            while (sp>1)
                            {
                                sp/=2;
                                maxGen--;
                            }
                            result = maxGen.ToString();
                        }
                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }
                    sw.Flush();
                }

            }
        }

        long PGCD(long a, long b)
        {
            if (a < b)
                return PGCD(b, a);
            if (b == 0)
                return a;
            return PGCD(b, a % b);
        }

        bool isPossible(long denom)
        {
            int cnt = 0;
            while (denom>0)
            {
                denom &= (denom - 1);
                cnt++;
                if (cnt > 1) return false;
            }
            return cnt == 1;
        }


    }
}
