using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 1; i <= t; ++i)
            {
                int n = int.Parse(Console.ReadLine());
                Console.Write("Case #" + i + ": ");
                if (n == 0)
                    Console.WriteLine("INSOMNIA");
                else
                {
                    int m = 0;
                    bool[] digits = new bool[10];
                    int nd = 0;
                    while (nd < 10)
                    {
                        m += n;
                        for (int h = m; h != 0; h /= 10)
                            if (!digits[h % 10])
                            {
                                digits[h % 10] = true;
                                nd++;
                            }
                    }
                    Console.WriteLine(m);
                }
            }
        }
    }
}
