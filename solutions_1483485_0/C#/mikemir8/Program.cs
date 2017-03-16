using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            ProcessFile();
        }

        public static void ProcessFile()
        {
            string path = @"C:\Users\Mike\Desktop\GoogleOutput\";
            StreamReader sr = new StreamReader(path + "A-small-attempt0.in");
            StreamWriter sw = new StreamWriter(path + "A-small-attempt0.out");

            int cases = int.Parse(sr.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                string res = ProcessCase(sr);
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
            }
            sw.Flush();
            sw.Close();
        }


        private static string ProcessCase(StreamReader sr)
        {
            string b = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
            string a = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
            Dictionary<char, char> alpha = new Dictionary<char, char>();
            alpha['y'] = 'a';
            alpha['e'] = 'o';
            alpha['q'] = 'z';
            for (int i = 0; i < a.Length; i++)
            {
                alpha[b[i]] = a[i];
            }
            string all = "abcdefghijklmnopqrstuvwxyz";
            char missingA = ' '; char missingB = ' ';
            foreach (char c in all.ToCharArray())
            {
                if (!alpha.Values.Contains<char>(c))
                    missingA = c;
                if (!alpha.Keys.Contains<char>(c))
                    missingB = c;
            }
            alpha[missingB] = missingA;

            //string values = sr.ReadLine().Split(' ');
            string phrase = sr.ReadLine();
            var newPhrase = new StringBuilder();

            foreach (var c in phrase)
                newPhrase.Append(alpha[c]);

            return newPhrase.ToString();
        }




    }
}
