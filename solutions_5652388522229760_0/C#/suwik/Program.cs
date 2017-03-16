using System;
using System.Runtime.Serialization;

namespace _629_B
{
    class Program
    {

        static bool[] seen = new bool[10];
        private static int seenNumber = 0;

        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine()); //200

            for (int i = 0; i < t; i++)
            {
                Console.Write("Case #{0}: ", i+1);
                for (int j = 0; j < 10; j++)
                {
                    seen[j] = false;
                }
                seenNumber = 0;
                var n = int.Parse(Console.ReadLine()); //i
                if (n == 0)
                {
                    Console.WriteLine("INSOMNIA");
                    continue;
                }
                int k = 0;
                int kn, mod, rest;
                do
                {
                    k++;
                    kn = k*n;
                    rest = kn;
                    while (rest > 0)
                    {
                        mod = rest % 10;
                        if (!seen[mod])
                        {
                            seen[mod] = true;
                            seenNumber++;
                        }
                        rest = rest / 10;
                    }
                } while (seenNumber < 10);
                Console.WriteLine(kn);
            }
        }
    }


}