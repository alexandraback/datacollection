using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class FractilesEasy : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int k = NextInt();
            int c = NextInt();
            int s = NextInt();
            return string.Join(" ", Enumerable.Range(1, s).ToArray());
        }
    }
}
