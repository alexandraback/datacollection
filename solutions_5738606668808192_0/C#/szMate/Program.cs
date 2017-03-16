using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class Program
    {
        static int howmanyones(long num)
        {
            int count = 0;
            while (num != 0)
            {
                if (num % 2 == 1) count++;
                num /= 2;
            }
            return count;
        }

        static bool check(long z, long u)
        {
            for (int i = 0; i < 32; i++)
            {
                if (howmanyones(z & u) > 1) return false;
                u <<= 1;
            }
            return true;
        }

        //source: http://www.dotnetperls.com/reverse-string
        public static string ReverseString(string s)
        {
            char[] arr = s.ToCharArray();
            Array.Reverse(arr);
            return new string(arr);
        }

        static long CCConvert(string num, long frombase)
        {
            long ret = 0;
            num = ReverseString(num);
            long h = 1;
            for (int i = 0; i < num.Length; i++)
            {
                if (num[i] == '1') ret += h;
                h *= frombase;
            }
            return ret;
        }

        static void Main(string[] args)
        {
            //Console.WriteLine(howmanyones(2)); Console.ReadLine();
            StreamReader sr = new StreamReader("C-small-attempt0(1).in");
            StreamWriter sw = new StreamWriter("outs.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] line = sr.ReadLine().Split();
                long N, J;
                N = Int64.Parse(line[0]);
                J = Int64.Parse(line[1]);
                List<long> set = new List<long>();
                List<long> set2 = new List<long>();

                long a, b;
                a = N - 1;
                b = N - a + 1;

                bool done = false;

                while (!done && a > b)
                {
                    b = N - a + 1;
                    long c = a - 1;
                    long d = b - 1;

                    long q = (long)Math.Pow(2, c - 1);
                    long oq = (long)Math.Pow(2, c);

                    while (!done && q % oq != 0)
                    {
                        long w = (long)Math.Pow(2, d - 1);
                        long ow = (long)Math.Pow(2, d);

                        while (!done && w % ow != 0)
                        {
                            //Console.WriteLine("{0} {1}", Convert.ToString(2 * q + 1, 2), Convert.ToString(2 * w + 1, 2));
                            if (check((2 * q + 1), (2 * w + 1)))
                            {
                                set.Add((2 * q + 1) * (2 * w + 1));
                                set2.Add(2 * w + 1);
                            }

                            if (set.Count == J) done = true;

                            w++;
                        }
                        q++;
                    }

                    a--;
                }

                //Console.WriteLine();
                sw.WriteLine("Case #{0}:", i + 1);
                for (int k = 0; k < set.Count; k++)
                {
                    sw.Write("{0}", Convert.ToString(set[k], 2));
                    string cucc = Convert.ToString(set2[k], 2);
                    for (int j = 2; j <= 10; j++)
                    {
                        sw.Write(" {0}", CCConvert(cucc, j));
                    }
                    sw.WriteLine();
                }
            }

            sw.Close();
        }
    }
}
