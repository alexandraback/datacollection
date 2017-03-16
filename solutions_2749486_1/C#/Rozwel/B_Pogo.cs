using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2013_R1C
{
    class B_Pogo : ProblemBase
    {
        //List<int> HopDistance;
        //public override void ProcessInput(TextReader inputStream)
        //{
        //    int Range = 1000;
        //    HopDistance = new List<int>(Range);
        //    HopDistance[0] = 0;
        //    for (int I = 1; I < Range; I++)
        //    {
        //        HopDistance[I] = HopDistance[I - 1] + I;
        //    }
        //    base.ProcessInput(inputStream);
        //}

        protected override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        protected class TestCase : TestCaseBase
        {
            string Line;
            public TestCase(TextReader inputStream)
            {
                Line = inputStream.ReadLine();
            }
            int TargX;
            int TargY;
            int CurX = 0;
            int CurY = 0;
            int DistX { get { return TargX - CurX; } }
            int DistY { get { return TargY - CurY; } }
            int AbsDistX { get { return Math.Abs(DistX); } }
            int AbsDistY { get { return Math.Abs(DistY); } }
            char DirY { get { return DistY > 0 ? 'N' : 'S'; } }
            char DirX { get { return DistX > 0 ? 'E' : 'W'; } }

            protected override void Solve(CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                string[] Values = Line.Split();
                TargX = int.Parse(Values[0]);
                TargY = int.Parse(Values[1]);

                int Move = 0;
                int Limit = 500;
                StringBuilder Moves = new StringBuilder();
                while ((Limit == 0 || Move < Limit) && (DistX != 0 || DistY != 0))
                {
                    token.ThrowIfCancellationRequested();
                    Move++;
                    if (Move == AbsDistX)
                    {//Move to X
                        if (DirX == 'E')
                        {
                            CurX += Move;
                            Moves.Append('E');
                        }
                        else
                        {
                            CurX -= Move;
                            Moves.Append('W');
                        }
                    }
                    else if (Move == AbsDistY)
                    {//Move to Y
                        if (DirY == 'N')
                        {
                            CurY += Move;
                            Moves.Append('N');
                        }
                        else
                        {
                            CurY -= Move;
                            Moves.Append('S');
                        }
                    }
                    else if (DistX == 0 || AbsDistX > AbsDistY)
                    {//move Y
                        if (AbsDistY > Move)
                        {
                            if (DirY == 'N')
                            {
                                CurY += Move;
                                Moves.Append('N');
                            }
                            else
                            {
                                CurY -= Move;
                                Moves.Append('S');
                            }

                        }
                        else
                        {
                            if (DirY == 'N')
                            {
                                CurY -= Move;
                                Moves.Append('S');
                            }
                            else
                            {
                                CurY += Move;
                                Moves.Append('N');
                            }
                        }
                    }
                    else
                    {// move X
                        if (AbsDistX > Move)
                        {
                            if (DirX == 'E')
                            {
                                CurX += Move;
                                Moves.Append('E');
                            }
                            else
                            {
                                CurX -= Move;
                                Moves.Append('W');
                            }

                        }
                        else
                        {
                            if (DirX == 'E')
                            {
                                CurX -= Move;
                                Moves.Append('W');
                            }
                            else
                            {
                                CurX += Move;
                                Moves.Append('E');
                            }
                        }
                    }
                }
                Result = Moves.ToString();
            }
        }
    }
}
