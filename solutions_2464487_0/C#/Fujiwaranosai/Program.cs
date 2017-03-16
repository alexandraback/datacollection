using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace Round1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader infile = new StreamReader("input.txt");
            StreamWriter outfile = new StreamWriter("output.txt");
            string line = infile.ReadLine();
            int T = int.Parse(line); // case num
            for (int i = 0; i < T; i++)
            {
                line = infile.ReadLine();
                BigInteger r, t;
                string[] arr = line.Split(' ');
                r = BigInteger.Parse(arr[0]);
                t = BigInteger.Parse(arr[1]);
                BigInteger x = solve(r, t);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, x));
            }
            infile.Close();
            outfile.Close();
        }

        static BigInteger solve(BigInteger r, BigInteger t)
        {
            BigInteger b = (BigInteger)r * 2 - 1;
            BigInteger d = b * b;
            d = d + (BigInteger)t * 8;
            d = SqRtN(d);
            BigInteger x = (d - b) / 4;
            return x;
        }

        static BigInteger SqRtN(BigInteger N)
        {
            if (N == 0)
                return 0;
            BigInteger n1 = N >> 1 + 1;
            BigInteger n2 = (n1 + N / n1) >> 1;
            while (n2 < n1)
            {
                n1 = n2;
                n2 = (n1 + N / n1) >> 1;
            }
            return n1;
        }
    }
}
