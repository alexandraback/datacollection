using System;
using System.Data;
using System.Linq;

namespace _629_B
{

    internal class Program
    {
        private static void Main(string[] args)
        {

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                
                var line = Console.ReadLine().Split(' ').Select(ulong.Parse).ToArray();
                var k = line[0];
                var c = line[1];
                var s = line[2];

                Console.Write("Case #{0}:", i + 1);
                if (s*c < k) Console.WriteLine(" IMPOSSIBLE");
                else
                {
                    ulong cnt = 0;
                    ulong lvl;
                    while (cnt < k)
                    {
                        ulong pos = cnt;
                        ulong tmp = cnt;
                        lvl = 1;
                        while (lvl <= c)
                        {
                            if (lvl >1) pos = pos*k + tmp;
                            lvl++;
                            cnt++;
                            if (tmp + 1 < k)
                            {
                                tmp++;
                            }
                        }
                        Console.Write(" " + (pos+1));
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}