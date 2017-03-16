using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Qualification
{
    class Three
    {
        const int I = 2;
        const int J = 3;
        const int K = 4;
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            int[,] Ps = new int[8, 10000];
            bool[,] done = new bool[8, 10000];
            for (int n_case = 1; n_case <= T; n_case++)
            {
                String line = text.ReadLine();
                String[] integers = line.Split(' ');
                bool res = true;
                int L = int.Parse(integers[0]);
                long X = long.Parse(integers[1]);
                string S = text.ReadLine();
                for (int i = 0; i < L; i++)
                {
                    Ps[0, i] = product(1, ctoi(S[i]));
                    Ps[1, i] = product(I, ctoi(S[i]));
                    Ps[2, i] = product(J, ctoi(S[i]));
                    Ps[3, i] = product(K, ctoi(S[i]));
                    Ps[4, i] = product(-1, ctoi(S[i]));
                    Ps[5, i] = product(-I, ctoi(S[i]));
                    Ps[6, i] = product(-J, ctoi(S[i]));
                    Ps[7, i] = product(-K, ctoi(S[i]));
                }
                int indexR = 0;
                int indexC = 0;
                long times = 0;
                //search I
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        done[i, j] = false;
                    }
                }
                bool found = false;
                while (!found && res && times < X)
                {
                    if (Ps[indexR, indexC] == I)
                    {
                        found = true;
                    }
                    if (!found && done[indexR, indexC] == true)
                    {
                        res = false;
                        break;
                    }
                    else done[indexR, indexC] = true;
                    switch (Ps[indexR, indexC])
                    {
                        case 1:
                        {
                            indexR = 0;
                            break;
                        }
                        case -1:
                        {
                            indexR = 4;
                            break;
                        }
                        case I:
                        {
                            indexR = 1;
                            break;
                        }
                        case -I:
                        {
                            indexR = 5;
                            break;
                        }
                        case J:
                        {
                            indexR = 2;
                            break;
                        }
                        case -J:
                        {
                            indexR = 6;
                            break;
                        }
                        case K:
                        {
                            indexR = 3;
                            break;
                        }
                        case -K:
                        {
                            indexR = 7;
                            break;
                        }
                    }
                    indexC++;
                    if (indexC == L)
                    {
                        indexC = 0;
                        times++;
                    }
                    if ( times >= X && !found )
                    {
                        res = false;
                    }
                }
                //search J
                indexR = 0;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        done[i, j] = false;
                    }
                }
                found = false;
                while (!found && res && times < X)
                {
                    if (Ps[indexR, indexC] == J)
                    {
                        found = true;
                    }
                    if (!found && done[indexR, indexC] == true)
                    {
                        res = false;
                        break;
                    }
                    else done[indexR, indexC] = true;
                    switch (Ps[indexR, indexC])
                    {
                        case 1:
                            {
                                indexR = 0;
                                break;
                            }
                        case -1:
                            {
                                indexR = 4;
                                break;
                            }
                        case I:
                            {
                                indexR = 1;
                                break;
                            }
                        case -I:
                            {
                                indexR = 5;
                                break;
                            }
                        case J:
                            {
                                indexR = 2;
                                break;
                            }
                        case -J:
                            {
                                indexR = 6;
                                break;
                            }
                        case K:
                            {
                                indexR = 3;
                                break;
                            }
                        case -K:
                            {
                                indexR = 7;
                                break;
                            }
                    }
                    indexC++;
                    if (indexC == L)
                    {
                        indexC = 0;
                        times++;
                    }
                    if ( times >= X && !found )
                    {
                        res = false;
                    }
                }
                //search K
                indexR = 0;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < L; j++)
                    {
                        done[i, j] = false;
                    }
                }
                found = false;
                while (!found && res && times < X)
                {
                    if (Ps[indexR, indexC] == K)
                    {
                        found = true;
                    }
                    if (!found && done[indexR, indexC] == true)
                    {
                        res = false;
                        break;
                    }
                    else done[indexR, indexC] = true;
                    switch (Ps[indexR, indexC])
                    {
                        case 1:
                            {
                                indexR = 0;
                                break;
                            }
                        case -1:
                            {
                                indexR = 4;
                                break;
                            }
                        case I:
                            {
                                indexR = 1;
                                break;
                            }
                        case -I:
                            {
                                indexR = 5;
                                break;
                            }
                        case J:
                            {
                                indexR = 2;
                                break;
                            }
                        case -J:
                            {
                                indexR = 6;
                                break;
                            }
                        case K:
                            {
                                indexR = 3;
                                break;
                            }
                        case -K:
                            {
                                indexR = 7;
                                break;
                            }
                    }
                    indexC++;
                    if (indexC == L)
                    {
                        indexC = 0;
                        times++;
                    }
                    if ( times >= X && !found )
                    {
                        res = false;
                    }
                }
                //********//
                indexR = 0;
                int cont = 1;
                while (indexC != 0)
                {
                    cont = product(cont, ctoi(S[indexC]));
                    indexC++;
                    if (indexC == L)
                    {
                        indexC = 0;
                        times++;
                    }
                }
                int cont2 = 1;
                for (int i = 0; i < L; i++)
                {
                    cont2 = product(cont2, ctoi(S[i]));
                }
                /*****/
                int len = 0;
                int app = cont2;
                while (true)
                {
                    len++;
                    if (app == 1) break;
                    app = product(app, cont2);
                }
                int p = (int)((X - (long)times) % (long)len);
                for (int i = 0; i < p; i++)
                {
                    cont = product(cont, cont2);
                }
                if (cont != 1)
                    res = false;
                /*****/
                if (res)
                    outtext.WriteLine("Case #" + n_case + ": YES");
                else outtext.WriteLine("Case #" + n_case + ": NO");

            }
            outtext.Flush();
        }
        static int foo(int a)
        {
            switch (a)
            {
                case 1:
                    {
                        return 0;
                    }
                case -1:
                    {
                        return 4;
                    }
                case I:
                    {
                        return 1;
                    }
                case -I:
                    {
                        return 5;
                    }
                case J:
                    {
                        return 2;
                    }
                case -J:
                    {
                        return 6;
                    }
                case K:
                    {
                        return 3;
                    }
                case -K:
                    {
                        return 7;
                    }
            }
            return 0;
        }
        static int product(int a, int b)
        {
            if (a < 0)
                return -product(-a, b);
            if (b < 0)
                return -product(a, -b);
            switch (a)
            {
                case 1: 
                {
                    return b;
                }
                case I:
                {
                    if (b == 1)
                        return I;
                    if (b == I)
                        return -1;
                    if (b == J)
                        return K;
                    if (b == K)
                        return -J;
                    break;
                }
                case J:
                {
                    if (b == 1)
                        return J;
                    if (b == I)
                        return -K;
                    if (b == J)
                        return -1;
                    if (b == K)
                        return I;
                    break;
                }
                case K:
                {
                    if (b == 1)
                        return K;
                    if (b == I)
                        return J;
                    if (b == J)
                        return -I;
                    if (b == K)
                        return -1;
                    break;
                }
            }
            return 0;
        }
        static int ctoi(char c)
        {
            if (c == 'i')
                return I;
            if (c == 'j')
                return J;
            if (c == 'k')
                return K;
            return 0;
        }
    }
}
