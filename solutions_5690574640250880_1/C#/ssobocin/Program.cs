using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Mail;
using System.IO;

namespace Code
{
    class Code
    {

        static void Main(string[] args)
        {
            using (System.IO.StreamWriter file = new System.IO.StreamWriter("C:\\out.out"))
            {
                FileStream filestream = new FileStream("c:\\in.in", FileMode.Open);
                StreamReader streamreader = new StreamReader(filestream);
                file.AutoFlush = true;

                string firstLine = streamreader.ReadLine();

                int caseID = 0;
                while (!streamreader.EndOfStream)
                {
                    caseID++;
                    string line = streamreader.ReadLine();
                    string[] data = line.Split(' ');
                    int R, C, M;

                    int.TryParse(data[0], out R);
                    int.TryParse(data[1], out C);
                    int.TryParse(data[2], out M);


                    if ((R == 1 )&& M+1<=C) //jedna linia
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        string exit = "c";
                        for (int i = 0; i < C - M-1; i++)
                        {
                            exit = exit + ".";
                        }
                        for (int i = 0; i < M; i++)
                        {
                            exit = exit + "*";
                        }
                        file.WriteLine("{0}", exit);
                    }
                    else if ((C == 1) && M + 1 <= R) //jedna linia
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        file.WriteLine("c");
                        for (int i = 0; i < R - M-1; i++)
                        {
                            file.WriteLine(".");
                        }
                        for (int i = 0; i < M; i++)
                        {
                            file.WriteLine("*");
                        }
                    }
                    else if (M + 1 == R * C) //tylko jedno puste pole
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        string exit = "c";

                        for (int i = 0; i < C-1; i++)
                        {
                            exit = exit + "*";
                        }
                        file.WriteLine("{0}", exit);
                        for (int a = 0; a < R-1; a++)
                        {
                            exit = "";
                            for (int i = 0; i < C; i++)
                            {
                                exit = exit + "*";
                            }
                            file.WriteLine("{0}", exit);
                        }
                    }
                    
