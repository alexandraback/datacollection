using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016
{
    class Program
    {

/*
        static int toBase(int num, int toBase)
        {
            for (int d = 0; d < 32; d++)
            {
                if ((start & (1 << d)) > 0)
                {
                    upper = BigInteger.Add(upper, BigInteger.Pow(baseN, d));
                }
            }
        }*/

        private static bool test = false;
        // c:\users\erickul\documents\visual studio 2015\Projects\GCJ2016\GCJ2016\Program.cs
        static void Main(string[] args)
        {
            string file = "a-small-attempt0.in";
            if (test) file = "test.txt";

            string[] lines = File.ReadAllLines($"c:\\users\\erickul\\downloads\\{file}" );
            StringBuilder output = new StringBuilder();
            int t = int.Parse(lines[0]);
            for (int i = 1; i <= t; i++)
            {
                output.Append($"CASE #{i}: ");
                string a = lines[i];
                char[] b = a.ToCharArray();
                string c = b[0].ToString();
                for (int j = 1; j < b.Length; j++)
                {
                    if (b[j] >= c[0])
                    {
                        c = b[j] + c;
                    }
                    else
                    {
                        c = c + b[j];
                    }
                }

                output.AppendLine(c);
            }

            Console.WriteLine(output.ToString());
            File.WriteAllText(@"c:\users\erickul\downloads\a.out", output.ToString());
        }
    }
}
