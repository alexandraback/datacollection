using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    using System.IO;

    class ProblemA
    {
        static void Main(string[] args)
        {
            //var inputFile = new System.IO.StreamReader("A-test.in");
            var inputFile = new System.IO.StreamReader("A-small-attempt0.in");

            var outputFile = new System.IO.StreamWriter("A-small.out");
            // var outputFile = new System.IO.StreamWriter("A-large.out");

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var k = 0; k < T; k++)
            {
                var line = inputFile.ReadLine();
                if (line == null) throw new InvalidDataException();

                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                var R = Convert.ToInt32(data[0]);
                var C = Convert.ToInt32(data[1]);
                var W = Convert.ToInt32(data[2]);

                var H = C/W + W - 1;

                if (C%W != 0)
                {
                    H++;
                }
                
                outputFile.Write("Case #" + (k + 1) + ": " + H + "\n");
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
