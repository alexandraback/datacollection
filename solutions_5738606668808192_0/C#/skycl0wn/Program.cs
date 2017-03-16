using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JamCoins
{
    class Program
    {
        public static long IntPow(long x, int pow)
        {
            long ret = 1;
            while (pow != 0)
            {
                if ((pow & 1) == 1)
                    ret *= x;
                x *= x;
                pow >>= 1;
            }
            return ret;
        }

        public static string GenerateSymmetricNumber(int N, int seed)
        {
            int innerSize = N/2 - 2;

            string s = Convert.ToString(seed, 2).PadLeft(innerSize, '0');
            return $"1{s}11{s}1";
        }

        public static void WriteOutput(string fileName, int N, int J)
        {
            var output = new List<string>();
            output.Add("Case #1:");

            for (int i = 0; i < J; i++)
            {
                StringBuilder line = new StringBuilder();

                line.Append(GenerateSymmetricNumber(N, i));

                for (long b = 2; b <= 10; b++)
                {
                    line.Append(" ");
                    line.Append(IntPow(b, N/2) + 1);
                }

                output.Add(line.ToString());
            }

            File.WriteAllLines(fileName, output);
        }

        public static void ReadInput(string fileName, out int N, out int J)
        {
            var inputLine = File.ReadAllLines(fileName).Skip(1).First();
            string[] tokens = inputLine.Split(' ');

            N = Int32.Parse(tokens[0]);
            J = Int32.Parse(tokens[1]);
        }

        static void Main(string[] args)
        {
            int N, J;
            ReadInput(args[0], out N, out J);
            WriteOutput(args[1], N, J);
        }
    }
}
