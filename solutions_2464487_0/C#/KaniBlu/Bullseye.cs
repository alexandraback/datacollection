using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace CodeJamTest
{
    class Bullseye : CodeJamTemplate
    {
        protected override void _run()
        {
            int T = readInt();

            for (int i = 0; i < T; i++)
            {
                string[] tokens = readTokens();
                BigInteger r = BigInteger.Parse(tokens[0]);
                BigInteger t = BigInteger.Parse(tokens[1]);
                write("Case #{0}: ", i+1);
                Console.WriteLine(i);

                r = BigInteger.Pow(r + 1, 2) - BigInteger.Pow(r, 2);
                BigInteger big = (-1 * (2*r+4) + squareRoot(BigInteger.Pow(2*r+4,2) - 16*(2*r-2*t) )) / 8;
                big++;
                writeLine(big.ToString());
            }
        }

        public static BigInteger squareRoot(BigInteger integer)
        {
            if (integer == 1 || integer == 0)
                return integer;

            BigInteger prev = BigInteger.Zero;
            BigInteger prev2 = BigInteger.Zero;
            BigInteger x = integer / 2;
            BigInteger q;

            while (x != prev && x != prev2)
            {
                prev2 = prev;
                prev = x;
                q = integer / x;
                x = (x + integer / x) >> 1;
            }

            return x;
        }
    }
}
