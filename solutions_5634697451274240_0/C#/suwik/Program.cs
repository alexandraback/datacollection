using System;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Runtime.Serialization;

namespace _629_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = long.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                var s = Console.ReadLine();
                s += '+';
                var last = s[0];
                int sum = 0;
                for (int j = 1; j < s.Length; j++)
                {
                    if (s[j] != last)
                    {
                        last = s[j];
                        sum++;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i+1, sum);
            }
        }
    }


}