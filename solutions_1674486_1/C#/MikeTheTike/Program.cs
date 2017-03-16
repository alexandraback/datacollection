using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Problem1
{
    class Program
    {

        static List<int>[] adjacencyMatrix;

        static void Main(string[] args)
        {
            var tests = Int32.Parse(Console.ReadLine());



            for (int testcase = 0; testcase < tests; testcase++)
            {

                var line = Console.ReadLine();

                var n = Int32.Parse(line);

                adjacencyMatrix = new List<int>[n];

                for (int i = 0; i < n; i++)
                {
                    // read adjacency matrix.
                    var adLint = Console.ReadLine();
                    var split = adLint.Split(' ');
                    var m = Int32.Parse(split[0]);
                    adjacencyMatrix[i] = new List<int>(m);
                    for (int j = 0; j < m; j++)
                    {
                        adjacencyMatrix[i].Add(Int32.Parse(split[j + 1]) - 1);
                    }
                }

                if (Solve(n))
                {
                    Console.WriteLine("Case #{0}: Yes", testcase + 1);
                }
                else
                {
                    Console.WriteLine("Case #{0}: No", testcase + 1);
                }

            }
        }

        private static bool Solve(int n)
        {
            for (int i = 0; i < n; i++)
            {
                var distinctParents = new List<int>();
    
                if (findAllParents(i, distinctParents))
                {
                    return true;
                }
            }

            return false;
        }

        private static bool findAllParents(int i, List<int> distinctParents)
        {
            foreach (var parent in adjacencyMatrix[i])
            {
                if (distinctParents.Contains(parent))
                {
                    return true;
                }

                distinctParents.Add(parent);
                if (findAllParents(parent, distinctParents))
                {
                    // bubble out.
                    return true;
                }
            }

            return false;
        }

        
    }
}
