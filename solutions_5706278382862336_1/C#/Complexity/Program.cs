using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PartElf
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader s = new StreamReader(@"C:\Users\Tim\Desktop\input.in");
            StreamWriter w = new StreamWriter(@"C:\Users\Tim\Desktop\output.txt");
            int t = Convert.ToInt32(s.ReadLine());
            for (int i = 1; i < t + 1; i++)
            {
                string[] number = s.ReadLine().Split('/');
                long x = Convert.ToInt64(number[0]);
                long y = Convert.ToInt64(number[1]);
                long gcd = GCD(x, y);
                x /= gcd;
                y /= gcd;
                
                if (y == 1)
                {
                    if (x == 0)
                        w.WriteLine("Case #" + i + ": impossible");
                    else
                        w.WriteLine("Case #" + i + ": 1");
                }
                else if (!IsPowerOfTwo(y))
                    w.WriteLine("Case #" + i + ": impossible");
                else
                {
                    double z = Convert.ToDouble(y) / Convert.ToDouble(x);                    
                    int pow = 1;
                    while (z > 2)
                    {
                        z /= 2;
                        pow++;                        
                    }
                    w.WriteLine("Case #" + i + ": " + pow);
                }
            }
            w.Close();
            s.Close();            
        }

        static bool IsPowerOfTwo(long x)
        {
            return (x != 0) && ((x & (x - 1)) == 0);
        }

        static long GCD(long a, long b)
        {
            while (b != 0)
            {
                long tmp = b;
                b = a % b;
                a = tmp;
            }

            return a;
        }
    }
}
