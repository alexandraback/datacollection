using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GCJ.Round1
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static string[] ReadStringArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ');
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                bool result = true;

                int[] NM = ReadIntArray(reader);
                int N = NM[0];
                int M = NM[1];

                int[][] data = new int[N][];
                for (int j = 0; j < N; j++)
                {
                    data[j] = ReadIntArray(reader);
                }

                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < M; k++)
                    {
                        bool temp = true;
                        for (int l = 0; l < N; l++)
                            if (data[j][k] < data[l][k])
                            {
                                temp = false;
                                break;
                            }

                        if (!temp)
                        {
                            temp = true;
                            for (int l = 0; l < M; l++)
                                if (data[j][k] < data[j][l])
                                {
                                    temp = false;
                                    break;
                                }
                        }


                        if (!temp)
                        {
                            result = false;
                            break;
                        }
                    }
                }

                //if (result)
                //{
                //    List<int> skipX = new List<int>();
                //    List<int> skipY = new List<int>();

                //    bool isChanged = true;
                //    while (skipX.Count < N - 1 && skipY.Count < M - 1 && isChanged)
                //    {
                //        isChanged = false;
                //        for (int x = 0; x < N; x++)
                //        {
                //            if (!skipX.Contains(x))
                //            {
                //                bool temp = false;
                //                int first = -1;

                //                for (int j = 0; j < M; j++)
                //                {
                //                    if (skipY.Contains(j))
                //                        continue;

                //                    if (first == -1)
                //                    {
                //                        first = j;
                //                        continue;
                //                    }

                //                    if (data[x][first] != data[x][j])
                //                    {
                //                        temp = true;
                //                        break;
                //                    }
                //                }
                //                if (!temp)
                //                {
                //                    skipX.Add(x);
                //                    isChanged = true;
                //                }
                //            }
                //        }

                //        if (!isChanged)
                //        {
                //            for (int y = 0; y < M; y++)
                //            {
                //                if (!skipY.Contains(y))
                //                {
                //                    bool temp = false;
                //                    int first = -1;

                //                    for (int j = 0; j < N; j++)
                //                    {
                //                        if (skipX.Contains(j))
                //                            continue;

                //                        if (first == -1)
                //                        {
                //                            first = j;
                //                            continue;
                //                        }

                //                        if (data[first][y] != data[j][y])
                //                        {
                //                            temp = true;
                //                            break;
                //                        }
                //                    }
                //                    if (!temp)
                //                    {
                //                        skipY.Add(y);
                //                        isChanged = true;
                //                    }
                //                }
                //            }
                //        }
                //    }
                //    result = isChanged;
                //}
                
                writer.WriteLine("Case #" + i + ": " + (result ? "YES" : "NO").ToString());
            }

            reader.Dispose();
            writer.Dispose();
        }

    }
}
