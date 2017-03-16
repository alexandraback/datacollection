using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GcjQ1SpeakingInTongues
{
    class GcjQ1
    {
        static char[] map = new[] {'y', 'h', 'e', 's', 'o', 'c', 
            'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
            'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

        static void Main(string[] args)
        {
            using (var reader = new StreamReader("input.txt"))
            using (var writer = new StreamWriter("output.txt"))
            {
                int caseCount = int.Parse(reader.ReadLine());
                for (int @case = 1; @case <= caseCount; @case++)
                {
                    var inputLine = reader.ReadLine();
                    var outputChars = new char[inputLine.Length];
                    for (int i = 0; i < inputLine.Length; i++)
                        if (inputLine[i] == ' ')
                            outputChars[i] = ' ';
                        else
                            outputChars[i] = map[inputLine[i] - 'a'];
                    var outputLine = new string(outputChars);
                    writer.WriteLine("Case #" + @case + ": " + outputLine);
                }
            }
        }
    }
}
