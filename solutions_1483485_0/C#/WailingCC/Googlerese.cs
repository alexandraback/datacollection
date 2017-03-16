using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FacebookHackerCup2012
{
    class Googlerese
    {
        Dictionary<Char, Char> letters = new Dictionary<char, char>();
        int cases;
        string line, line2;
        public Googlerese()
        {
            BuildDictionary();
            StreamWriter output = new StreamWriter("googlereseoutput.txt");
            StreamReader file = new StreamReader("googlerese.txt");
            cases = Convert.ToInt32(file.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                line2 = "";
                for (int j = 0; j < line.Length; j++)
                {
                    char a = line[j];
                    line2 += letters[a];
                }
                output.WriteLine("Case #" + (i + 1) + ": " + line2);

            }
            file.Close();
            output.Close();
            Console.WriteLine("Done!");
        }

        public void BuildDictionary()
        {
            StreamReader file = new StreamReader("googlereseinput.txt");
            StreamReader file2 = new StreamReader("googlereseinput2.txt");
            
            cases = Convert.ToInt32(file.ReadLine());
            letters.Add('y', 'a');
            letters.Add('e', 'o');
            letters.Add('q', 'z');
            letters.Add('z','q');
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                line2 = file2.ReadLine();
                for (int j = 0; j < line.Length; j++)
                {
                    char a = line[j];
                    char b = line2[j];
                    if (!letters.ContainsKey(a)) letters.Add(a, b);
                }
                
            }

            var list = letters.Keys.ToList();
            list.Sort();
            file.Close();
            file2.Close();
        }
    }
}
