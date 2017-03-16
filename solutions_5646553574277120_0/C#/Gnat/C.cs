using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace _2015
{
    internal class Program
    {
        private static void Solve(int caseNo, StreamReader sr, StreamWriter sw)
        {
            var m = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse);
            var c = m[0];
            var v = m[2];
            var d = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse);

            var coinsOrig = new List<int>();
            foreach (var i in d)
            {
                for (int j = 0; j < c; j++)
                {
                    coinsOrig.Add(i);
                }
            }

            var addCount = 0;

            for (int i = 1; i <= v; i++)
            {
                var current = i;
                var coins = coinsOrig.Select(item => item).ToList();

                while (current > 0)
                {
                    if (coins.Count == 0)
                    {
                        for (int k = v; k >= 1; k --)
                        {
                            if (k <= i && !coinsOrig.Contains(k))
                            {
                                addCount++;
                                for (int j = 0; j < c; j++)
                                {
                                    coinsOrig.Add(k);
                                }
                                break;
                            }
                        }

                        current = i;
                        coins = coinsOrig.Select(item => item).ToList();
                    }
                    else
                    {
                        var coinMax = coins.Max();
                        if (current >= coinMax)
                        {
                            current -= coinMax;
                            coins.Remove(coinMax);
                        }
                        else
                        {
                            coins.Remove(coinMax);
                        }
                    }
                }
            }

            Console.WriteLine("Case #{0}: {1}", caseNo, addCount);
            sw.WriteLine("Case #{0}: {1}", caseNo, addCount);
        }

        private static void Main(string[] args)
        {
            var file = args[0];
            var sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
            var sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));
            var maxCase = Convert.ToInt32(sr.ReadLine());

            var caseNo = 1;
            while (caseNo <= maxCase)
            {
                Solve(caseNo, sr, sw);
                caseNo++;
            }

            sr.Close();
            sw.Close();
        }
    }
}
