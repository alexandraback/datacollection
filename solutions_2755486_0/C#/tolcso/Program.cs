using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GreatWall
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader("C-small-attempt1.in");
            System.IO.StreamWriter sw = new System.IO.StreamWriter("output.out");
            int T = Convert.ToInt32(sr.ReadLine());
            int N;
            string[] buf;
            int[,] tribes; // di, ni, wi, ei, si, delta_di, delta_pi, delta_si
            int[] wall, needwall;
            for (int t = 1; t <= T; t++)
            {
                int count = 0;
                N = Convert.ToInt32(sr.ReadLine());
                tribes = new int[N, 8];
                for (int n = 0; n < N; n++)
                {
                    buf = sr.ReadLine().Split();
                    for (int i = 0; i < 8; i++)
                        tribes[n, i] = Convert.ToInt32(buf[i]);
                }
                int minwi = tribes[0,2];
                for (int n = 1; n < N; n++)
                {
                    if (tribes[n,2] < minwi)
                        minwi = tribes[n,2];
                }
                for (int n = 0; n < N; n++)
                {
                    if (tribes[n, 2] + tribes[n, 1] * tribes[n, 6] < minwi)
                        minwi = tribes[n, 2] + tribes[n, 1] * tribes[n, 6];
                }
                int maxe = tribes[0, 3] + tribes[0, 1] * tribes[0, 6];
                for (int n = 0; n < N; n++)
                {
                    if (tribes[n, 3] > maxe)
                        maxe = tribes[n, 3];
                }
                for (int n = 1; n < N; n++)
                {
                    if (tribes[n,3]+tribes[n,1]*tribes[n,6] > maxe)
                        maxe = tribes[n,3]+tribes[n,1]*tribes[n,6];
                }
                wall = new int[maxe - minwi + 1];
                needwall = new int[maxe - minwi + 1];
                int maxd = tribes[0, 0] + tribes[0, 1] * tribes[0, 5];
                for (int n = 1; n < N; n++)
                {
                    if (tribes[n, 0] + tribes[n, 1] * tribes[n, 5] > maxd)
                        maxd = tribes[n, 0] + tribes[n, 1] * tribes[n, 5];
                }

                for (int d = 0; d <= maxd; d++)
                {
                    for (int n = 0; n < N; n++)
                    {
                        if (tribes[n, 0] == d)
                        {
                            bool success = false;
                            for (int i = tribes[n, 2] - minwi; i < tribes[n, 3] - minwi; i++)
                                if (tribes[n, 4] > wall[i])
                                {
                                    if (tribes[n,4] > needwall[i])
                                        needwall[i] = tribes[n, 4];
                                    success = true;
                                }
                            if (success)
                                count++;
                            if (--tribes[n, 1] > 0)
                            {
                                tribes[n, 0] += tribes[n, 5];
                                tribes[n, 2] += tribes[n, 6];
                                tribes[n, 3] += tribes[n, 6];
                                tribes[n, 4] += tribes[n, 7];
                            }
                        }
                    }
                    for (int i = 0; i <= maxe - minwi; i++)
                    {
                        wall[i] = needwall[i];
                    }
                }
                sw.WriteLine("Case #" + t.ToString() + ": " + count.ToString());
            }
            sw.Close();
        }
    }
}
