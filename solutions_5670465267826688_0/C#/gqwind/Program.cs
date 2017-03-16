using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Q_C
{
    class Program
    {
        static int[,] map = new int[5, 5] { {0, 0, 0, 0, 0}, {0, 1, 2, 3, 4 }, {0, 2, -1, 4, -3 }, {0, 3, -4, -1, 2 }, {0, 4, 3, -2, -1 } };
        static void Main(string[] args)
        {
            string fin = "C-small-attempt0.in";
            string fout = "C.out";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            Int64 X;
            Int32 L;
            string str;
            string text;
            for (int i = 1; i <= T; i++)
            {
                text = sr.ReadLine();
                L = Int32.Parse(text.Split(' ')[0]);
                X = Int64.Parse(text.Split(' ')[1]);
                str = sr.ReadLine();
                int cur = 1;
                int mult = 1;
                int ch;
                int multL = 1;
                Int32 upper;
                if (X < 8) upper = L * (int) X;
                else upper = 8 * L;
                bool ifound = false;
                bool jfound = false;
                for (int j = 0; j < upper; j++)
                {
                    ch = ((int) str[j % L] - 'i') + 2 ;

                    cur = (cur > 0) ? map[cur, ch] : -map[-cur, ch];
                    mult = (mult > 0) ? map[mult, ch] : -map[-mult, ch];

                    if (!ifound && cur == 2)
                    {
                        ifound = true;
                        cur = 1;
                    }
                    else if (ifound && !jfound && cur == 3)
                    {
                        jfound = true;
                        cur = 1;
                    }

                    if (j == L - 1) 
                        multL = mult;
                    if (ifound && jfound && j >= L - 1)
                        break;
                }

                string ans = "NO";
                if (ifound && jfound)
                {
                    if (multL == -1 && X % 2 == 1) ans = "YES";
                    else if (multL > 1 && X % 4 == 2) ans = "YES";
                    else if (multL < -1 && X % 4 == 2) ans = "YES";
                }
                sw.WriteLine(string.Format("Case #{0}: {1}", i, ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}
