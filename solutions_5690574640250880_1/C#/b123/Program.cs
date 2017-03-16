namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;

    class Program
    {
        private static NumberFormatInfo ni;

        static int Main(string[] args)
        {
            ni = (NumberFormatInfo)CultureInfo.CurrentCulture.NumberFormat.Clone();
            ni.NumberGroupSeparator = String.Empty;

            StreamWriter writer = null;
            if (args.Length < 2) { return 1; }

            try
            {
                // Attempt to open output file.
                writer = new StreamWriter(args[1]);
                // Redirect standard output from the console to the output file.
                Console.SetOut(writer);
                // Redirect standard input from the console to the input file.
                Console.SetIn(new StreamReader(args[0]));
            }
            catch (IOException e)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine(e.Message);
                return 1;
            }

            Solve();

            writer.Close();
            // Recover the standard output stream so that a  
            // completion message can be displayed.
            StreamWriter standardOutput = new StreamWriter(Console.OpenStandardOutput());
            standardOutput.AutoFlush = true;
            Console.SetOut(standardOutput);
            Console.WriteLine("Complete");
            return 0;
        }

        public static List<T> ReadLine<T>()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(s => (T)Convert.ChangeType(s, typeof(T))).ToList();
        }

        public static void Solve()
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                var line = ReadLine<int>();
                int R = line[0];
                int C = line[1];
                int M = line[2];
                int S = R * C - M; // Safe

                var Grid = new char[R][]; // Fill it up with mines.
                for (int r = 0; r < R; r++)
                {
                    Grid[r] = new char[C];
                    for (int c = 0; c < C; c++)
                    {
                        Grid[r][c] = '*';
                    }
                }
                bool possible = true;

                // Case M = 0. Always possible
                if (M == 0)
                {
                    for (int r = 0; r < R; r++)
                    {
                        for (int c = 0; c < C; c++)
                        {
                            Grid[r][c] = '.';
                        }
                    }
                }

                // Case M = RC-1. (S = 1) Always possible
                else if (M == R * C - 1)
                {
                    // Nothing needed
                }

                // Case C=1 or R=1. Always possible
                else if (C == 1 || R == 1)
                {
                    for (int s = 0; s < S; s++)
                    {
                        if (C == 1)
                        {
                            Grid[s][0] = '.';
                        }
                        else if (R == 1)
                        {
                            Grid[0][s] = '.';
                        }
                    }
                }

                // Case C=2 or R=2. Possible if M is even and S != 2
                else if (C == 2 || R == 2)
                {
                    if (M % 2 != 0 || S == 2)
                    {
                        possible = false;
                    }
                    else
                    {
                        var L = S / 2;
                        for (int l = 0; l < L; l++)
                        {
                            if (C == 2)
                            {
                                Grid[l][0] = '.';
                                Grid[l][1] = '.';
                            }
                            else if (R == 2)
                            {
                                Grid[0][l] = '.';
                                Grid[1][l] = '.';
                            }
                        }
                    }
                }

                // C and R >= 3. Possible for S = 1, 4, 6, 8, 9, 10, 11, 12, 13, ...
                else
                {
                    switch (S)
                    {
                        case 1:
                            break; // already covered above
                        case 2:
                            possible = false;
                            break;
                        case 3:
                            possible = false;
                            break;
                        case 4:
                            for (int r = 0; r < 2; r++)
                            {
                                for (int c = 0; c < 2; c++)
                                {
                                    Grid[r][c] = '.';
                                }
                            }
                            break;
                        case 5:
                            possible = false;
                            break;
                        case 6:
                            for (int r = 0; r < 2; r++)
                            {
                                for (int c = 0; c < 3; c++)
                                {
                                    Grid[r][c] = '.';
                                }
                            }
                            break;
                        case 7:
                            possible = false;
                            break;
                        default:
                            int col = 0;
                            while (S > 3 && col < C)
                            {
                                Grid[0][col] = '.';
                                Grid[1][col] = '.';
                                col++;
                                S -= 2;
                            }
                            int row = 2;
                            while (S > 1 && row < R)
                            {
                                Grid[row][0] = '.';
                                Grid[row][1] = '.';
                                row++;
                                S -= 2;
                            }
                            col = 2;
                            row = 2;
                            for (int c = col; c < C; c++)
                            {
                                for (int r = row; r < R; r++)
                                {
                                    if (S > 0)
                                    {
                                        Grid[r][c] = '.';
                                        S--;
                                    }
                                }
                            }
                            break;
                    }
                }

                Console.WriteLine("Case #{0}:", t);
                if (possible)
                {
                    Grid[0][0] = 'c';
                    for (int r = 0; r < R; r++)
                    {
                        var sb = new StringBuilder();
                        for (int c = 0; c < C; c++)
                        {
                            sb.Append(Grid[r][c]);
                        }
                        Console.WriteLine(sb);
                    }
                }
                else
                {
                    Console.WriteLine("Impossible");
                }
            }
        }
    }
}
