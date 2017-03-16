using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012Qual_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "C-small.in";

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

            var caseCount = Convert.ToInt32(input[0]);
            var sw = new Stopwatch();
            sw.Start();

            for (int i = 0; i < caseCount; i++)
            {
                var vars = input[1 + i].Split(' ');

                var minLevel = Convert.ToInt32(vars[0]);
                var maxLevel = Convert.ToInt32(vars[1]);

                var current = minLevel;

                var hitCount = 0;

                while (current < maxLevel)
                {
                    var dict = new Dictionary<int, byte>();

                    var strRepr = current.ToString();

                    for (int j = 1; j < strRepr.Length; j++)
                    {
                        if (strRepr[strRepr.Length - j] == '0')
                            continue;

                        var startStr = strRepr.Substring(strRepr.Length - j);

                        var replacedString = startStr + strRepr.Substring(0, strRepr.Length - j);
                        var repl = Convert.ToInt32(replacedString);

                        if(repl > current && repl <= maxLevel)
                        {
                            if (!dict.ContainsKey(repl))
                            {
                                ++hitCount;
                                dict.Add(repl, 0);
                            }
                        }
                    }

                    ++current;
                }

                sb.AppendFormat("Case #{0}: {1}", i + 1, hitCount);
                sb.AppendLine();
                Console.WriteLine("Case #{0}: {1} - time spent {2:0.00}", i + 1, hitCount, sw.ElapsedMilliseconds / 1000);
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
