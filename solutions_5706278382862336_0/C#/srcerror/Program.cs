using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\CodeJam\03\A-small-attempt1.in";
            string output = @"d:\Work\CodeJam\03\A-small-attempt1.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        //string result = Task2(sin);
                        //string result = Task3(sin);
                        //string result = Task4(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        
        private static string Task3(StreamReader sin)
        {
            
            return "";
        }

        private static string Task2(StreamReader sin)
        {

            return "";
        }

        private static string Task1(StreamReader sin)
        {
            var x = sin.ReadLine().Split('/').ToList();
            var P = BigInteger.Parse(x[0]);
            var Q = BigInteger.Parse(x[1]);

            // find non 2 
            var q1 = FindNon2(Q);
            string impossible = "impossible";

            if (P == 0) return impossible;
            // divide
            if (P%q1 != 0)
            {
                return impossible;
            }
            P = P/q1;
            Q = Q/q1;

            while (P%2 == 0)
            {
                P = P/2;
                Q = Q/2;
            }

            //if (P > Q/2) return "1";

            var pow = FindPow(Q, P);
            return pow.ToString();
        }

        private static BigInteger FindPow(BigInteger q, BigInteger p)
        {
            var x = q;
            BigInteger result = 1;
            while (x / 2 > p)
            {
                result++;
                x /= 2;
            }
            return result;
        }

        private static BigInteger FindNon2(BigInteger q)
        {
            var d = q;
            while (true)
            {
                var m = d%2;
                if (m != 0)
                {
                    return d;
                }
                d = d/2;
            }
        }
    }
}
