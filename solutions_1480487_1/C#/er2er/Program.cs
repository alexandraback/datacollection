using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;

namespace _1b_a_safety
{
    class Program
    {
        static void Solve()
        {
            string s = Console.ReadLine();
            string[] sa = s.Split(' ');
            int cnt = int.Parse(sa[0]);
            int[] J = new int[222];
            int S = 0;
            for (int i = 1; i <= cnt; ++i)
            {
                S += J[i] = int.Parse(sa[i]);
            }

            for (int i = 1; i <= cnt; ++i)
            {
                double pmin = 0, pmax = 100, eps = 1e-9;
                while (pmax - pmin > eps)
                {
                    double p = (pmin + pmax) / 2;
                    // próba dla p - czy da się tak rozłożyć głosy, żeby wszyscy mieli więcej niż #i
                    double pval = (double)J[i] + p * (double)S,
                        rest = (double)S - p * (double)S;
                    bool possible = true;
                    for (int j = 1; j <= cnt; ++j)
                    {
                        if (j != i && J[j] < pval)
                        {
                            double need = pval - J[j];
                            if (need > rest)
                            {
                                possible = false;
                                break;
                            }
                            rest -= need;
                        }
                    }
                    if (possible)
                        pmin = p;
                    else
                        pmax = p;
                }
                double pr = Math.Round(pmin * 100, 7);
                Console.Write(" {0}", pr);
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
            int nCases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= nCases; ++c)
            {
                Console.Write("Case #{0}:", c);
                Solve();
            }
            //Console.ReadKey();
        }
    }
    /*
4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
     * */
}
