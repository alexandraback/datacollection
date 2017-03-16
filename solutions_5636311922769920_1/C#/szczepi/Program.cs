using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Fractiles
{
    class Solver
    {
        public Solver(int originalLength, int complexity, int numberOfStudents)
        {
            this.originalLength = originalLength;
            this.complexity = complexity;
            this.numberOfStudents = numberOfStudents;
        }

        public String Solve()
        {
            if (complexity == 1)
            {
                if (numberOfStudents == originalLength)
                    return CreateSequence(originalLength, 1);

                return Impossible;
            }
            else
            {
                if (originalLength > 1)
                {
                    if (numberOfStudents >= originalLength - 1)
                        return CreateSequence(originalLength - 1, 2);

                    return Impossible;
                }
                else
                {
                    if (numberOfStudents == 1)
                        return CreateSequence(1, 1);

                    return Impossible;
                }
            }
        }

        public String CreateSequence(int length, int startingPosition)
        {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < length; ++i)
                stringBuilder.Append((i + startingPosition).ToString() + " ");

            return stringBuilder.ToString();
        }

        private const String Impossible = "IMPOSSIBLE";
        int originalLength;
        int complexity;
        int numberOfStudents;
    }
    class Program
    {
        static void Main(string[] args)
        {
            int testCases = int.Parse(Console.ReadLine());
            for (int testCase = 1; testCase <= testCases; ++testCase)
            {
                String[] tokens = Console.ReadLine().Split(' ');
                int originalLength = int.Parse(tokens[0]);
                int complexity = int.Parse(tokens[1]);
                int numberOfStudents = int.Parse(tokens[2]);

                Solver solver = new Solver(originalLength, complexity, numberOfStudents);
                Console.WriteLine("Case #{0}: {1}", testCase, solver.Solve());
            }
        }
    }
}
