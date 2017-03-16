#region using directives

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

#endregion

namespace ProblemA
{
    internal class Program
    {
        private static readonly Dictionary<char, char> Dictionary = new Dictionary<char, char> {{'y', 'a'}, {'e', 'o'}, {'q', 'z'}, {'z', 'q'}};

        private static void Main()
        {
            string[] input = File.ReadAllLines("input.txt");
            int count = Int32.Parse(input[0]);

            var sb = new StringBuilder();

            for (int i = 1; i <= count; i++)
            {
                sb.Append("Case #" + i + ": ");
                for (int pos = 0; pos < input[i].Length; pos++)
                {
                    char c = input[i][pos];

                    if (!Dictionary.ContainsKey(c))
                    {
                        int index = Stone.IndexOf(c);
                        Dictionary.Add(c, Rosetta[index]);
                    }

                    sb.Append(Dictionary[c]);
                }
                sb.AppendLine();
            }

            Console.Write(sb.ToString());
            File.WriteAllText("ouput.txt", sb.ToString().Trim());
        }

        private const string Rosetta = @"our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up";

        private const string Stone = @"ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv";
    }
}