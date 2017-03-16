using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace A
{
    class _2012QA
    {
        static void Main()
        {
            var LetterConverter = new Dictionary<string, string>
                                      {
                                          {"a", "y"},
                                          {"b", "h"},
                                          {"c", "e"},
                                          {"d", "s"},
                                          {"e", "o"},
                                          {"f", "c"},
                                          {"g", "v"},
                                          {"h", "x"},
                                          {"i", "d"},
                                          {"j", "u"},
                                          {"k", "i"},
                                          {"l", "g"},
                                          {"m", "l"},
                                          {"n", "b"},
                                          {"o", "k"},
                                          {"p", "r"},
                                          {"q", "z"},
                                          {"r", "t"},
                                          {"s", "n"},
                                          {"t", "w"},
                                          {"u", "j"},
                                          {"v", "p"},
                                          {"w", "f"},
                                          {"x", "m"},
                                          {"y", "a"},
                                          {"z", "q"},
                                          {" ", " "},
                                      };
            var CaseCounter = 0;
            var FirstTime = true;
            var sb = new StringBuilder();
            using (var sr = new StreamReader("2012a.in"))
            {
                String line;
                // Read and display lines from the file until the end of
                // the file is reached.
                while ((line = sr.ReadLine()) != null)
                {
                    if (FirstTime)
                    {
                        FirstTime = false;
                        continue;
                    }
                    CaseCounter++;

                    var sb2 = new StringBuilder();
                    var charArray = line.ToCharArray();
                    foreach (var c in charArray)
                        sb2.Append(LetterConverter[c.ToString()]);

                    sb.AppendLine("Case #" + CaseCounter + ": " + sb2);
                }
                using (var outfile = new StreamWriter(@"output.txt"))
                {
                    outfile.Write(sb.ToString());
                }
            }
        }
    }
}
