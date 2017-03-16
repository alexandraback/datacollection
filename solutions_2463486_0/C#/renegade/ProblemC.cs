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
            long A, B, C=0;
            var fragments = sr.ReadLine().Trim().Split();
            A = Convert.ToInt64(fragments[0]);
            B = Convert.ToInt64(fragments[1]);
            long i = (long)Math.Floor(Math.Sqrt(A));

            var valid = new List<long>{ 1, 4, 9, 121, 484 };
            valid.ForEach(x => {
                if (x >= A && x <= B) C++;
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
