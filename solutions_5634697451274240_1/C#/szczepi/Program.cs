using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace RevengeOfThePancakes
{
    class Solver
    {
        public Solver(string stack)
        {
            CreateStack(stack);         
        }

        public int Solve()
        {
            return RecurentSolver(stack.Length);
        }

        private int RecurentSolver(int stackLengthToFix)
        {
            if (stackLengthToFix == 0)
                return 0;

            int numberOfConnectedTruesFromRight = GetNumberOfConnectedTruesFromRight(stackLengthToFix);
            if (numberOfConnectedTruesFromRight > 0)
                return RecurentSolver(stackLengthToFix - numberOfConnectedTruesFromRight);


            bool performedRevertion = false;
            RevertConnectTruesFromLeft(stackLengthToFix, out performedRevertion);
            RevertWholeStack(stackLengthToFix);

            if (performedRevertion)
                return 2 + RecurentSolver(stackLengthToFix);

            return 1 + RecurentSolver(stackLengthToFix);
        }

        void RevertConnectTruesFromLeft(int stackLengthToRevert, out bool performedRevertion)
        {
            performedRevertion = false;
            for (int i = 0; i < stackLengthToRevert; ++i)
            {
                if (stack[i] == true)
                {
                    stack[i] = false;
                    performedRevertion = true;
                }
                else
                {
                    break;
                }
            }
        }

        void RevertWholeStack(int stackLengthToRevert)
        {
            for (int i = 0; i < stackLengthToRevert / 2; ++i)
            {
                bool temp = stack[i];
                stack[i] = stack[stackLengthToRevert - 1 - i];
                stack[stackLengthToRevert - 1 - i] = temp;
            }

            for (int i = 0; i < stackLengthToRevert; ++i)
                stack[i] = !stack[i];
        }


        private int GetNumberOfConnectedTruesFromRight(int stackLengthToFix)
        {
            int result = 0;
            for (int i = stackLengthToFix - 1; i >= 0; --i)
            {
                if (stack[i] == true)
                    ++result;
                else
                    break;
            }

            return result;
        }

        private void CreateStack(string stack)
        {
            this.stack = new bool[stack.Length];
            for (int i = 0; i < stack.Length; ++i)
                this.stack[i] = stack[i] == '+';
        }

        private bool[] stack;
    }
    class Program
    {
        static void Main(string[] args)
        {
            RunTests();
            int testCases = int.Parse(Console.ReadLine());
            for (int testCase = 1; testCase <= testCases; ++testCase)
            {
                Solver solver = new Solver(Console.ReadLine());
                Console.WriteLine("Case #{0}: {1}", testCase, solver.Solve());
            }
        }

        private static void RunTests()
        {
            Debug.Assert(new Solver("-").Solve() == 1);
            Debug.Assert(new Solver("+").Solve() == 0);
            Debug.Assert(new Solver("++").Solve() == 0);
            Debug.Assert(new Solver("+++").Solve() == 0);

            Debug.Assert(new Solver("--").Solve() == 1);
            Debug.Assert(new Solver("---").Solve() == 1);

            Debug.Assert(new Solver("-+").Solve() == 1);
            Debug.Assert(new Solver("-++").Solve() == 1);
            Debug.Assert(new Solver("--++").Solve() == 1);

            Debug.Assert(new Solver("+-").Solve() == 2);

            Debug.Assert(new Solver("---").Solve() == 1);
            Debug.Assert(new Solver("--+").Solve() == 1);
            Debug.Assert(new Solver("-+-").Solve() == 3);
            Debug.Assert(new Solver("-++").Solve() == 1);
            Debug.Assert(new Solver("+--").Solve() == 2);
            Debug.Assert(new Solver("+-+").Solve() == 2);
            Debug.Assert(new Solver("++-").Solve() == 2);
            Debug.Assert(new Solver("+++").Solve() == 0);
        }
    }
}
