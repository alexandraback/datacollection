using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamResearch
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemA\\A-large.in"))
            {
                using (var writer = new StreamWriter("C:\\Users\\Jon\\Desktop\\CodeJam\\Qualification\\ProblemA\\A-large.out"))
                {
                    var testCases = int.Parse(reader.ReadLine());
                    for(int tc = 1; tc <= testCases; tc++)
                    {
                        var n = int.Parse(reader.ReadLine());
                        var res = Solve(n);
                        if (n != 0)
                        {
                            var seen = new bool[10];
                            for (int i = 1; i <= res / n; i++)
                            {
                                var n2 = n * i;
                                while (n2 != 0)
                                {
                                    seen[n2 % 10] = true;
                                    n2 /= 10;
                                }
                                var valid = true;
                                for (int j = 0; j < 10; j++)
                                {
                                    if (!seen[j])
                                        valid = false;
                                }
                                if (valid && i != res / n)
                                {
                                    Console.WriteLine("Invalid calculation, calculated {0}, actual answer {1}", res / n, i);
                                    break;
                                }
                            }
                        }
                        writer.WriteLine("Case #{0}: {1}", tc, res == -1 ? "INSOMNIA" : res.ToString());
                        Console.WriteLine("Case #{0}: {1}", tc, res == -1 ? "INSOMNIA" : res.ToString());
                    }
                }
            }
            Console.ReadKey();
        }

        static long[] _cycles = new long[] { 1, 10, 5, 10, 5, 2, 5, 10, 5, 10 };

        static long Solve(long n)
        {
            if (n == 0)
            {
                return -1;
            }
            var numDigits = (long)Math.Log10(n * 10);
            var table = new long[numDigits + 1, 10];
            long cycleLength = 1;
            long TenToI = 1;
            for (long i = 0; i < numDigits; i++)
            {
                //cycleLength *= _cycles[(n / TenToI) % 10];
                cycleLength *= 10;
                TenToI *= 10;
                for (long j = 0; j < cycleLength; j++)
                {
                    var digit = (((n % TenToI) * (j + 1)) * 10 / TenToI) % 10;
                    if (table[i, digit] == 0)
                        table[i, digit] = j + 1;
                }
            }
            for (long i = 1; i <= 10; i++)
            {
                table[numDigits, i % 10] = (i * TenToI + n - 1) / n;
            }
            long num = 0;
            for (long i = 0; i < 10; i++)
            {
                long num2 = long.MaxValue;
                for(long j = 0; j < numDigits + 1; j++)
                {
                    if(table[j, i] > 0)
                        num2 = Math.Min(num2, table[j, i]);
                }
                num = Math.Max(num, num2);
            }
            if (num == long.MaxValue)
                return -1;
            return n * num;
        }
    }
}
