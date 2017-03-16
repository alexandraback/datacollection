using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace QRProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "C-small-attempt9.in";
            String outputPath = path + Path.DirectorySeparatorChar + "C-small-attempt9.in.txt";
            //String inputPath = path + Path.DirectorySeparatorChar + "example.txt";
            //String outputPath = path + Path.DirectorySeparatorChar + "example.out.txt";

            StreamReader reader = new StreamReader(inputPath);
            StreamWriter writer = new StreamWriter(outputPath);

            int caseNumber = 0;
            string line = reader.ReadLine();
            caseNumber = Convert.ToInt32(line);

            for (int i = 0; i < caseNumber; ++i)
            {
                DoOneCase(i + 1, reader, writer);
            }
            reader.Close();
            writer.Close();
        }

        public static void DoOneCase(int caseNumber, StreamReader reader, StreamWriter writer)
        {
            // read colum row and mineNum
            string line = reader.ReadLine();
            string[] word = line.Split(new char[] { ' ' });
            int rowNum = Convert.ToInt32(word[0]);
            int columNum = Convert.ToInt32(word[1]);
            int mineNum = Convert.ToInt32(word[2]);
            int mN = mineNum;
            
            // create map
            char[,] map = new char[rowNum, columNum];
            
            
            for (int r = 0; r < rowNum; ++r)
            {
                for (int c = 0; c < columNum; ++c)
                {
                    map[r, c] = '.';
                }
            }

            // create wall num
            int[,] wallNum = new int[rowNum, columNum];
            UpdateWallNum(rowNum, columNum, map, wallNum);

            int minR = -1;
            int minC = -1;
            bool canMine = false;
            int clickR = rowNum - 1;
            int clickC = columNum - 1;

            //Console.Write("\n(" + mineNum + ")");
            //PrintMap(map, rowNum, columNum);
            //PrintWallNum(wallNum, rowNum, columNum);

            while (mineNum > 0)
            {
                if (mineNum == 1)
                { 
                    int a = 0;
                }
                // get min Wall num
                canMine = GetMinWallNum(rowNum, columNum, wallNum, map, ref minR, ref minC, mineNum);

                if (!canMine)
                {
                    break;
                }
                // set mine
                map[minR, minC] = '*';
                //if (hasMine(clickR, clickC, map, rowNum, columNum))
                //{
                //    break;
                //}

                mineNum--;
                // set wall
                createWall(minC, minR, map, columNum, rowNum);
                UpdateWallNum(rowNum, columNum, map, wallNum);

                //Console.Write("\n(" + mineNum + ")");
                //PrintMap(map, rowNum, columNum);
                //PrintWallNum(wallNum, rowNum, columNum);
            }


            // print map
            string result = "";
            if (mineNum > 0 || isImpossible(wallNum, rowNum, columNum))
            {
                result = "Impossible";
            }

            //writer.WriteLine("Case #" + caseNumber + ": " + (rowNum*columNum - mN) + " " + mN);
            writer.WriteLine("Case #" + caseNumber + ":");
            if (result.Length==0)
            {
                for (int r = 0; r < rowNum; ++r)
                {
                    StringBuilder sb = new StringBuilder();
                    for (int c = 0; c < columNum; ++c)
                    {
                        if (r == clickR && c == clickC)
                        {
                            sb.Append('c');
                        }
                        else
                        {
                            if (map[r, c] == '*')
                            {
                                sb.Append('*');
                            }
                            else
                            {
                                sb.Append('.');
                            }
                            //sb.Append(map[r, c]);
                        }
                    }
                    writer.WriteLine(sb);
                }
            }
            else
            {
                writer.WriteLine(result);
            }
        }

        private static void PrintMap(char[,] map, int rowNum, int columNum)
        {
            Console.WriteLine("---------------------------------------");
            for (int r = 0; r < rowNum; ++r)
            {
                StringBuilder sb = new StringBuilder();
                for (int c = 0; c < columNum; ++c)
                {
                    sb.Append(map[r, c]);
                }
                Console.WriteLine(sb);
            }
        }
        private static void PrintWallNum(int[,] wallNum, int rowNum, int columNum)
        {
            Console.WriteLine("-------------Wall--------------------------");
            for (int r = 0; r < rowNum; ++r)
            {
                StringBuilder sb = new StringBuilder();
                for (int c = 0; c < columNum; ++c)
                {
                    sb.Append(" " + wallNum[r, c]);
                }
                Console.WriteLine(sb);
            }
        }

        private static bool GetMinWallNum(int rowNum, int columNum, int[,] wallNum, char[,]map, 
            ref int minR, ref int minC, int mineNum)
        {
            minR = -1;
            minC = -1;
            int min = 9;
            bool result = false;
            for (int r = 0; r < rowNum; ++r)
            {
                for (int c = 0; c < columNum; ++c)
                {
                    if (wallNum[r, c] == 9 || (r==rowNum-1 && c == columNum-1))
                    {
                        continue;
                    }
                    if (wallNum[r, c] < min && mineable(r, c, wallNum, map, mineNum, rowNum, columNum))
                    {
                        // judge no 
                        min = wallNum[r, c];
                        minR = r;
                        minC = c;
                        result = true;
                    }
                }
            }
            return result;
        }
        private static bool isImpossible(int[,] wallNum, int rowNum, int columNum) 
        {
            for (int r = 0; r < rowNum; ++r)
            {
                for (int c = 0; c < columNum; ++c)
                {
                    if (r == rowNum - 1 && c == columNum - 1)
                    {
                        continue;
                    }
                    if (wallNum[r, c] <= 0 )
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        private static bool hasMine(int row, int col, char[,] map, int rowNum, int columNum)
        {
            int minC = col - 1 < 0 ? 0 : col - 1;
            int maxC = col + 1 > columNum - 1 ? columNum - 1 : col + 1;
            int minR = row - 1 < 0 ? 0 : row - 1;
            int maxR = row + 1 > rowNum - 1 ? rowNum - 1 : row + 1;

            for (int r = minR; r <= maxR; ++r)
            {
                for (int c = minC; c <= maxC; ++c)
                {
                    if (r == row && c == col)
                    {
                        continue;
                    }
                    else
                    {
                        if (map[r, c] == '*')
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private static bool mineable(int row, int col, int[,] wallNum1, char[,] map1, int mineNum, int rowNum, int columNum)
        {
            if (row == rowNum - 1 && col == columNum - 1)
            {
                return false;
            }

            if (mineNum == 2 && row == rowNum-3 && col == columNum-3)
            {
                return false;
            }

            if (mineNum == 1)
            {
                // copy data
                int[,] wallNum = new int[rowNum, columNum];
                char[,] map = new char[rowNum, columNum];
                for (int r = 0; r < rowNum; ++r)
                {
                    for (int c = 0; c < columNum; ++c)
                    {
                        wallNum[r, c] = wallNum1[r, c];
                        map[r, c] = map1[r, c];
                    }
                }

                // update
                map[row, col] = '*';
                createWall(col, row, map, columNum, rowNum);
                UpdateWallNum(rowNum, columNum, map, wallNum);

                return !isImpossible(wallNum, rowNum, columNum);
            }
            return true;
        }

        private static void UpdateWallNum(int rowNum, int columNum, char[,] map, int[,] wallNum)
        {
            for (int r = 0; r < rowNum; ++r)
            {
                for (int c = 0; c < columNum; ++c)
                {
                    if (map[r, c] == '*')
                    {
                        wallNum[r, c] = 9;
                    }
                    else
                    {
                        wallNum[r, c] = calWallNum(r, c, map, columNum, rowNum);
                    }
                }
            }
        }

        public static void createWall(int col, int row, char[,] map, int colNum, int rowNum)
        {
            int minC = col - 1 < 0 ? 0 : col - 1;
            int maxC = col + 1 > colNum - 1 ? colNum - 1 : col + 1;
            int minR = row - 1 < 0 ? 0 : row - 1;
            int maxR = row + 1 > rowNum - 1 ? rowNum - 1 : row + 1;

            for (int r = minR; r <= maxR; ++r)
            {
                for (int c = minC; c <= maxC; ++c)
                {
                    if (r == row && c == col)
                    {
                        continue;
                    }
                    else
                    {
                        if (map[r, c] == '.')
                        {
                            map[r, c] = 'w';
                        }
                    }
                }
            }
        }

        public static int calWallNum(int row, int col, char[,] map, int colNum, int rowNum)
        {
            int minC = col - 1 < 0 ? 0 : col - 1;
            int maxC = col + 1 > colNum - 1 ? colNum - 1 : col + 1;
            int minR = row - 1 < 0 ? 0 : row - 1;
            int maxR = row + 1 > rowNum - 1 ? rowNum - 1 : row + 1;

            int count = 0;
            for (int r = minR; r <= maxR; ++r)
            {
                for (int c = minC; c <= maxC; ++c)
                {
                    if (r == row && c == col)
                    {
                        continue;
                    }
                    else
                    {
                        if (map[r, c] == '.')
                        {
                            count++;
                        }
                    }
                }
            }
            return count;
        }
    }
}
