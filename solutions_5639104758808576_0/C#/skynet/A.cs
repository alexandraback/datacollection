using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QR
{
    class A
    {
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Append, FileAccess.Write)))
            { 
                using(var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    var t = int.Parse(Console.In.ReadLine());
                    for (int i = 1; i <= t; ++i)
                    {
                        var inps = Console.In.ReadLine().Split(" ".ToCharArray());
                        var sMax = int.Parse(inps[0]);
                        var arr = inps[1];
                        int res = 0;
                        int runSum = 0;
                        for (int j = 0; j <= sMax; ++j)
                        {
                            int val = arr[j] - '0';
                            res = Math.Max(res, j - runSum);
                            runSum += val;
                        }
                        Console.WriteLine("Case #{0}: {1}", i, res);
                    }
                }
            }                       
        }
    }
}
