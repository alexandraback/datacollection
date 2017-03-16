using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Googlerese
{
    class Program
    {
        static char Translate(char c)
        {
            switch (c)
            {
                case 'a': return 'y';
                case 'b': return 'h';
                case 'c': return 'e';
                case 'd': return 's';
                case 'e': return 'o';
                case 'f': return 'c';
                case 'g': return 'v';
                case 'h': return 'x';
                case 'i': return 'd';
                case 'j': return 'u';
                case 'k': return 'i';
                case 'l': return 'g';
                case 'm': return 'l';
                case 'n': return 'b';
                case 'o': return 'k';
                case 'p': return 'r';
                case 'q': return 'z';
                case 'r': return 't';
                case 's': return 'n';
                case 't': return 'w';
                case 'u': return 'j';
                case 'v': return 'p';
                case 'w': return 'f';
                case 'x': return 'm';
                case 'y': return 'a';
                case 'z': return 'q';
                default: return ' ';
            }
        }

        static void Main(string[] args)
        {
            string fileName = "A-Small";

            // Load file
            TextReader tr = new StreamReader(@"D:\Kiguti\Google Code Jam\2012\Qualification\A.Speaking in Tongues\Input\" + fileName + ".in");
            string sCases = tr.ReadLine();

            // create a writer and open the file
            TextWriter tw = new StreamWriter(@"D:\Kiguti\Google Code Jam\2012\Qualification\A.Speaking in Tongues\Output\" + fileName + ".out");

            int Cases = Int32.Parse(sCases);

            // Run cases
            for (int k = 1; k <= Cases; k++)
            {
                string googlerese = tr.ReadLine();

                StringBuilder word = new StringBuilder();
                foreach (char c in googlerese)
                {
                    word.Append(Translate(c));
                }

                tw.WriteLine(string.Format("Case #{0}: {1}", k.ToString(), word.ToString()));
            }

            // close the stream
            tw.Close();
            tr.Close();
        }
    }
}
