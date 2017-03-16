using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QR
{
    class B
    {
        static int getLessThan(int value, int[] arr)
        {
            return arr.Sum(x => (x-1)/value);
        }
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Append, FileAccess.Write)))
            { 
                using(var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    const int PMAX = 1000;
                    var t = int.Parse(Console.In.ReadLine());
                    for (int i = 1; i <= t; ++i)
                    {
                        var d = int.Parse(Console.In.ReadLine());
                        var inps = Console.In.ReadLine().Split(" ".ToCharArray());
                        var row = new int[d];
                        for (int j = 0; j < d; ++j) {
                            int.TryParse(inps[j], out row[j]);
                        }

                        int res = PMAX;
                        int add = 0;
                        for (int j = PMAX; j >= 1; --j)
                        {
                            res = Math.Min(res, getLessThan(j, row) + j);
                        }
                        
                        Console.WriteLine("Case #{0}: {1}", i, res);
                    }
                }
            }                       
        }
    }
}
