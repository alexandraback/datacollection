using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _1B_1
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFilename = @"D:\Projects\GoogleCodeJam2015\1B-1\input\A-small-attempt3.in";
            string outputFilename = Path.Combine(Path.GetDirectoryName(inputFilename), Path.GetFileNameWithoutExtension(inputFilename) + ".out");

            using (var output = new StreamWriter(outputFilename))
            {
                using (var input = new StreamReader(inputFilename))
                {
                    int T = Convert.ToInt32(input.ReadLine());
                    for (int i = 1; i <= T; i++)
                    {
                        long N = long.Parse(input.ReadLine());
                        long R = Solve3(N);
                        output.WriteLine("Case #{0}: {1}", i, R);
                    }
                }
            }
        }
        /*
        public static long Solve(long N)
        {
            if (N <= 20)
                return N;
            long count = 1;
            long i = 1;

            while (i < N)
            {
                string s = i.ToString();
                if (s.Length >= 2 && s[s.Length - 1] > s[0])
                {
                    s = String.Join("", s.Reverse());
                    long j = long.Parse(s);
                    if (j <= N)
                        i = j;
                    else i++;
                }
                else
                {
                    i++;
                }
                count++;
            }

            return count;
        }
        */

        public static long Solve3(long N)
        {
            if (N <= 20)
                return N;

            long i = 0;
            int maxLen = N.ToString().Length;
            int l = 0;
            long count = 0;
            while (l < maxLen - 1)
            {
                l++;
                if (l == 1)
                    count += 10;
                else
                    count += 9 + 1 + long.Parse(new string('9', l - 1));
            }
            i = long.Parse("1" + new string('0', maxLen - 1));

            long maxC = 0;
            long maxInv = 0;
            long c = 0;

            while (c < N - i)
            {
                c++;
                long k = invert(i + c);
                if (k > maxInv && k <= N && k > i + c)
                {
                    maxInv = k;
                    maxC = c;
                }
            }

            if (maxC > 0)
            {
                count += maxC;
                i = maxInv;
                count++;
            }

            count += N - i;

            return count;
        }

        public static long Solve(long N)
        {
            if (N <= 20)
                return N;
            else
            {
                long i = 10;
                long count = 10;
                while (i < N)
                {
                    int l = i.ToString().Length;
                    long maxNumAtLength = (long)Math.Pow(10, l - 1) + long.Parse(new String('9', l - 2));
                    long maxNumToTry = Math.Min(N, maxNumAtLength);
                    long maxC = 0;
                    long maxInv = 0;
                    long c = 0;
                    while (c < maxNumToTry - i)
                    {
                        c++;
                        long k = invert(i + c);
                        if (k > maxInv && k <= N && k > i + c)
                        {
                            maxInv = k;
                            maxC = c;
                        }
                        else if (k > N)
                            break;
                    }

                    if (maxC > 0)
                    {
                        count += maxC;
                        i = maxInv;
                        count++;
                    }

                    while (i < N && i.ToString().Length == l)
                    {
                        i++;
                        count++;
                    }
                }

                return count;
            }
        }

        public static long invert(long X)
        {
            return long.Parse(String.Join("", X.ToString().Reverse()));
        }
    }
}
