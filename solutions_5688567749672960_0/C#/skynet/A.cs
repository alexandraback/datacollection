using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B
{
    class A
    {
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Create, FileAccess.Write)))
            {
                using (var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    var t = int.Parse(Console.In.ReadLine());
                    var array = new int[10000001];
                    for (var j = 1; j<=10000000; ++j)
                    {
                        array[j] = j;
                    }
                    var was = new bool[10000001];
                    var list = new List<int>();
                    list.Add(1);
                    was[1] = true;
                    int x = 0;
                    for (; x < list.Count && list[x] <= 10000000; ++x)
                    {
                        var cur = list[x];
                        if (cur < 10000000 && !was[cur + 1])
                        {
                            array[cur + 1] = Math.Min(array[cur + 1], array[cur] + 1);
                            list.Add(cur + 1);
                            was[cur + 1] = true;
                        }
                        var temp = cur;
                        var reverse = 0;
                        while (temp > 0)
                        {
                            reverse *= 10;
                            reverse += temp % 10;
                            temp /= 10;
                        }
                        if (!was[reverse])
                        {
                            array[reverse] = Math.Min(array[reverse], array[cur] + 1);
                            list.Add(reverse);
                            was[reverse] = true;
                        }
                    }
                    for (int i = 1; i <= t; ++i)
                    {
                        var n = long.Parse(Console.In.ReadLine());
                        Console.WriteLine("Case #{0}: {1}", i, array[n]);
                    }
                }
            }  
        }
    }
}
