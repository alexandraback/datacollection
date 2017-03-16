using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Threading;
using System.Numerics;

namespace CodeJam
{
    class Program
    {
        private static string CodeJam(int[] values)
        {
            int a = values[0];
            int b = values[1];
            int k = values[2];

            int bitwiseAnd = 0;
            List<int> bitwiseAnds = new List<int>();
            for (int i = 0; i < a; i++)
                for (int j = 0; j < b; j++)
                {
                    bitwiseAnd = i & j;
                    if (bitwiseAnd < k) bitwiseAnds.Add(bitwiseAnd);
                }

            return bitwiseAnds.Count.ToString();
        }


        static void Main(string[] args)
        {
            string fileIn = "..\\..\\..\\B-small-attempt0.in";
            string fileOut = "..\\..\\..\\fileOut.txt";
            using (StreamReader sr = new StreamReader(fileIn))
            using (StreamWriter sw = new StreamWriter(fileOut))
            {
                string theAnswer = string.Empty;
                int cases = int.Parse(sr.ReadLine());
                for (int i = 1; i <= cases; i++)
                {
                    int[] line = sr.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();

                    string answer = "Case #" + i + ": " + CodeJam(line);
                    sw.WriteLine(answer);
                    Console.WriteLine(answer);
                }
            }
            Console.WriteLine("\r\nProcess Complete! Press any key to exit.");
            Console.ReadLine();
        }
    }
}
