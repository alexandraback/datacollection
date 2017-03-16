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
            StreamWriter sw = new StreamWriter(new FileStream("C-small.out", FileMode.Create));
            sw.WriteLine("Case #1:");

            int N = 16;
            int j = 50;
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
