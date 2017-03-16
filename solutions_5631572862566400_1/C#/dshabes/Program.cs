using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_1A_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var N = int.Parse(Console.ReadLine());
                var bffs = Console.ReadLine().Split().Select(n => int.Parse(n) - 1).ToArray();
                var maxLoop = 0;
                var lengths = new int[N];
                var destinations = new int[N];
                var terminals = new int[N];
                for (int i = 0; i < N; i++)
                {
                    if (bffs[bffs[i]] == i)
                    {
                        lengths[i] = 1;
                        destinations[i] = i;
                        terminals[i] = 1;
                    }
                }
                for (int i = 0; i < N; i++)
                {
                    if (lengths[i] != 0) continue;
                    var ii = i;
                    var dd = 0;
                    do
                    {
                        lengths[ii] = -2;
                        ii = bffs[ii];
                        dd++;
                    } while (lengths[ii] == 0);
                    if (lengths[ii] == -1)
                    {
                        ii = i;
                        while (lengths[ii] != -1)
                        {
                            lengths[ii] = -1;
                            ii = bffs[ii];
                        }
                    } else if (lengths[ii] == -2)
                    {
                        var iii = ii;
                        ii = i;
                        while (ii != iii)
                        {
                            lengths[ii] = -1;
                            ii = bffs[ii];
                        }
                        int d = 0;
                        do
                        {
                            lengths[ii] = -1;
                            ii = bffs[ii];
                            d++;
                        } while (ii != iii);
                        if (d > maxLoop)
                            maxLoop = d;
                    } else
                    {
                        var iii = ii; 
                        ii = i;
                        if (terminals[destinations[iii]] < lengths[iii] + dd)
                            terminals[destinations[iii]] = lengths[iii] + dd;
                        while (lengths[ii] <= 0)
                        {
                            lengths[ii] = lengths[iii] + dd;
                            destinations[ii] = destinations[iii];
                            dd--;
                            ii = bffs[ii];
                        }
                    }
                }
                var result = 0;
                for (int i = 0; i < N; i++)
                {
                    result += terminals[i];
                }
                if (result < maxLoop)
                    result = maxLoop;

                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
