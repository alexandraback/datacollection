using System;
using System.Numerics;

namespace Fractiles
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());
            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample
                string[] values = Console.ReadLine().Split(' ');
                int patternLength = int.Parse(values[0]);
                int complexity = int.Parse(values[1]);
                int studentCount = int.Parse(values[2]);

                SolveTheProblem(sp + 1, patternLength, complexity, studentCount);
            }
        }

        static void SolveTheProblem(int sp, int patternLength, int complexity, int studentCount)
        {
            string[] outValues;
            
            BigInteger powerStep = 1;
            for (int i = 1; i < complexity; i++)
            {
                powerStep *= patternLength;
            }

            if (studentCount < patternLength)
            {
                outValues = null;
            }
            else
            {
                outValues = new string[patternLength];
                for (int i = 0; i < patternLength; i++)
                {
                    outValues[i] = (powerStep * i + 1).ToString();
                }
            }

            // Print results
            Console.Write("Case #{0}:", sp);
            if (outValues != null)
            {
                for (int i = 0; i < outValues.Length; i++)
                {
                    Console.Write(" {0}", outValues[i]);
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine(" IMPOSSIBLE");
            }
        }
    }
}
