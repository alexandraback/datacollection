using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace GCJ2014
{

    class B
    {

        static void Main(string[] args)
        {
            const long M = 1000000007L;

            long[] power = new long[200];
            power[0] = 1;
            for (int i = 1; i < power.Length; i++)
			{
			    power[i] = (power[i-1]*i)% M;
			}

            var T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                var N = int.Parse(Console.ReadLine());
                string[] w = Console.ReadLine().Split().ToArray();
                bool zero = false;

                
                var temp2 = new List<string>();
                foreach (var s in w)
                {
                    int i;
                    for (i = 0; i < temp2.Count; i++)
                    {
                        if (temp2[i].First() == s.Last())
                        {
                            break;
                        }
                    }
                    temp2.Insert(i, s);
                }
                w = temp2.ToArray();
                var test = string.Concat(w);
                test += "0";
                bool[] was = new bool['z' - 'a' + 1];
                for (int j = 0; j < test.Length - 1; j++)
                {
                    if (test[j] != test[j + 1])
                    {
                        if (was[test[j]-'a'])
                        {
                            zero = true;
                            break;
                        }
                        was[test[j]-'a'] = true;                        
                        
                    }
                }

                if (zero)
                {
                    Console.WriteLine("Case #{0}: {1}", t, 0);
                    continue;
                }

                long res = 1;
                long partLen = 1;
                long parts = 1;
                for (int j = 0; j < w.Length ; j++)
                {
                    var d = w[j].Distinct().ToArray();


                    if (d.Count() == 1)
                    {
                        if (j < w.Length - 1 )
                        {
                            partLen++;
                        }
                        else
                        {
                            res *= (power[partLen - 1 + (j == w.Length - 1 ? 1: 0) ] % M);
                            res %= M;                            
                        }
                    }
                    else
                    {
                        res *= (power[partLen - 1 + (j == w.Length - 1 ? 1 : 0)] % M);
                            res %= M;
                        partLen = 1;
                    }

                    
                    if(j < w.Length - 1 && w[j].Last() != w[j + 1][0]){
                        parts++;
                        res *= (power[partLen - 1 + (j == w.Length - 1 ? 1 : 0)] % M);
                        res %= M;
                        partLen = 1;
                    }

                }
                while (parts > 0)
                {
                    res *= (parts);
                    parts--;
                    res %= M;
                }
                Console.WriteLine("Case #{0}: {1}", t, res);
            }
        }
    }
}
