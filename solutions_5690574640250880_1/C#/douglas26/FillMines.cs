using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2014
{
    class FillMines
    {
        
        public void solution(string filename)
        {
            StreamWriter sw = new StreamWriter("FillMines.txt");

            StreamReader sr = new StreamReader(filename);
            string strSize = sr.ReadLine();
            int iSize = Int32.Parse(strSize);

            for (int caseIndex = 0; caseIndex < iSize; caseIndex++)
            {
                string line = sr.ReadLine();
                string[] meta = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int Row = Convert.ToInt32(meta[0]);
                int Column = Convert.ToInt32(meta[1]);
                int Mines = Convert.ToInt32(meta[2]);

                char[,] FillMap = new char[Row, Column];
                for (int i = 0; i < Row; i++)
                    for (int j = 0; j < Column; j++)
                        FillMap[i, j] = '.';

                if (Math.Min(Row, Column) >= 3)
                    Fill(Row, Column, Mines, FillMap, 0, 0);
                else
                    EasyFill(Row, Column, Mines, FillMap, 0, 0);

                //Console.WriteLine();
                //Console.WriteLine(line);
                //printmap(FillMap, Row, Column, 0, 0);

                //Console.WriteLine("Case #{0}: {1} {2}", caseIndex + 1, DecWarPoints, WarPoints);

                bool even = false;
                //sw.WriteLine();
                //sw.WriteLine(line);
                if ((Row * Column - Mines) % 2 == 0)
                    even = true;

                 sw.WriteLine("Case #{0}:", caseIndex + 1);
                 if (FillMap[Row - 1, Column - 1] == 'f')
                 {
                     sw.WriteLine("Impossible");
   
                     
                 }
                 else
                 {
                     //if (!even)
                     //    sw.WriteLine("奇数");
                     for (int i = 0; i < Row; i++)
                     {
                         for (int j = 0; j < Column; j++)
                         {
                             sw.Write(FillMap[i, j]);

                         }
                         sw.WriteLine();
                     }

                 }

            }
            sw.Close();

        }

        private void EasyFill(int Row, int Column, int Mines, char[,] FillMap, int p, int p_2)
        {
            if (Row == 1 || Column == 1)
            {
                int fillcount = 0;
                for (int i = 0; i < Row; i++)
                    for (int j = 0; j < Column; j++)
                        if (fillcount < Mines)
                        {
                            fillcount++;
                            FillMap[i, j] = '*';
                        }
                FillMap[Row - 1, Column - 1] = 'c';
                return;
            }
            else if (Row == 2)
            {
                int fillcount = 0;
                for (int j = 0; j < Column; j++)
                    for (int i = 0; i < 2; i++)
                        if (fillcount < Mines)
                        {
                            fillcount++;
                            FillMap[i, j] = '*';
                        }
                if ((Mines % 2 == 0 && Mines <= Row * Column - 4) || Mines == Row * Column - 1)
                    FillMap[Row-1, Column-1] = 'c';
                else
                    FillMap[Row-1, Column-1] = 'f';
                return;

            }
            else if (Column == 2)
            {
                int fillcount = 0;
                for (int i = 0; i < Row; i++)
                    for (int j = 0; j < 2; j++)

                        if (fillcount < Mines)
                        {
                            fillcount++;
                            FillMap[i, j] = '*';
                        }
                if ((Mines % 2 == 0 && Mines <= Row * Column - 4) || Mines == Row * Column - 1)
                    FillMap[Row-1, Column-1] = 'c';
                else
                    FillMap[Row-1, Column-1] = 'f';
                return;

            }
        }

        private void Fill(int Row, int Column, int Mines, char[,] FillMap, int RowIndex, int ColIndex)
        {
            //当填不够一行，或者剩3*3时，不再填
            if (Mines < Math.Min(Row, Column) || (Row == 3 && Column == 3))
            {
                //剩3*3的情况下，仅有Mines = 1，3，5，8可行
              
                if ((Row == 3 && Column == 3))
                {
                    int[] valid = new int[] { 0, 1, 3, 5, 8 };
                    if (Mines == 5)
                    {
                        FillMap[RowIndex, ColIndex] = '*';
                        FillMap[RowIndex + 1, ColIndex] = '*';
                        FillMap[RowIndex + 2, ColIndex] = '*';

                        FillMap[RowIndex, ColIndex] = '*';
                        FillMap[RowIndex, ColIndex + 1] = '*';
                        FillMap[RowIndex, ColIndex + 2] = '*';

                        FillMap[RowIndex + 2, ColIndex + 2] = 'c';
                        //printmap(FillMap, RowIndex + 3, ColIndex + 3, 0, 0);
                        return;
                    }
                    else
                    {
                        int fillcount = 0;
                        for (int i = RowIndex; i < RowIndex + 3; i++)
                            for (int j = ColIndex; j < ColIndex + 3; j++)
                            {
                                if (fillcount < Mines)
                                {
                                    FillMap[i, j] = '*';
                                    fillcount++;
                                }
                            }

                        if (valid.ToList<int>().Contains(Mines))
                            FillMap[RowIndex + 2, ColIndex + 2] = 'c';
                        else
                            FillMap[RowIndex + 2, ColIndex + 2] = 'f';
                        //printmap(FillMap, RowIndex + 3, ColIndex + 3, 0, 0);
                        return;
                    }

                }
                //剩余方块大于3*3，且剩余小于等于2个
                else
                {
                    //直接从长边开始填满
                    //if (Row == 4 && Column == 4 && Mines == 3)
                    //{
                    //    FillMap[RowIndex, ColIndex] = '*';
                    //    FillMap[RowIndex, ColIndex+1] = '*';
                    //    FillMap[RowIndex+1, ColIndex] = '*';

                    //    FillMap[RowIndex + Row - 1, ColIndex + Column - 1] = 'c';
                    //}
                    //else
                    if (Row < Column)
                    {
                        if (Mines < Column - 1)
                            for (int i = 0; i < Mines; i++)
                                FillMap[RowIndex, ColIndex + i] = '*';
                        else
                        {
                            for (int i = 0; i < Mines-1; i++)
                                FillMap[RowIndex, ColIndex + i] = '*';
                            FillMap[RowIndex+1, ColIndex] = '*';
                        }

                        FillMap[RowIndex + Row - 1, ColIndex + Column - 1] = 'c';
                        return;
                    }
                    else
                    {
                        if (Mines < Row - 1)
                            for (int i = 0; i < Mines; i++)
                                FillMap[RowIndex + i, ColIndex] = '*';
                        else
                        {
                            for (int i = 0; i < Mines-1; i++)
                                FillMap[RowIndex + i, ColIndex] = '*';
                            FillMap[RowIndex , ColIndex+1] = '*';
 
                        }
                        FillMap[RowIndex + Row - 1, ColIndex + Column - 1] = 'c';
                        return;

                    }

                }

            }

            //剩余雷数可以按行填充，或者按列填充后剩下至少3行3列
            else
            {
                //从小的一侧开始填充
                if (Row < Column)
                {
                    int tmp_cols = Mines / Row;
                    int left = Mines % Row;
                    while (Column - tmp_cols < 3)
                    {
                        tmp_cols = tmp_cols - 1;
                        left = left + Row;
                    }
                    for (int i = RowIndex; i < RowIndex + Row; i++)
                        for (int j = ColIndex; j < ColIndex + tmp_cols; j++)

                            FillMap[i, j] = '*';
                    if (left > 0)
                    {
                        //printmap(FillMap, RowIndex, ColIndex + tmp_cols, Row, Column - tmp_cols);
                        Fill(Row, Column - tmp_cols, left, FillMap, RowIndex, ColIndex + tmp_cols);
                    }
                    else
                    {
                        FillMap[RowIndex + Row - 1, ColIndex + Column - 1] = 'c';
                        return;
                    }

                }
                else
                {
                    int tmp_rows = Mines / Column;
                    int left = Mines % Column;
                    while (Row - tmp_rows < 3)
                    {
                        tmp_rows = tmp_rows - 1;
                        left = left + Column;
                    }
                    for (int i = RowIndex; i < RowIndex + tmp_rows; i++)
                        for (int j = ColIndex; j < Column + ColIndex; j++)

                            FillMap[i, j] = '*';

                    if (left > 0)
                    {
                        //printmap(FillMap, RowIndex + tmp_rows, ColIndex, Row - tmp_rows, Column);
                        Fill(Row - tmp_rows, Column, left, FillMap, RowIndex + tmp_rows, ColIndex);
                    }
                    else
                    {
                        FillMap[RowIndex + Row - 1, ColIndex + Column - 1] = 'c';
                        return;
                    }

                }
            }
            
        }

        private void printmap(char[,] FillMap, int RowIndex, int ColIndex,int RowCount,int ColumCount)
        {
            for (int i = 0; i < RowCount + RowIndex; i++)
            {
                for (int j = 0; j < ColumCount + ColIndex; j++)
                {
                    if (i >= RowIndex && j >= ColIndex)
                        Console.Write("  ");
                    else
                        Console.Write(FillMap[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
