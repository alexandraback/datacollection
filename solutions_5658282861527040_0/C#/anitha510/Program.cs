using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace Lottery
{
    class Program
    {
        static void Main(string[] args)
        {
            if (File.Exists(@"C:\Anitha\Projects\CodeJam\output.txt"))
            {
                File.Delete(@"C:\Anitha\Projects\CodeJam\output.txt");
            }
            int counter = 0, linesUsed;
            string[] LinesToWrite;
            string line;

            using (System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Anitha\Projects\CodeJam\input.in"))
            {
                linesUsed = int.Parse(file.ReadLine());
                LinesToWrite = new string[linesUsed];

                while ((line = file.ReadLine()) != null)
                {
                    int[] values = line.Split(' ').Select(x => int.Parse(x)).ToArray();
                    int count = 0;
                    for (int a = 0; a < values[0]; a++)
                    {
                        for (int b = 0; b < values[1]; b++)
                        {
                            int c = a & b;
                            if (c < values[2])
                                count++;
                        }
                    }
                    LinesToWrite[counter] = "Case #" + (counter + 1) + ": " + count.ToString();
                    counter++;
                }

                file.Close();
            }

            File.WriteAllLines(@"C:\Anitha\Projects\CodeJam\output.txt", LinesToWrite);

        }
    }
}
