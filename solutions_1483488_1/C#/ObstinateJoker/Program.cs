using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static int numDigits(int n)
        {
            int i;

            for (i = 0; n > 0; i++)
            {
                n /= 10;
            }

            return (i == 0 ? 1 : i);
        }

        static string process(string input)
        {
            string[] inputs = input.Split(' ');
            int a = int.Parse(inputs[0]);
            int b = int.Parse(inputs[1]);

            int n = 0;
            int d = numDigits(a);
            int d_offset = (int)Math.Pow(10, d-1);

            for (int i = a; i <= b; i++)
            {
                // Find the number of distinct pairs (this can be at most the number of digits in i)
                int num = i;
                List<int> pairs = new List<int>();

                // Find all unique pairs
                for (int j = 0; j < (d-1); j++)
                {
                    num = (num / 10) + ((num % 10) * d_offset);
                    if (num >= i || num < a || num > b || pairs.Contains(num) || numDigits(num) != d) continue;
                    pairs.Add(num);
                }

                // Add unique pairs to count
                n += pairs.Count;
            }
            
            return n.ToString();
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
