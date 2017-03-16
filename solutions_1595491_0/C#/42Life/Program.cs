/* C# Program
 * Google Code Jam 2012
 * Qualification Round
 * Problem B. Dancing With the Googlers
 * 
 * Copyright Craig A Maher - 2012
 */
using System;
using System.IO;

namespace CodeJamQR12PB {
    class Program {
        static void Main(string[] args) {
            //files
            StreamReader input;
            StreamWriter output;
            input = new StreamReader("B-small-attempt0.in");
            output = new StreamWriter("B-small-attempt0.out");

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i) {
                outString = Process(input.ReadLine());
                output.WriteLine("Case #{0}: {1}", i, outString);
                Console.WriteLine("Case #{0}: {1}", i, outString);
            }

            input.Close();
            output.Close();


            Console.ReadLine();
        }

        private static string Process(string input) {
            String outString = String.Empty;
            int N;// the number of Googlers
            int S;//  the number of surprising triplets of scores
            int p;// Result of at least this number
            int[] googlers; // the total points of the Googlers
            string[] numbers = input.Split(' ');

            N = int.Parse(numbers[0]);
            S = int.Parse(numbers[1]);
            p = int.Parse(numbers[2]);
            googlers = new int[N];
            for (int i = 0; i < googlers.Length; ++i)
            {
                googlers[i] = int.Parse(numbers[3 + i]);
            }
            int min;//the minimum number to have a score aove p without being suprising
            int minSuprising;// the minimum score to have a score higher then three with a suprising result
            int count = 0;
            if (p >= 2) {
                min = p + 2 * (p - 1);
                minSuprising = p + 2 * (p - 2);
            } else {
                min = p;
                minSuprising = p;
            }

            for (int i = 0; i < googlers.Length; ++i) {
                if (googlers[i] >= min) {
                    count++;
                } else if (googlers[i] >= minSuprising && S > 0) {
                    S--;
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
