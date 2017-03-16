using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2016
{
    public class CountingSheep
    {
        public string Solve(int N)
        {
            if (N == 0)
            {
                return "INSOMNIA";
            }

            int bit = 0;
            for (int i = 1; i < 200; ++i)
            {
                int number = i * N;

                for (int x = number; x > 0; x /= 10)
                {
                    int dig = (x % 10);
                    bit |= (1 << dig);
                }

                if (bit == 0x3FF)
                {
                    string answer = number.ToString();
                    return answer;
                }
            }

            return "INSOMNIA";
        }
    }
}
