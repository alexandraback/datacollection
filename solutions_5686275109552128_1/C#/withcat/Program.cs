using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program
{

    static void Main(string[] args)
    {
        var T = int.Parse(Console.ReadLine());
        for (var t = 0; t < T; t++)
        {
            var D = int.Parse(Console.ReadLine());
            var P = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(v=>v).ToArray();

            var min = P[0];
            for (var eat = 1; eat < P[0]; eat++)
            {
                int div = 0;
                foreach (var p in P)
                {
                    if (p <= eat) break;
                    if (p%eat == 0) div += p/eat-1;
                    else div += p/eat;
                }
                if (div + eat < min) min = div + eat;
            }

            Console.WriteLine("Case #{0}: {1}", t + 1, min);
        }
    }
}
