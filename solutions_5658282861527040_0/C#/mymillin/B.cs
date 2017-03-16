using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_PreRound
{
    class B
    {
        public B()
        {
            using (StreamWriter sw = new StreamWriter(@"D:\output.txt"))
            {
                //foreach (var r in GetCases().AsParallel().Select(t => Tuple.Create(t.Item1, Solve(t))).OrderBy(t => t.Item1))
                foreach (var r in GetCases().Select(t => Tuple.Create(t.CaseNumber, Solve(t))).OrderBy(t => t.Item1))
                {
                    Console.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                    sw.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                }
            }
        }

        IEnumerable<Input> GetCases()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\B-small-attempt0.in"))
            ///using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\B-large.in"))
            //using (StreamReader sr = new StreamReader(@"input_A.txt"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int i = 1; i <= caseCount; i++)
                {
                    var parts = sr.ReadLine().Split(' ');

                    yield return new Input()
                    {
                        CaseNumber = i,
                        A = long.Parse(parts[0]),
                        B = long.Parse(parts[1]),
                        K = long.Parse(parts[2]),
                    };
                }
            }
        }

        public class Input
        {
            public int CaseNumber { get; set; }
            public long A { get; set; }
            public long B { get; set; }
            public long K { get; set; }
        }

        public string Solve(Input input)
        {
            var A = Binary(input.A -1);
            var B = Binary(input.B -1);

            var K = Binary(input.K - 1);

            var x = SolveSub(A,B,K,63,false,false,false);
            return "" + x;
        }

        public long SolveSub(int[] A, int[] B, int[] K, int pos, bool safeA, bool safeB, bool safeK)
        {
            if (pos == -1)
            {
                return 1;
            }

            long sum = 0;

            if (A[pos] == 1 || safeA)
            {
                // A choose 1
                if (B[pos] == 1 || safeB)
                {
                    // B chhose 1
                    if (K[pos] == 1 || safeK)
                    {
                        sum += SolveSub(A, B, K, pos - 1, safeA, safeB, safeK);
                    }
                }

                // B choose 0
                sum += SolveSub(A, B, K, pos - 1, safeA, B[pos] == 1 || safeB, K[pos] == 1 || safeK);
            }

            // B chhose 1
            if (B[pos] == 1 || safeB)
            {
                sum += SolveSub(A, B, K, pos - 1, A[pos] == 1 || safeA, safeB, K[pos] == 1 || safeK);
            }

            // B choose 0
            sum += SolveSub(A, B, K, pos - 1, A[pos] == 1 || safeA, B[pos] == 1 || safeB, K[pos] == 1 || safeK);

            return sum;
        }

        static int[] Binary(long x)
        {
            var ret = new int[64];

            int pos = 0;
            while (x > 0)
            {
                ret[pos++] = (int)(x % 2);
                x = x / 2;
            }

            return ret;
        }
    }
}
