using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2014Round1C_A
{
    class Program
    {
        static void Main(string[] args)
        {

            int caseNum = 1;

            string fileName = "A-small-attempt0";
            using (StreamReader sr = new StreamReader(string.Format("../../{0}.in", fileName)))
            using (StreamWriter sw = new StreamWriter(string.Format("../../{0}.out", fileName)))
            {
                int T = int.Parse(sr.ReadLine());
                for (int t = 0; t < T; t++)
                {
                    string[] PQ = sr.ReadLine().Split('/');
                    Int64 P = int.Parse(PQ[0]);
                    Int64 Q = int.Parse(PQ[1]);

                    Debug.WriteLine(caseNum);
                    sw.WriteLine(string.Format("Case #{0}: {1}", caseNum++, Solve(P, Q)));
                }
            }
        }

        static string Solve(Int64 P, Int64 Q)
        {
            Int64 gcd = GetGCD(P, Q);
            Int64 P2 = P / gcd;
            Int64 Q2 = Q / gcd;

            //if Q2 is power of 2 then return that number.
            if (IsPowerOfTwo(Q2))
            {
                int powerCount = 0;
                while(Q2 > P2)
                {
                    powerCount++;
                    Q2 /= 2;
                }
                //Int64 power = (Int64)Math.Log(Q2, 2d);
                return powerCount + "";
            }

            return "impossible";
        }

        static bool IsPowerOfTwo(Int64 x)
        {
            return (x & (x - 1)) == 0;
        }

        //public static bool isPrime(Int64 number)
        //{
        //    Int64 boundary = (Int64)Math.Floor(Math.Sqrt(number));

        //    if (number == 1) return false;
        //    if (number == 2) return true;

        //    for (Int64 i = 2; i <= boundary; ++i)
        //    {
        //        if (number % i == 0) return false;
        //    }

        //    return true;
        //}

        private static Int64 GetGCD(Int64 a, Int64 b)
        {
            //Drop negative signs
            a = Math.Abs(a);
            b = Math.Abs(b);

            //Return the greatest common denominator between two integers
            while (a != 0 && b != 0)
            {
                if (a > b)
                    a %= b;
                else
                    b %= a;
            }

            if (a == 0)
                return b;
            else
                return a;
        }
    }
}
