using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ.SiT
{
    class Program
    {
        static void FillDictionary(ref Dictionary<char, char> dict, string input, string output)
        {
            var totalLength = input.Length;

            for (var i = 0; i < totalLength; ++i)
                if (!dict.ContainsKey(input[i]))
                    dict.Add(input[i], output[i]);
        }

        static void Main(string[] args)
        {
            using (var sr = new StreamReader(new FileStream("file.in", FileMode.Open)))
            {
                var testCases = Convert.ToInt32(sr.ReadLine());
                var output = new List<String>();

                var translate = new Dictionary<char, char>();
                FillDictionary(ref translate, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
                FillDictionary(ref translate, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
                FillDictionary(ref translate, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
                translate.Add('z', 'q');
                translate.Add('q', 'z');

                var i = 0;
                while (!sr.EndOfStream)
                    output.Add(sr.ReadLine().ToCharArray().Aggregate("Case #" + ++i + ": ", (current, ch) => current + translate[ch]));

                File.WriteAllLines("file.out", output);
            }
        }
    }
}
