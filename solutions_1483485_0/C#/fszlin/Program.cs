using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication6
{
    class Program
    {
        static Dictionary<char, char> mapping = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            var sampleIn = new[] {
                "aozq",
                "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"
            };
            var sampleOut = new[] {
                "yeqz",
                "our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"
            };

            for (var i = 0; i < sampleIn.Length; ++i)
            {
                for (var j = 0; j < sampleIn[i].Length; ++j)
                {
                    if (Char.IsLetter(sampleIn[i][j]))
                    {
                        mapping[sampleIn[i][j]] = sampleOut[i][j];
                    }
                }
            }

            var inputs = File.ReadAllLines("../../in.txt");
            var buffer = new StringBuilder();
            var T = Int32.Parse(inputs[0]);
            for (int i = 1; i < inputs.Length; ++i)
            {
                buffer.AppendFormat("Case #{0}: ", i);
                new Program().Process(inputs[i], buffer);
            }

            Console.Write(buffer);
            File.WriteAllText("../../out.txt", buffer.ToString());
        }

        private void Process(string text, StringBuilder output)
        {
            foreach (var c in text)
            {
                if (Char.IsLetter(c))
                    output.Append(mapping[c]);
                else
                    output.Append(c);
            }

            output.AppendLine();
        }
    }
}
