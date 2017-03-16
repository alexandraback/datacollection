using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Recycle : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int A = int.Parse(s.Split(' ')[0]);
                int B = int.Parse(s.Split(' ')[1]);
                long ret = NumRecycle(A,B);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long NumRecycle(int A, int B)
        {
            long ret = 0;
            for (int i = A; i <= B; i++)
            {
                HashSet<int> mem = new HashSet<int>();
                string si = i.ToString();
                char[] c = new char[si.Length*2];
                for (int j = 0; j < si.Length; j++)
                {
                    c[j] = si[j];
                    c[j + si.Length] = si[j];
                }
                for (int j = 1; j < si.Length; j++)
                {
                    if (c[j] >= c[0])
                    {
                        string s2 = new string(c, j, si.Length);
                        int jj = int.Parse(s2);
                        if (jj > i && jj <= B && !mem.Contains(jj))
                        {
                            mem.Add(jj);
                            ret++;
                        }
                    }
                }
            }

            return ret;
        }
    }
}
