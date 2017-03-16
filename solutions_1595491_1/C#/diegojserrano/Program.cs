using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CJ3
{
    class Program
    {
        static void Main(string[] args)
        {
            int c, n, s, p;

            c = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= c; i++)
            {
                string linea = Console.ReadLine();
                string []valores = linea.Split();
                n = Convert.ToInt32(valores[0]);
                s = Convert.ToInt32(valores[1]);
                p = Convert.ToInt32(valores[2]);

                int minOk = p * 3 - 2;
                int minS = minOk - 2;
                if (minS < 0) minS = 31;
                int cOk = 0;
                int cS = 0;
                for (int j = 0; j < n; j++)
                {
                    int v = Convert.ToInt32(valores[j + 3]);
                    if (v >= minOk) cOk++;
                    else if (v >= minS) cS++;
                }
                int res = cOk + Math.Min(s, cS);
                Console.WriteLine("Case #" + i + ": " + res);
            }
        }
    }
}

