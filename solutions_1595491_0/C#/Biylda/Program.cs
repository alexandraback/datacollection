using System;
using System.Collections.Generic;
using System.Text;

namespace Dancing_With_the_Googlers
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                string[] tokens = Console.ReadLine().Split(' ');
                int N = Int32.Parse(tokens[0]);
                int S = Int32.Parse(tokens[1]);
                int p = Int32.Parse(tokens[2]);
                int better_count = 0;
                int better_surprising_count = 0;
                for (int j = 0; j < N; ++j)
                {
                    int total = Int32.Parse(tokens[j+3]);
                    if (total == 0)
                    {
                        if (p == 0)
                            ++better_count;
                        continue;
                    }
                    int k = total / 3;
                    int d = total % 3;
                    int best = k + (d == 0 ? 0 : 1);
                    int surprising_best = best + (d == 1 ? 0 : 1);
                    if(best >= p)
                        ++better_count;
                    else if(surprising_best >= p)
                        ++better_surprising_count;
                }
                if(better_surprising_count > S)
                    better_surprising_count = S;
                Console.WriteLine("Case #{0}: {1}", i, better_count + better_surprising_count);
            }
        }
    }
}
