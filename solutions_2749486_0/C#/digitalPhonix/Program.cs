using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Template
{
    class Program
    {
        class Solver
        {
            int a, b;
            string solution;
            public Solver(int a, int b)
            {
                this.a = a;
                this.b = b;
                solution = "";
            }

            public void Solve()
            {
                if (a > 0)
                {
                    for (int i = 0; i < a; i++)
                    {
                        solution = solution + "WE";
                    }
                }
                else if (a < 0)
                {
                    for (int i = 0; i > a; i--)
                    {
                        solution = solution + "EW";
                    }
                }
                if (b > 0)
                {
                    for (int i = 0; i < b; i++)
                    {
                        solution = solution + "SN";
                    }
                }
                else if (b < 0)
                {
                    for (int i = 0; i > b; i--)
                    {
                        solution = solution + "NS";
                    }
                }
            }

            public String Solution()
            {
                return solution;
            }
        }

        static void Main(string[] args)
        {
            // Create solvers
            int testCases = Convert.ToInt32(Console.ReadLine());
            Solver[] solvers = new Solver[testCases];
            for (int t = 1; t <= testCases; t++)
            {
                String[] bounds = Console.ReadLine().Split(' ');
                int a = Convert.ToInt32(bounds[0]);
                int b = Convert.ToInt32(bounds[1]);

                solvers[t - 1] = new Solver(a, b);
            }

            // Wait for solvers to finish
            Parallel.For(0, testCases, (t) =>
            {
                Console.Error.WriteLine("Starting {0}...", t + 1);
                solvers[t].Solve();
                Console.Error.WriteLine("Finished {0}!", t + 1);
            });

            // Output results
            for (int t = 1; t <= testCases; t++)
            {
                Console.WriteLine("Case #{0}: {1}", t, solvers[t - 1].Solution());
            }
            Console.ReadLine();
        }
    }
}