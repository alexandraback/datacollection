using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class FractilesHard : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int k = NextInt();
            int c = NextInt();
            int s = NextInt();
            if (k > c * s)
            {
                return "IMPOSSIBLE";
            }
            int l = 0;
            var result = new List<long>();
            while (l<k)
            {
                result.Add(location(l, c, k));
                l += c;
            }
            return string.Join(" ", result);
        }

        long location(int startIndex, int length, int k)
        {
            long r = 0;
            for (int i = startIndex; i < Math.Min(startIndex + length, k); i++)
            {
                r = r * k + i;
            }
            return r + 1;
        }
    }
}
