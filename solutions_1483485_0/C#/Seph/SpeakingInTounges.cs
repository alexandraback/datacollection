using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GoogleCodeJam
{
    class SpeakingInTounges
    {

        public static void Main()
        {
            string InputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\SpeakingInTounges\\in.txt";
            string OutputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\SpeakingInTounges\\out.txt";

            char[] mapping = new char[26];

            string input = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
            string output = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

            for (int x = 0; x < input.Length; x++)
            {
                char cIn = input[x];
                char cOut = output[x];
                if (cIn != ' ')
                    mapping[cIn - 'a'] = cOut;
            }
            mapping['y' - 'a'] = 'a';
            mapping['e' - 'a'] = 'o';
            mapping['q' - 'a'] = 'z';
            mapping['z' - 'a'] = 'q';
            //Console.WriteLine(mapping);

            string FileOutput = "";
            string FileInput = System.IO.File.ReadAllText(InputPath);

            string[] InputLines = FileInput.Split(new string[] { "\r", "\n", "\r\n" }, StringSplitOptions.RemoveEmptyEntries);

            int Cases = Int32.Parse(InputLines[0]);
            for (int x = 1; x <= Cases; x++)
            {
                if (x != 1)
                    FileOutput += "\n";
                FileOutput += "Case #"+x+": "+Translate(mapping,InputLines[x]);
            }


            System.IO.File.WriteAllText(OutputPath, FileOutput);

        }

        public static string Translate(char[] mapping, string input)
        {
            string result = "";

            for (int x = 0; x < input.Length; x++)
            {
                char cur = input[x];
                char replace = cur!=' '?mapping[cur - 'a']: cur;
                result += replace;
            }

            return result;

        }
    }
}
