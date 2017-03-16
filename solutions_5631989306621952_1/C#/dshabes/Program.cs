using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var s = Console.ReadLine();
                string last = "";
                last += s[0];
                for (int i = 1; i < s.Length; i++)
                {
                    if (s[i] >= last[0])
                        last = s[i] + last;
                    else
                        last += s[i];
                }
                Console.WriteLine("Case #{0}: {1}", testN, last);
            }
        }
    }
}
