using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static long GetDivisor(BigInteger n)
        {
            if(n % 2L == 0)
            {
                return 2L;
            }
            for(long i = 3; i <= 100000; i += 2)
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
            string input = "../../C-Large.in";

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

                    BigInteger high = new BigInteger(2);
                    for(var k = 0; k < N-2; k++)
                    {
                        high *= 2;
                    }

                    for(BigInteger it = new BigInteger(0); it < high;  it++)
                    {
                        Stack<int> st = new Stack<int>();

                        var buf = it;
                        while(buf > 0)
                        {
                            st.Push((int)(buf % 2));
                            buf = buf / 2;
                        }
                        string bits = "1" + string.Join("", st).PadLeft(N - 2, '0') + "1";

                        List<long> divisors = new List<long>();
                        for(long bs = 2; bs <= 10; bs++)
                        {
                            var values = bits.Select(x => new BigInteger(x - '0')).ToList().Select((x, index) =>
                            {
                                BigInteger temp = x;
                                for(int j = 0; j < N-1- index; j++)
                                {
                                    temp = temp * bs;
                                }
                                return temp;
                            });
                            BigInteger val = new BigInteger(0);
                            foreach(var v in values)
                            {
                                val += v;
                            }
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
