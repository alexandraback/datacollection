using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    public class Point: IComparable
    {
        public int x, y;
        
        public int Dist()
        {
            return x + y;
        }
        public int CompareTo(object obj)
        {
            Point outP = (Point)obj;
            /*if (this.Dist() < outP.Dist()) return -1;
            else
                if (this.Dist() > outP.Dist()) return 1; else*/
            if (x < outP.x) return -1; else
            if (x > outP.x) return 1; else
            if (y < outP.y) return -1; else
            if (y > outP.y) return 1; else
            return 0;
        }
    }

    public class Solver
    {
        bool hasAnswer;
        int R, C, M, OldM;
        int[,] Map = new int[60,60];

        public void Run()
        {
            using (FileStream input = new FileStream("C-small-attempt3.in", FileMode.Open))
            using (FileStream output = new FileStream("small_output.txt", FileMode.Create))
            //using (FileStream input = new FileStream("input.txt", FileMode.Open))
            //using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask();
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private void SolveTask()
        {
            hasAnswer = true;
            List<Point> allPoints = new List<Point>();
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C;j++ )
                {
                    Map[i, j] = 0;
                }

            for (int i = 2; i < R; i++)
                for (int j = 2; j < C; j++)
                {
                    allPoints.Add(new Point() { x = i, y = j });                    
                }
            allPoints.Sort();
            int minDist = 2;
            for (int i = allPoints.Count - 1; i >= 0 && M > 0; i--)
            {
                Point p = allPoints[i];
                if (p.Dist() > minDist)
                {
                    M--;
                    Map[p.x, p.y] = 1;
                }
                else
                    if (p.Dist() == minDist && (p.x != 1 || p.y != 1))
                    {
                        M--;
                        Map[p.x, p.y] = 1;
                    }
            }
            //Last 2 rows and 2 columns
            if (M>0)
            {
                for (int i = C - 1; i > 2 && M > 0; i--)
                {
                    if (R == 1)
                    {
                        Map[0, i] = 1;
                        M--;
                    }
                    else
                    {
                        if (M > 1)
                        {
                            Map[0, i] = Map[1, i] = 1;
                            M -= 2;
                        }
                        else
                        {
                            if (R >= 3 && C >= 3 && Map[2, 2] == 1)
                            {
                                Map[2, 2] = 0;
                                Map[0, i] = Map[1, i] = 1;
                                M = 0;
                            }
                        }

                    }
                }
                for (int i = R - 1; i > 2 && M > 0; i--)
                {
                    if (C == 1)
                    {
                        Map[i, 0] = 1;
                        M--;
                    }
                    else
                    {
                        if (M > 1)
                        {
                            Map[i, 0] = Map[i, 1] = 1;
                            M -= 2;
                        }
                        else
                        {
                            if (R >= 3 && C >= 3 && Map[2, 2] == 1)
                            {
                                Map[2, 2] = 0;
                                Map[i, 0] = Map[i, 1] = 1;
                                M = 0;
                            }
                        }

                    }
                }
            }
            if (M > 0)
            {
                if (C >= 3)
                {
                    if (R == 1)
                    {
                        Map[0, 2] = 1;
                        M--;
                    }
                    else
                    {
                        if (M>1)
                        {
                            Map[0, 2] = Map[1, 2] = 1;
                            M -= 2;
                        }
                    }
                }
            }
            if (M > 0)
            {
                if (R >= 3)
                {
                    if (C == 1)
                    {
                        Map[2, 0] = 1;
                        M--;
                    }
                    else
                    {
                        if (M > 1)
                        {
                            Map[2, 0] = Map[2, 1] = 1;
                            M -= 2;
                        }
                    }
                }
            }
            if (M>0)
            {
                if (R==1 && C>=1)
                {
                    Map[0, 1] = 1;
                    M--;
                }
                if (R >= 1 && C == 1)
                {
                    Map[1, 0] = 1;
                    M--;
                }
                if (R>=1 && C>=1 && M>=3)
                {
                    Map[0, 1] = Map[1, 1] = Map[1, 0] = 1;
                    M -= 3;
                }
            }
            if (M>0)
            {
                hasAnswer = false;
            }            
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}:", testNum));
            //writer.WriteLine(R + " " + C + " " + OldM);
            if (hasAnswer)
            {
                WriteMap(writer);
            }
            else
            {
                writer.WriteLine("Impossible");
                //WriteMap(writer);
                //writer.WriteLine("Left " + M.ToString());
            }
            //writer.WriteLine();
        }

        private void WriteMap(StreamWriter writer)
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        writer.Write('c');
                    }
                    else
                        if (Map[i, j] == 1)
                        {
                            writer.Write('*');
                        }
                        else
                        {
                            writer.Write('.');
                        }
                }
                writer.WriteLine();
            }
        }

        private void ReadInput(StreamReader reader)
        {
            string[] input = reader.ReadLine().Split(' ');
            R = Int32.Parse(input[0]);
            C = Int32.Parse(input[1]);
            M = Int32.Parse(input[2]);
            OldM = M;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
