using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemBSmall
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfTestCases = int.Parse(Console.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                Trial();
            }
        }

        static void Trial()
        {
            var inputs = Console.ReadLine().Split(' ').Select((x) => (int.Parse(x)));
            int A = inputs.ElementAt(0), B = inputs.ElementAt(1), K = inputs.ElementAt(2);

            int count = 0;
            for (int i = 0; i < A; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    if ((i & j) < K)
                    {
                        count++;
                    }
                }
            }

            Console.WriteLine(count);
        }
    }
}
