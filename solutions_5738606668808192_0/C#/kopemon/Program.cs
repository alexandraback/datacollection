using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static long GetDivisor(long n)
        {
            if(n % 2L == 0)
            {
                return 2L;
            }
            for(long i = 3; i <= n / i; i += 2)
            {
                if(n % i == 0)
                {
                    return i;
                }
            }
            return 0L;
        }

        static void Main(string[] args)
        {
            string input = "../../C-small-attempt0.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int c = 1; c <= T; c++)
                {
                    Console.WriteLine($"Case #{c}:");
                    tw.WriteLine($"Case #{c}:");

                    int count = 0;

                    var data = tr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
                    var N = data[0];
                    var J = data[1];

                    for(long it = 0; it < (2 << (N - 2)); it++)
                    {
                        string bits = "1" + Convert.ToString(it, 2).PadLeft(N-2, '0') + "1";

                        List<long> divisors = new List<long>();
                        for(long bs = 2; bs <= 10; bs++)
                        {
                            long val = bits.Select(x => (int)(x - '0')).ToList().Select((x, index) => (long)x * (long)Math.Pow(bs, N - index - 1)).Sum();
                            var div = GetDivisor(val);
                            if(div == 0L)
                            {
                                break;
                            }
                            else
                            {
                                divisors.Add(div);
                            }
                        }

                        if(divisors.Count() == 9)
                        {
                            Console.WriteLine(bits + " " + string.Join(" ", divisors));
                            tw.WriteLine(bits + " " + string.Join(" ", divisors));
                            count++;
                        }
                        if(count == J)
                        {
                            break;
                        }
                    }

                }
            }
        }
    }
}
