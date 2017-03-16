using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R0C_MinesweeperMaster
    {
        bool logEnabled = false;
        static string baseFileName = "C-large";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        private static class Cell
        {
            public const char Mine = '*';
            public const char Empty = '.';
            public const char Clicked = 'c';
        }

        private int R { get; set; }
        private int C { get; set; }
        private int M { get; set; }
        private int Empty { get; set; }

        private bool Transposed { get; set; }
        private bool Possible { get; set; }

        private string Result { get; set; }
        
        private char[][] Grid { get; set; }
        private int ClickedRow { get; set; }
        private int ClickedColumn { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };

            string[] s = reader.ReadLine().Split(sep);
            R = Int32.Parse(s[0]);
            C = Int32.Parse(s[1]);
            M = Int32.Parse(s[2]);

            Empty = (R * C) - M;
        }

        private void Solve()
        {
            // Prepare grid
            if (R > C)
            {
                int temp = R;
                R = C;
                C = temp;
                Transposed = true;
            }
            else
            {
                Transposed = false;
            }
            Grid = new char[R][];
            for (int i = 0; i < R; i++)
            {
                Grid[i] = new char[C];
                for (int j = 0; j < C; j++)
                {
                    Grid[i][j] = Cell.Empty;
                }
            }

            // Solve
            if ((Empty == 1) || (M == 0))
            {
                if (Empty == 1)
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            Grid[i][j] = Cell.Mine;
                        }
                    }
                }
                Grid[0][0] = Cell.Clicked;
                Possible = true;
            }
            else if (R == 1)
            {
                Grid[0][0] = Cell.Clicked;
                for (int j = Empty; j < C; j++)
                {
                    Grid[0][j] = Cell.Mine;
                }
                Possible = true;
            }
            else if (R == 2)
            {
                if ((Empty >= 4) && (Empty % 2 == 0))
                {
                    int emptyCols = Empty / 2;
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = emptyCols; j < C; j++)
                        {
                            Grid[i][j] = Cell.Mine;
                        }
                    }
                    Grid[0][0] = Cell.Clicked;
                    Possible = true;
                }
                else
                {
                    Possible = false;
                }
            }
            else if (Empty <= 9)
            {
                if ((Empty == 4) || (Empty == 6))
                {
                    int emptyCols = Empty / 2;
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            if ((i < 2) && (j < emptyCols))
                            {
                                Grid[i][j] = Cell.Empty;
                            }
                            else
                            {
                                Grid[i][j] = Cell.Mine;
                            }
                        }
                    }
                    Grid[0][0] = Cell.Clicked;
                    Possible = true;
                }
                else if (Empty >= 8)
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            if ((i < 3) && (j < 3))
                            {
                                Grid[i][j] = Cell.Empty;
                            }
                            else
                            {
                                Grid[i][j] = Cell.Mine;
                            }
                        }
                    }
                    if (Empty == 8)
                    {
                        Grid[2][2] = Cell.Mine;
                    }
                    Grid[0][0] = Cell.Clicked;
                    Possible = true;
                }
                else
                {
                    Possible = false;
                }
            }
            else if (Empty <= 11)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if ((i < 3) && (j < 4))
                        {
                            Grid[i][j] = Cell.Empty;
                        }
                        else
                        {
                            Grid[i][j] = Cell.Mine;
                        }
                    }
                }
                Grid[2][3] = Cell.Mine;
                if (Empty == 10)
                {
                    Grid[2][2] = Cell.Mine;
                }
                Grid[0][0] = Cell.Clicked;
                Possible = true;
            }
            else
            {
                int tempR = R;
                int tempC = C;
                int tempM = M;

                while (tempM >= Math.Min(tempR, tempC))
                {
                    if (tempR < tempC)
                    {
                        for (int i = 0; i < tempR; i++)
                        {
                            Grid[i][tempC - 1] = Cell.Mine;
                            tempM--;
                        }
                        tempC--;
                    }
                    else
                    {
                        for (int j = 0; j < tempC; j++)
                        {
                            Grid[tempR - 1][j] = Cell.Mine;
                            tempM--;
                        }
                        tempR--;
                    }
                }

                int leftover1 = tempM / 2;
                int leftover2 = tempM - leftover1;

                for (int i = 1; i <= leftover2; i++)
                {
                    Grid[tempR - i][tempC - 1] = Cell.Mine;
                }
                for (int i = 1; i <= leftover1; i++)
                {
                    Grid[tempR - i][tempC - 2] = Cell.Mine;
                }

                Grid[0][0] = Cell.Clicked;

                Possible = true;
            }

            // Format output
            if (Possible)
            {
                StringBuilder sb = new StringBuilder(String.Empty);
                if (Transposed)
                {
                    for (int i = 0; i < C; i++)
                    {
                        for (int j = 0; j < R; j++)
                        {
                            sb.Append(Grid[j][i]);
                        }
                        if (i < C - 1) sb.AppendLine();
                    }
                }
                else
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            sb.Append(Grid[i][j]);
                        }
                        if (i < R - 1) sb.AppendLine();
                    }
                }
                Result = sb.ToString();
            }
            else
            {
                Result = "Impossible";
            }
        }

        public R0C_MinesweeperMaster()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}:\r\n{1}", t, Result));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R0C_MinesweeperMaster();
        }
    }
}
