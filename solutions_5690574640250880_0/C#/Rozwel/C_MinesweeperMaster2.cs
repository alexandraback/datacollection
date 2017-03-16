using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2014_QR
{
    public class C_MinesweeperMaster2 : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            sbyte R;
            sbyte C;
            short M;

            public TestCase(TextReader inputStream)
            {
                string[] values = inputStream.ReadLine().Split(' ');

                R = sbyte.Parse(values[0]);
                C = sbyte.Parse(values[1]);
                M = short.Parse(values[2]);
            }

            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                char[,] Grid = new char[R, C];
                Result = "";
                short CellCount = (short)(R * C);
                short OpenCells = (short)(CellCount - M);

                if (OpenCells == 1)
                {
                    InitializeGrid(Grid, '*', token);
                }
                else
                {
                    InitializeGrid(Grid, '.', token);
                    short Mines = M;
                    sbyte CMax = (sbyte)(C - 1);
                    sbyte RMax = (sbyte)(R - 1);



                    if (C == 1 || R == 1)
                    {//if 1 by anything, fill it
                        for (sbyte r = RMax; r >= 0 && Mines > 0; r--)
                        {
                            for (sbyte c = CMax; c >= 0 && Mines > 0; c--)
                            {
                                Grid[r, c] = '*';
                                Mines--;
                            }
                        }
                    }
                    else if (C == 2 || R == 2)
                    {//if 2 by anything, 
                        if (Mines % 2 == 0 && OpenCells >=4 )
                        {//fill only if even number of mines, and 4 or more cells are open
                            if (C == 2)
                            {//if we have two cols, fill by rows
                                for (sbyte r = RMax; r >= 0 && Mines > 0; r--)
                                {
                                    for (sbyte c = CMax; c >= 0 && Mines > 0; c--)
                                    {
                                        Grid[r, c] = '*';
                                        Mines--;
                                    }
                                }
                            }
                            else
                            {//if more than 2 cols, fill by col
                                for (sbyte c = CMax; c >= 0 && Mines > 0; c--)
                                {
                                    for (sbyte r = RMax; r >= 0 && Mines > 0; r--)
                                    {
                                        Grid[r, c] = '*';
                                        Mines--;
                                    }
                                }
                            }
                        }
                        else
                        {//odd number of mines or less than 4 open cells is impossible in 2x? grid
                            Result = "Impossible";
                        }
                    }
                    else
                    {//grid is 3 by 3 or larger
                        for (sbyte r = RMax; r > 1 && Mines > 0; r--)
                        {
                            for (sbyte c = CMax; c >= 0 && Mines > 0; c--)
                            {
                                if (c > 1 && r > 2)
                                {//in the green zone, nothing we do here can invalidate the board, fill it
                                    Grid[r, c] = '*';
                                    Mines--;
                                }
                                else if (c <= 1 && r > 2)
                                {//in the yellow zone, may need to move to next row if we don't have enough mines to finish this one
                                    if (Mines <= c)
                                    {//we don't have enough mines to finish the row, move to the next one and reset c
                                        r--;
                                        c = CMax;
                                    }
                                    Grid[r, c] = '*';
                                    Mines--;
                                }
                                else if (c > 1 && r == 2)
                                {//in the orange zone, need to make sure we do not break the last rows, flip and fill cols instead
                                    if (Mines >= 3)
                                    {//we can fill the rest of this col
                                        Grid[0, c] = '*';
                                        Mines--;
                                        Grid[1, c] = '*';
                                        Mines--;
                                        CMax = c;
                                    }
                                    Grid[2, c] = '*';
                                    Mines--;
                                }
                                else //if (c <= 1 && r == 2)
                                {//in red zone, last 2 cells, if we can't fill both without left overs, this configuration is impossible
                                    if (Mines == c + 1)
                                    {
                                        Grid[2, c] = '*';
                                        Mines--;
                                    }
                                    else
                                    {
                                        Result = "Impossible";
                                    }
                                }
                            }
                        }
                    }
                }
                if (Result == "")
                {
                    StringBuilder result = new StringBuilder();
                    for (byte r = 0; r < R; )
                    {
                        token.ThrowIfCancellationRequested();
                        for (byte c = 0; c < C; c++)
                        {
                            token.ThrowIfCancellationRequested();
                            result.Append(Grid[r, c]);
                        }
                        r++;
                        if (R != r)
                        {
                            result.AppendLine();
                        }
                    }
                    Result = result.ToString();
                }
            }

            private void InitializeGrid(char[,] Grid, char value, System.Threading.CancellationToken token)
            {
                for (byte r = 0; r < R; r++)
                {
                    token.ThrowIfCancellationRequested();
                    for (byte c = 0; c < C; c++)
                    {
                        token.ThrowIfCancellationRequested();
                        Grid[r, c] = value;
                    }
                }
                Grid[0, 0] = 'c';
            }
        }
        protected override void WriteCase(TextWriter outputStream, int index)
        {
            outputStream.WriteLine(String.Format("Case #{0}:", index));
            outputStream.WriteLine(ProblemSet[index].Result);
        }
    }
}
