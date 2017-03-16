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
            System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    int[] limits = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                    int cases = limits[0];
                    for (int i = 0; i < cases; i++)
                    {
                        int typed, total;
                        int[] casevalues = reader.ReadLine().Split(null).Select(s => int.Parse(s)).ToArray();
                        typed = casevalues[0];
                        total = casevalues[1];
                        double[] probab = reader.ReadLine().Split(null).Select(s => double.Parse(s)).ToArray();
                        double res = total + 2;
                        double ilo = 1;
                        for (int j = 0; j <= typed; j++)
                        {
                            double t = ilo * (total - j + 1 + typed - j) + (1 - ilo) * (total - j + total + 1 + 1 + typed - j);
                            if(j < typed)
                                ilo *= probab[j];
                            res = Math.Min(res, t);
                        }

                        writer.WriteLine("Case #" + (i + 1) + ": " + string.Format("{0:0.000000}",res));
                    }
                }
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
