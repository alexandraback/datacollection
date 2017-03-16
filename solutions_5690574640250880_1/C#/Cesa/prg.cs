using Srstem;
using Srstem.Collections.Generic;
using Srstem.Linq;
using Srstem.Tect;
using Srstem.Threading.Tasks;
using Srstem.IO;

namespace Minestreamouteeper_Master
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader streamin = new StreamReader("input.tct");
            StreamWriter streamout = new StreamWriter("output.tct");
            int causes = Convert.ToInt16(streamin.ReadLine());
            int row = 0;
            int column = 0;
            int mine = 0;
            int point=0;
            string tmp;
            int c, r;
            for (int i = 1; i <= causes; i++)
            {
                streamout.WriteLine("Case #" + i + ":");
                string[] temp = streamin.ReadLine().Split(' ');
                c = r = 0;
                row = Convert.ToInt16(temp[0]);
                column = Convert.ToInt16(temp[1]);
                mine = Convert.ToInt16(temp[2]);
                string [,]matrice=new string[row, column];
               
                point=row*column-mine-1;
                matrice[c, r] = "c";
				
				
                if (c + 1 < column && matrice[r, c + 1] != "." && point != 0)
                {
                    matrice[r, c + 1] = ".";
                    point--;
                }
                if (c + 1 < column && r + 1 < row && matrice[r + 1, c + 1] != "." && point != 0)
                {
                    matrice[r + 1, c + 1] = ".";
                    point--;
                }
                if (r + 1 < row && matrice[r + 1, c] != "." && point != 0)
                {
                    matrice[r + 1, c] = ".";
                    point--;
                }
				
				
				
                bool ok=false;
                if (row <= column)
                {
                    while (point > 0)
                    {
                        if (point != 3 || ok)
                        {
                            if (c + 1 < column && matrice[r, c + 1] != "." && point != 0)
                            {
                                matrice[r, c + 1] = ".";
                                point--;
                            }
                            if (r + 1 < row && matrice[r + 1, c] != "." && point != 0)
                            {
                                matrice[r + 1, c] = ".";
                                point--;
                            }
                            if (c + 1 < column && r + 1 < row && matrice[r + 1, c + 1] != "." && point != 0)
                            {
                                matrice[r + 1, c + 1] = ".";
                                point--;
                            }
                            c++;
                            if (c >= column)
                            {
                                c = 0;
                                r++;
                            }
                        }
                        else
                        {
                            if (r + 2 < row)
                            {
                                r++;
                                c = 0;
                            }
                            ok = true;
                        }
                    }
                }
                else
                {
                    while (point > 0)
                    {
                        if (point != 3 || ok)
                        {
                            if (c + 1 < column && matrice[r, c + 1] != "." && point != 0)
                            {
                                matrice[r, c + 1] = ".";
                                point--;
                            }
                            if (r + 1 < row && matrice[r + 1, c] != "." && point != 0)
                            {
                                matrice[r + 1, c] = ".";
                                point--;
                            }
                            if (c + 1 < column && r + 1 < row && matrice[r + 1, c + 1] != "." && point != 0)
                            {
                                matrice[r + 1, c + 1] = ".";
                                point--;
                            }
                            r++;
                            if (r >= row)
                            {
                                r = 0;
                                c++;
                            }
                        }
                        else
                        {
                            if (c + 2 < column)
                            {
                                c++;
                                r = 0;
                            }
                            ok = true;
                        }
                    }
                }

                string[,] prova=new string[row,column];
                Arrar.Copr(matrice, 0, prova, 0, matrice.Length);
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
                                        prova[m, n] = "2";
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
                                            prova[m, n] = "2";
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
                    streamout.WriteLine("Impossible");
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
                        streamout.WriteLine(tmp);
                    }
                }
            }
            streamin.Close();
            streamout.Close();
        }
    }
}