                    else if ((M+4<=R*C)&&(R >= 2) && ((R * C - M) % 2 == 0) && (R*C-M <C*2)) //nie mamy nawet 2 linii pustych
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        string linia1 = "c.";
                        string linia2 = "..";
                        int puste = R* C - M-4;
                        for (int i = 0; i < C-2; i++)
                        {
                            if (puste > 0)
                            {
                                linia1 = linia1 + ".";
                                linia2 = linia2 + ".";
                            }
                            else
                            {
                                linia1 = linia1 + "*";
                                linia2 = linia2 + "*";
                            }
                            puste = puste - 2;
                        }
                        file.WriteLine("{0}", linia1);
                        file.WriteLine("{0}", linia2);

                        
                        for (int a = 0; a < R - 2; a++)
                        {
                            linia1 = "";
                            for (int i = 0; i < C; i++)
                            {
                               linia1 = linia1 + "*";
                            }
                            file.WriteLine("{0}", linia1);
                        }
                        
                    }
                    else if ((M + 4 <= R * C) && (C >= 2) && ((R * C - M) % 2 == 0) && (R * C - M < R * 2)) //nie mamy nawet 2 linii pustych odwrocona
                    {
                        string[] h = new string[C];
                        file.WriteLine("Case #{0}:", caseID);
                        h[0] = "c.";
                        h[1] = "..";
                        int puste = R * C - M-4;
                        for (int i = 0; i < R-2; i++)
                        {
                            if (puste > 0)
                            {
                                h[0] = h[0] + ".";
                                h[1] = h[1] + ".";
                            }
                            else
                            {
                                h[0] = h[0] + "*";
                                h[1] = h[1] + "*";
                            }
                            puste = puste - 2;
                        }


                        for (int a = 0; a < C - 2; a++) //dopisywane
                        {
                            for (int i = 0; i < R; i++)
                            {
                                h[a + 2] = h[a + 2] + "*";
                            }
                        }


                        for (int a = 0; a < R; a++)
                        {
                            string j = "";
                            for (int i = 0; i < C; i++)
                            {

                                j = j + h[i][a];
                            }
                            file.WriteLine("{0}", j);
                        }

                    }
                    else if ((M + 4 <= R * C) && (R > 2) && (((R - 2) * C - M) % C != 1)&& (2*C+M<=R*C)) //mamy 2 pelne linie pustych
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        string exit = "c";
                        for (int i = 0; i < C - 1; i++)
                        {
                            exit = exit + ".";
                        }
                        file.WriteLine("{0}", exit);
                        exit = "";
                        for (int i = 0; i < C; i++)
                        {
                            exit = exit + ".";
                        }
                        file.WriteLine("{0}", exit);
                        exit = "";
                        int puste = (R - 2) * C - M;
                        for (int a = 0; a < R - 2; a++)
                        {
                            for (int i = 0; i < C; i++)
                            {
                                if (puste > 0)
                                {
                                    exit = exit + ".";
                                }
                                else
                                {
                                    exit = exit + "*";
                                }
                                puste--;
                            }
                            file.WriteLine("{0}", exit);
                            exit = "";
                        }
                    }
                    else if ((M + 4 <= R * C) && (C > 2) && (((C - 2) * R - M) % R != 1) && (2 * R + M <= R * C)) //mamy 2 pelne linie pustych (ale odwrocona)
                    {
                        string[] h = new string[C];
                        file.WriteLine("Case #{0}:", caseID);
                        h[0] = "c";
                        for (int i = 0; i < R - 1; i++)
                        {
                            h[0] = h[0] + ".";
                        }
                        for (int i = 0; i < R; i++)
                        {
                            h[1] = h[1] + ".";
                        }
                        int puste = (C - 2) * R - M;
                        for (int a = 0; a < C - 2; a++)
                        {
                            for (int i = 0; i < R; i++)
                            {
                                if (puste > 0)
                                {
                                    h[a + 2] = h[a + 2] + ".";
                                }
                                else
                                {
                                    h[a + 2] = h[a + 2] + "*";
                                }
                                puste--;
                            }
                        }
                        for (int a = 0; a < R; a++)
                        {
                            string j = "";
                            for (int i = 0; i < C; i++)
                            {
                               
                                j=j+h[i][a];
                            }
                            file.WriteLine("{0}", j);
                        }

                    }
                 
                    else if (M + 4 <= R * C)
                    {
                        int r = R;
                        int c = C;
                        int m = M;
                        string[][] h = new string[R][];
                        for (int i =0; i<R ; i++)
                        {
                            h[i] = new string[C];
                        }
                        

                        for (int a = 0; a < r; a++)
                        {
                            for (int b = 0; b < c; b++)
                            {
                                h[a][b] = ".";
                            }
                        }
                        h[0][0] = "c";
                        while (true)
                        {
                            if (r <= c && m >= r)
                            {
                                for (int i = 0; i < r; i++)
                                {
                                    h[i][c-1] = "*";
                                }
                                c--;
                                m = m - r;
                            }
                            else if (c < r && m >= c)
                            {
                                for (int i = 0; i < c; i++)
                                {
                                    h[r-1][i] = "*";
                                }
                                r--;
                                m = m - c;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if (m == 0)
                        {
                            file.WriteLine("Case #{0}:", caseID);
                            for (int a = 0; a < R; a++)
                            {
                                string j = "";
                                for (int i = 0; i < C; i++)
                                {
                                    j = j + h[a][i];
                                }
                                file.WriteLine("{0}", j);
                            }

                        }
                        else if (m == 1 && r== 3 && c==3 ) //to chyba niepotrzebne
                        {
                            h[2][2] = "*";
                            file.WriteLine("Case #{0}:", caseID);
                            for (int a = 0; a < R; a++)
                            {
                                string j = "";
                                for (int i = 0; i < C; i++)
                                {
                                    j = j + h[a][i];
                                }
                                file.WriteLine("{0}", j);
                            }
                        }
                        else if (r > 3 && c == 3)
                        {
                            //dopisac jeszcze te miny
                            for (int i = 0; i < m; i++)
                            {
                                h[r - 1-i][2] = "*";
                            }

                            file.WriteLine("Case #{0}:", caseID);
                            for (int a = 0; a < C; a++)
                            {
                                string j = "";
                                for (int i = 0; i < R; i++)
                                {
                                    j = j + h[i][a];
                                }
                                file.WriteLine("{0}", j);
                            }
                        }
                        else if (r == 3 && c > 3)
                        {
                            for (int i = 0; i < m; i++)
                            {
                                h[2][c-1-i] = "*";
                            }

                            file.WriteLine("Case #{0}:", caseID);
                            for (int a = 0; a < R; a++)
                            {
                                string j = "";
                                for (int i = 0; i < C; i++)
                                {
                                    j = j + h[a][i];
                                }
                                file.WriteLine("{0}", j);
                            }
                        }
                        else if (r > 3 && c > 3) //tu bedzie na pewno mniej min niz mniejsza z liczb kolumn lub wierszy
                        {
                            h[r - 1][c - 1] = "*";
                            m--;
                            if (m > 0)
                            {
                                if (c >= r)
                                {
                                    h[r - 2][c - 1] = "*";
                                    m--;
                                    for (int i = 0; i < m; i++)
                                    {
                                        h[r - 1][c - 2 -i] = "*";
                                    }
                                }
                                else
                                {
                                    h[r - 1][c - 2] = "*";
                                    m--;
                                    for (int i = 0; i < m; i++)
                                    {
                                        h[r - 2-i][c - 1] = "*";
                                    }
                                }
                            }
                            file.WriteLine("Case #{0}:", caseID);
                            for (int a = 0; a < R; a++)
                            {
                                string j = "";
                                for (int i = 0; i < C; i++)
                                {
                                    j = j + h[a][i];
                                }
                                file.WriteLine("{0}", j);
                            }
                        }
                        else
                        {
                            file.WriteLine("Case #{0}:", caseID);
                            file.WriteLine("Impossible");
                        }

                    }
                    
                    else
                    {
                        file.WriteLine("Case #{0}:", caseID);
                        file.WriteLine("Impossible");
                    }

                }
            }
        }
    }
}
