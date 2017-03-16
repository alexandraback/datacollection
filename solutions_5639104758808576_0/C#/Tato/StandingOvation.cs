using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StandingOvation
{
    using System.IO;

    class StandingOvation
    {
        static void Main(string[] args)
        {
            var inputFile = new System.IO.StreamReader(args[0]);
            var outputFile = new System.IO.StreamWriter("A-small-attempt0.out");

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var k = 0; k < T; k++)
            {
                var line = inputFile.ReadLine();
                if (line == null) throw new InvalidDataException();

                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                var Smax = Convert.ToInt32(data[0]);
                var S = new int[Smax + 1];
                var friends = 0;
                var count = 0;

                for (var i = 0; i <= Smax; i++)
                {
                    var c = data[1].ElementAt(i).ToString();
                    S[i] = Convert.ToInt32(c);
                    count += S[i];

                    if (count < i + 1)
                    {
                        friends++;
                        count++;
                    }
                }

                outputFile.Write("Case #" + (k + 1) + ": " + friends + "\n");
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
