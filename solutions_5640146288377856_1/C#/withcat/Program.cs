using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var T = int.Parse(Console.ReadLine());
        for (var t = 0; t < T; t++)
        {
            var r1 = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();
            var R = r1[0];
            var C = r1[1];
            var W = r1[2];

            int cnt = 0;
            cnt += (C - 1) / W;
            for (int r = 1; r < R; r++)
            {
                cnt += C/W;
            }
            cnt += W;
            Console.WriteLine("Case #{0}: {1}", t + 1, cnt);
        }
    }
}
