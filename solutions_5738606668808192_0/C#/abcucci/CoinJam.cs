using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2016
{
    public class CoinJam
    {
        public string[] Solve(int N, int J)
        {
            // answer format: jamcoin, divisors base 2 to 10.
            List<string> answers = new List<string>();

            // N: jamcoin string length.
            // J: the count of different jamcoins.

            // jam coin trial.
            long start = (1L << (N - 1)) + 1L;
            long end = (1L << N);
            //
            for (long K = start; K < end; K += 2)
            {
                List<int> divs = new List<int>();

                for (int i = 2; i <= 10; ++i)
                {
                    BigInteger number = new BigInteger(0, 0);
                    for (int bit = 0; bit < N; ++bit)
                    {
                        number *= i;
                        long mask = 1L << (N - 1 - bit);
                        if ((K & mask) > 0)
                        {
                            number += 1;
                        }
                    }

                    int div = -1;
                    for (int n = 3; n < 1001; n += 2)
                    {
                        long mod = number % (long)n;
                        if (mod == 0)
                        {
                            div = n;
                            break;
                        }
                    }
                    if (div < 0)
                    {
                        break;
                    }
                    divs.Add(div);
                }
                //
                if (divs.Count == 9)
                {
                    string answer = string.Format("{0}", Convert.ToString(K, 2));
                    foreach (int div in divs)
                    {
                        answer += string.Format(" {0}", div);
                    }
                    answers.Add(answer);

                    if (answers.Count == J)
                    {
                        break;
                    }
                }
            }


            return (string[])answers.ToArray();
        }

        public class BigInteger
        {
            public long Upper = 0;
            public long Lower = 0;

            public static long Base1 = 1L << 56;
            //public static long Base1 = 1000L;

            public static BigInteger operator +(BigInteger x, long y)
            {
                long lower = x.Lower + (y % BigInteger.Base1);
                long upper = x.Upper + (y / BigInteger.Base1);
                BigInteger z = new BigInteger(upper, lower);
                return z;
            }

            public static BigInteger operator +(BigInteger x, BigInteger y)
            {
                long lower = x.Lower + y.Lower;
                long upper = x.Upper + y.Upper;
                BigInteger z = new BigInteger(upper, lower);
                return z;
            }

            public static BigInteger operator *(BigInteger x, long y)
            {
                long lower = x.Lower * y;
                long upper = x.Upper * y;
                BigInteger z = new BigInteger(upper, lower);
                return z;
            }

            public static long operator %(BigInteger x, long y)
            {
                long mod1 = x.Upper % y;
                long mod2 = BigInteger.Base1 % y;
                long lower = x.Lower + mod1 * mod2;
                long mod = lower % y;
                return mod;
            }

            public BigInteger(long upper, long lower)
            {
                this.Upper = upper + (lower / BigInteger.Base1);
                this.Lower = lower % BigInteger.Base1;
                return;
            }
        }

    }
}
