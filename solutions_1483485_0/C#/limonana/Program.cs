using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace template
{
    class Program
    {
        //static Dictionary<char, char> mappings;
        static void Main(string[] args)
        {
            Dictionary<char, char>  mappings = prepareMappings();
            StreamReader reader = File.OpenText("A-small-practice.in");
            StreamWriter writer = new StreamWriter("small_out.txt");            
            int T = int.Parse(reader.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                String answer= translate(reader.ReadLine(),mappings); 

                writer.WriteLine(String.Format("Case #{0}: {1}", t, answer));
            }
            writer.Flush();
            writer.Close();
            reader.Close();
        }

        private static string translate(string str, Dictionary<char, char> mappings)
        {
            StringBuilder res = new StringBuilder(str.Length);
            for (int i = 0; i < str.Length; i++)
            {
                res.Append(mappings[str[i]]);
            }

            return res.ToString();
        }

        private static Dictionary<char, char> prepareMappings()
        {
            Dictionary<char, char> dic = new Dictionary<char, char>();
            dic.Add('y', 'a');
            dic.Add('e', 'o');
            dic.Add('q', 'z');
            dic.Add(' ', ' ');
            String org = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
            String googles = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
            for (int i = 0; i < googles.Length; i++)
            {
                if (!dic.ContainsKey(googles[i]))
                    dic.Add(googles[i], org[i]);
            }
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (!dic.ContainsKey(c))
                {
                    dic.Add(c, 'q');
                }
            }
            return dic;
        }
    }
}
