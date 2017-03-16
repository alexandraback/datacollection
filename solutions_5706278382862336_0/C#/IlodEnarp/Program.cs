using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Globalization;

namespace ConsoleApplication1
{
    class Program
    {
        static long GCD(long a, long b)
        {
            while (b > 0)
            {
                long rem = a % b;
                a = b;
                b = rem;
            }
            return a;
        }

        static int Gen(long numerator, long denominator)
        {
            long gcd = GCD(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if ((denominator & (denominator - 1)) == 0 && denominator <= 0x10000000000L)
            {
                for (int i = 0, power = 2; i < 40; ++i, power *= 2)
                {
                    if (numerator * power >= denominator)
                    {
                        return i + 1;
                    }
                }
                return -1;
            }
            else
            {
                return -1;
            }
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader c = new System.IO.StreamReader("C:\\Users\\Ilod\\Downloads\\A-small-attempt0.in");
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Scanner s = new Scanner(c.ReadLine());
            int N = s.nextInt();
            for (int iTest = 0; iTest < N; ++iTest)
            {
                string[] line = c.ReadLine().Split('/');
                s = new Scanner(line[0]);
                long numerator = s.nextLong();
                s = new Scanner(line[1]);
                long denominator = s.nextLong();
                int ret = Gen(numerator, denominator);
                if (ret >= 0)
                {
                    Debug.WriteLine(string.Format("Case #{0}: {1}", iTest + 1, ret));
                }
                else
                {
                    Debug.WriteLine(string.Format("Case #{0}: impossible", iTest + 1));
                }
            }
        }
    }
}
