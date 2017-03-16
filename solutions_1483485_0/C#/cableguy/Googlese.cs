using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Googlese
{
    class Googlese
    {
        static string ProcessCase(TextReader rd, Dictionary<char, char> googleToEng)
        {
            var google = rd.ReadLine();
            var eng = google.ToCharArray().Select(g => googleToEng[g]).ToArray();
            return new string(eng);
        }

        static string[] knownIn = {"a zoo", "our language is impossible to understand",  "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
        static string[] knownOut = { "y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };

        static void Main(string[] args)
        {
            var mapping = new Dictionary<char, char>();
            for (int i = 0; i < knownIn.Length; i++)
            {
                var eng = knownIn[i];
                var google = knownOut[i];

                Trace.Assert(eng.Length == google.Length);

                for (int j = 0; j < eng.Length; j++)
                {
                    char from = eng[j];
                    char to = google[j];
                    if (from == ' ')
                    {
                        Trace.Assert(to == ' ');
                        continue;
                    }

                    if (mapping.ContainsKey(to))
                        Trace.Assert(mapping[to] == from);
                    else
                        mapping[to] = from;
                }
            }

            Console.WriteLine("{0} known", mapping.Count);

            char missingFrom = ' ';
            char missingTo = ' ';
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (!mapping.ContainsKey(c))
                    missingTo = c;

                if (!mapping.ContainsValue(c))
                    missingFrom = c;
            }

            Trace.Assert(missingFrom != ' ');
            Trace.Assert(missingTo != ' ');

            mapping.Add(missingTo, missingFrom);
            mapping.Add(' ', ' ');

            //const string InFile = @"C:\Users\Owen\Downloads\A-Eg.txt";
            const string InFile = @"C:\Users\Owen\Downloads\A-small-attempt0.in";
            //const string InFile = @"C:\Users\Owen\Downloads\A-large-practice.in";

            using (var rd = File.OpenText(InFile))
            using (var wr = File.CreateText(@"C:\Users\Owen\Downloads\Out.txt"))
            {
                int t = int.Parse(rd.ReadLine());

                for (int i = 1; i <= t; i++)
                {
                    var result = ProcessCase(rd, mapping);
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    wr.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
