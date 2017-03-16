using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamRound1C
{
    class Solution
    {
        static void Main(string[] args)
        {
            string output = string.Empty;
            string[] lines = File.ReadAllLines("A-small-attempt2.in");
            //int n = Convert.ToInt32(Console.ReadLine());
            int n = Convert.ToInt32(lines[0]);
            List<string> results = new List<string>();
            Dictionary<long, bool> powerOfTwo = new Dictionary<long, bool>();
            Dictionary<long, Dictionary<long, int>> dictionary = new Dictionary<long, Dictionary<long, int>>(); //For Dynamic Programming

            long power = 1;
            for(int i = 0; i < 40; i++)
            {
                power = power * 2;
                powerOfTwo.Add(power, true);
            }

            for (int i = 1; i <= n; i++)
            {
                string[] pqSplit = lines[i].Split('/');
                long p = Convert.ToInt64(pqSplit[0]);
                long q = Convert.ToInt64(pqSplit[1]);
                long gcd = Gcd(p, q);
                long qPrime = q / gcd;
                if (!powerOfTwo.ContainsKey(qPrime))
                {
                    results.Add("impossible");
                }
                else
                {
                    int generation = 0;
                    while ((double)p / (double)q < 1.0)
                    {
                        if (dictionary.ContainsKey(p) && dictionary[p].ContainsKey(q))
                        {
                            results.Add(dictionary[p][q].ToString());
                            break;
                        }
                        else
                        {
                            q = q / 2;
                            generation++;
                        }
                    }
                    if (dictionary.ContainsKey(p) && !dictionary[p].ContainsKey(q))
                    {
                        dictionary[p].Add(q, generation);
                    }
                    else if (!dictionary.ContainsKey(p))
                    {
                        dictionary.Add(p, new Dictionary<long, int>());
                        dictionary[p].Add(q, generation);
                    }
                    results.Add(generation.ToString());
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int c = 1; c <= n; c++)
            {
                Console.WriteLine("Case #{0}: {1}", c, results[c - 1]);
                sb.AppendLine(string.Format("Case #{0}: {1}", c, results[c - 1]));
            }
            output = sb.ToString();
            File.WriteAllText("A-small-attempt2.out", output);
            Console.ReadKey();
        }

        public static long Gcd(long a, long b)
        {
            long remainder;

            while (b != 0)
            {
                remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }
    }
}
