using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class NewLotteryGame
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var c in Enumerable.Range(1, numTestCases))
            {
                var temp = helper.ReadInt64Array();
                helper.OutputCase(Solve(temp[0], temp[1], temp[2]));
            }
        }

        //< A, < B
        public static long Solve(long A, long B, long K)
        {
            return SolveWithEquality(A - 1, B - 1, K);
        }

        
        //<= A, <= B
        public static long SolveWithEquality(long A, long B, long K)
        {
            if (K <= 0) return 0;

            if (A == 0 && B == 0)
                return 1;

            var e = FindLargestBit(A, B);

            //Optimization, all 1's in both
            var powtwo = 1L << e;
            if (A == powtwo - 1 && B == powtwo - 1)
            {
                return (1L << (2 * e)) * Math.Min(powtwo, K);
            }

            var aset = (A & powtwo) != 0;
            var bset = (B & powtwo) != 0;

            if (aset && bset)
            {
                return
                    SolveWithEquality(A - powtwo, B - powtwo, K - powtwo) +  //(1, 1)
                    SolveWithEquality(A - powtwo, powtwo - 1, K) +  //(1, 0)
                    SolveWithEquality(powtwo - 1, B - powtwo, K) +  //(0, 1)
                    SolveWithEquality(powtwo - 1, powtwo - 1, K);   //(0, 1)
            }
            else if (aset)
            {
                return
                    SolveWithEquality(A - powtwo, B, K) + //1
                    SolveWithEquality(powtwo - 1, B, K); //0
            }
            else if (bset)
            {
                return
                    SolveWithEquality(A, B - powtwo, K) + //1
                    SolveWithEquality(A, powtwo - 1, K); //0
            }
            throw new ArgumentException();
        }

        public static int FindLargestBit(long A, long B)
        {
            //Find the largest bit that's set
            int e = 0;
            var powTwo = 1L;
            while (true)
            {
                if (A < powTwo && B < powTwo)
                    return e - 1;
                else
                {
                    powTwo <<= 1;
                    e += 1;
                }
            }
        }
    }
}
