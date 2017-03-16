using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace cgcja
{
    class Program
    {
        static void Main(string[] args)
        {
            String textFile = "D:\\gcj.txt";
            System.Text.Encoding enc = Encoding.GetEncoding("shift_jis");
            string[] s = File.ReadAllLines(textFile, enc);

            int n = 0;
            int[] Tm = rarray(s[0]);
            int T = Tm[0];

            string fname = @"D:\Test.txt";
            Encoding sjis = Encoding.GetEncoding("Shift-JIS");
            StreamWriter w = new StreamWriter(fname, false, sjis);

            for (int j = 0; j < T; j++)
            {
                long[] len = larray(s[++n]);
                //int N = len[0];

                long a = len[0];
                long b = len[1];
                long k = gcd(a, b);
                a /= k;
                b /= k;
                int cb = 0;
                int ca = 0;
                bool imp = false;

                while (b > 1)
                {
                    b /= 2;
                    cb++;
                    if (b % 2 == 1 && b != 1)
                    {
                        w.WriteLine("Case #{0}: impossible",j+1);
                        imp = true;
                        break;
                    }
                }
                while (a > 1)
                {
                    a /= 2;
                    ca++;
                }
                if (!imp)
                {
                    w.WriteLine("Case #{0}: {1}",j+1,cb - ca);
                }
            }
            w.Close();
        }

        static int[] rarray(string a)
        {
            return (from s in a.Split('/') select int.Parse(s)).ToArray();
        }
        static long[] larray(string a)
        {
            return (from s in a.Split('/') select long.Parse(s)).ToArray();
        }

        static long[] rarray2(string a)
        {
            return (from s in a.Split(' ') select Convert.ToInt64(s, 2)).ToArray();
        }

        static long gcd(long a, long b)
        {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
    }
}
