using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Dijkstra
    {
        public static void Run(CodeJamHelper helper)
        {
            var numTestCases = helper.ReadLineInt32();
            foreach (var n in Enumerable.Range(1, numTestCases))
            {
                var parts = helper.ReadInt32Array();
                var L = parts[0];
                var X = parts[1];
                var repeated = helper.ReadLine();

                var canSolve = Solve(repeated, X);

                helper.OutputCase(canSolve ? "YES" : "NO");
            }
        }

        //1, i, j, k, -1, -i, -j, -k
        //0, 1, 2, 3,  4,  5,  6,  7
        private static byte[][] _product = new byte[][]
        {            
            new byte[] { 0, 1, 2, 3, 4, 5, 6, 7 },
            new byte[] { 1, 4, 3, 6, 5, 0, 7, 2 },
            new byte[] { 2, 7, 4, 1, 6, 3, 0, 5 },
            new byte[] { 3, 2, 5, 4, 7, 6, 1, 0 },
            new byte[] { 4, 5, 6, 7, 0, 1, 2, 3, },
            new byte[] { 5, 0, 7, 2, 1, 4, 3, 6,},
            new byte[] { 6, 3, 0, 5, 2, 7, 4, 1, },
            new byte[] { 7, 6, 1, 0, 3, 2, 5, 4, },
        };

        public static bool Solve(string repeated, int X)
        {
            var longString = string.Concat(Enumerable.Repeat(repeated, X));

            bool metTargetOnce = false;
            bool metTargetTwice = false;
            bool doneChecking = false;
            byte target = 1;

            byte current = 0;  //1

            foreach(var c in longString)
            {
                current = _product[current][c - 'h'];
                if(!doneChecking && current == target)
                {
                    if(metTargetOnce)
                    {
                        metTargetTwice = true;
                        doneChecking = true;
                    }
                    else
                    {
                        metTargetOnce = true;
                        target = 3;  //Now looking for "ij" = k
                    }
                }
            }

            //As we run through the string, we should encounter "i" and then "ij" = k, and the final product should be "ijk" = -1
            return current == 4 && metTargetOnce && metTargetTwice;
        }

        public static byte Multiply(string s)
        {
            byte current = 0;  //1

            foreach(var c in s)
            {
                current = _product[current][c - 'h'];
            }

            return current;
        }


    }
}