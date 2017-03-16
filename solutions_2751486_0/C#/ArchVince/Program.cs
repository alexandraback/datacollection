using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace CodeJamQualifications
{
    class Program
    {
        const string challenge = "Names";
        const string outputFolder = @"C:\Users\Arch\Documents\CodeJam\Output\";

        static void Main(string[] args)
        {
            ClearFile();

            string[] lines = File.ReadAllLines(args[0]);
            int count = int.Parse(lines[0]);

            for (int i = 0; i < count; i++)
            {
                string word = lines[i + 1].Split(new char[] { ' ' })[0];
                int n = int.Parse(lines[i + 1].Split(new char[] { ' ' })[1]);

                int inRow = 0;
                int lastFound = 0;
                int score = 0;

                for (int h = 0; h < word.Length; h++)
                {
                    if (isVowel(word[h]))
                        inRow = 0;
                    else
                    {
                        inRow++;
                        if (inRow >= n)
                        {
                            score += (h + 2 - n - lastFound) * (word.Length - h);
                            lastFound = h + 2 - n;
                        }
                    }
                }

                Save("Case #" + (i + 1) + ": " + score + "\n");
            }
        }

        private static bool isVowel(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }

        private static void Save(string toSave)
        {
            File.AppendAllText(outputFolder + challenge + ".out", toSave);
        }

        private static void ClearFile()
        {
            File.WriteAllText(outputFolder + challenge + ".out", "");
        }
    }
}