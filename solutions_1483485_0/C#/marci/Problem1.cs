using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2012
{
    class Problem1
    {
        static string input = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
        static string output = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

        //For example (and here is a hint!), our awesome translation algorithm includes the following three mappings: 'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'. This means that "a zoo" will become "y qee". 
        static Dictionary<char, char> mapping = new Dictionary<char, char>() { { 'y', 'a' }, { 'e', 'o' }, { 'q', 'z' } };

        static Problem1()
        {
            for (int i = 0; i < output.Length; ++i)
            {
                var ic = input[i];
                var oc = output[i];

                if (mapping.Keys.Contains(ic))
                {
                    if (mapping[ic] != oc)
                        throw new ArgumentException();
                }
                else
                    mapping.Add(ic, oc);
            }
 
            var letters = "abcdefghijklmnopqrstuvwxyz".ToList();

            mapping.Add(letters.Except(mapping.Keys).First(), letters.Except(mapping.Values).First());
        }

        public static void Solve(string inFilePath, string outFilePath)
        {
            using (var inFile = File.OpenText(inFilePath))
            using (var outFile = File.OpenWrite(outFilePath))
            using (var outWriter = new StreamWriter(outFile))
            {
                var cases = int.Parse(inFile.ReadLine());

                for (int c = 0; c < cases; ++c)
                {
                    var input = inFile.ReadLine();
                    var output = Translate(input);
                    var outLine = string.Format("Case #{0}: {1}", c + 1, output);
                    Console.WriteLine(outLine);
                    outWriter.WriteLine(outLine);
                }
                outWriter.Flush();
            }
        }

        private static string Translate(string input)
        {
            char[] chars = new char[input.Length];
            for (int i = 0; i < input.Length; ++i)
            {
                chars[i] = mapping[input[i]];
            }
            return new string(chars);
        }
    }
}
