using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamQualification
{
    class ProblemC
    {

        public void Execute(string[] args)
        {
            Stopwatch s = new Stopwatch();
            s.Start();

            StringBuilder output = new StringBuilder();

            using (StreamReader read = new StreamReader(File.OpenRead(args[0])))
            {

                int lines = int.Parse(read.ReadLine());

                for (int lc = 0; lc < lines; lc++)
                {

                    string[] curLine = read.ReadLine().Split(' ');

                    int min = int.Parse(curLine[0]);
                    int max = int.Parse(curLine[1]);

                    int count = 0;

                    for (int i = min; i <= max; i++)
                    {
                        int iterCount = (int)Math.Log10(i);

                        for (int j = 0; j < iterCount; j++)
                        {
                            int left = (int)Math.Pow(10, iterCount - j);
                            int right = (int)Math.Pow(10, j + 1);
                            int shifted = (i / left) + ((i % left) * right);

                            if (shifted == i)
                            {
                                // madness lies ahead
                                break;
                            }

                            if (shifted > i && shifted <= max)
                            {
                                count++;
                            }

                        }
                    }

                    output.AppendLine("Case #" + (lc + 1) + ": " + count);
                }
            }

            s.Stop();
            Console.WriteLine(s.ElapsedMilliseconds + " ms");
            Console.WriteLine(s.ElapsedTicks + " ticks");

            File.WriteAllText("output-c.txt", output.ToString());

        }
    }
}
