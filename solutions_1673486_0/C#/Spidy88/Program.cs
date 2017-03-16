using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1A_A.Password_Problem
{
    class Program
    {
        static void Main(string[] args)
        {
            String fileName = "N:/Users/Spidy/Downloads/" + Console.ReadLine();
            StreamReader fileStream = new StreamReader(fileName);
            StreamWriter output = new StreamWriter("N:/Users/Spidy/Downloads/password-problem.txt");
            int numTestCases = Int32.Parse(fileStream.ReadLine());
            for (int testCase = 0; testCase < numTestCases; ++testCase)
            {
                String[] testCaseInput = fileStream.ReadLine().Split(' ');
                int a = Int32.Parse(testCaseInput[0]);
                int b = Int32.Parse(testCaseInput[1]);

                int power = (int)Math.Pow(2, a);
                double[] prob = new double[power];

                double strategy1_success_prob = 1.00d;
                double strategy2_success_prob = 1.00d;
                double strategy3_success_prob = 1.00d;
                double strategy4_success_prob = 1.00d;

                String[] probInput = fileStream.ReadLine().Split(' ');
                for (int i = 0; i < a; ++i)
                {
                    prob[i] = Double.Parse(probInput[i]);
                    strategy1_success_prob *= prob[i];
                    strategy2_success_prob *= ((double)i + 1.0d == a ? (1.0d - prob[i]) : prob[i]);
                    strategy3_success_prob *= ((double)i + 2.0d >= a ? (1.0d - prob[i]) : prob[i]);
                }
                strategy3_success_prob += strategy1_success_prob + (strategy2_success_prob * 2);
                strategy2_success_prob += strategy1_success_prob;

                double strategy1_failure_prob = 1.0d - strategy1_success_prob;
                double strategy2_failure_prob = 1.0d - strategy2_success_prob;
                double strategy3_failure_prob = 1.0d - strategy3_success_prob;

                int strategy1_success = b - a + 1;
                int strategy1_failure = b - a + 1 + b + 1;
                int strategy2_success = b - a + 3;
                int strategy2_failure = b - a + 3 + (a > 1 ? (b + 1) : 0);
                int strategy3_success = b - a + 5;
                int strategy3_failure = b - a + 5 + (a > 2 ? (b + 1) : 0);
                int strategy4_success = b + 2;

                double avg_strategy1 = (strategy1_success_prob * (double)strategy1_success) + (strategy1_failure_prob * (double)strategy1_failure);
                double avg_strategy2 = (strategy2_success_prob * (double)strategy2_success) + (strategy2_failure_prob * (double)strategy2_failure);
                double avg_strategy3 = (strategy3_success_prob * (double)strategy3_success) + (strategy3_failure_prob * (double)strategy3_failure);
                double avg_strategy4 = (strategy4_success_prob * (double)strategy4_success);

                Console.WriteLine("Strategy 1");
                Console.WriteLine("Success Key Count: " + strategy1_success);
                Console.WriteLine("Success Probability: " + strategy1_success_prob);
                Console.WriteLine("Failure Key Count: " + strategy1_failure);
                Console.WriteLine("Failure Probability: " + strategy1_failure_prob);
                Console.WriteLine("Average Key Count: " + avg_strategy1);
                Console.WriteLine();

                Console.WriteLine("Strategy 2");
                Console.WriteLine("Success Key Count: " + strategy2_success);
                Console.WriteLine("Success Probability: " + strategy2_success_prob);
                Console.WriteLine("Failure Key Count: " + strategy2_failure);
                Console.WriteLine("Failure Probability: " + strategy2_failure_prob);
                Console.WriteLine("Average Key Count: " + avg_strategy2);
                Console.WriteLine();

                Console.WriteLine("Strategy 3");
                Console.WriteLine("Success Key Count: " + strategy3_success);
                Console.WriteLine("Success Probability: " + strategy3_success_prob);
                Console.WriteLine("Failure Key Count: " + strategy3_failure);
                Console.WriteLine("Failure Probability: " + strategy3_failure_prob);
                Console.WriteLine("Average Key Count: " + avg_strategy3);
                Console.WriteLine();

                Console.WriteLine("Strategy 4");
                Console.WriteLine("Success Key Count: " + strategy4_success);
                Console.WriteLine("Success Probability: " + strategy4_success_prob);
                Console.WriteLine("Average Key Count: " + avg_strategy4);
                Console.WriteLine();

                double solution = Math.Min(avg_strategy1, Math.Min(avg_strategy2, Math.Min(avg_strategy3, avg_strategy4)));

                output.WriteLine("Case #" + (testCase + 1) + ": " + solution);
                Console.WriteLine("Case #" + (testCase + 1) + ": " + solution);
            }

            fileStream.Close();
            output.Close();
            Console.ReadKey();
        }
    }
}
