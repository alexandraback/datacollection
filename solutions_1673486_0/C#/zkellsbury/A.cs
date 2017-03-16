using System;
using System.IO;
using System.Collections.Generic;

namespace GoogleCodeJam2012
{
    class MyPair
    {
        public char X { get; set; }
        public int Y { get; set; }
    }
    class A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("a.in");
            TextWriter fileOut = new StreamWriter("a.out");

            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 0; caseCount < countNum; caseCount++)
            {
                string[] specs = fileIn.ReadLine().Split(' ');
                int a = Int32.Parse(specs[0]);
                int b = Int32.Parse(specs[1]);

                string[] probVals = fileIn.ReadLine().Split(' ');
                float[] probs = new float[a];

                for (int i = 0; i < a; i++)
                {
                    probs[i] = float.Parse(probVals[i]);
                }

                List<string> permutations = new List<string>();
                createPermutations(a, permutations, "");

                float[] results = new float[a + 2];

                // Continuing typing
                float mult = 1;

                // Probability of the one right perm occurring
                foreach (float f in probs) { mult *= f; }

                results[0] = (mult * (b - a + 1)) + ((1.0f - mult) * (b + b - a + 2));

                // Backspace permutations
                for (int i = 1; i <= a; i++)
                {
                    float total = 0.0f;
                    int wrongCount = ((b - a) + 1 + (2 * i) + (b + 1));
                    int rightCount = ((b - a) + 1 + (2 * i));

                    foreach (string str in permutations)
                    {
                        if (str.Substring(0, a - i).Contains("x"))
                        {
                            total += determineProb(probs, str) * (float)wrongCount;
                        }
                        else
                        {
                            total += determineProb(probs, str) * (float)rightCount;
                        }
                    }

                    results[i] = total;
                }

                // Just return right away
                results[a + 1] = b + 2;

                float low = float.PositiveInfinity;
                // Find lowest
                foreach (float f in results)
                {
                    if (f < low) { low = f; }
                }

                fileOut.WriteLine("Case #" + (caseCount + 1) + ": " + low.ToString("0.000000"));
                Console.WriteLine("Case #" + (caseCount + 1) + " completed!");
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();
        }


        public static void createPermutations(int length, List<string> perm, string str)
        {
            if (str.Length < length)
            {
                createPermutations(length, perm, str + "o");
                createPermutations(length, perm, str + "x");
            }
            else
            {
                perm.Add(str);
            }
        }

        public static float determineProb(float[] probs, string str)
        {
            char[] arr = str.ToCharArray();
            float mult = 1.0f;
            for (int i = 0; i < str.Length; i++)
            {
                mult *= (arr[i] == 'x') ? (1 - probs[i]) : probs[i];
            }

            return mult;
        }
    }

}
