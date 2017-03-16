using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem1
{
    class Program
    {
        static bool C(char c)
        {
            return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
        }

        static bool HasCons(String s, int n)
        {
            for (int i = 0; i < s.Length; ++i)
            {
                int num = 0;
                for (num = 0; num < n && i+num < s.Length; ++num)
                {
                    if (!C(s[i + num]))
                    {
                        break;
                    }
                }
                if (num >= n)
                    return true;
            }
            return false;
        }

        static int NValue(String s, int n)
        {
            int num = 0;
            for (int i = 0; i < s.Length; ++i)
            {
                for (int j = i; j <= s.Length; ++j)
                {
                    if (HasCons(s.Substring(i, j - i), n))
                    {
                        num++;
                    }
                }
            }
            return num;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] line = Console.ReadLine().Trim(' ').Split(' ');
                int N = int.Parse(line[1]);
                Console.WriteLine("Case #{0}: {1}", i + 1, NValue(line[0].ToLower(), N));
            }
        }
    }
}
