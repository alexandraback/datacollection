using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace jam
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("");
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    int totalsum = 0;
                    int[] limits = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                    int cases = limits[0];
                    for (int i = 0; i < cases; i++)
                    {
                        totalsum = 0;
                        int[] casevalues = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                        List<Level> oneStarOrder = new List<Level>();
                        List<Level> twoStarOrder = new List<Level>();

                        int[,] levels = new int[casevalues[0],2];
                        for (int j = 0; j < casevalues[0]; j++)
                        {
                            int[] level = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                            var l = new Level() { oneStar = level[0], twoStars = level[1] };
                            oneStarOrder.Add(l);
                            twoStarOrder.Add(l);
                        }
                        oneStarOrder.Sort();
                        twoStarOrder = twoStarOrder.OrderBy(l => l.twoStars).ToList();
                        int stars = 0;
                        while (twoStarOrder.Count > 0)
                        {
                            if (twoStarOrder.First().twoStars <= stars)
                            {
                                Level f = twoStarOrder.Where(l => oneStarOrder.Contains(l)).FirstOrDefault();
                                if (f == null || f.twoStars > stars)
                                    f = twoStarOrder.First();
                                if(f.twoStars > stars)
                                {
                                    totalsum = -1;
                                    break;
                                }
                                twoStarOrder.Remove(f);
                                if (oneStarOrder.Contains(f))
                                {
                                    oneStarOrder.Remove(f);
                                    stars++;
                                }
                                stars++;

                            }
                            else
                            {
                                if (oneStarOrder.Count == 0)
                                {
                                    totalsum = -1;
                                    break;
                                }
                                var f = oneStarOrder.First();
                                if (f.oneStar > stars)
                                {
                                    totalsum = -1;
                                    break;
                                }
                                oneStarOrder.Remove(f);
                                stars++;
                            }
                            totalsum++;
                        }
                        writer.WriteLine("Case #" + (i + 1) + ": " + (totalsum >=0 ? totalsum.ToString() : "Too Bad"));
                    }
                }
            }
        }

        public class Level : IComparable
        {
            public int oneStar;
            public int twoStars;


            public int CompareTo(object obj)
            {
                var l = (Level)obj;
                if(oneStar == l.oneStar && twoStars == l.twoStars)
                    return 0;
                if(oneStar < l.oneStar)
                    return -1;
                if (oneStar == l.oneStar && twoStars > l.twoStars)
                    return -1;
                return 1;
            }
        }


        static int GCD(int a, int b)
        {
            int Remainder;

            while (b != 0)
            {
                Remainder = a % b;
                a = b;
                b = Remainder;
            }

            return a;
        }

    }
}
