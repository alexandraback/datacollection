using System;
using System.IO;
using System.Linq;

namespace B
{
    class SolverB
    {
        public string SolveOne(TextReader input)
        {
            var args = input.ReadLine().Split(' ').Select(int.Parse).ToList();
            int A = args[0];
            int B = args[1];
            int K = args[2];

            if (K >= A && K >= B)
            {
                return (A*B).ToString();
            }

            int cnt = 0;
            for (int a = 0; a < A; ++a)
            {
                for (int b = 0; b < B; ++b)
                {
                    if ((a & b) < K)
                    {
                        ++cnt;
                    }
                }
            }
            return cnt.ToString();
        }
    }
}