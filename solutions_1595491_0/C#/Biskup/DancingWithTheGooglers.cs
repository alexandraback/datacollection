using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Qualification
{
    public class DancingWithTheGooglers
    {
        [STAThread]
        public static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            int _case = Convert.ToInt32(srd.GetNext());

            for (int tc = 0; tc < _case; tc++)
            {
                int N = Convert.ToInt32(srd.GetNext());
                int S = Convert.ToInt32(srd.GetNext());
                int p = Convert.ToInt32(srd.GetNext());
                int[] points = new int[N];
                for (int i = 0; i < N; i++)
                    points[i] = Convert.ToInt32(srd.GetNext());

                int ret = 0;
                for (int i = 0; i < N; i++)
                {
                    if ( ((points[i] + 2) % 3 == 0 && (points[i] + 2) / 3 >= p) ||
                         ((points[i] + 1) % 3 == 0 && (points[i] + 1) / 3 >= p) ||
                         (points[i] % 3 == 0 && points[i] / 3 >= p) )
                    {
                        ret++;
                        continue;
                    }

                    if ( ((points[i] + 2) % 3 == 0 && (points[i] + 2) / 3 >= p) ||
                         ((points[i] + 3) % 3 == 0 && (points[i] + 3) / 3 >= p && points[i]!=0) ||
                         ((points[i] + 4) % 3 == 0 && (points[i] + 4) / 3 >= p))
                    {
                        if (S == 0) continue;
                        S--;
                        ret++;
                        continue;
                    }
                }


                sw.Write(String.Format("Case #{0:G}: {1:G}\n", tc+1, ret));
            }

            sr.Close();
            sw.Close();
        }
    }
}