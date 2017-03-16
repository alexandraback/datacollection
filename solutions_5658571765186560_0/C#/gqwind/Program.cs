using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Q_D
{
    class Program
    {
        static void Main(string[] args)
        {
            string fin = "D-small-attempt0.in";
            string fout = "D.out";
            string w1 = "RICHARD";
            string w2 = "GABRIEL";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            int X, R, C;
            for (int i = 1; i <= T; i++)
            {
                string text = sr.ReadLine();
                X = Int32.Parse(text.Split(' ')[0]);
                R = Int32.Parse(text.Split(' ')[1]);
                C = Int32.Parse(text.Split(' ')[2]);
                string ans = "";
                if (X == 1)
                    ans = w2;
                if (X == 2)
                {
                    if (R * C % 2 == 0)
                        ans = w2;
                    else
                        ans = w1;
                }
                if (X == 3)
                {
                    if (R * C % 3 == 0 && R > 1 && C > 1)
                        ans = w2;
                    else
                        ans = w1;
                }
                if (X == 4)
                {
                    if (R * C == 12 || R * C == 16)
                        ans = w2;
                    else
                        ans = w1;
                }
                sw.WriteLine(string.Format("Case #{0}: {1}", i, ans));
            }

            sr.Close();
            sw.Close();
        }
    }
}
