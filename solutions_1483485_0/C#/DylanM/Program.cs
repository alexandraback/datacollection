using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Speaking_in_Tongues
{
    class Program
    {
        static Dictionary<string, string> CharacterMap = new Dictionary<string, string>()
        {
            {"y", "a"},
            {"n", "b"},
            {"f", "c"},
            {"i", "d"},
            {"c", "e"},
            {"w", "f"},
            {"l", "g"},
            {"b", "h"},
            {"k", "i"},
            {"u", "j"},
            {"o", "k"},
            {"m", "l"},
            {"x", "m"},
            {"s", "n"},
            {"e", "o"},
            {"v", "p"},
            {"z", "q"},
            {"p", "r"},
            {"d", "s"},
            {"r", "t"},
            {"j", "u"},
            {"g", "v"},
            {"t", "w"},
            {"h", "x"},
            {"a", "y"},
            {"q", "z"},
            { " ", " "}
        };

        static void Main(string[] args)
        {
            List<string> translates = new List<string>();

            using (StreamReader sr = new StreamReader("input_small.txt"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
                    string line = sr.ReadLine();
                    string translated = string.Empty;

                    for (int j = 0; j < line.Length; j++)
                    {
                        translated += CharacterMap[line.Substring(j, 1)];
                    }

                    translates.Add(translated);
                }
            }

            using (StreamWriter sw = new StreamWriter("output_small.txt"))
            {
                for (int i = 0; i < translates.Count; i++)
                {
                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + translates[i]);
                }
            }
        }
    }
}
