using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static int Solve(long A, long B)
        {
            return fairsquares.Count(x => x >= A && x <= B);
        }

        static List<long> fairsquares = new List<long>();

        static bool IsPalindrome(long x)
        {
            string s = x.ToString();
            for (int i = 0; i < s.Length / 2; i++)
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            return true;
        }

        static void Prepare()
        {
            for (long i = 0; i <= 10000000; i++)
                if (IsPalindrome(i) && IsPalindrome(i * i))
                    fairsquares.Add(i * i);
        }

        static void Main(string[] args)
        {
            Prepare();

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                long A = long.Parse(line[0]);
                long B = long.Parse(line[1]);

                Console.WriteLine("Case #{0}: {1}", t, Solve(A, B));
            }
        }
    }
}
