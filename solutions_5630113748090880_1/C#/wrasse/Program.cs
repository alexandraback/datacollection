using System;
using System.Collections.Generic;
using System.Linq;

namespace _2016_1A_B
{
    class Program
    {
        static void Main()
        {
            var input = Console.ReadLine();
            var caseCount = int.Parse(input);

            for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                input = Console.ReadLine();
                var N = int.Parse(input);

                var heights = new Dictionary<int, int>();
                for (int ii = 0; ii < (2 * N - 1); ii++)
                {
                    input = Console.ReadLine();
                    int[] h = input.Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
                    for (int jj = 0; jj < N; jj++)
                    {
                        if (heights.ContainsKey(h[jj]))
                        {
                            heights[h[jj]] += 1;
                        }
                        else
                        {
                            heights.Add(h[jj], 1);
                        }
                    }
                }

                var missing = new int[N];
                int count = 0;
                foreach (var entry in heights)
                {
                    if (entry.Value % 2 > 0)
                    {
                        missing[count] = entry.Key;
                        count++;
                    }
                }

                Array.Sort(missing);
                string output = "";
                foreach (var entry in missing)
                {
                    if (output != "") output += " ";
                    output += entry.ToString();
                }

                Console.WriteLine($"Case #{caseNumber}: {output}");
            }
        }
    }
}
