using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FairAndSquare
{
    class Program
    {
        static bool isSquare(int num)
        {
            int s = (int)Math.Sqrt(num);
            return s * s == num && isFair(s); // misread rules here... hacky code today
        }

        static bool isFair(int num)
        {
            String numAsDecimal = "" + num;
            List<char> temp = new List<char>(numAsDecimal.Reverse());
            return (new String(temp.ToArray()) == numAsDecimal);
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] nums = Console.ReadLine().Split(' ');
                int start = int.Parse(nums[0]);
                int end = int.Parse(nums[1]);
                int count = 0;
                for (int j = start; j <= end; ++j)
                {
                    if (isSquare(j) && isFair(j))
                    {
                        count++;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, count);
            }
        }
    }
}
