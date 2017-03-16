using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Dancing : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int N = int.Parse(s[0]);
                int surprising = int.Parse(s[1]);
                int minscore = int.Parse(s[2]);
                int[] scores = new int[N];
                for (int i = 0; i < N; i++)
                {
                    scores[i] = int.Parse(s[i + 3]);
                }
                long ret = maxGooglers(scores,surprising,minscore);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int maxGooglers(int[] scores, int surprising, int required)
        {
            Array.Sort(scores);
            Array.Reverse(scores);
            int ret = 0;
            for (int i = 0; i < scores.Length; i++)
            {
                if (scores[i] >= required)
                {
                    if (((scores[i] + 2) / 3) >= required)
                    {
                        ret++;
                    }
                    else
                    {
                        if (surprising > 0 && required * 3 - 4 <= scores[i])
                        {
                            surprising--;
                            ret++;
                        }
                    }
                }
            }
            return ret;
        }

    }
}
