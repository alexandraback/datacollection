using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Runtime.Serialization;
using Newtonsoft.Json;

namespace _629_B
{
    class Program
    {
        static void Main(string[] args)
        {
            const ulong maxPrime = 10000000;
            string json = File.ReadAllText(maxPrime + ".txt");
            var primes = JsonConvert.DeserializeObject<List<ulong>>(json);
            //Precomputation
            /*for (ulong i = primes[primes.Count-1] + 1; i < maxPrime; i++)
            {
                if (i%(maxPrime/10) == 0) Console.WriteLine(i/(maxPrime/10));
                int j = 0;
                bool prime = true;
                while (primes[j]*primes[j] <= i && j < primes.Count)
                {
                    if (i%primes[j] == 0)
                    {
                        prime = false;
                        break;
                    }
                    j++;
                }
                if (prime) primes.Add(i);
            }
            json = JsonConvert.SerializeObject(primes);
            File.WriteAllText(maxPrime + ".txt", json);
            */
            var t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                Console.WriteLine("Case #{0}:", t);
                var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int n = line[0]; //32;//16;
                int j = line[1];//500;//50;

                ulong num = Convert.ToUInt64(Math.Pow(2, n-1)) - 1;
                ulong max = Convert.ToUInt64(Math.Pow(2, n)) - 1;
                bool[] bits = new bool[n];
                ulong current = num;
                int jamcoins = 0;

                while (current < max && jamcoins < j)
                {
                    List<ulong> divisors = new List<ulong>();
                    current += 2;
                    CalculateBits(current, bits, n);
                    for (int k = 2; k <= 10; k++)
                    {
                        var bas = InterpretInBase(bits, k);
                        var divisor = CalculateDivisor(bas, primes);
                        if (divisor == 0)
                        {
                            break;
                        }
                        else
                        {
                            divisors.Add(divisor);
                        }
                    }
                    if (divisors.Count == 9)
                    {
                        Console.Write(AsString(bits) + " ");
                        foreach (var divisor in divisors)
                        {
                            Console.Write(divisor + " ");
                        }
                        Console.WriteLine();
                        jamcoins++;
                    }
                }
            }
        }

        private static void CalculateBits(ulong current, bool[] bits, int n)
        {
            var tmp = current;
            for (int k = 0; k < n; k++)
            {
                bits[k] = (tmp & 1) > 0;
                tmp = tmp >> 1;
            }
        }

        private static ulong CalculateDivisor(ulong num, List<ulong> primes)
        {
            int i = 0;
            while (i < primes.Count && primes[i]*primes[i] <= num)
            {
                if (num%primes[i] == 0) return primes[i];
                i++;
            }
            return 0;
        }

        private static ulong InterpretInBase(bool[] bits, int bas)
        {
            ulong ret = 0;
            for (int i = 0; i < bits.Length; i++)
            {
                if (bits[i]) ret += (ulong)Math.Pow(bas, i);
            }
            return ret;
        }

        private static string AsString(bool[] bits)
        {
            string s = "";
            for (int i = 0; i < bits.Length; i++)
            {
                s = (bits[i] ? "1" : "0") + s;
            }
            return s;
        }
    }


}