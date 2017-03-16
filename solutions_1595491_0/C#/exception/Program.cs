using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Users\\Avinash\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Users\\Avinash\\Desktop\\output.txt");

            int T;
            T = int.Parse(tr.ReadLine());

            string input = null;

            for (int caseno = 1; caseno <= T; caseno++)
            {
                input = tr.ReadLine();
                string[] arr = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int[] C = new int[3];
                for (int i = 0; i < 3; i++)
                    C[i] = int.Parse(arr[i]);
                int N = C[0];
                int S = C[1];
                int p = C[2];
                int[] points = new int[N];
                for (int i = 3; i < arr.Length; i++)
                    points[i - 3] = int.Parse(arr[i]);

                Array.Sort(points);

                int[] first = new int[N];
                int[] second = new int[N];
                int[] third = new int[N];

                for (int i = 0; i < N; i++)
                {
                    if (points[i] % 3 == 0)
                    {
                        if (S <= 0)
                        {
                            first[i] = points[i] / 3;
                            second[i] = (points[i] / 3);
                            third[i] = (points[i] / 3);
                        }
                        else
                        {
                            if ((points[i] / 3) + 1 >= p && (points[i] / 3) - 1 >= 0)
                            {
                                first[i] = (points[i] / 3) - 1;
                                second[i] = points[i] / 3;
                                third[i] = (points[i] / 3) + 1;
                                S--;
                            }
                            else
                            {
                                first[i] = points[i] / 3;
                                second[i] = points[i] / 3;
                                third[i] = points[i] / 3;
                            }
                        }
                    }
                    else if (points[i] % 3 == 1)
                    {
                        first[i] = points[i] / 3;
                        second[i] = points[i] / 3;
                        third[i] = (points[i] / 3) + 1;
                    }
                    else
                    {
                        if (S <= 0)
                        {
                            first[i] = points[i] / 3;
                            second[i] = (points[i] / 3) + 1;
                            third[i] = (points[i] / 3) + 1;
                        }
                        else
                        {
                            if ((points[i] / 3) + 2 >= p)
                            {
                                first[i] = points[i] / 3;
                                second[i] = points[i] / 3;
                                third[i] = (points[i] / 3) + 2;
                                S--;
                            }
                            else
                            {
                                first[i] = points[i] / 3;
                                second[i] = (points[i] / 3) + 1;
                                third[i] = (points[i] / 3) + 1;
                            }
                        }
                    }

                }

                int max = 0;
                for (int i = 0; i < N; i++)
                {
                    if (first[i] >= p || second[i] >= p || third[i] >= p)
                        max++;
                }
                tw.WriteLine("Case #{0}: {1}", caseno, max);
            }

            tr.Close();
            tw.Close();
        }
    }
}