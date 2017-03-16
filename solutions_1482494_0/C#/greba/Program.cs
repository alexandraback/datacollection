using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012QualificationProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader reader = File.OpenText(@"b.in"))
            using (TextWriter writer = File.CreateText(@"b.out"))
            {
                var cases = Convert.ToInt32(reader.ReadLine());
                for (int c = 1; c <= cases; c++)
                {
                    var N = Convert.ToInt32(reader.ReadLine());
                    int[] a = new int[N];
                    int[] b = new int[N];
                    for (int n = 0; n < N; n++)
                    {
                        var line = reader.ReadLine();
                        var split = line.Split(' ');
                        var ai = Convert.ToInt32(split[0]);
                        var bi = Convert.ToInt32(split[1]);
                        a[n] = ai;
                        b[n] = bi;
                    }

                    var levels = 0;
                    var starCount = 0;

                    while (true)
                    {
                        var aMin = a.Min();
                        var bMin = b.Min();

                        if (bMin == int.MaxValue)
                            break;

                        levels++;
                        if (bMin > starCount)
                        {
                            if (aMin > starCount)
                            {
                                levels = -1;
                                break;
                            }
                            else
                            {
                                starCount++;
                                //complete this level
                                var aMinIndex = -1;
                                var bValue = -1;
                                for (int n = 0; n < N; n++)
                                {
                                    if (a[n] == aMin && b[n] > bValue)
                                    {
                                        aMinIndex = n;
                                        bValue = b[n];
                                    }
                                }
                                a[aMinIndex] = int.MaxValue;
                            }
                        }
                        else
                        {
                            //complete this level
                            var bMinIndex = -1;
                            var twoStars = false;
                            for (int n = 0; n < N; n++)
                            {
                                if (b[n] == bMin)
                                {
                                    bMinIndex = n;
                                    if (a[n] != int.MaxValue)
                                    {
                                        twoStars = true;
                                        break;
                                    }
                                }
                            }
                            if (twoStars)
                            {
                                starCount++;
                            }
                            starCount++;
                            a[bMinIndex] = int.MaxValue;
                            b[bMinIndex] = int.MaxValue;
                        }
                    }
                    if (levels == -1)
                        writer.WriteLine("Case #{0}: {1}", c, "Too Bad");
                    else
                        writer.WriteLine("Case #{0}: {1}", c, levels);
                    writer.Flush();
                }
            }
        }
    }
}
