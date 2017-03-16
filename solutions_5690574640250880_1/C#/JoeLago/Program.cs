using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Template
{
    class Program
    {
        static String runCase(StreamReader inputReader)
        {
            int[] numbers = inputReader.ReadLine().Split(' ').Select(n => Convert.ToInt32(n)).ToArray();

            int height = numbers[0];
            int width = numbers[1];
            int mines = numbers[2];
            int spaces = height * width - mines;

            bool isOddPair = (width == 2 || height == 2) && (spaces % 2 == 1);
            bool isImpossibleLargeGrid = (width > 1 && height > 1) 
                && (spaces == 2 || spaces == 3 || spaces == 5 || spaces == 7);

            if ((spaces > 1 && (isOddPair || isImpossibleLargeGrid)) || spaces < 1)
            {
                return "\nImpossible";
            }

            String[][] grid = new String[height][];
            int drawToColumn = -1;

            if (height == 2)
            {
                drawToColumn = mines / 2 - 1;
            }

            for (int row = 0; row < height; row++)
            {
                grid[row] = new String[width];

                for (int column = 0; column < width; column++)
                {
                    if (column == width - 1 && row == height - 1)
                    {
                        grid[row][column] = "c";
                    }
                    else if (mines > 0)
                    {
                        if (spaces == 1 
                            || (drawToColumn >= 0 && column <= drawToColumn))
                        {
                            grid[row][column] = "*";
                            mines--;
                        }
                        else if (drawToColumn >= 0 && column > drawToColumn)
                        {
                            grid[row][column] = ".";
                        }
                        else if (height - row == 3
                            && (mines == column * 2 || mines + 1 == column * 2))
                        {
                            if (mines % 2 == 1)
                            {
                                grid[row][column] = "*";
                                mines--;
                            }
                            else
                            {
                                grid[row][column] = ".";
                            }

                            drawToColumn = mines / 2 - 1;
                        }
                        else if (width - column - 1 == mines 
                            && height - row == mines)
                        {
                            grid[row][column] = "*";
                            mines--;
                            drawToColumn = 0;
                        }
                        else if (width - column == 3 && mines == 2)
                        {
                            grid[row][column] = "*";
                            mines--;
                            grid[row][++column] = ".";
                            grid[row][++column] = ".";
                        }
                        else if (height - row == 2 && mines == column + 2)
                        {
                            grid[row][column] = "*";
                            drawToColumn = column;
                        }
                        else
                        {
                            grid[row][column] = "*";
                            mines--;
                        }
                    }
                    else
                    {
                        grid[row][column] = ".";
                    }
                }
            }

            String gridOutput = "\n";
            for (int row = 0; row < height; row++)
            {
                for (int column = 0; column < width; column++)
                {
                    gridOutput += grid[row][column];
                }

                if (row != height - 1)
                {
                    gridOutput += "\n";
                }
            }

            return gridOutput;
        }

        //static String fileName = "practice";
        static String fileName = "C-large";
        static String folderName = "2014QC";

        static String pathToFiles = "../../../../io/";
        static String inputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".in";
        static String outputFileName = pathToFiles + "\\" + folderName + "\\" + fileName + ".out";

        static void Main(string[] args)
        {
            File.WriteAllText(outputFileName, string.Empty);
            using (StreamWriter outputFile = new StreamWriter(outputFileName))
            {
                using (StreamReader inputReader = new StreamReader(inputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = runCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ":" + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
