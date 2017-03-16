using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Bullseye : GCJBase
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
                long r = long.Parse(s.Split(' ')[0]);
                long t = long.Parse(s.Split(' ')[1]);
                long ret = Calc(r, t);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private long Calc(long r, long t)
        {
            long min = 1;
            long max = int.MaxValue;

            while (max > min)
            {
                long mid = (max + min+1) / 2;
                long i = ink(r, mid);
                if (i > t)
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid;
                }
            }

            return min;
        }

        private long ink(long r, long rings)
        {
            long initial = 2 * r + 1;
            long diff = 4;
            long sum = initial + initial + diff * (rings - 1) ;
            sum /= 2;
            if (long.MaxValue / rings< sum) return long.MaxValue;
            sum *= rings;
            return sum;
        }

    }
}
