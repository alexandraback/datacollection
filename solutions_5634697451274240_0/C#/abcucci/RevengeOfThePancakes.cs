using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2016
{
    public class RevengeOfThePancakes
    {
        public int Solve(string input)
        {
            int N = input.Length;
            bool[] sides = new bool[N];
            for (int i = 0; i < N; ++i)
            {
                sides[i] = (input[i] == '+');
            }

            int flip = 0;
            for (int i = 0; i < N - 1; ++i)
            {
                if (sides[i] != sides[i + 1])
                {
                    ++flip;
                }
            }
            if (sides[N - 1] == false)
            {
                ++flip;
            }

            return flip;
        }
    }
}
