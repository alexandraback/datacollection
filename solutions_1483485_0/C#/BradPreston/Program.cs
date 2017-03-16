using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CJ2012Round1Prob1
{
    class Program
    {

        

        public static void solve()
        {
            Dictionary<char, char> mapping;
            

            mapping = new Dictionary<char,char>();

            Dictionary<string, string> stringMappings = new Dictionary<string, string>();
            stringMappings.Add("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            stringMappings.Add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            stringMappings.Add("yeqz","aozq");
            stringMappings.Add("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

            
            foreach (KeyValuePair<string, string> pair in stringMappings)
            {

                for (int i = 0; i < pair.Key.Length; i++)
                {
                    if (!mapping.ContainsKey(pair.Key[i]))
                    {
                        mapping.Add(pair.Key[i], pair.Value[i]);
                        
                    }
                }
            }


            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");

            int numCases = Int32.Parse(sr.ReadLine());

            int lineNum = 0;
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                lineNum++;
                sw.Write("Case #" + lineNum.ToString() + ": ");
                foreach (char c in line)
                {
                    sw.Write(mapping[c]);
                }
                sw.WriteLine();
            }

            sw.Close();
            sr.Close();

            
            
            
        }

        static void Main(string[] args)
        {
            solve();
            Console.ReadKey();
        }
    }
}
