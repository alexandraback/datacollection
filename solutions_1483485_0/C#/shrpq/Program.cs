using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void WriteLine(StreamWriter sw, string format, params object[] args)
        {
            sw.WriteLine(format, args);
            Console.WriteLine(format, args);
        }

        static void Write(StreamWriter sw, string format, params object[] args)
        {
            sw.Write(format, args);
            Console.Write(format, args);
        }

        static void Main(string[] args)
        {
            //const string fileName = "large.in";
            const string fileName = "small.in";         
   
            string[] oLines = new string[] {
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"
            };

            string[] tLines = new string[] {
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"
            };

            Dictionary<char, char> table = new Dictionary<char, char>();

            for (int line = 0; line < oLines.Length; line++)
            {
                string textLine = oLines[line];

                for (int pos = 0; pos < textLine.Length; pos++)
                {
                    if (!table.ContainsKey(textLine[pos]))
                    {
                        table.Add(textLine[pos], tLines[line][pos]);
                    }
                }
            }

            table.Add('z', 'q');
            table.Add('q', 'z');

            Console.WriteLine(table.Keys.Count);

            string dataFolder = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(new Uri(typeof(Program).Assembly.CodeBase).LocalPath)));

            using (StreamReader sr = File.OpenText(Path.Combine(dataFolder, fileName)))
            {
                using (StreamWriter sw = File.CreateText(Path.Combine(dataFolder, Path.GetFileNameWithoutExtension(fileName) + ".out")))
                {
                    int caseCount = int.Parse(sr.ReadLine());

                    for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                    {
                        string s = sr.ReadLine();

                        StringBuilder sb = new StringBuilder();

                        foreach (char c in s)
                            sb.Append(table[c]);
                        
                        WriteLine(sw, "Case #{0}: {1}", caseNumber, sb);                        
                    }
                }
            }
        }
    }
}
