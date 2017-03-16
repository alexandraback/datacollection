using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QR
{
    class C
    {
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Append, FileAccess.Write)))
            { 
                using(var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    var map = new int['z'];
                    map['1'] = 1;
                    map['i'] = 2;
                    map['j'] = 3;
                    map['k'] = 4;
                    var multmat = new int[5, 5] {
                    {0,0,0,0,0},
                    {0,1,2,3,4},
                    {0,2,-1,4,-3},
                    {0,3,-4,-1,2},
                    {0,4,3,-2,-1}
                    };
                    Func<int, int, int> mult = (int x, int y) => { return Math.Sign(x*y)*multmat[Math.Abs(x), Math.Abs(y)];};
                    var t = int.Parse(Console.In.ReadLine());
                    for (int i = 1; i <= t; ++i)
                    {
                        var inps = Console.In.ReadLine().Split(" ".ToCharArray());
                        var l = int.Parse(inps[0]);
                        var x = long.Parse(inps[1]);
                        if (x > 11) { // any 1,i,j,k in power of 4 equals to 1 - no need that many repeatitions
                            x -= (x - 11) / 4 * 4; 
                        }
                        var str = Console.In.ReadLine();
                        var arr = new int[(l+1) * x];
                        string res = "NO";
                        arr[0] = 1;
                        bool wasi = false, wasik = false;
                        for (int j = 1;j <= l * x; ++j) {
                            arr[j] = mult(arr[j - 1], map[str[(j - 1)%l]]);
                            wasi |= arr[j] == 2;
                            wasik |= wasi & (arr[j] == 4);
                        }
                        if (arr[l * x] == -1 && wasik) {
                            res = "YES";
                        }
                        Console.WriteLine("Case #{0}: {1}", i, res);
                    }
                }
            }                       
        }
    }
}
