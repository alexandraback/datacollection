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
            var r1 = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var X = r1[0];
            var R = (r1[1] > r1[2]) ? r1[1] : r1[2];
            var C = (r1[1] > r1[2]) ? r1[2] : r1[1];

            var pass = true;

            if (X >= 7) pass = false;
            if ((R * C) % X != 0) pass = false;

            for (var r = X; r > X / 2; r--)
            {
                var c = X - r + 1;

                if (r > R || c > C)
                {
                    pass = false;
                }
                else if (r == R && c == C)
                {

                }
                else if (r == R || c == C)
                {
                    if (R * C < 3 * X)
                    {
                        if (r == R && c > 2) pass = false;
                        if (c == C && r > 2) pass = false;
                    }
                }
            }

            var win = "GABRIEL";
            if (!pass) win = "RICHARD";

            Console.WriteLine("Case #{0}: {1}", t + 1, win);
        }
    }
}
