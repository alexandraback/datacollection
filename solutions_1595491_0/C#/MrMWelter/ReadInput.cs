using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;

namespace CodeJam.Dance
{
    public class ReadInput
    {
        public static dynamic InputOutput(string inputFile, string outputFile)
        {
            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);
            dynamic inputResult = new ExpandoObject();

            inputResult.TestCases = int.Parse(reader.ReadLine());
            inputResult.Cases = new List<dynamic>();

            for (int line = 0; line < inputResult.TestCases; line++)
            {
                string text = reader.ReadLine();
                string[] words = text.Split(' ');
                int surprises = int.Parse(words[1]);
                int p = int.Parse(words[2]);

                int caseone = p + Math.Max(0, p - 2) + Math.Max(0, p - 2);
                int easy = p + Math.Max(0, p - 1) + Math.Max(0, p - 1);
                int atleastp = 0;

                for (int counter = 3; counter < words.Length; counter++)
                {
                    int gsum = int.Parse(words[counter]);
                    if (gsum >= easy)
                        atleastp++;
                    else
                        if (gsum >= caseone)
                        {
                            if (surprises > 0)
                            {
                                atleastp++;
                                surprises--;
                            }
                        }
                }

                //output:
                string sout = "Case #" + (line +1) +": " + atleastp;
                writer.WriteLine(sout);
                Console.WriteLine(sout);
                writer.Flush();

            }

            Console.ReadKey();
            return inputResult;
        }
    }
}
