using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int CN = int.Parse(Console.ReadLine());
            for (int cn = 1; cn <= CN; cn++)
            {
                string[] line = Console.ReadLine().Split(' ');
                UInt64 R = UInt64.Parse(line[0]), T = UInt64.Parse(line[1]);
                UInt64 A = T, a = 2 * R + 1, sa = a;
                UInt64 n = 0;
                while (A >= sa)
                {
                    n++;
                    sa += a + (n << 2);
                }

                string msg = "Case #" + cn + ": " + n;
                Console.WriteLine(msg);
                Console.Error.WriteLine(msg + " " + R + " " + T);
            }
        }
    }
}
