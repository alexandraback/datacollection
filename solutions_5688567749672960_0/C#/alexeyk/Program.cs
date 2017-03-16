using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoundB_A
{
    class Program
    {

        static long reverse(long num){
            long res = 0;

            long power10 = 1;

            while (num != 0)
            {
                long letter = num % 10;
                if (letter != 0 || power10 != 1)
                {
                    res *= 10;
                    res += letter;
                    power10 *= 10;
                }
                num /= 10;
            }

            return res;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 0; t < T; t++)
            {
                long N = long.Parse(Console.ReadLine());

                HashSet<long> generated = new HashSet<long>();
                generated.Add(1);
                List<long> newList = new List<long>();
                newList.Add(1);

                long steps = 1;

                while (!generated.Contains(N))
                {
                    steps++;
                    var next = new List<long>();
                    foreach(var num in newList){

                        TryAdd(num + 1, generated, next);
                        TryAdd(reverse(num), generated, next);
                    }

                    newList = next;
                }

                Console.WriteLine("Case #{0}: {1}", t + 1, steps);
            }
        }

        private static void TryAdd(long p, HashSet<long> generated, List<long> next)
        {
            if (p > 90000000)
            {
                return;
            }

            if (!generated.Contains(p))
            {
                generated.Add(p);
                next.Add(p);
            }
        }
    }
}
