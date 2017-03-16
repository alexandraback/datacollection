using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GCJ
{
    class FairAndSquare
    {
        public static string Result(StreamReader sr)
        {
            long A, B, C = 0;
            var fragments = sr.ReadLine().Trim().Split();
            A = Convert.ToInt64(fragments[0]);
            B = Convert.ToInt64(fragments[1]);
            long i = (long)Math.Floor(Math.Sqrt(A));

            var valid = new List<long> { 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 
                                                 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001 };

            valid.ForEach(x =>
            {
                long sq = x*x;
                if (sq >= A && sq <= B) C++;
            });

            return C.ToString();
        }

        private static bool isPalindrome(long l)
        {
            char[] ca = l.ToString().ToArray();
            Array.Reverse(ca);
            return (l.ToString() == new string(ca));
        }
    }

    class ProblemC
    {
        public ProblemC(StreamReader sr)
        {
            using (StreamWriter sw = new StreamWriter("outputC.txt"))
                Convert.ToInt32(sr.ReadLine().Trim()).Times(i =>
                {
                    var output = String.Format("Case #{0}: {1}", i + 1, FairAndSquare.Result(sr));
                    Console.Out.WriteLine(output);
                    sw.WriteLine(output);
                });
        }
    }
}
