using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace gcj2012 {
    public static class QRA {
        public const string Round = "QR";
        public const string Problem = "A";
        //public const string Type = "sample";
        public const string Type = "small";
        //public const string Type = "large";

        public static void Solve() {
            const string inputFile = Round + Problem + "-" + Type + ".in";
            const string outputFile = Round + Problem + "-" + Type + ".out";

            var inputs="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
            var outputs = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

            Dictionary<char,char> dicts=new Dictionary<char, char>();
            dicts.Add('z','q');
            dicts.Add('q', 'z');
            dicts.Add(' ', ' ');
            for (int i = 0; i < inputs.Length; i++)
            {
                if (inputs[i]==' ') continue;
                if (!dicts.ContainsKey(inputs[i]))
                {
                    dicts.Add(inputs[i], outputs[i]);
                }
                else
                {
                    if (outputs[i]!=dicts[inputs[i]])
                    {
                        Debugger.Break();
                    }
                }

            }

            var reader = new StreamReader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            string line = reader.ReadLine();

            String[] valoriInput = line.Split(' ');

            int T = int.Parse(valoriInput[0]);


            for (int i = 0; i < T; i++)
            {
                line = reader.ReadLine();

                string outputvar = "";
                foreach (var c in line)
                {
                    outputvar += dicts[c];
                }

                String Case="Case #" + (i+1).ToString() + ": ";
                String output = Case + outputvar;
                tw.WriteLine(output);
            }

            tw.Close();
            reader.Close();

        }


    }


}
