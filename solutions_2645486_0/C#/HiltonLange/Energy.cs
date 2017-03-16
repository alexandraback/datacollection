using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Energy : GCJBase
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
                long E = long.Parse(s.Split(' ')[0]);
                long R = long.Parse(s.Split(' ')[1]);
                long N = long.Parse(s.Split(' ')[2]);
                string[] vals = Console.ReadLine().Split(' ');
                long[] vls = new long[N];

                for (int i = 0; i < N; i++)
                {
                    vls[i] = long.Parse(vals[i]);
                }
                long ret = BestValue(E,R,vls);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long BestValue(long E, long R, long[] val)
        {
            int N = val.Length;

            long[] idx = new long[N];
            for (int i = 0; i < N; i++)
            {
                idx[i] = i;
            }

            long[] val2 = new long[N];
            Array.Copy(val, val2, N);
            Array.Sort(val2, idx);
            Array.Reverse(val2);
            Array.Reverse(idx);

            long[] spend = new long[N];
            for (int i = 0; i < N; i++)
            {
                long e = E;
                for (int j = 0; j < N; j++)
                {
                    if (j == i)
                    {
                        spend[j] = e;
                    }
                    e -= spend[j];
                    e += R;
                    if (e >= E) e = E;
                }
            }

            long ret = 0;
            for (int i = 0; i < N; i++)
            {
                ret += spend[idx[i]] * val[i];
            }

            return ret;

        }

    }
}
