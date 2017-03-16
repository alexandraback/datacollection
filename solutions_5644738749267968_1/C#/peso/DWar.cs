using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.IO;

namespace DWar
{
    class DWar
    {
        static void Main(string[] args)
        {
            // Enforce English encoding of numbers
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            using (var rd = File.OpenText(args[0]))
            using (var wr = File.CreateText(args[1]))
            {
                int t = int.Parse(rd.ReadLine()); // test cases

                for (int i = 1; i <= t; i++)
                {
                    Console.WriteLine("Processing case #{0}", i);
                    
                    int N = int.Parse(rd.ReadLine());
                    double[] naomi = rd.ReadLine().Split(' ').Select(n => Convert.ToDouble(n)).ToArray();
                    double[] ken = rd.ReadLine().Split(' ').Select(n => Convert.ToDouble(n)).ToArray();

                    System.Diagnostics.Debug.Assert(ken.Length == N);
                    System.Diagnostics.Debug.Assert(naomi.Length == N);

                    Array.Sort(ken);
                    Array.Sort(naomi);

                    // largest values
                    int k9 = ken.Length - 1;
                    int n9 = naomi.Length - 1;
                    // smallest values
                    int k0 = 0;
                    int n0 = 0;

                    // Compute Deceptive War score
                    int d_score = 0;

                    for (int j = 0; j < N; j++)
                    {
                        // If naomi bottom beats ken bottom, do that
                        // otherwise play naomi bottom against ken top (and loose)
                        if (naomi[n0] > ken[k0])
                        {
                            d_score++;
                            n0++; k0++;
                        }
                        else
                        {
                            n0++; // forget k9, since we don't use it in this loop
                        }

                    }

                    // Compute War score
                    int w_score = 0;

                    for (int j = 0; j < N; j++)
                    {
                        // If naomi top looses to ken top, do that
                        // otherwise play naomi top against ken bottom (and win)
                        if (naomi[n9] < ken[k9])
                        {
                            n9--; k9--;
                        }
                        else
                        {
                            n9--; // k0++; forget k0, since we don't use it in this loop
                            w_score++;
                        }
                    }


                    wr.WriteLine("Case #{0}: {1} {2}", i, d_score, w_score);
                }
            }
        }
    }
}
