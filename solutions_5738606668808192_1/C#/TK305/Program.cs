using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamC
{
    class Program
    {
        static long toBase10(long num, long b)
        {
            long converted = 0;
            long multiplier = 1;

            while (num > 0)
            {
                long digit = (long)(num % 10);
                converted += digit * multiplier;
                num = num/10;
                multiplier *= b;
            }
            return converted;
        }
        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter(new FileStream("C-large.out", FileMode.Create));
            sw.WriteLine("Case #1:");

            /* When N = 32, the number is too big to be handled. 
             * However, we know that the program can handle N = 16.
             * Let string X represents one of the jamcoins of length 16.
             * If X was a multiple of k when it is interpreted in base b, X = kt.
             * Then X*b^16+X = kt*b^16 + kt = k(t*b^16+t) is also a multiple of k in base b.
             * Also X*b^16+X in base b can be represented as a string XX as the length of X is 16.
             * Then, XX will be of length 32.
             * Then, X*b^16+X is a jamcoin of length 32.
             * Let's use this property as we can find 500 jamcoins of length 16.
            */
            int N = 16;
            int j = 500;
            int count = 0;

            Dictionary<string, List<long>> dic = new Dictionary<string, List<long>>();

            long max_middle = (long)Math.Pow(2, (double)N - 2);
            long const_part = (long)Math.Pow(2, (double)N - 1) + 1;

            for (long k = 0; k < max_middle && count < j; k++)
            {
                string middle = Convert.ToString(k * 2 + const_part, 2);
                long current_num = long.Parse(middle);
                bool jamcoin = true;
                dic[middle] = new List<long>();
                for (long base_num = 2; base_num <= 10 && jamcoin; base_num++)
                {
                    long converted = toBase10(current_num, base_num);
                    bool not_prime = false;
                    long square_root = (long)Math.Pow((double)converted, 0.5) + 1;
                    for (long z = 2; z < square_root && !not_prime; z++)
                    {
                        if (converted % z == 0)
                        {
                            dic[middle].Add(z);
                            not_prime = true;
                        }
                    }
                    if (!not_prime)
                    {
                        jamcoin = false;
                        dic.Remove(middle);
                    }
                }
                if (jamcoin)
                {
                    sw.Write(middle);
                    sw.Write(middle);
                    foreach (long element in dic[middle])
                        sw.Write(" {0}", element);
                    count++;
                    if (count != j)
                        sw.WriteLine();
                }
            }
            sw.Close();
        }
    }
}
