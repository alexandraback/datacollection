using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016Q_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (var i = 0; i < T; i++)
            {
                var ar = Console.ReadLine().Split(' ');
                var K = int.Parse(ar[0]);
                var C = int.Parse(ar[1]);
                var S = int.Parse(ar[2]);
                if (K > C * S)
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", i + 1);
                else
                {
                    var r = new List<long>();
                    var s = (K - 1) / C + 1;
                    for (var j = 0; j < s; j++)
                    {
                        var n = 0L;
                        for (int k = j * C; k < (j + 1) * C && k < K; k++)
                        {
                            n *= K;
                            n += k;
                        }
                        r.Add(n + 1);
                    }
                    Console.WriteLine("Case #{0}: {1}", i + 1, string.Join(" ", r));
                }
            }
        }
    }
}
