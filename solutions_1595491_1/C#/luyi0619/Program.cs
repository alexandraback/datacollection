using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine()),cas = 1;
            while(t-- > 0)
            {
                String[] input = Console.ReadLine().Split();
                int n = Int32.Parse(input[0]), s = Int32.Parse(input[1]) , p = Int32.Parse(input[2]);
                int[] ti = new int[n];
                for (int i = 0; i < n; i++)
                    ti[i] = Int32.Parse(input[3 + i]);
                int ans = 0;
                while (p <= 10)
                {
                    int now = 0 , add = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if ((ti[i] + 2) / 3 >= p)
                        {
                            now++;
                            continue;
                        }
                        if (ti[i] % 3 == 0)
                        {
                            int small = ti[i] / 3;
                            if (small + 1 >= p && small > 0)
                            {
                                add++;
                            }
                        }
                        else if (ti[i] % 3 == 1)
                        {
                            int small = ti[i] / 3;
                            if (small + 1 >= p)
                            {
                                add++;
                            }
                        }
                        else
                        {
                            int large = ti[i] / 3 + 1;
                            if (large + 1 >= p)
                            {
                                add++;
                            }
                        }
                    }


                    ans = Math.Max(ans, now + Math.Min(s,add));
                    
                    p++;
                }
                
                Console.WriteLine("Case #{0}: {1}", cas++, ans);
            }
        }
    }
}
