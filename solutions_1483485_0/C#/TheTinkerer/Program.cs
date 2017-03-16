using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SpeakingInTongues
{
    class Program
    {
        static Dictionary<char, char> CharMapping = new Dictionary<char, char>()
            {
                {'a', 'y'},
                {'b', 'h'},
                {'c', 'e'},
                {'d', 's'},
                {'e', 'o'},
                {'f', 'c'},
                {'g', 'v'},
                {'h', 'x'},
                {'i', 'd'},
                {'j', 'u'},
                {'k', 'i'},
                {'l', 'g'},
                {'m', 'l'},
                {'n', 'b'},
                {'o', 'k'},
                {'p', 'r'},
                {'q', 'z'},
                {'r', 't'},
                {'s', 'n'},
                {'t', 'w'},
                {'u', 'j'},
                {'v', 'p'},
                {'w', 'f'},
                {'x', 'm'},
                {'y', 'a'},
                {'z', 'q'},
            };

        static void Main(string[] args)
        {
            using(StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    // read number of test cases
                    int rowCount;
                    int.TryParse(reader.ReadLine(), out rowCount);

                    // read line by line
                    for (int i = 0; i < rowCount; i++)
                    {
                        string googlerese = reader.ReadLine();
                        StringBuilder english = new StringBuilder();
                        
                        // translate
                        foreach (char text in googlerese)
                        {
                            char result;
                            CharMapping.TryGetValue(text, out result);
                            english.Append(result);
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, english.ToString());
                    }
                }
            }
        }
    }
}
