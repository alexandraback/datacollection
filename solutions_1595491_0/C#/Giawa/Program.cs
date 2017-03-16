using System;
using System.IO;
using System.Collections.Generic;

namespace DancingWithGooglers
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader input = new StreamReader(@"C:\Users\Montana\Desktop\B-small-attempt0.in"))
            using (StreamWriter output = new StreamWriter(@"C:\Users\Montana\Desktop\out2.txt"))
            {
                int count = int.Parse(input.ReadLine());

                for (int i = 0; i < count; i++)
                {
                    output.WriteLine("Case #{0}: {1}", (i + 1), FindScore(input.ReadLine()));
                }
            }
        }

        private static int FindScore(string line)
        {
            string[] split = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int c = int.Parse(split[0]);
            int s = int.Parse(split[1]);
            int p = int.Parse(split[2]);
            int baseScore = 0;

            List<int> googlers = new List<int>();
            for (int i = 0; i < c; i++)
                googlers.Add(int.Parse(split[i + 3]));

            // first cull out the ones that are guaranteed to have a score over
            for (int i = 0; i < googlers.Count; i++)
            {
                if (FindMaxNormal(googlers[i]) >= p) { baseScore++; googlers.RemoveAt(i--); }
            }

            // now we need to find the best case for assigning the surprises
            googlers.Sort();

            for (int i = 0; i < s && googlers.Count - 1 - i >= 0; i++)
            {
                if (FindMaxSurprised(googlers[googlers.Count - 1 - i]) >= p) baseScore++;
            }

            return baseScore;
        }

        private static int FindMaxNormal(int score)
        {
            if (score == 0) return 0;
            return (int)Math.Min(10, Math.Floor((double)(score + 2) / 3));
        }

        private static int FindMaxSurprised(int score)
        {
            if (score == 0) return 0;
            return (int)Math.Min(10, Math.Floor((double)(score + 4) / 3));
        }
    }
}
