using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012Qual_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "A-small.in";

            if (args.Count() > 0)
                inputFileName = args[0];

            var sb = new StringBuilder();
            var input = new List<string>();

            using (var stream = new FileStream(inputFileName, FileMode.Open))
            {
                using (var reader = new StreamReader(stream))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        input.Add(line);
                    }
                }
            }

            var dictInput = new List<string>
                            {
                                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                                "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                            }.ToArray();

            var dictOutput = new List<string>
                            {
                                "our language is impossible to understand",
                                "there are twenty six factorial possibilities",
                                "so it is okay if you want to just give up",
                            }.ToArray();

            var dictionary = new Dictionary<char, char>();

            for (int j = 0; j < dictInput.Length; j++)
            {
                for (int i = 0; i < dictInput[j].Length; i++)
                {
                    if(!dictionary.ContainsKey(dictInput[j][i]))
                    {
                        dictionary.Add(dictInput[j][i], dictOutput[j][i]);
                    }
                }
            }

            dictionary.Add('q', 'z');
            dictionary.Add('z', 'q');

            var caseCount = Convert.ToInt32(input[0]);

            for (int i = 0; i < caseCount; i++)
            {
                var line = input[1 + i];

                var sbInner = new StringBuilder();

                foreach (var ch in line)
                {
                    sbInner.Append(dictionary[ch]);
                }

                sb.AppendFormat("Case #{0}: {1}", i + 1, sbInner.ToString());
                sb.AppendLine();
            }

            using (var stream = new FileStream(inputFileName + ".out", FileMode.Create))
            {
                using (var writer = new StreamWriter(stream))
                {
                    writer.Write(sb.ToString());
                }
            }
        }
    }
}
