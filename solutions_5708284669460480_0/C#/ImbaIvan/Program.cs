using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam6
{
    class Program
    {
        private static string alphabet;
        private static string targetWord;
        private static int S;

        static int GetSubs(string curWord)
        {
            var ind = -1;
            var startIndex = 0;
            var result = 0;
            var max = curWord.Length;

            ind = curWord.IndexOf(targetWord);

            while (startIndex < max && ind != -1)
            {
                result++;
                startIndex = ind + 1;
                ind = curWord.IndexOf(targetWord, startIndex);
            }

            return result;
        }

        static void Count(out double max, out double comb, out double sum, string curWord)
        {
            if (curWord.Length == S)
            {
                var number = GetSubs(curWord);
                max = number;
                comb = 1;
                sum = number;
            }
            else
            {
                max = 0;
                comb = 0;
                sum = 0;
                for (int i = 0; i < alphabet.Length; i++)
                {
                    double tmpComb;
                    double tmpSum;
                    double tmpMax;
                    Count(out tmpMax, out tmpComb, out tmpSum, curWord + alphabet[i]);
                    sum += tmpSum;
                    comb += tmpComb;
                    if (max < tmpMax)
                    {
                        max = tmpMax;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            double k = 0;
            var n = k.ToString();
            var inputFileName = Console.ReadLine();
            var inputStream = new FileStream(inputFileName, FileMode.Open);
            var inputFile = new StreamReader(inputStream);

            var outputFileName = "Output_" + inputFileName;
            var outputStream = new FileStream(outputFileName, FileMode.Create);
            var outputFile = new StreamWriter(outputStream);

            var T = int.Parse(inputFile.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var KLS = inputFile.ReadLine().Split(' ');
                var K = int.Parse(KLS[0]);
                var L = int.Parse(KLS[1]);
                S = int.Parse(KLS[2]);
                alphabet = inputFile.ReadLine();
                targetWord = inputFile.ReadLine();

                double max = 0;
                double comb = 0;
                double sum = 0;

                Count(out max,out comb,out sum, "");

                double expected = sum/comb;
                expected = Math.Truncate(expected * 10000000) / 10000000;


                var result = max - expected;
                string h = result.ToString();
                h = h.Replace(',', '.');
                if(h.IndexOf('.') == -1)
                {
                    h = h + ".0";
                }

                outputFile.WriteLine(string.Format("Case #{0}: {1:G}", i + 1, h));

            }
            inputFile.Close();
            outputFile.Close();
        }
    }
}
