using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016
{
    class Program
    {

/*
        static int toBase(int num, int toBase)
        {
            for (int d = 0; d < 32; d++)
            {
                if ((start & (1 << d)) > 0)
                {
                    upper = BigInteger.Add(upper, BigInteger.Pow(baseN, d));
                }
            }
        }*/

        private static bool test = false;
        // c:\users\erickul\documents\visual studio 2015\Projects\GCJ2016\GCJ2016\Program.cs
        static void Main(string[] args)
        {
            string file = "c-small-attempt0.in";
            if (test) file = "test.txt";

            string[] lines = File.ReadAllLines($"c:\\users\\erickul\\downloads\\{file}" );
            StringBuilder output = new StringBuilder();
            int t = int.Parse(lines[0]);
            int nextLine = 1;
            for (int i = 1; i <= t; i++)
            {
                output.Append($"CASE #{i}: ");
                int n = int.Parse(lines[nextLine]);
                nextLine++;
                string[] bff = lines[nextLine].Split(' ');
                nextLine++;
                int[] bffn = new int[n];
                for (int j = 0; j < n; j++)
                {
                    bffn[j] = int.Parse(bff[j]);

                }

                int[] status = new int[n];
                int[] length = new int[n];
                Dictionary<int, List<int>> conn = new Dictionary<int, List<int>>();
                int max = 0;
                for (int j = 0; j < n; j++)
                {
                    bool[] used = new bool[n];
                    used[j] = true;
                    int last = j;
                    int prev = -1;
                    int on = bffn[j] - 1;
                    int num = 1;
                    conn[j] = new List<int>();
                    conn[j].Add(j);
                    while (!used[on])
                    {
                        conn[j].Add(on);
                        num++;
                        used[on] = true;
                        prev = last;
                        last = on;
                        on = bffn[on] - 1;
                    }

                    if (on == prev)
                    {
                        length[j] = num;
                        status[j] = 1;
                    }
                    else if (on == j)
                    {
                        length[j] = num;
                        max = Math.Max(num, max);
                        status[j] = 2;
                    }
                    else
                    {
                        status[j] = 3;
                    }
                }


                int[] usedF = new int[n];
                while (true)
                {
                    int maxLeft = 0;
                    int maxI = -1;
                    for (int j = 0; j < n; j++)
                    {
                        if (status[j] == 1 && usedF[j] == 0)
                        {
                            bool saw1 = false;
                            bool good = true;
                            foreach (var i1 in conn[j])
                            {
                                if (!saw1 && usedF[i1] == 2)
                                {
                                    good = false;
                                    break;
                                }
                                else if (usedF[i1] == 1)
                                {
                                    saw1 = true;
                                }
                            }

                            if (!good)
                            {
                                continue;
                            }

                            if (length[j] > maxLeft)
                            {
                                maxLeft = length[j];
                                maxI = j;
                            }
                        }
                    }


                    if (maxI > -1)
                    {
                        foreach (var i1 in conn[maxI])
                        {
                            usedF[i1]++;
                            if (i1 != maxI && i1 != conn[maxI].Last())
                            {
                                usedF[i1]++;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                int tot = Math.Max(usedF.Where(x => x>0).Count(), max);
                output.AppendLine(tot.ToString());
            }
            Console.WriteLine(output.ToString());
            File.WriteAllText(@"c:\users\erickul\downloads\a.out", output.ToString());
        }
    }
}
