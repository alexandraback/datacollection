using System;

namespace OminousOmino
{
    using System.IO;

    class OminousOmino
    {
        static void Main(string[] args)
        {
            var inputFile = new System.IO.StreamReader(args[0]);
            var outputFile = new System.IO.StreamWriter("D-large.out");

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var k = 0; k < T; k++)
            {
                var line = inputFile.ReadLine();
                if (line == null) throw new InvalidDataException();

                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var X = Convert.ToInt32(data[0]);
                var R = Convert.ToInt32(data[1]);
                var C = Convert.ToInt32(data[2]);
                var gabriel = false;

                switch (X)
                {
                    case 1:
                        gabriel = true;
                        break;
                    case 2:
                        if ((R*C) % 2 == 0)
                        {
                            gabriel = true;
                        }
                        break;
                    case 3:
                        if ((R>1) && (C>1) && (R*C % 3 == 0))
                        {
                            gabriel = true;
                        }
                        break;
                    case 4:
                        if ((R > 2) && (C > 2) && (R*C%4 == 0))
                        {
                            gabriel = true;
                        }
                        break;
                    case 5:
                        if ((R*C != 15) && (R > 2) && (C > 2) && (R * C % 5 == 0))
                        {
                            gabriel = true;
                        }
                        break;
                    case 6:
                        if ((R > 3) && (C > 3) && (R * C % 6 == 0))
                        {
                            gabriel = true;
                        }
                        break;
                }

                if (gabriel)
                {
                    outputFile.Write("Case #" + (k + 1) + ": GABRIEL" + "\n");
                }
                else
                {
                    outputFile.Write("Case #" + (k + 1) + ": RICHARD" + "\n");
                }
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
