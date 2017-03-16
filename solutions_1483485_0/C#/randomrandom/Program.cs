using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Translation
{
    class Program
    {
        private static StreamReader reader = null;
        private static StreamWriter writer = null;

        static void Main(string[] args)
        {
            reader = new StreamReader("A-small-attempt0.in");
            writer = new StreamWriter("A-small.out");

            using (reader)
            {
                using (writer)
                {
                    int tests = int.Parse(reader.ReadLine());
                    string line = null;

                    for (int test = 0; test < tests; test++)
                    {
                        line = reader.ReadLine();

                        line = DecodeSentance(line);

                        writer.WriteLine("Case #{0}: {1}", test+1, line);
                    }
                }
            }
        }

        private static char DecodeLetter(char letter)
        {
            char toReturn = ' ';
            char[] allLetters = {
                'y', 'h', 'e', 's', 'o', 'c', 'v',
                'x', 'd', 'u', 'i', 'g', 'l', 'b',
                'k', 'r', 'z', 't', 'n', 'w', 'j',
                'p', 'f', 'm', 'a', 'q'
                                 };
            const int ascii = 97;

            if (letter != ' ')
            {
                toReturn = allLetters[letter - ascii];
            }

            return toReturn;
        }

        private static string DecodeSentance(string line)
        {
            StringBuilder output = new StringBuilder();

            for (int i = 0; i < line.Length; i++)
            {
                output.Append(DecodeLetter(line[i]));
            }

            string outputString = output.ToString();

            return outputString;
        }
    }
}
