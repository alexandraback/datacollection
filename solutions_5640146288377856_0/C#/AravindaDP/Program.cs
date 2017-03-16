using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            A();
        }

        static void A()
        {
            StreamReader sr = new StreamReader("C:\\CodeJam\\Round1C\\A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("C:\\CodeJam\\Round1C\\A-small-attempt0.out");
            int T,R,C,W;

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] toks = sr.ReadLine().Split(' ');
                R = int.Parse(toks[0]);
                C = int.Parse(toks[1]);
                W = int.Parse(toks[2]);

                int y = C / W;
                if (C % W != 0)
                    y = y + 1;
                y = y+( W - 1);
                y = y * R;
                sw.WriteLine(String.Format("Case #{0}: {1}", (i + 1).ToString(), y.ToString()));
            }

            sr.Close();
            sw.Close();
        }
    }
}
