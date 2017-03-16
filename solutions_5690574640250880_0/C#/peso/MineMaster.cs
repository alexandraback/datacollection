using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MineMaster
{
    class MineMaster
    {
        static int M; // Mines that should be in the grid
        static int R, C; // Dimensions of the grid
        static char[,] g; // The grid we work on
        static bool transposed;

        static void Fill(int r1, int c1, int r2, int c2, char v)
        {
            for (int r= r1; r<r2; r++) 
                for (int c=c1; c<c2; c++) 
                    g[r,c] = v;
        }
        // Expand current cell, and if no mines are next to it, expand all neighbours as well
        // Return number of cells that are revealed
        static int ExpandFill(int r0, int c0, char[,] g) {
            g[r0, c0] = 'c';
            var dxy = new int[8, 2] { { 0, 1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
            int revealed = 1; int mines = 0;
            for (var i = 0; i<8; i++) {
                int r = r0+dxy[i,0]; int c=c0+dxy[i,1];
                if (r<0 || r>=R || c<0 || c>=C) continue;
                if (g[r,c] == '*') {
                    mines ++;
                }
            }
            // If no mines next to me, expand more cells
            if (mines == 0) {
                // Collect fill count from neighbours
                for (var i = 0; i<8; i++)
                {
                    int r = r0 + dxy[i, 0]; int c = c0 + dxy[i, 1];
                    if (r<0 || r>=R || c<0 || c>=C) continue;
                    if (g[r,c] == '.') {
                        revealed += ExpandFill(r,c,g);
                    }
                }
            }
            return revealed;
        }
        
        static void Transpose() {
            char[,] g_t = new char[C,R];
            for (int r=0; r<R; r++)
                for (int c=0; c<C; c++) 
                    g_t[c,r] = g[r,c];
            var tmp = C; C=R; R=tmp;
            g = g_t;
            transposed = ! transposed;
        }

        // Verify that the current solution is valid
        static bool Verify() {
            // Verify number of mines
            int count_M = 0;
            for (int r=0; r<R; r++)
                for (int c=0; c<C; c++) 
                    if (g[r,c] == '*') count_M ++;
            if (count_M != M) 
                return false;

            // Locate starting point
            char[,] t = new char[R,C];
            int cr=-1,cc=-1;
            for (int r=0; r<R; r++)
                for (int c=0; c<C; c++) { 
                    if (g[r,c] == 'c') { cr=r; cc=c; }
                    t[r,c] = g[r,c];
                }
            if (cr==-1) 
                return false;

            // Verify fill-property
            int revealed = ExpandFill(cr,cc, t);
            if (revealed + M != R*C)
                return false;

            // No more checks
            return true;
        }

        /// <summary>
        /// Generate a solution in the subsection of the grid specified. If you call it on a subset of g, the remaining part must be filled
        /// with mines. The function will fill mines from the bottom and from the right.
        /// </summary>
        /// <param name="R">Top-most rows to use</param>
        /// <param name="C">Left-most columns to use</param>
        /// <param name="M">Mines to place</param>
        /// <param name="g">Grid to place mines in - and initial click-marker</param>
        static void GenerateSolution(int R, int C, int M) {
            int F = R * C - M; // Empty cells


            if (F == 0)
            {
                g = null;
            }
            else if (F == 1)
            {
                Fill(0,0, R,C, '*');
                g[0, 0] = 'c';
            }
            else if (C == 1)
            {
                Fill(F, 0, R, C, '*');
                g[0, 0] = 'c';
            }
            else if ((C == 2) && ((F % 2 == 1) || F==2))
            {
                g = null;
            }
            else if (C == 2)
            {
                Fill(F / 2, 0, R, C, '*');
                g[0, 0] = 'c';
            }
            else if (C >= 3 && (F==7 || F==5 || F<=3))
            {
                g = null;
            }
            else if (C == 3)
            {
                var fillRow = R - (M / 3); // First of bottom rows to fill completely
                Fill(fillRow, 0, R, C, '*');
                var ml = M - 3 * (M / 3);
                Fill(fillRow - ml, C - 1, fillRow, C, '*');
                g[0, 0] = 'c';
            }
            else 
            {
                // at least 4 colums
                // at least 4 rows (because R>=C by transposition trick)
                // F >= 8
                // --> strategy is to fill until we have a 3 col problem

                var minesLeft = M;

                // Fill columns from right
                var fillCol = C - (M / R);
                if (fillCol < 3) fillCol = 3;
                Fill(0, fillCol, R, C, '*');
                minesLeft -= (C - fillCol) * R;
                
                // Recurse, if we have a width-3 area left
                if (fillCol == 3)
                {
                    GenerateSolution(R, fillCol, minesLeft);
                    return;
                }

                System.Diagnostics.Debug.Assert(fillCol > 3);

                // Fill rows from bottom (don't fill right side again)
                var fillRow = R - (minesLeft / fillCol);
                if (fillRow < 3) fillRow = 3;
                Fill(fillRow, 0, R, fillCol, '*');
                minesLeft -= (R - fillRow) * fillCol;

                // Fill remaining from bottom right corner
                var fillPair = minesLeft / 2;
                Fill(fillRow-2, fillCol-fillPair, fillRow, fillCol, '*');
                minesLeft -= fillPair * 2;

                // Fill last cell if needed
                if (minesLeft == 1) {
                    g[fillRow-1, fillCol-fillPair-1] = '*';
                    minesLeft--;
                }
                System.Diagnostics.Debug.Assert(minesLeft == 0);

                // Click here
                g[0, 0] = 'c';
            }
        }

        static void Main(string[] args)
        {
            using (var rd = File.OpenText(args[0]))
            using (var wr = File.CreateText(args[1]))
            {
                int t = int.Parse(rd.ReadLine()); // test cases

                for (int i = 1; i <= t; i++)
                {
                    Console.WriteLine("Processing case #{0}", i);
                    wr.WriteLine("Case #{0}:", i);
                    string[] s = rd.ReadLine().Split(' ');
                    R = int.Parse(s[0]); // 1 .. 50
                    C = int.Parse(s[1]); // 1 .. 50
                    M = int.Parse(s[2]); // 0 .. R*C-1
                    Console.WriteLine("  {0}x{1} fill with {2} mines", R,C,M);

                    g = new char[R, C];
                    Fill(0, 0, R, C, '.');
                    transposed = false;

                    // Only write code to handle case where R>=C .. we transpose back when we are done
                    if (C>R) Transpose();

                    GenerateSolution(R,C,M);

                    //
                    // Print solution
                    //
                    if (g == null) {
                        Console.WriteLine("  Impossible");
                        wr.WriteLine("Impossible");
                    }
                    else {
                        if (transposed) Transpose(); // Get back to original layout
                        bool resultCorrect = Verify();
                        string msg = "OK";
                        if (!resultCorrect) msg = "Verification failed";
                        Console.WriteLine("  {0}", msg);
                        for (int r = 0; r < R; r++)
                        {
                            for (int c = 0; c < C; c++)
                            {
                                wr.Write(g[r, c]);
                            }
                            wr.WriteLine();
                        }
                    }
                }
            }
        }
    }
}
