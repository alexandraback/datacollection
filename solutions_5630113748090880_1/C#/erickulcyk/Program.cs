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
            string file = "B-large.in";
            if (test) file = "test.txt";

            string[] lines = File.ReadAllLines($"c:\\users\\erickul\\downloads\\{file}" );
            StringBuilder output = new StringBuilder();
            int t = int.Parse(lines[0]);
            int nextLine = 1;
            for (int i = 1; i <= t; i++)
            {
                output.Append($"CASE #{i}: ");
                int n = int.Parse(lines[nextLine]);
                nextLine++;
                int[][] sq = new int[n][];
                int[][] input = new int[2*n-1][];
                for (int j = 0; j < n; j++)
                {
                    sq[j] = new int[n];
                }

                Dictionary<int, int> tot = new Dictionary<int, int>();
                for (int j = 0; j < 2*n - 1; j++)
                {
                    input[j] = new int[n];
                    string line = lines[nextLine];
                    nextLine++;
                    string[] nums = line.Split(' ');
                    for (int k = 0; k < n; k++)
                    {
                        int num = int.Parse(nums[k]);
                        tot[num] = tot.ContainsKey(num) ? tot[num] + 1 : 1;
                    }
                }


                bool first = true;
                foreach (var num in tot.Keys.OrderBy(x => x))
                {
                    if (tot[num] % 2 == 1)
                    {
                        if (!first)
                        {
                            output.Append(" ");
                        }

                        output.Append(num);
                        first = false;
                    }


                }

                output.AppendLine();
            }

            Console.WriteLine(output.ToString());
            File.WriteAllText(@"c:\users\erickul\downloads\a.out", output.ToString());
        }
    }
}
