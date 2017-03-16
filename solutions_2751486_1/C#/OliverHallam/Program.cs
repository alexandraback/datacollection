using System.IO;
using System.Linq;

namespace Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileName = "c:\\temp\\1A\\A-large.in";
            using (var reader = new StreamReader(fileName))
            using (var writer = new StreamWriter(Path.ChangeExtension(fileName, "out")))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var row = reader.ReadLine().Split(' ');
                    var name = row[0];
                    var n = int.Parse(row[1]);

                    var nvalue = GetNValue(name, n);

                    writer.WriteLine("Case #{0}: {1}", caseID, nvalue);
                    writer.Flush();
                }
            }
        }

        private static object GetNValue(string name, int n)
        {
            long substrings = 0;
            var consonants = name.Select(IsConsonant).ToArray();
            
            int firstNotIncluded = 0;
            var runLength = 0;
            for (var i = 0; i < consonants.Length; i++)
            {
                if (consonants[i])
                {
                    runLength++;
                    if (runLength >= n)
                    {
                        // every substring starting before this run counts;
                        var starts = i - n + 2 - firstNotIncluded;
                        var ends = consonants.Length - i;
                        substrings += starts * ends;
                        firstNotIncluded = i - n + 2;
                    }
                }
                else
                    runLength = 0;
            }

            return substrings;
        }

        private static bool IsConsonant(char c)
        {
            return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
    }
}
