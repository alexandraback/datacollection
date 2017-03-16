using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Net.Configuration;
using System.Runtime.CompilerServices;
using System.Runtime.Hosting;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml.Schema;
using Microsoft.CSharp;

namespace GCJ_2014_Qualification
{
    class Program
    {
        static void Main(string[] args)
        {
            string sInFileName = "c:/in.txt";
            string sOutFileName = "c:/out.txt";

            string sIn = File.ReadAllText(sInFileName);
            StringReader oSR = new StringReader(sIn);

            StringBuilder oAnswer = new StringBuilder();

            // read number of cases
            int T = int.Parse(oSR.ReadLine());

            // case by case
            for (int i = 0; i < T; i++)
            {
                // read case
                string sCase = oSR.ReadLine();
                string[] aCase = sCase.Split(' ');
                int R = int.Parse(aCase[0]);
                int C = int.Parse(aCase[1]);
                int M = int.Parse(aCase[2]);

                int n = R*C;
                char[,] aSolution = null;
                char[,] bs;
                aSolution = Solve(R, C, M, out bs);

                // write answer
                oAnswer.AppendFormat("Case #{0}: ", i + 1);
                oAnswer.AppendLine();
//                oAnswer.AppendFormat("{0} {1} {2}\n", R, C, M);
                if (aSolution == null)
                {
                    oAnswer.Append("Impossible");
                    oAnswer.AppendLine();
                    aSolution = bs;
                }
                else
                {
                    for (int j = 0; j < R; j++)
                    {
                        for (int k = 0; k < C; k++)
                        {
                            oAnswer.Append(aSolution[j, k]);
                        }
                        oAnswer.AppendLine();
                    }
                }
            }

            string sOut = oAnswer.ToString();
            File.WriteAllText(sOutFileName, sOut);
        }

        private static char[,] Solve(int R, int C, int M, out char[,] bs)
        {
            char[,] a = new char[R, C];

            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    a[i, j] = '.';

            a[0, 0] = 'c';

            if (M > 0)
            {
                // place the mines
                int r = C - 1;
                int b = R - 1;

                int y_cr = 2;
                int x_cr = 2;
                int nM = M;

                // no crit square?
                if (nM > 0 && C < 3)
                {
                    for (int y = b; y > y_cr; y--)
                    {
                        for (int x = r; x >= 0; x --)
                        {
                            a[y, x] = '*';
                            nM--;
                            if (nM == 0)
                                break;
                        }
                        if (nM == 0)
                            break;
                    }
                }
                if (nM > 0 && R < 3)
                {
                    for (int x = r; x > x_cr; x--)
                    {
                        for (int y = b; y >= 0; y--)
                        {
                            a[y, x] = '*';
                            nM--;
                            if (nM == 0)
                                break;
                        }
                        if (nM == 0)
                            break;
                    }
                }

                // fill the "even" square
                for (int y = b; y >= y_cr; y--)
                {
                    if (y > R - 1)
                        continue;
                    for (int x = r; x >= x_cr; x--)
                    {
                        if (x > C - 1)
                            continue;

                        a[y, x] = '*';
                        nM--;
                        if (nM == 0)
                            break;
                    }
                    if (nM == 0)
                        break;
                }

                // fill the left "odd" square
                if (nM > 0 && C > 2 && R > 2)
                {
                    int nLeftLevel = b;
                    while (nLeftLevel > y_cr && nM > 0)
                    {
                        if (nM == 1)
                        {
                            nM --;
                            a[y_cr, x_cr] = '.';
                            a[nLeftLevel, 0] = '*';
                            a[nLeftLevel, 1] = '*';
                            break;
                        }

                        nM -= 2;
                        a[nLeftLevel, 0] = '*';
                        a[nLeftLevel, 1] = '*';
                        nLeftLevel --;
                    }
                }

                // fill the upper "odd" square
                if (nM > 0 && C > 2 && R > 2)
                {
                    int nUpLevel = r;
                    while (nUpLevel > x_cr && nM > 0)
                    {
                        if (nM == 1)
                        {
                            nM--;
                            a[y_cr, x_cr] = '.';
                            a[0, nUpLevel] = '*';
                            a[1, nUpLevel] = '*';
                            break;
                        }

                        nM -= 2;
                        a[0, nUpLevel] = '*';
                        a[1, nUpLevel] = '*';
                        nUpLevel--;
                    }
                }

                // fill the last 3*3 square
                if (C > 2 && R > 1 && nM-- > 0)
                    a[1, 2] = '*';
                if (C > 2 && nM-- > 0)
                    a[0, 2] = '*';
                if (C > 1 && R > 2 && nM-- > 0)
                    a[2, 1] = '*';
                if (R > 2 && nM-- > 0)
                    a[2, 0] = '*';
                if (C > 1 && R > 1 && nM-- > 0)
                    a[1, 1] = '*';
                if (R > 1 && nM-- > 0)
                    a[1, 0] = '*';
                if (C > 1 && nM-- > 0)
                    a[0, 1] = '*';
                if (nM-- > 0)
                {
                    throw new ApplicationException("No space for mines!");
                }
            }
            int O = HowManyShown(a, R, C, out bs);
            if (O != R*C - M)
                return null;

            return a;
        }

        static int HowManyShown(char[,] a, int R, int C, out char[,] b)
        {
            b = (char[,]) a.Clone();

            b[0, 0] = '.';
            int S = HowManyShown(b, R, C, 0, 0);
           
            return S;
        }

        static int HowManyShown(char[,] b, int R, int C, int x, int y)
        {
            if (b[y, x] != '.')
                return 0;

            bool b8 = true;

            if (x < C - 1)
                if (b[y, x + 1] == '*')
                    b8 = false;
            if (b8 && y < R - 1)
            {
                if (b[y + 1, x] == '*')
                    b8 = false;
                if (x < C - 1)
                    if (b[y + 1, x + 1] == '*')
                        b8 = false;
            }

            if (b8)
            {
                b[y, x] = '8';
                int nR = 0, nD = 0, nRD = 0;
                if (x < C - 1)
                {
                    nR = HowManyShown(b, R, C, x + 1, y);
                    if (y < R - 1)
                        nRD = HowManyShown(b, R, C, x + 1, y + 1);
                }
                if (y < R - 1)
                    nD = HowManyShown(b, R, C, x, y + 1);

                return 1 + nR + nD + nRD;
            }
            else
            {
                b[y, x] = 'S';
                return 1;
            }
        }
    }
}
