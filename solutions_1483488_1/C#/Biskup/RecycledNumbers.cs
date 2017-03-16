using System;
using System.Collections.Generic;
using System.IO;

namespace Qualification
{
    public class RecycledNumbers
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
                int A = Convert.ToInt32(srd.GetNext());
                int B = Convert.ToInt32(srd.GetNext());
                int ret = 0;
                var ll = new List<int>();

                for (int n = A; n < B; n++)
                {
                    ll.Clear();
                    int m = n;
                    var zn = (int) Math.Log(n, 10);
                    for (int i = 0; i < zn; i++)
                    {
                        int ost = m%10;
                        m = m/10;
                        if (ost == 0) continue;
                        m = (int)(Math.Pow(10, zn)) * ost + m;
                        if (!ll.Contains(m) && n < m && m <= B)
                        {
                            ll.Add(m);
                            ret++;
                        }
                    }
                }

                sw.Write(String.Format("Case #{0:G}: {1:G}\n", tc + 1, ret));
            }

            sr.Close();
            sw.Close();
        }
    }
}