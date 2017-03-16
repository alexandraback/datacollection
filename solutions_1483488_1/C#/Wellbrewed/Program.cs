using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RecycledNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt"))
            {
                var T = int.Parse(sr.ReadLine());
                for (int i = 1; i <= T; i++)
                {
                    var result = string.Empty;

                    var input = sr.ReadLine();
                    var parts = input.Split(' ');
                    var A = int.Parse(parts[0]);
                    var B = int.Parse(parts[1]);

                    var order = parts[0].Length - 1;

                    int pairCount = CountPairs(order, A, B);
                    result = pairCount.ToString();

                    sw.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }

        private static int[] Orders = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, };

        private static int CountPairs(int order, int A, int B)
        {
            if (order == 0)
                return 0;

            var count = 0;

            for (int n = A; n < B; n++)
            {
                HashSet<int> uniques = new HashSet<int>();
                for (int ord = 0; ord < order; ord++)
                {
                    var E = Orders[ord];
                    int m = n / E + n % E * Orders[order - ord - 1];
                    if (m > n && m <= B)
                    {
                        if (uniques.Contains(m))
                            continue;

                        count++;
                        uniques.Add(m);
                    }
                }
            }
            return count;
        }
    }
}
