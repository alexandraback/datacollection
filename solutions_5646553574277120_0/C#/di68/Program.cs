using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Round1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var writer = new StreamWriter("output.txt", false)) {}

            using (var reader = new StreamReader(args[0]))
            using (var writer = new StreamWriter("output.txt", true))
            {
                int t = Convert.ToInt32(reader.ReadLine());
                for (int i = 0; i < t; i++)
                {
                    var line = Array.ConvertAll(reader.ReadLine().Split(new[] { ' ' }), Int32.Parse);
                    var line2 = Array.ConvertAll(reader.ReadLine().Split(new[] { ' ' }), Int32.Parse);
                    var program = new Program(i + 1, writer, line[0], line[1], line[2], line2);
                }
            }
        }

        public Program(int t, StreamWriter writer, int c, int d, int v, int[] coins)
        {
            var impossible = new bool[v + 1];
            for (int i = 1; i <= v; i++)
            {
                if (!Check(coins, i)) impossible[i] = true;
            }

            var newCoins = new int[coins.Length];
            for (int i = 1; i <= v; i++)
            {
                if (impossible[i])
                {
                    if (!Check(coins, i))
                    {
                        newCoins = new int[coins.Length + 1];
                        for (int j = 0; j < coins.Length; j++)
                        {
                            newCoins[j] = coins[j];
                        }
                        newCoins[coins.Length] = i;
                        Array.Sort(newCoins);
                        coins = newCoins;
                    }
                }
            }

            writer.WriteLine(String.Format("Case #{0}: {1}", t, newCoins.Length - d));
        }

        private bool Check(int[] coins, int v)
        {
            int sum = v;
            for (int j = coins.Length - 1; j >= 0; j--)
            {
                if (coins[j] > sum) continue;
                sum -= coins[j];
            }
            return sum == 0;
        }
    }
}
