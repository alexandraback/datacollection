using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                // Read input
                var input = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                var L = input[0].ToLower();
                var N = long.Parse(input[1]);
                // Process
                var result = GetResult(L, N);
                // Write Output
                Console.WriteLine("Case #{0}: {1}", t + 1, result);
            }
        }

        static long GetResult(string L, long N)
        {
            List<Tuple<long, long>> blocks = new List<Tuple<long, long>>();
            var lastVowelIndex = -1;
            for (int i = 0; i < L.Length; i++)
            {
                if (IsVowel(L[i]))
                {
                    lastVowelIndex = i;
                }
                else
                {
                    if (i - lastVowelIndex >= N)
                    {
                        blocks.Add(new Tuple<long, long>(i - N + 1, i));
                    }
                }
            }

            long result = 0;
            for (int i = 0; i < blocks.Count; i++)
            {
                var item = blocks[i];
                if (i != blocks.Count - 1)
                {
                    var nextItem = blocks[i + 1];
                    result += (item.Item1 + 1) * (nextItem.Item2 - item.Item2);
                }
                else
                {
                    result += (item.Item1 + 1) * (L.Length - item.Item2);
                }
            }

            return result;
        }

        static bool IsVowel(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }

        static bool IsConsonant(char c)
        {
            return !IsVowel(c);
        }
    }
}
