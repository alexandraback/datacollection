using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FairAndSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "D:\\Data\\CodeJam\\1_3\\C-small-attempt0.in";
            string output = "D:\\Data\\CodeJam\\1_3\\C-small-attempt0.out";

            StreamReader sr = new StreamReader(input);
            int T = int.Parse(sr.ReadLine());
            long[] start = new long[T];
            long[] end = new long[T];
            int[] result = new int[T];
            string line;
            for (int k = 0; k < T; k++)
            {
                line = sr.ReadLine();
                string[] part = line.Split(' ');
                start[k] = long.Parse(part[0]);
                end[k] = long.Parse(part[1]);
                result[k] = GetResult(start[k], end[k]);
            }

            sr.Close();

            StreamWriter sw = new StreamWriter(output);
            for (int k = 0; k < T; k++)
            {
                sw.WriteLine("Case #{0}: {1}", k + 1, result[k]);
            }
            sw.Close();
        }

        static int GetResult(long start, long end)
        {
            int result = 0;
            long sqrt_start = (long)Math.Ceiling(Math.Sqrt(start));
            long sqrt_end = (long)Math.Sqrt(end);
            for (long i = sqrt_start; i <= sqrt_end; i++)
            {
                if (isPalindromes(i.ToString()) && isPalindromes((i * i).ToString()))
                    result++;
            }
            return result;
        }

        static bool isPalindromes(string number)
        {
            int len = number.Length;
            for (int i = 0; i <= (int)(len / 2); i++)
            {
                if (number[i] != number[len - i - 1])
                    return false;
            }
            return true;
        }
    }
}
