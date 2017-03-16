using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemA\Input\A-small-attempt1.in";
            const string outputFile = @"C:\Users\Tyler\Desktop\GoogleCodeJam2012\ProblemA\Output\Small.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = SpeakinginTongues.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class SpeakinginTongues
    {
        public static Dictionary<char, char> TranslationMap = ComputeMap();

        public String Translated { get; set; }

        public static SpeakinginTongues ParseCase(StreamReader sr)
        {
            var parameters = sr.ReadLine();

            return new SpeakinginTongues { Translated = parameters };
        }

        public String SolveCase()
        {
            return new string(Translated.ToCharArray().Select(c => TranslationMap[c]).ToArray());
        }

        public static Dictionary<char, char> ComputeMap()
        {
            var map = new Dictionary<char, char>();
            var reverse = new Dictionary<char, char>();
            map['y'] = 'a';
            map['e'] = 'o';
            map['q'] = 'z';
            reverse['a'] = 'y';
            reverse['o'] = 'e';
            reverse['z'] = 'q';
            var inputString = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
            var outputString = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
            Enumerable.Range(0, outputString.Length).ToList().ForEach(i =>
                                                                          {
                                                                              reverse[outputString[i]] = inputString[i];
                                                                              map[inputString[i]] = outputString[i];
                                                                          });

            var missingIn = "abcdefghijklmnopqrstuvwxyz".ToCharArray().Where(c => !map.ContainsKey(c));
            var missingOut = "abcdefghijklmnopqrstuvwxyz".ToCharArray().Where(c => !reverse.ContainsKey(c));

            if(missingIn.Count() > 1)
                throw new Exception("blam");

            map[missingIn.First()] = missingOut.First();
            return map;
        }
    }
}
