using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2106
{
    class CoinJam
    {

        public CoinJam()
        {
            using (StreamReader reader = File.OpenText("input.txt"))
            {
                using (StreamWriter writer = File.CreateText("output.txt"))
                {
                    reader.ReadLine();
                    string input = reader.ReadLine();
                    string [] inputs = input.Split(' ');
                    int n = int.Parse(inputs[0]);
                    int j = int.Parse(inputs[1]);
                    Solve(n, j, writer);
                }
            }
        }

        public static void Solve(int N, int J,TextWriter writer)
        {
            writer.WriteLine("case #1: ");
            for (int i = 0; i < J; i++)
            {
                string half = "1" + ToBinaryWithPadding(i, N / 2 -2 ) + "1";
                string num = half + half;
                writer.Write(num);
                for (int j = 2; j <= 10; j++)
                {
                    writer.Write(" " + (power((ulong)j, N/2) + 1));
                }
                writer.WriteLine();
            }

        }

        public static string ToBinaryWithPadding(int i, int length)
        {
            string binary = Convert.ToString(i, 2);
            string padding = new string('0', length - binary.Length);
            return padding + binary;
        }

        private static ulong power(ulong x, int y)
        {
            if (y == 0)
                return 1;
            ulong halfPow = power(x, y / 2);
            if (y % 2 == 0)
            {
                return halfPow * halfPow;
            }
            return (halfPow * halfPow) * x;
        }
    }
}
