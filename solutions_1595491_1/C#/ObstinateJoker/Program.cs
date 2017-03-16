using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static string process(string input)
        {
            string[] inputs = input.Split(' ');
            int googlers = int.Parse(inputs[0]);
            int surprises = int.Parse(inputs[1]);
            int bestSubscore = int.Parse(inputs[2]);

            int maxOverBest = 0;
            for (int i = 3; i < (googlers + 3); i++)
            {
                int score = int.Parse(inputs[i]);
                
                if (score > (3*bestSubscore - 3)) {
                    // If X > 3P - 3, one of the sub-scores must be over P
                    maxOverBest++;
                } else if ((score > 0) && (score < 29) && (score >= (3*bestSubscore - 4)) && (surprises > 0)) {
                    // If X >= 3P - 4, we can organize it so that a subscore is over P,
                    // but only if score is between 1 and 28.
                    // See notes.txt for rough working
                    maxOverBest++;
                    surprises--;
                }
            }

            return maxOverBest.ToString();
        }

        static void Main(string[] args)
        {
            int numLines = int.Parse(Console.ReadLine());

            string output = "";
            for (int i = 0; i < numLines; i++)
            {
                string input = Console.ReadLine();

                output += "Case #" + (i + 1) + ": ";

                output += process(input);

                output += "\n";
            }

            Console.WriteLine(output);
        }
    }
}
