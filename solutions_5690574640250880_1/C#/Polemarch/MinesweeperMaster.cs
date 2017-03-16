using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2008_1a
{
    class MinesweeperMaster
    {
        static void Main(string[] args)
        {
            var me = new Numbers();
            using (var helper = new CodeJamHelper('C', ProblemType.Large, 0))
            {
                var numTestCases = helper.ReadLineInt32();
                foreach (var caseNum in Enumerable.Range(1, numTestCases))
                {
                    var temp = helper.ReadInt32Array();
                    var R = temp[0];
                    var C = temp[1];
                    var M = temp[2];
                    Draw(R, C, M, Solve(R, C, M), helper);
                }
            }
        }

        public static void Draw(int R, int C, int M, bool[,] finalSolution, CodeJamHelper helper)
        {
            //If impossible
            if (finalSolution == null)
            {
                helper.OutputCase();
                helper.WriteLine("Impossible");
                return;
            }

            helper.OutputCase();

            var fR = finalSolution.GetLength(0);
            var fC = finalSolution.GetLength(1);

            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    if (r == 0 && c == 0)
                        helper.Write("c");
                    else if (r >= fR || c >= fC)
                        helper.Write("*");
                    else
                        helper.Write(finalSolution[r, c] ? "*" : ".");
                }
                helper.Write(Environment.NewLine);
            }
        }


        //We can't fill any more rows/columns.  Just have to lay out the mines.
        public static bool[,] FinalSolve(int R, int C, int M)
        {
            //0 = empty, 1 = mine, 2 = click
            var solution = new bool[R,C];
            if (M == 0) return solution;

            //Paint in mines starting from the bottom right.  Leave the first two rows and first two columns empty.
            int m = 0;
            for (int r = R - 1; r > 1; r--)
            {
                for (int c = C - 1; c > 1; c--)
                {
                    solution[r, c] = true;                    
                    m += 1;

                    if (m == M)
                    {
                        return solution;
                    }
                }
            }
            
            //No solution!  Can't place enough mines
            return null;
        }

        ///Assume all mines are at the corners and fill rows and columns
        public static bool[,] Solve(int R, int C, int M)
        {
            //Initial case -- if there's only one non-mine, just click it.
            if (R * C - M <= 1)
            {
                var rv = new bool[1, 1];
                return rv;
            }

            //One row
            if (R == 1)
            {
                var rv = new bool[R, C];
                for (int c = 0; c < C; ++c)
                {
                    rv[0, c] = c >= (C - M);
                }
                return rv;
            }

            //One column
            if (C == 1)
            {
                var rv = new bool[R, C];
                for (int r = 0; r < R; ++r)
                {
                    rv[r, 0] = r >= (R - M);
                }
                return rv;
            }

            //Recursive stuff
            return CanSolveHelper(R, C, M);
        }

        private static bool[,] CanSolveHelper(int R, int C, int M)
        {
            //If we're down to a line but it wasn't originally that way, then all squares are adjacent to mines, so there's no solution
            if (R == 1 || C == 1)
            {
                return null;
            }

            //Recurse.  Fill in a row or column to keep the candidate space as square as possible.
            if (R >= C)
            {
                if(M >= C)
                    return CanSolveHelper(R - 1, C, M - C);
            }
            else
            {
                if (M >= R)
                    return CanSolveHelper(R, C - 1, M - R);
            }

            return FinalSolve(R, C, M);
        }
    }
}
