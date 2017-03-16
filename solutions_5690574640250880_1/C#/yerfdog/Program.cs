using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14qr
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\C-large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\C-large.out");
            for (int a = 0; a < t; a++)
            {
                string[] line= lines[idx++].Split(' ');
                int row = int.Parse(line[0]);
                int col = int.Parse(line[1]);
                int m = int.Parse(line[2]);
                int blanks = row * col - m;
                string[,] matrix = new string[row, col];
                for (int b = 0; b < row; b++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        matrix[b, c] = "*";
                    }
                }
                bool possible = false;
                if (row == 1)
                {
                    possible = true;
                    matrix[0, 0] = "c";
                    for (int i = 1; i < blanks; i++)
                    {
                        matrix[0, i] = ".";
                    }
                }
                else if (col == 1)
                {
                    possible = true;
                    matrix[0, 0] = "c";
                    for (int i = 1; i < blanks; i++)
                    {
                        matrix[i, 0] = ".";
                    }
                }
                else if (blanks == 1)
                {
                    possible = true;
                    matrix[0, 0] = "c";
                }
                else if (blanks == 2 || blanks == 3 || blanks == 5 || blanks == 7)
                {
                }
                else if ((row == 2 || col == 2) && m ==1)
                {
                }
                else
                {
                    possible = true;
                    if (row > col)
                    {
                        int[] rows = new int[row];
                        int height = blanks / 2;
                        if (blanks / col >= 2)
                        {
                            height = col;
                        }
                        for (int i = 0; i < blanks / height; i++)
                        {
                            rows[i] = height;
                        }
                        if (blanks % height != 0)
                        {
                            rows[blanks / height] = blanks % height;
                        }
                        if (blanks % height == 1)
                        {
                            if (blanks / height > 2)
                            {
                                rows[blanks / height - 1]--;
                                rows[blanks / height]++;
                            }
                            else
                            {
                                rows[0]--;
                                rows[1]--;
                                rows[2] += 2;
                            }
                        }
                        for (int i = 0; i < row; i++)
                        {
                            for (int j = 0; j < rows[i]; j++)
                            {
                                matrix[i, j] = ".";
                            }
                        }
                        matrix[0, 0] = "c";
                    }
                    else
                    {
                        int[] cols = new int[col];
                        int height = blanks / 2;
                        if (blanks / row >= 2)
                        {
                            height = row;
                        }
                        for (int i = 0; i < blanks / height; i++)
                        {
                            cols[i] = height;
                        }
                        if (blanks % height != 0)
                        {
                            cols[blanks / height] = blanks % height;
                        }
                        if (blanks % height == 1)
                        {
                            if (blanks / height > 2)
                            {
                                cols[blanks / height - 1]--;
                                cols[blanks / height]++;
                            }
                            else
                            {
                                cols[0]--;
                                cols[1]--;
                                cols[2] += 2;
                            }
                        }
                        for (int i = 0; i < col; i++)
                        {
                            for (int j = 0; j < cols[i]; j++)
                            {
                                matrix[j, i] = ".";
                            }
                        }
                        matrix[0, 0] = "c";
                    }
               
                }
                tw.WriteLine("Case #{0}:", a + 1);
                if (!possible)
                {
                    tw.WriteLine("Impossible");
                }
                else
                {
                    for (int i = 0; i < row; i++)
                    {
                        string rowVal = "";
                        for(int j =0; j< col; j++){
                            rowVal +=matrix[i,j];
                        }
                        tw.WriteLine(rowVal);
                    }
                }
            }
            tw.Close();
        }

    }
}
