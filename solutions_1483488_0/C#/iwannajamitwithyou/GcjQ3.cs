using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GcjQ3RecycledNumbers
{
    class GcjQ3
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("input.txt"))
            using (var writer = new StreamWriter("output.txt"))
            {
                int T = int.Parse(reader.ReadLine());
                for (int t = 1; t <= T; t++)
                {
                    var parts = reader.ReadLine().Split(' ');
                    int A = int.Parse(parts[0]);
                    int B = int.Parse(parts[1]);

                    int bigMod = 1;
                    while (bigMod <= A)
                        bigMod *= 10;

                    int res = 0;
                    for (int k = A; k <= B; k++)
                    {
                        int newK = k;
                        while (true)
                        {
                            newK = newK * 10;
                            newK = newK % bigMod + (newK / bigMod);
                            if (newK == k)
                                break;

                            if (newK > k && newK <= B)
                                res++;
                        }                        
                    }

                    writer.WriteLine("Case #{0}: {1}", t, res);
                }
            }
        }
    }
}
