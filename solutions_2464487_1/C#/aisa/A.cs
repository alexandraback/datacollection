using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace A
{
    class A
    {


        static void Main(string[] args)
        {
            var fs = new FileStream("A.in", FileMode.Open);
            var input = new StreamReader(fs);
            var fis = new FileStream("A.out", FileMode.Create);
            var output = new StreamWriter(fis);

            char[] sep = { ' ' };
            BigInteger T = 0;
            var str = input.ReadLine();
            string[] temp = str.Split(sep);

            T = BigInteger.Parse(temp[0]);
            for (int i = 1; i <= T; i++)
            {
                BigInteger r = 0, t = 0;
                var s = input.ReadLine();
                temp = s.Split(sep);
                r = BigInteger.Parse(temp[0]);
                t = BigInteger.Parse(temp[1]);


                BigInteger mid = t / 2;
                BigInteger x = 2 * mid * mid + mid * (2 * r + 3) + 2 * r + 1;
                BigInteger low = 0;
                BigInteger top = t;
                while (low < top - 1)
                {
                    if (x > t)
                    {
                        top = mid;
                    }
                    else
                    {
                        low = mid;
                    }

                    mid = (top + low) / 2;
                    x = 2 * mid * mid + mid * (2 * r + 3) + 2 * r + 1;
                }
                if (low  == t-1)
                    output.WriteLine("Case #{0}: {1}", i, low);
                else
                    output.WriteLine("Case #{0}: {1}", i, top);
            }
            output.Close();
        }

    }
}
