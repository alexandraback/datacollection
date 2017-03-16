using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var parameters = inputStream.ReadLine().Split(' ');
                    var name = parameters[0];
                    var n = int.Parse(parameters[1]);

                    var consecutiveConsonants = new List<int>();
                    int? start = null;
                    for (var i = 0; i < name.Length; i++)
                    {
                        var letter = name[i];
                        switch (letter)
                        {
                            case 'a':
                            case 'e':
                            case 'i':
                            case 'o':
                            case 'u':
                                {
                                    if (start != null && i - start.Value == n)
                                        consecutiveConsonants.Add(start.Value);
                                    start = null;
                                    break;
                                }
                            default:
                                {
                                    if (start == null)
                                        start = i;
                                    if (i - start.Value == n)
                                    {
                                        consecutiveConsonants.Add(start.Value);
                                        start++;
                                    }
                                    break;
                                }
                        }
                    }
                    if (start != null && name.Length - start.Value == n)
                        consecutiveConsonants.Add(start.Value);

                    var result = 0L;
                    var previousStart = 0;
                    foreach (var cc in consecutiveConsonants)
                    {
                        result += (cc - previousStart + 1L) * (name.Length - cc - n + 1);
                        previousStart = cc + 1;
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                }
            }
        }
    }
}
