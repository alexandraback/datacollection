using System;
using System.Collections.Generic;
using System.Linq;

namespace qtn1
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCount = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < testCount; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            int result = 0;

            int R, C, W;

            string[] parts = Console.ReadLine().Trim().Split(' ');
            R = int.Parse(parts[0]);
            C = int.Parse(parts[1]);
            W = int.Parse(parts[2]);

            if (W == 1)
            {
                result = C;
            }
            else if (C == W)
            {
                result = C;
            }
            else
            {
                //C > W
                int diff = C - W;
                result = (int)Math.Ceiling(diff * 1.0 / W) + W;
            }

            result *= R;
            Console.WriteLine("Case #" + testNum + ": " + result);
        }
    }
}
