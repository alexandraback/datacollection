using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static int Solve(int A, int B)
        {
            int count = 0;
            for (int i = A; i <= B; i++)
                if (fs[i])
                    count++;

            return count;
        }

        static bool[] fs = new bool[1001];

        static bool IsPalindrome(int x)
        {
            string s = x.ToString();
            for (int i = 0; i < s.Length / 2; i++)
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            return true;
        }

        static void Prepare()
        {
            for (int i = 0; i < 100; i++)
                if (i * i <= 1000 && IsPalindrome(i) && IsPalindrome(i * i))
                    fs[i*i] = true;
        }

        static void Main(string[] args)
        {
            Prepare();

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int A = int.Parse(line[0]);
                int B = int.Parse(line[1]);

                Console.WriteLine("Case #{0}: {1}", t, Solve(A, B));
            }
        }
    }
}
