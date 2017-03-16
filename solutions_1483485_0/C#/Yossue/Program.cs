using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, char> mapCharacter = new Dictionary<char, char>();
            List<string> inputLinesSample = new List<string>();
            List<string> outputLinesSample = new List<string>();

            using (StreamReader r = new StreamReader(@"../../samplein.txt"))
            {
                string line;
                while ((line = r.ReadLine()) != null)
                {
                    inputLinesSample.Add(line);
                }
            }

            using (StreamReader r = new StreamReader(@"../../sampleout.txt"))
            {
                string line;
                while ((line = r.ReadLine()) != null)
                {
                    outputLinesSample.Add(line);
                }
            }

            if (inputLinesSample.Count != outputLinesSample.Count)
            {
                throw new Exception("inconsistency in line count");
            }

            int lineCount = inputLinesSample.Count;
            for (int i = 0; i < lineCount; ++i)
            {
                if (inputLinesSample[i].Length != outputLinesSample[i].Length)
                {
                    throw new Exception("inconsistency in character length");
                }

                int lineLength = inputLinesSample[i].Length;
                for (int j = 0; j < lineLength; ++j)
                {
                    if (mapCharacter.ContainsKey(inputLinesSample[i].ElementAt(j)) &&
                        mapCharacter[inputLinesSample[i].ElementAt(j)] != outputLinesSample[i].ElementAt(j))
                    {
                        throw new Exception("Invalid Map: " + inputLinesSample[i].ElementAt(j));
                    }
                    else
                    {
                        mapCharacter[inputLinesSample[i].ElementAt(j)] = outputLinesSample[i].ElementAt(j);
                    }
                }
            }

            // from hints
            mapCharacter['y'] = 'a';
            mapCharacter['e'] = 'o';
            mapCharacter['q'] = 'z';

            string alphabets = "abcdefghijklmnopqrstuvwxyz";

            char notInKeyCharacter;
            foreach (char c in alphabets)
            {
                if (!mapCharacter.ContainsKey(c))
                {
                    notInKeyCharacter = c;

                    char notInValueCharacter;
                    Dictionary<char, bool> mapFound = new Dictionary<char, bool>();
                    foreach (char c2 in alphabets)
                    {
                        mapFound[c2] = false;
                    }

                    foreach (char c2 in mapCharacter.Values)
                    {
                        mapFound[c2] = true;
                    }

                    foreach (char c2 in alphabets)
                    {
                        if (!mapFound[c2])
                        {
                            notInValueCharacter = c2;
                            mapCharacter[notInKeyCharacter] = notInValueCharacter;
                            break;
                        }
                    }
                    break;
                }
            }

            //---------------------------------------------------

            List<string> inputLines = new List<string>();
            int numTestCases = 0;
            using (StreamReader r = new StreamReader(@"../../A-small-attempt1.in"))
            {
                string line;
                bool isFirstLine = true;
                while ((line = r.ReadLine()) != null)
                {
                    if (isFirstLine)
                    {
                        isFirstLine = false;
                        int.TryParse(line, out numTestCases);
                    }
                    else
                    {
                        inputLines.Add(line);
                    }
                }
            }

            using (StreamWriter w = new StreamWriter(@"../../A-small-attempt1.out"))
            {
                int index = 1;
                foreach (string line in inputLines)
                {
                    StringBuilder outLine = new StringBuilder();
                    foreach (char c in line)
                    {
                        if (!mapCharacter.ContainsKey(c))
                        {
                            throw new Exception("Key not found: " + c);
                        }

                        outLine.Append(mapCharacter[c]);
                    }

                    w.WriteLine("Case #{0}: {1}", index, outLine);
                    ++index;
                }
            }
        }
    }
}
