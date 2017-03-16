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
            StreamReader reader = new StreamReader(args[0]);
            int count = int.Parse(reader.ReadLine());
            for (int i = 0; i < count; i++)
            {
                List<int> parameters = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => Int32.Parse(x)).ToList();
                int A = parameters[0];
                int B = parameters[1];

                int result = 0;
                for (int n = A; n <= B - 1; n++)
                {
                    int length = (n == 0) ? 1 : (int)Math.Log10(n) + 1;
                    int cycle = Cycle(n, length);
                    while (cycle != n)
                    {
                        if (cycle > n && cycle <= B)
                        {
                            result++;
                        }
                        cycle = Cycle(cycle, length);
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }
        }

        private static int Cycle(int integer, int length)
        {
            int div = integer / 10;
            int mod = integer % 10;

            return (integer / 10) + ((int)Math.Pow(10, length - 1) * mod);
        }
    }
}
