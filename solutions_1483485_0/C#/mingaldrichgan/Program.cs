using System.Diagnostics;
using System.IO;

namespace CodeJam.SpeakingInTongues
{
    class Program
    {
        const string inputFile = @"C:\Temp\CodeJam\SpeakingInTongues\A-small-attempt0.in";
        const string outputFile = @"C:\Temp\CodeJam\SpeakingInTongues\A-small-attempt0.out";

        static string toEnglish(string googlerese)
        {
            char[] english = new char[googlerese.Length];

            for (int i = 0; i < googlerese.Length; i++)
            {
                switch (googlerese[i])
                {
                    // The following case statements were generated using code found at the end of this source file:
                    case 'a': english[i] = 'y'; break;
                    case 'b': english[i] = 'h'; break;
                    case 'c': english[i] = 'e'; break;
                    case 'd': english[i] = 's'; break;
                    case 'e': english[i] = 'o'; break;
                    case 'f': english[i] = 'c'; break;
                    case 'g': english[i] = 'v'; break;
                    case 'h': english[i] = 'x'; break;
                    case 'i': english[i] = 'd'; break;
                    case 'j': english[i] = 'u'; break;
                    case 'k': english[i] = 'i'; break;
                    case 'l': english[i] = 'g'; break;
                    case 'm': english[i] = 'l'; break;
                    case 'n': english[i] = 'b'; break;
                    case 'o': english[i] = 'k'; break;
                    case 'p': english[i] = 'r'; break;
                    case 'q': english[i] = 'z'; break;
                    case 'r': english[i] = 't'; break;
                    case 's': english[i] = 'n'; break;
                    case 't': english[i] = 'w'; break;
                    case 'u': english[i] = 'j'; break;
                    case 'v': english[i] = 'p'; break;
                    case 'w': english[i] = 'f'; break;
                    case 'x': english[i] = 'm'; break;
                    case 'y': english[i] = 'a'; break;
                    case 'z': english[i] = 'q'; break;

                    default: english[i] = googlerese[i]; break;
                }
            }

            return new string(english);
        }


        static void Main()
        {
            string[] inputLines = File.ReadAllLines(inputFile);
            int T = int.Parse(inputLines[0]);

            Debug.Assert(inputLines.Length > T);

            string[] outputLines = new string[T];

            for (int t = 0; t < T; t++)
            {
                outputLines[t] = "Case #" + (t + 1).ToString() + ": " + toEnglish(inputLines[t + 1]);
            }

            File.WriteAllLines(outputFile, outputLines);
        }

        /*
            The case statements in the toEnglish(...) method were generated using the following code:

            string[] googlerese =
            {
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"
            };

            string[] english =
            {
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"
            };

            Dictionary<char, char> dictionary = new Dictionary<char, char>();

            dictionary.Add('y', 'a');
            dictionary.Add('e', 'o');
            dictionary.Add('q', 'z');
            dictionary.Add('z', 'q'); // Added later by elimination.

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < googlerese[i].Length; j++)
                {
                    if (dictionary.ContainsKey(googlerese[i][j]))
                    {
                        if (dictionary[googlerese[i][j]] != english[i][j]) { throw new Exception(); }
                    }
                    else
                    {
                        dictionary.Add(googlerese[i][j], english[i][j]);
                    }
                }
            }

            for (char letter = 'a'; letter <= 'z'; letter++)
            {
                if (dictionary.ContainsKey(letter)) { Console.WriteLine("case '" + letter + "': english[i] = '" + dictionary[letter] + "'; break;"); }
            }
        */
    }
}
