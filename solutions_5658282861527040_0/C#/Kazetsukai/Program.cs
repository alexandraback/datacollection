using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam5
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var file = File.CreateText("output.txt"))
            {
                var cases = int.Parse(Console.ReadLine());

                for (int i = 0; i < cases; i++)
                {
                    DoACase(file, i+1);
                }
            }
        }

        private static void DoACase(StreamWriter file, int caseNum)
        {
            file.Write("Case #" + caseNum + ": ");

            var split = Console.ReadLine().Split().Select(v => int.Parse(v)).ToArray();
            var a = split[0];
            var b = split[1];
            var k = split[2];

            int highest = Math.Max(a, b);
            int wins = 0;

            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    int val = (i & j);
                    if (val < k)
                    {
                        wins ++;
                    }
                }
            }

            file.WriteLine(wins);
        }
    }
}
