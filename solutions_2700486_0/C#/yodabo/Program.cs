using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    class Program
    {
        static UInt64 GetIndexOnOuterEdge(Int64 X, UInt64 Y)
        {
            return Y;
        }

        static bool IsInTriangle(UInt64 nInner, Int64 X, UInt64 Y)
        {
            return nInner >= ((UInt64)(Math.Max(X, -X))) + Y;
        }

        static bool IsInLongEdge(UInt64 nOuter, UInt64 nInner, UInt64 nLevel)
        {
            return (nLevel + nInner + 1 < nOuter);
        }

        static double nPr(UInt64 N, UInt64 R)
        {
            double ret = 1;
            for (UInt64 n = N; n > R; --n) // todo: might want to optimize this
            {
                ret *= n;
            }
            return ret;
        }



        static double nProbRight(UInt64 R, UInt64 N, Int64 Ml, Int64 Mr)
        {
            if (R == 0)
                return 1;
            if (N == 0)
                return 0;
            if (Ml == 0 && Mr == 0)
                return 0;
            if (Ml == 0)
                return nProbRight(R - 1, N - 1, Ml, Mr - 1); // went right
            if (Mr == 0)
                return nProbRight(R, N - 1, Ml - 1, Mr); // went left
            return 0.5 * nProbRight(R, N - 1, Ml - 1, Mr) + 0.5 * nProbRight(R - 1, N - 1, Ml, Mr - 1);
            //returns probability that exactly i when to the right
            // this only works in some cases...
            //if (nOuter < nInner)
            //    return nPr(nOuter, i) / Math.Pow(2, nOuter);
            
            //return 0;
        }

        static double NProb(UInt64 nOuter, UInt64 nInner, UInt64 nLevel)
        {
            nLevel++; // 0-indexed, but for the math we want 1-indexed
            double ret = 0;
            
            // return probability that at least nLevel went to the right
            // this is sum of probabilities that exactly i when to the right for i >= nLevel
            //for (UInt64 i = nLevel; i <= nOuter; ++i)
            //{
            //    ret += nProbRight(i, nOuter, 1+(Int64)nInner, 1+(Int64)nInner);
            //}
            ret = nProbRight(nLevel, nOuter, 1 + (Int64)nInner, 1 + (Int64)nInner);
            return ret;
        }

        static double Solve(UInt64 N, Int64 X, UInt64 Y)
        {
            // Diamonds start at 0,Y, then fall

            // first eliminate filled inner triangles (if N > 6, inner triangle of side 3 will be filled with prob. 1).  This is true for odd-sided triangular numbers.
            // find largest nInner such that nInner * (nInner+1)/2 is less than N, nInner is odd
            UInt64 NOuter = N;
            UInt64 nInner = 1;
            for (nInner = 1; nInner * (nInner + 1) / 2 <= N; nInner += 2)
            {}
            nInner-=2;
            NOuter = N - nInner;

            // if X/Y are in the filled inner triangle, done
            if (IsInTriangle(nInner, X, Y))
            {
                return 1;
            }

            UInt64 nIndex = GetIndexOnOuterEdge(X, Y);

            // if we are close to having this filled in (ie - forced to have X/Y), done
            if (IsInLongEdge(NOuter, nInner, nIndex)) // todo: wrong constraint
            {
                return 1;
            }

            return NProb(NOuter, nInner, nIndex);
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                // read input...
                String[] line = Console.ReadLine().Trim(' ').Split(' ');
                UInt64 N = UInt64.Parse(line[0]);
                Int64 X = Int64.Parse(line[1]);
                UInt64 Y = UInt64.Parse(line[2]);
                
                Console.WriteLine("Case #{0}: {1}", 1 + i, Solve(N, X, Y));
            }
        }
    }
}
