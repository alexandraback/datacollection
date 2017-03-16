using System;
using System.Collections.Generic;
using System.Linq; 
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            checked
            {
                const string outputfile = @"F:\GoogleCodeJam\output.txt";

                StreamReader r = new StreamReader(@"F:\GoogleCodeJam\input.in");

                if (File.Exists(outputfile))
                    File.Delete(outputfile);

                if (File.Exists(@"F:\GoogleCodeJam\Program.cs"))
                    File.Delete(@"F:\GoogleCodeJam\Program.cs");

                File.Copy(@"f:\Projects\ConsoleApplication1\ConsoleApplication1\Program.cs",
                    @"F:\GoogleCodeJam\Program.cs");

                StreamWriter w = new StreamWriter(outputfile);

                int T = int.Parse(r.ReadLine());

                // prepare arrs
                Dictionary<char, char> map = new Dictionary<char, char>();
                //map.Add('q', 'q');
                //map.Add('z', 'z');

                map.Add('q', 'z');
                map.Add('z', 'q');


                fill("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi", map);
                fill("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", map);
                fill("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv", map);

                // console all unknown characters
                string all = "abcdefghijklmnopqrstuvwxyz";
                Console.WriteLine(all);
                Console.WriteLine(translate(all, map));
                Console.ReadLine();

                for (int t = 0; t < T; t++)
                {
                    string s = r.ReadLine();

                    
                    
                    w.WriteLine("Case #" + (t + 1) + ": " + translate(s, map));

                    
                }

                r.Close();
                w.Close();
            }
        }

        private static void fill(string eng, string g, Dictionary<char, char> dict)
        {
            for (int i = 0; i < g.Length; i++)
            {
                if (dict.ContainsKey(g[i]))
                    continue;

                dict.Add(g[i], eng[i]);
            }
        }

        private static string translate(string g, Dictionary<char, char> dict)
        {
            char[] ret = new char[g.Length];
            for (int i = 0; i < g.Length; i++)
            {
                if (dict.ContainsKey(g[i]))
                    ret[i] = dict[g[i]];
                else
                {
                    ret[i] = g[i].ToString().ToUpper()[0];
                }
            }

            return new string(ret);
        }

       
    }
}
