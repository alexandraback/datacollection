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
            var inputFileName = Console.ReadLine();
            var inputStream = new FileStream(inputFileName, FileMode.Open);
            var inputFile = new StreamReader(inputStream);

            var outputFileName = "Output_" + inputFileName;
            var outputStream = new FileStream(outputFileName, FileMode.Create);
            var outputFile = new StreamWriter(outputStream);

            var T = int.Parse(inputFile.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var RCW = inputFile.ReadLine().Split(' ');
                var R = int.Parse(RCW[0]);
                var C = int.Parse(RCW[1]);
                var W = int.Parse(RCW[2]);

                int score = (C / W) * R + W - 1;
                if (C % W != 0)
                {
                    score++;
                }

                outputFile.WriteLine(string.Format("Case #{0}: {1}", i + 1, score));

            }
            inputFile.Close();
            outputFile.Close();
        }
    }
}
