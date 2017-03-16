using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test.in", "A-small-attempt0.in", "A-large.in" }[1];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round1BA(input, output);
            }
            Console.Read();
        }

        static void Round1BA(StreamReader fileInput, StreamWriter fileOutput)
        {
            var Digits = new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
            var Vectors = new int[10][];
            for (int i = 0; i < 10; i++)
                Vectors[i] = new int[26];
            for (int i = 0; i < 10; i++)
            {
                foreach (var c in Digits[i])
                    Vectors[i][c - 'A']++;
            }
            //for (int i = 0; i < 10; i++)
            //{
            //    Console.WriteLine(string.Join(" ", Vectors[i].Select(x => x.ToString())));
            //}
            var Order = new[] { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };


            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var S = fileInput.ReadLine();

                var CC = new int[26];
                foreach (var c in S)
                    CC[c - 'A']++;

                var Counts = new int[10];
                foreach (var o in Order)
                {
                    while (true)
                    {
                        int i;
                        for (i = 26; --i >= 0;)
                            if (CC[i] < Vectors[o][i]) break;
                        if (i >= 0) break;
                        Counts[o]++;
                        for (i = 26; --i >= 0;)
                            CC[i] -= Vectors[o][i];
                    }
                }

                {
                    for (int i = 26; --i >= 0;)
                        if (CC[i] != 0) Console.WriteLine("error {0}", i);
                }

                string num = "";
                {
                    for (int i = 0; i < 10; i++)
                        for (int j = Counts[i]; --j >= 0;)
                            num += i.ToString();
                }

                var result = string.Format("Case #{0}: {1}", t + 1, num);
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
