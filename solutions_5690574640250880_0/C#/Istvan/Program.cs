using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Reading input file...");
            StreamReader streamReader = new StreamReader(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem C\inputSmall.txt");
            StreamWriter streamWriter = new StreamWriter(@"D:\Work\Programming Challange\CodeJam 2014\Qualifying\Problem C\outputSmall.txt", false);
            
            string line = streamReader.ReadLine();
            int nrOfTests = 0;
            if(!int.TryParse(line, out nrOfTests))
            {
                Console.WriteLine("Number of tests is not an int!");
                return;
            }

            Console.WriteLine("Number of tests: " + nrOfTests.ToString());
            for(int i=0; i<nrOfTests;i++)
            {
                int caseNR = i+1;
                Console.WriteLine("Case #"+caseNR.ToString()+": reading input");
                line = streamReader.ReadLine();
                string[] items = line.Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries);
                if(items.Length != 3)
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": number of input parameters is not 3");
                }
                int nrRows = 0;
                int nrCols = 0;
                int nrBombs = 0;
                if(!int.TryParse(items[0], out nrRows))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": number of rows is not numeric");
                }
                if (!int.TryParse(items[1], out nrCols))
                {
                    Console.WriteLine("Case #"+caseNR.ToString()+": number of cols is not numeric");
                }
                if (!int.TryParse(items[2], out nrBombs))
                {
                    Console.WriteLine("Case #" + caseNR.ToString() + ": number of bombs is not numeric");
                }

                //process it
                Console.WriteLine("Case #" + caseNR.ToString() + ": processing input");
                int nrFreeCells = nrRows * nrCols - nrBombs;
                int renderType = 0;
                int renderNrOfCols = 0;
                int renderNrOfRows = 0;
                /* Render types:
                 * - 1 - full lines
                 * - 2 - full columns
                 * - 3 - partial rows
                 * - 4 - diagonal
                 */

                if (nrFreeCells == 1)
                {
                    renderNrOfCols = 1;
                    renderType = 1;
                }
                if (renderType == 0)
                {
                    //check if it fits for a number of fixed lines
                    if ((nrFreeCells % nrCols == 0) && (nrFreeCells / nrCols <= nrRows) && ((nrFreeCells / nrCols > 1) || nrRows == 1))
                    {
                        renderNrOfCols = nrCols;
                        renderType = 1;
                    }
                    //check if it fits for a number of fixed columns
                    if ((nrFreeCells % nrRows == 0) && (nrFreeCells / nrRows <= nrCols) && ((nrFreeCells / nrRows > 1) || nrCols == 1))
                    {
                        renderNrOfCols = nrFreeCells / nrRows;
                        renderType = 2;
                    }
                }

                //try to find the aprox area
                if (renderType == 0)
                {
                    for (int j = 2; j <= nrCols; j++)
                    {
                        if((nrFreeCells % j != 1) && (nrFreeCells / Convert.ToDecimal(j) <= nrRows) && (nrFreeCells / j >= 2))
                        {
                            renderType = 1;
                            renderNrOfCols = j;
                        }
                    }
                    if (renderType == 0)
                    {
                        for (int j = 2; j <= nrRows; j++)
                        {
                            if ((nrFreeCells % j != 1) && (nrFreeCells / Convert.ToDecimal(j) <= nrCols) && (nrFreeCells / j >= 2))
                            {
                                renderType = 3;
                                renderNrOfRows = j;
                            }
                        }
                    }
                }
                if (renderType == 0)
                {
                    //try the diagonal option
                    for (int j = 1; j <= Math.Min(nrCols, nrRows)-2; j++)
                    {
                        int tmpNrFreeCells = 0;
                        for (int z = 1; z <= Math.Min(j, nrCols); z++)
                        {
                            tmpNrFreeCells += Math.Min(nrRows, z);
                        }
                        if (tmpNrFreeCells == nrFreeCells && j > 4)
                        {
                            //found a solution
                            renderType = 4;
                            renderNrOfRows = j;
                        }
                        if (tmpNrFreeCells == nrBombs && j <= nrRows - 2 && j <= nrCols - 2)
                        {
                            renderType = 5;
                            renderNrOfRows = j;
                        }
                    }
                }
                if (renderType == 0)
                {
                    //try the small box option
                    for (int j = 1; j <= Math.Min(nrCols, nrRows) - 2; j++)
                    {
                        if (j*j == nrFreeCells)
                        {
                            //found a solution
                            renderType = 6;
                            renderNrOfRows = j;
                        }
                        if (j*j == nrBombs)
                        {
                            renderType = 7;
                            renderNrOfRows = j;
                        }
                    }
                }

                //write results
                Console.WriteLine("Case #" + caseNR.ToString() + ":");
                streamWriter.WriteLine("Case #" + caseNR + ": ");
                if (renderType == 0)
                {
                    Console.WriteLine("Impossible");
                    streamWriter.WriteLine("Impossible");
                }
                else
                {
                    //render the map
                    int renderedFreeSpaces = 0;
                    for (int x = 1; x <= nrRows; x++)
                    {
                        StringBuilder mapLine = new StringBuilder();
                        for (int y = 1; y <= nrCols; y++)
                        {
                            if (renderType == 1 || renderType == 2)
                            {
                                if (y <= renderNrOfCols && ((x - 1) * renderNrOfCols + y <= nrFreeCells))
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                }
                            }
                            if (renderType == 3/*partial rows*/)
                            {
                                if(x <= renderNrOfRows && ((y-1) * renderNrOfRows + x <= nrFreeCells))
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                }
                            }
                            if (renderType == 4 /*diagonal empty*/)
                            {
                                if(x + y < renderNrOfRows + renderNrOfRows)
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                } 
                            }
                            if (renderType == 5 /*diagonal bombs*/)
                            {
                                if (x + y <= nrRows + nrCols - renderNrOfRows)
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                }
                            }
                            if (renderType == 6 /*small box*/)
                            {
                                if (x <= renderNrOfRows && y <= renderNrOfRows)
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                }
                            }
                            if (renderType == 7 /*small box bombs*/)
                            {
                                if (x <= nrRows - renderNrOfRows || y <= nrCols - renderNrOfRows)
                                {
                                    mapLine.Append((x == 1 && y == 1) ? "c" : ".");
                                    renderedFreeSpaces++;
                                    continue;
                                }
                            }
                            mapLine.Append("*");
                        }
                        Console.WriteLine(mapLine.ToString());
                        streamWriter.WriteLine(mapLine.ToString());
                    }
                    if (renderedFreeSpaces != nrFreeCells)
                    {
                        Console.WriteLine(string.Format("RENDERED FREE CELLS ({0}) DO NOT MATCH NR OF FREE CELLS ({1})", renderedFreeSpaces, nrFreeCells));
                        throw new ApplicationException();
                    }
                }
            }
            streamReader.Close();
            streamWriter.Close();
            Console.ReadLine();
        }

    }
}
