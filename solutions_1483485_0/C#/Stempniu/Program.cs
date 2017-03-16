using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Speaking_in_Tongues
{
    class Program
    {
        private static readonly Dictionary<char, char> Letters = new Dictionary<char, char>
                                                         {
                                                                      {'a', 'y'},
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
                                                                      {'z','q'}
                                                         };

        static void Main(string[] args)
        {
            string[] text = File.ReadAllLines(@"d:\a.txt");
            for (int i = 1; i < text.Length; i++)
            {
                var stringBuilder = new StringBuilder();
                stringBuilder.Append(string.Format("Case #{0}: ", i));
                foreach (char c in text[i])
                {
                    if(c.Equals(' '))
                    {
                        stringBuilder.Append(' ');
                    }
                    else
                    {
                        stringBuilder.Append(Letters[c]);
                    }
                }
                stringBuilder.AppendLine();
                File.AppendAllText(@"d:\out.txt", stringBuilder.ToString());
            }
        }
    }
}
