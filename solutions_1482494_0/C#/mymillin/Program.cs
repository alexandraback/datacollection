using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;


namespace CJ2
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("input.txt");
            StreamWriter output = new StreamWriter("output.txt");

            int Count = int.Parse(input.ReadLine());

            for (int i = 0; i < Count; i++)
            {
                string[] line = input.ReadLine().Split(new char[] { ' ' });

                int L = int.Parse(line[0]);

                int[][] p = new int[L][];

                for (int j = 0; j < L; j++)
                {
                    p[j] = new int[3];
                    line = input.ReadLine().Split(new char[] { ' ' });

                    p[j][1] = int.Parse(line[0]);
                    p[j][2] = int.Parse(line[1]);
                }

                string sol = Solve(L, p);

                Debug.WriteLine("Case #" + (i + 1) + ": " + sol);
                output.WriteLine("Case #" + (i + 1) + ": " + sol);
            }


            input.Close();
            output.Close();
        }

        static string Solve(int L, int[][] p)
        {
            bool[] f1 = new bool[L];
            bool[] f2 = new bool[L];
            int star = 0;
            int round = 0;
            int count1 = 0, count2 = 0;

            bool flag = true;

            while (flag)
            {
                flag = false;

                for (int i = 0; i < L; i++)
                {
                    if (!f2[i] && !f1[i] && p[i][2] <= star)
                    {
                        f2[i] = true;
                        count2++;
                        star++;
                        round++;
                        flag = true;
                        f1[i] = true;
                        count1++;
                        star++;
                    }
                }

                if (!flag && count2 != L)
                {
                    for (int i = 0; i < L; i++)
                    {
                        if (!f2[i] && p[i][2] <= star)
                        {
                            f2[i] = true;
                            count2++;
                            star++;
                            round++;
                            flag = true;
                        }
                    }
                }

                if (!flag && count1 != L)
                {
                    for (int i = 0; i < L; i++)
                    {
                        if (!f1[i] && p[i][1] <= star)
                        {
                            flag = true;
                            f1[i] = true;
                            count1++;
                            star++;
                            round++;
                            break;
                        }
                    }
                }
            }

            if (count2 == L)
            {
                return round.ToString();
            }
            else
                return "Too Bad";

        }

        static string Solve2(int L, int[][] p)
        {
            int star = 0;
            int round = 0;
            int min1 = -1, min2 = -1;
            bool[] f1 = new bool[L];
            bool[] f2 = new bool[L];
            int f1count = 0;
            int f2count = 0;

            while (true)
            {
                //Debug.WriteLine(star+ " "+ f1count +" " +f2count);

                if (f2count == L)
                    return round.ToString();

                for (int i = 0; i < L; i++)
                {
                    if (!f1[i] && min1 == -1)
                    {
                        min1 = i;
                    }
                    else if (!f1[i] && p[i][1] < p[min1][1])
                    {
                        min1 = i;
                    }

                    if (!f2[i] && min2 == -1)
                    {
                        min2 = i;
                    }
                    else if (!f2[i] && p[i][2] < p[min2][2])
                    {
                        min2 = i;
                    }
                }

                if (star >= p[min2][2] && !f2[min2])
                {
                    f2[min2] = true;
                    round++;
                    star++;
                    f2count++;
                    if (!f1[min2])
                    {
                        star++;
                        f1[min2] = true;
                        f1count++;
                        min1 = -1;
                    }
                    min2 = -1;
                    continue;
                }

                if (f1count == L)
                {
                    return "Too Bad";
                }
                else if (star >= p[min1][1] && !f1[min1])
                {
                    f1[min1] = true;
                    round++;
                    star++;
                    f1count++;
                    min1 = -1;
                    continue;
                }

                return "Too Bad";
            }
        }
    }
}
