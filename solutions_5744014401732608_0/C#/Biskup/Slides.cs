using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace Qualification
{
    public class Slides
    {
        [STAThread]
        public static void Main(string[] args)
        {
            var sr = new StreamReader("B.in");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            int _case = Convert.ToInt32(srd.GetNext());

            for (int tc = 0; tc < _case; tc++)
            {
                sw.Write(String.Format("Case #{0:G}: ", tc + 1));

                Int64 B = Convert.ToInt64(srd.GetNext());
                Int64 M = Convert.ToInt64(srd.GetNext());

                int[,] a = new int[B,B];

                if (Math.Pow(2, B - 2) < M)
                {
                    sw.Write(String.Format("IMPOSSIBLE\n"));
                    continue;

                }
                sw.Write(String.Format("POSSIBLE\n"));

                for (int i = 0; i < B - 1; i++)
                    for (int j = i + 1; j < B - 1; j++)
                        a[i, j] = 1;

                //int[] k = new int[B];
                int ik = 0;
                while (M > 0)
                {
                    a[ik+1, B - 1] = (int) (M%2);
                    //k[ik] = (int)(M % 2);
                    M = M/2;
                    ik++;
                }

                if (a[B - 1, B - 1] == 1)
                {
                    a[B - 1, B - 1] = 0;
                    for (int i = 0; i < B - 1; i++)
                        a[i, B - 1] = 1;
                }

                for (int i = 0; i < B; i++)
                {
                    for (int j = 0; j < B; j++)
                        sw.Write(String.Format("{0:G}", a[i,j]));
                    sw.Write(String.Format("\n"));
                }
            }

            sr.Close();
            sw.Close();
        }
    }
}