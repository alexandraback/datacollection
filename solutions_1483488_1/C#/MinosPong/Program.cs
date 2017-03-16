using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());

            for (int i = 0; i < size; i++)
            {
                int ret = 0;
                //SortedList<int, int> sl = new SortedList<int, int>();
                Console.Write("Case #");
                Console.Write(i+1);
                Console.Write(": ");                
                
                string inputs = Console.ReadLine();
                string[] ips = inputs.Split(' ');
                int digit = ips[0].Length;
                int xx = 1;
                int xxx = 1;
                for (int d = 1; d < digit; d++ )
                {
                    xx *= 10;
                    xxx += xx;
                }
                int n = int.Parse(ips[0]);
                int m = int.Parse(ips[1]);
                for (int num =n; num <= m; num++)
                {
                    int x = num;
                    while ((x = (x % xx)*10 + (int)(x / xx)) != num)
                    {
                        if (x <= m && x >= n)
                            ret++;
                    }
                }

                Console.WriteLine(ret/2);
            }
        }
    }
}
