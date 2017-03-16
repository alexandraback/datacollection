using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());
            for (int i = 0; i < testCaseCount; ++i)
            {
                DoWork(i);
            }
        }

        static void DoWork(int testCaseNumber)
        {
            int N = int.Parse(Console.ReadLine());

            Dictionary<int, int> soldiers = new Dictionary<int, int>();
            for (int i = 0; i < 2 * N - 1; ++i)
            {
                string[] heights = Console.ReadLine().Split(' ');
                foreach (string height in heights)
                {
                    int h = int.Parse(height);
                    if (soldiers.ContainsKey(h))
                    {
                        ++soldiers[h];
                    }
                    else
                    {
                        soldiers.Add(h, 1);
                    }
                }
            }

            List<int> result = new List<int>(N);
            foreach (KeyValuePair<int, int> kvp in soldiers)
            {
                if (kvp.Value % 2 == 1)
                {
                    result.Add(kvp.Key);
                }
            }
            result.Sort();
            
            Console.WriteLine("Case #{0}: {1}", testCaseNumber + 1, string.Join(" ", result));
        }
    }
}
