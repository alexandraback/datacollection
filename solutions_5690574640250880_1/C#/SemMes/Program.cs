using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Minesweeper_Master
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int causes = Convert.ToInt16(sr.ReadLine());
            int row = 0;
            int column = 0;
            int mine = 0;
            int pointtot=0;
            string tmp;
            int x, y;
            for (int i = 1; i <= causes; i++)
            {
                sw.WriteLine("Case #" + i + ":");
                string[] temp = sr.ReadLine().Split(' ');
                x = y = 0;
                row = Convert.ToInt16(temp[0]);
                column = Convert.ToInt16(temp[1]);
                mine = Convert.ToInt16(temp[2]);
                string [,]matrice=new string[row, column];
               
                pointtot=row*column-mine-1;
                matrice[x, y] = "c";
                if (x + 1 < column && matrice[y, x + 1] != "." && pointtot != 0)
                {
                    matrice[y, x + 1] = ".";
                    pointtot--;
                }
                if (x + 1 < column && y + 1 < row && matrice[y + 1, x + 1] != "." && pointtot != 0)
                {
                    matrice[y + 1, x + 1] = ".";
                    pointtot--;
                }
                if (y + 1 < row && matrice[y + 1, x] != "." && pointtot != 0)
                {
                    matrice[y + 1, x] = ".";
                    pointtot--;
                }
                bool vai=false;
                if (row <= column)
                {
                    //righe maggiori delle colonne
                    while (pointtot > 0)
                    {
                        if (pointtot != 3 || vai)
                        {
                            if (x + 1 < column && matrice[y, x + 1] != "." && pointtot != 0)
                            {
                                matrice[y, x + 1] = ".";
                                pointtot--;
                            }
                            if (y + 1 < row && matrice[y + 1, x] != "." && pointtot != 0)
                            {
                                matrice[y + 1, x] = ".";
                                pointtot--;
                            }
                            if (x + 1 < column && y + 1 < row && matrice[y + 1, x + 1] != "." && pointtot != 0)
                            {
                                matrice[y + 1, x + 1] = ".";
                                pointtot--;
                            }
                            x++;
                            if (x >= column)
                            {
                                x = 0;
                                y++;
                            }
                        }
                        else
                        {
                            if (y + 2 < row)
                            {
                                y++;
                                x = 0;
                            }
                            vai = true;
                        }
                    }
                }
                else
                {
                    //colonne maggiori delle righe 
                    while (pointtot > 0)
                    {
                        if (pointtot != 3 || vai)
                        {
                            if (x + 1 < column && matrice[y, x + 1] != "." && pointtot != 0)
                            {
                                matrice[y, x + 1] = ".";
                                pointtot--;
                            }
                            if (y + 1 < row && matrice[y + 1, x] != "." && pointtot != 0)
                            {
                                matrice[y + 1, x] = ".";
                                pointtot--;
                            }
                            if (x + 1 < column && y + 1 < row && matrice[y + 1, x + 1] != "." && pointtot != 0)
                            {
                                matrice[y + 1, x + 1] = ".";
                                pointtot--;
                            }
                            y++;
                            if (y >= row)
                            {
                                y = 0;
                                x++;
                            }
                        }
                        else
                        {
                            if (x + 2 < column)
                            {
                                x++;
                                y = 0;
                            }
                            vai = true;
                        }
                    }
                }

                string[,] prova=new string[row,column];
                Array.Copy(matrice, 0, prova, 0, matrice.Length);
                for (int m = 0; m < row; m++)
                {
                    for (int n = 0; n < column; n++)
                    {
                        if (prova[m, n] == "c" || prova[m, n] == "0")
                        {
                            if (m + 1 < row && n + 1 < column)
                            {
                                if (prova[m + 1, n + 1] != null && prova[m, n + 1] != null && prova[m + 1, n] != null)
                                {
                                    prova[m + 1, n + 1] = "0";
                                    prova[m, n + 1] = "0";
                                    prova[m + 1, n] = "0";
                                }
                                else
                                    prova[m, n] = "1";
                            }
                            else
                            {
                                if (m + 1 == row && n + 1 < column)
                                {
                                    if (prova[m, n + 1] != null)
                                    {
                                        prova[m, n + 1] = "0";
                                    }
                                    else
                                        prova[m, n] = "1";
                                }
                                else
                                {
                                    if (m + 1 < row && n + 1 == column)
                                    {
                                        if (prova[m + 1, n] != null)
                                        {
                                            prova[m + 1, n] = "0";
                                        }
                                        else
                                            prova[m, n] = "1";
                                    }
                                }
                            }
                        }
                       
                    }
                }
                bool ok = true;
                for (int m = 0; m < row; m++)
                {
                    for (int n = 0; n < column; n++)
                    {
                        if (prova[m, n] == ".")
                            ok = false;
                    }
                }
                if (!ok)
                { 
                    sw.WriteLine("Impossible");
                }
                else
                {
                    for (int m = 0; m < row; m++)
                    {
                        tmp = "";
                        for (int n = 0; n < column; n++)
                        {
                            if (matrice[m, n] == null)
                                tmp = tmp + "*";
                            tmp = tmp + matrice[m, n];
                        }
                        sw.WriteLine(tmp);
                    }
                }
            }
            sr.Close();
            sw.Close();
        }
    }
}
