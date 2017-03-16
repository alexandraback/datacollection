using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

class Program
{
    const string InputPath = "C:\\CodeJam\\IO\\ProblemB\\B-small-attempt2.in";

    static void Main()
    {
        using (StreamReader reader = new StreamReader(InputPath))
        {
            using (StreamWriter writer = new StreamWriter(Path.ChangeExtension(InputPath, "out")))
            {
                int T = int.Parse(reader.ReadLine());
                for (int x = 1; x <= T; x++)
                {
                    int N = int.Parse(reader.ReadLine());
                    int[] a = new int[N];
                    int[] b = new int[N];

                    for (int i = 0; i < N; i++)
                    {
                        string[] input = reader.ReadLine().Split(' ');
                        a[i] = int.Parse(input[0]);
                        b[i] = int.Parse(input[1]);
                    }

                    int[] stars = new int[N];
                    int totalStars = 0;
                    bool tooBad = false;
                    int y = 0;

                    while (totalStars < (2 * N))
                    {
                        int i;
                        int iBest = -1;
                        int aMax = -1;

                        for (i = 0; i < N; i++)
                        {
                            if ((b[i] <= totalStars) && (stars[i] < 2) && (a[i] > aMax))
                            {
                                aMax = a[i];
                                iBest = i;
                            }
                        }

                        if (iBest >= 0)
                        {
                            totalStars += (2 - stars[iBest]);
                            stars[iBest] = 2;
                            y++;
                            continue;
                        }

                        iBest = -1;
                        int bMax = -1;
                        for (i = 0; i < N; i++)
                        {
                            if ((a[i] <= totalStars) && (stars[i] < 1) && (b[i] > bMax))
                            {
                                bMax = b[i];
                                iBest = i;
                            }
                        }

                        if (iBest >= 0)
                        {
                            totalStars++;
                            stars[iBest] = 1;
                            y++;
                            continue;
                        }

                        tooBad = true;
                        break;
                    }

                    writer.WriteLine("Case #" + x + ": " + (tooBad ? "Too Bad" : y.ToString()));
                }
            }
        }
    }
}
