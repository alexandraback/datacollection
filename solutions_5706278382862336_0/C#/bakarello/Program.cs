using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace GOOGLEJAM1
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger a, b;
            TextReader sr = File.OpenText("input.txt");
            StreamWriter sw = new StreamWriter(File.OpenWrite("output.txt"));

            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] str = sr.ReadLine().Split('/');
                a = ulong.Parse(str[0]);
                b = ulong.Parse(str[1]);

                BigInteger d = gcd(a, b);
                a /= d;
                b /= d;

                if (IsPowerOfTwo(b))
                {
                    int p = 1;
                    if (b == 1 && a == 1)
                        sw.WriteLine("Case #"+(i+1)+": "+1);
                    while (b >= 2)
                    {
                        if (a >= b / 2)
                        {
                            sw.WriteLine("Case #" + (i + 1) + ": " + p);
                            break;
                        }
                        else
                        {
                            p += 1;
                            b /= 2;
                        }
                    }
                }
                else
                {
                    sw.WriteLine("Case #" + (i + 1) + ": " + "impossible");
                }
            }
            sw.Dispose();
            sr.Dispose();
        }
        static bool IsPowerOfTwo(BigInteger val)
        {
            return val != 0 && (val & (val - 1)) == 0;
        }
        static BigInteger gcd(BigInteger a, BigInteger b)
        {
            while (b != 0)
                b = a % (a = b);
            return a;
        }
    }
}
