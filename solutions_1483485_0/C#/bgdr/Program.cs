using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace GoogleCodeJam
{
    class Program
    {
        static string translate(string inp, Dictionary<char, char> map)
        {
            string outp = "";
            for (int i = 0; i < inp.Length; ++i)
            {
                char c = inp[i];
                if (c != ' ')
                {
                    outp += map[c];
                }
                else
                {
                    outp += " ";
                }
            }
            return outp;
        }
        static void Main(string[] args)
        {
            string inp0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
            string out0 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
            Dictionary<char, char> map = new Dictionary<char, char>();
            map.Add('z', 'q');
            map.Add('q', 'z');
            for (int i = 0; i < inp0.Length; ++i)
            {
                if (!map.ContainsKey(inp0[i]))
                {
                    map.Add(inp0[i], out0[i]);
                }
            }
            string line;
            StreamReader sr = new StreamReader("A.in");
            StreamWriter sw = new StreamWriter("A.out");

            int n = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < n; ++i)
            {
                line = sr.ReadLine();
                sw.WriteLine("Case #" + (i + 1) + ": " + translate(line, map));
            }
            sw.Close();
        }
    }
}
