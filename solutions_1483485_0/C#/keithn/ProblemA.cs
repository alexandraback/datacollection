using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamQualification
{
    class ProblemA
    {
        string[] refEnglish =
        {
            "aoz",
            "our language is impossible to understand",
            "there are twenty six factorial possibilities",
            "so it is okay if you want to just give up"
        };

        string[] refTranslated = 
        {
            "yeq",
            "ejp mysljylc kd kxveddknmc re jsicpdrysi",
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
            "de kr kd eoya kw aej tysr re ujdr lkgc jv"
        };

        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        public Dictionary<char, char> MapCharacters()
        {
            Dictionary<char,char> map = new Dictionary<char,char>();

            for (int i = 0; i < refEnglish.Length; i++)
            {
                for (int j = 0; j < refEnglish[i].Length; j++)
                {
                    if (alphabet.Contains(refEnglish[i][j]))
                    {
                        map[refTranslated[i][j]] = refEnglish[i][j];
                    }
                }
            }

            var missingTranslatedChars = alphabet.Where(a => !map.Keys.Contains(a)).ToArray();
            var missingEnglishChars = alphabet.Where(a => !map.Values.Contains(a)).ToArray();

            if (missingEnglishChars.Length > 1 || missingTranslatedChars.Length > 1)
            {
                throw new Exception("Not enough data.");
            }

            if (missingEnglishChars.Length == 1)
            {
                map[missingTranslatedChars[0]] = missingEnglishChars[0];
            }

            foreach (char translated in map.Keys.ToList())
            {
                map[translated.ToString().ToUpper()[0]] = map[translated].ToString().ToUpper()[0];
            }
            

            return map;
        }

        public string EnglishFromTranslated(string translated, Dictionary<char, char> map)
        {
            StringBuilder english = new StringBuilder();

            foreach (char trans in translated)
            {
                if (map.ContainsKey(trans))
                {
                    english.Append(map[trans]);
                }
                else
                {
                    english.Append(trans);
                }
            }

            return english.ToString();
        }

        public void Execute(string[] args)
        {
            var map = MapCharacters();

            int numCases = int.Parse(Console.ReadLine());

            StringBuilder output = new StringBuilder();

            for (int i = 0; i < numCases; i++)
            {
                string line = Console.ReadLine();
                string english = EnglishFromTranslated(line, map);
                output.AppendLine("Case #" + (i + 1) + ": " + english);
            }

            Console.WriteLine(output);

        }

    }
}
