using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ":");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            string[] parts = input.ReadLine().Split(' ');
            int y = int.Parse(parts[0]);
            int x = int.Parse(parts[1]);
            int mines = int.Parse(parts[2]);
            int spaces = (x * y) - mines;

            output.WriteLine();
            //output.WriteLine(x.ToString() + ", " + y.ToString() + " - " + mines.ToString());

            switch (spaces)
            {
                case 0:
                    output.WriteLine("Impossible");
                    break;
                case 1:
                    WriteDots(output, x, 1, true);
                    while (--y > 0)
                    {
                        WriteDots(output, x, 0, false);
                    }
                    break;
                case 2:
                case 3:
                case 5:
                case 7:
                    if (x > 1 && y > 1)
                    {
                        output.WriteLine("Impossible");
                    }
                    else
                    {
                        if (x > 1)
                        {
                            WriteDots(output, x, spaces, true);
                        }
                        else
                        {
                            output.WriteLine("c");
                            for (int index = 1; index < spaces; index++)
                            {
                                output.WriteLine(".");
                            }
                            for (int index = spaces; index < y; index++)
                            {
                                output.WriteLine("*");
                            }
                        }
                    }
                    break;
                default:
                    if (y == 1)
                    {
                        WriteDots(output, x, spaces, true);
                    }
                    else
                    {
                        if (x == 2 || y == 2)
                        {
                            if ((spaces & 1) != 0)
                            {
                                output.WriteLine("Impossible");
                            }
                            else
                            {
                                if (x == 2)
                                {
                                    int total = mines + spaces;
                                    WriteDots(output, x, x, true);
                                    spaces -= 2;

                                    for (int index = 1; index < y; index++)
                                    {
                                        if (spaces > 0)
                                        {
                                            WriteDots(output, x, x, false);
                                        }
                                        else
                                        {
                                            WriteDots(output, x, 0, false);
                                        }
                                        spaces -= 2;
                                    }
                                }
                                else
                                {
                                    int spacesInLine = x - (mines / y);
                                    WriteDots(output, x, spacesInLine, true);
                                    while (--y > 0)
                                    {
                                        WriteDots(output, x, spacesInLine, false);
                                    }
                                }
                            }
                        }
                        else
                        {
                            if ((spaces < x * 2) && (y > 2))
                            {
                                int thirdLine = 0;
                                if ((spaces & 1) != 0)
                                {
                                    thirdLine = 3;
                                    spaces -= 3;
                                }
                                WriteDots(output, x, (spaces / 2), true);
                                WriteDots(output, x, (spaces / 2), false);
                                WriteDots(output, x, thirdLine, false);
                                y -= 3;
                                while (y > 0)
                                {
                                    WriteDots(output, x, 0, false);
                                    y--;
                                }
                            }
                            else
                            {
                                int remainder;
                                int lines = Math.DivRem(spaces, x, out remainder);
                                if ((lines == y - 1) && remainder == 1)
                                {
                                    int spacesPerRow = Math.DivRem(spaces, y, out remainder);
                                    if (remainder == 0)
                                    {
                                        WriteDots(output, x, spacesPerRow, true);
                                        for (int index = 1; index < y; index++)
                                        {
                                            WriteDots(output, x, spacesPerRow, false);
                                        }
                                    }
                                    else
                                    {
                                        if (remainder == 1)
                                        {
                                            if (spacesPerRow < 3)
                                            {
                                                output.WriteLine("Impossible");
                                            }
                                            else
                                            {
                                                WriteDots(output, x, spacesPerRow + 1, true);
                                                WriteDots(output, x, spacesPerRow + 1, false);
                                                y -= 2;
                                                while (y > 1)
                                                {
                                                    WriteDots(output, x, spacesPerRow, false);
                                                    y--;
                                                }
                                                WriteDots(output, x, spacesPerRow - 1, false);
                                            }
                                        }
                                        else
                                        {
                                            WriteDots(output, x, spacesPerRow + 1, true);
                                            while (remainder > 1)
                                            {
                                                WriteDots(output, x, spacesPerRow + 1, false);
                                                remainder--;
                                                y--;
                                            }
                                            while (y > 1)
                                            {
                                                WriteDots(output, x, spacesPerRow, false);
                                                y--;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (lines == 2 && remainder == 1)
                                    {
                                        WriteDots(output, x, x - 1, true);
                                        WriteDots(output, x, x - 1, false);
                                        WriteDots(output, x, 3, false);
                                        y -= 3;
                                        while (y > 0)
                                        {
                                            WriteDots(output, x, 0, false);
                                            y--;
                                        }
                                    }
                                    else
                                    {
                                        WriteDots(output, x, x, true);
                                        y--;
                                        lines -= 1;
                                        while (lines > 1)
                                        {
                                            WriteDots(output, x, x, false);
                                            y--;
                                            lines -= 1;
                                        }
                                        if (remainder == 1)
                                        {
                                            WriteDots(output, x, x - 1, false);
                                            y--;
                                            WriteDots(output, x, remainder + 1, false);
                                            y--;
                                        }
                                        else
                                        {
                                            WriteDots(output, x, x, false);
                                            y--;
                                            if (y > 0)
                                            {
                                                WriteDots(output, x, remainder, false);
                                                y--;
                                            }
                                        }
                                        while (y > 0)
                                        {
                                            WriteDots(output, x, 0, false);
                                            y--;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
            }
            
        }

        private static void WriteDots(TextWriter output, int lineLength, int spaces, bool firstLine)
        {
            if (firstLine)
            {
                output.Write("c");
            }
            else
            {
                if (spaces > 0)
                {
                    output.Write(".");
                }
                else
                {
                    output.Write("*");
                    lineLength--;
                }
            }
            for (int index = 1; index < spaces; index++)
            {
                output.Write(".");
            }
            for (int index = spaces; index < lineLength; index++)
            {
                output.Write("*");
            }
            output.WriteLine();
        }
    }
}
