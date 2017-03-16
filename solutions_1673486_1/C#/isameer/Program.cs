using System;
using System.Collections.Generic;
using System.Text;

namespace Password
{
    class Program
    {
        static void Main(string[] args)
        {
            
            long T = long.Parse(Console.ReadLine());

            for (long t = 1; t <= T; t++)
            {
                long A, B;
                string[] line = Console.ReadLine().Split();
                A = long.Parse(line[0]);
                B = long.Parse(line[1]);
                double[] p = new double[A];
                line = Console.ReadLine().Split();
                for (long i = 0; i < A; i++)
                    p[i] = double.Parse(line[i]);

                double[] expectedValues = new double[1 + A + 1];

                // Press enter and type again. This always takes B + 2 keystrokes
                expectedValues[expectedValues.Length - 1] = B + 2;

                for (long i = 0; i <= A; i++)
                {
                    double probability_of_no_errors_in_first_A_minus_i_characters = 1.0;
                    for (long j = 0; j < A - i; j++)
                        probability_of_no_errors_in_first_A_minus_i_characters = probability_of_no_errors_in_first_A_minus_i_characters * p[j];
                    expectedValues[i] = (B + 1 - A + 2*i) + (B + 1) * (1 - probability_of_no_errors_in_first_A_minus_i_characters);

                 //   Console.WriteLine(probability_of_no_errors_in_first_A_minus_i_characters);
                  //  Console.WriteLine(expectedValues[i]);
                }

                double best = double.MaxValue;

                for (long i = 0; i < expectedValues.Length; i++)
                    if (best > expectedValues[i])
                        best = expectedValues[i];

                Console.WriteLine("Case #" + t + ": " + best);
            }
        }
    }
}
