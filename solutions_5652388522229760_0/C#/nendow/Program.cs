using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016Q_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (var i = 1; i <= T; i++)
            {
                var N = int.Parse(Console.ReadLine());
                if (N == 0)
                    Console.WriteLine("Case #{0}: INSOMNIA", i);
                else
                {
                    var f = new bool[10];
                    var n = 0;
                    while (f.Any(x => !x))
                    {
                        n += N;
                        var t = n;
                        while (t > 0)
                        {
                            f[t % 10] = true;
                            t /= 10;
                        }
                    }
                    Console.WriteLine("Case #{0}: {1}", i, n);
                }
            }
        }
    }
}
