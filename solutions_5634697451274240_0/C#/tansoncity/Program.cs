using System;
using System.Text;

namespace Pancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());
            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample
                string cakes = Console.ReadLine();
                SolveTheProblem(sp + 1, cakes);
            }
        }

        static char Flip(char c)
        {
            if (c == '+')
                return '-';

            return '+';
        }

        static int NumberOfFlip(string cakes, char rightSide)
        {
            char wrongSide = Flip(rightSide);
            int lastWrong = cakes.LastIndexOf(wrongSide);

            if (lastWrong == -1) // no need to flip
                return 0;

            return NumberOfFlip(cakes.Substring(0, lastWrong + 1), wrongSide) + 1;
        }

        static void SolveTheProblem(int sp, string cakes)
        {
            int outValue;

            // Calculation
            outValue = NumberOfFlip(cakes, '+');

            // Print results
            Console.Write("Case #{0}: {1}", sp, outValue);
            Console.WriteLine();

        }
    }
}
