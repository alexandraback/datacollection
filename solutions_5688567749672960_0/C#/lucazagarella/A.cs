using System;
using System.Collections.Generic;
using System.Linq;

namespace GoogleCodeJam.Rounds.R1B.A
{
    public class A : Problem
    {
        protected override string SolveCase()
        {
            line = reader.ReadLine();
            String[] valoriInput = line.Split(' ');

            long n = long.Parse(valoriInput[0]);

            long r = 1;
            while (n > 1)
            {
                if (n % 10 == 0)
                {
                    r++;
                    n--;
                    continue;
                }
                if (n < 10)
                {
                    r += n - 1;
                    n = 1;
                    continue;
                }

                var a = ToArray(n);

                var l = a.Length;

                long sx = 0;
                long dx = 0;
                for (int i = 0; i < l / 2; i++)
                {
                    dx *= 10;
                    dx += a[i];
                    sx *= 10;
                    sx += a[l - i - 1];
                }

                var dxr = Swap(dx);
                var sxr = Swap(sx);

                var d = dxr - 1;
                n -= dxr - 1;
                if (sxr > 1)
                {
                    n = Swap(n) - sxr + 1;
                    d += sxr;
                }
                r += d;
                if (d == 0)
                {
                    r += 2;
                    n -= 2;
                }

            }

            string res = r.ToString();

            res = res.Replace(',', '.');

            return res;
        }

        long Swap(long n)
        {
            return long.Parse(string.Join("", n.ToString().Reverse()));
        }

        int[] ToArray(long n)
        {
            var l = new List<int>();
            while (n > 0)
            {
                int li = (int)(n % 10);
                l.Add(li);
                n -= li;
                n /= 10;
            }
            return l.ToArray();
        }





    }
}


