using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamZad1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input =  "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvqz";
            string output = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upzq";

            Dictionary<char, char> maping = new Dictionary<char, char>();

            for (int i = 0; i < input.Length; i++)
            {
                if (!maping.ContainsKey(input[i]))
                {
                    maping.Add(input[i], output[i]);
                }
            }

            string[] file = File.ReadAllLines(@"C:\Users\Admin\Downloads\A-small-attempt0.in");
            int n = int.Parse(file[0]);

            StringBuilder bui = new StringBuilder();
            for (int i = 1; i <= n; ++i)
            {
                bui.Append("Case #" + i.ToString() + ": ");
                foreach (char item in file[i])
                {
                    bui.Append(maping[item]);
                }
                bui.Append(Environment.NewLine);
            }
            File.WriteAllText(@"C:\Users\Admin\Downloads\out.txt", bui.ToString());
        }
    }
}

