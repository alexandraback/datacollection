using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"../../A-small.in");
            
            lines[0] = null;

            Dictionary<char, char> decode = new Dictionary<char, char>()
            {
                {'a','y'},
                {'b','h'},
                {'c','e'},
                {'d','s'},
                {'e','o'},
                {'f','c'},
                {'g','v'},
                {'h','x'},
                {'i','d'},
                {'j','u'},
                {'k','i'},
                {'l','g'},
                {'m','l'},
                {'n','b'},
                {'o','k'},
                {'p','r'},
                {'q','z'},
                {'r','t'},
                {'s','n'},
                {'t','w'},
                {'u','j'},
                {'v','p'},
                {'w','f'},
                {'x','m'},
                {'y','a'},
                {'z','q'},
            };

            int ct = 1;
            List<string> output = new List<string>();
            foreach (string line in lines)
            {
                if (line == null)
                    continue;
                string decodedStr = "Case #" + ct + ": ";
                foreach (char character in line)
                {
                    if (character == ' ')
                    {
                        decodedStr += ' ';
                    }
                    else
                    {
                        decodedStr += decode[character];
                    }
                }
                output.Add(decodedStr);
                ct++;
            }
            System.IO.File.WriteAllLines("../../A-small.out", output);
        }
    }
}
