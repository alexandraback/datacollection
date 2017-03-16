using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r0pd
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var parameters = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var X = parameters[0];
                    var R = parameters[1];
                    var C = parameters[2];

                    var width = R;
                    var height = C;
                    if (width < height)
                    {
                        width = C;
                        height = R;
                    }

                    var win = false;

                    var boardSize = R * C;
                    if (boardSize % X != 0)
                        win = true;

                    if (boardSize < X)
                        win = true;

                    if (X >= 7)
                        win = true;

                    if (X == 6 && height <= 3)
                        win = true;

                    if (X == 5 && height <= 3)
                        win = true;

                    if (X == 4 && height <= 2)
                        win = true;

                    if (X == 3 && height <= 1)
                        win = true;


                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, win ? "RICHARD" : "GABRIEL");
                }
            }
        }
    }
}
