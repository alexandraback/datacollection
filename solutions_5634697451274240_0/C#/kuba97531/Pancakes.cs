using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class Pancake : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            return solve(NextWord());
        }

        //left is top of the stack - right is bottom of the stack
        private int solve(string pattern)
        {
            Console.WriteLine(pattern);
            if (!pattern.Contains('-'))
            {
                return 0;
            }
            if (pattern == "-") return 1;

            if (pattern[pattern.Length - 1] == '+')
            {
                return solve(pattern.Substring(0, pattern.Length - 1));
            }
            if (pattern[0] == '+')
            {
                return solve(swapTop(pattern)) + 1;
            }
            return solve(swapAll(pattern)) + 1;
        }

        private string swapTop(string pattern)
        {
            string result = "";
            bool top = true;
            foreach (var ch in pattern.ToCharArray())
            {
                if (ch == '+' && top)
                {
                    result += "-";
                }
                else
                {
                    top = false;
                    result += ch;
                }
            }
            return result;
        }

        private string swapAll(string pattern)
        {
            var result = "";
            foreach (var ch in pattern.ToCharArray())
            {
                if (ch == '+')
                {
                    result = "-" + result;
                }
                else
                {
                    result = "+" + result;
                }
            }
            return result;
        }

    }
}
