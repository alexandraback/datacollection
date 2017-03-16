using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SpeakingInTongues
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(args[0]);
            int count = int.Parse(reader.ReadLine());
            List<string> lines = new List<string>();
            while (count != 0)
            {
                lines.Add(reader.ReadLine());
                count--;
            }

            for(int i = 0; i < lines.Count; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                foreach (char googlereseChar in lines[i])
                {
                    Console.Write(Translate(googlereseChar));
                }
                Console.WriteLine();
            }
        }

        private static char Translate(char googlereseChar)
        {
            switch (googlereseChar)
            {
                case ' ':
                    return ' ';
                case 'a':
                    return 'y';
                case 'b':
                    return 'h';
                case 'c':
                    return 'e';
                case 'd':
                    return 's';
                case 'e':
                    return 'o';
                case 'f':
                    return 'c';
                case 'g':
                    return 'v';
                case 'h':
                    return 'x';
                case 'i':
                    return 'd';
                case 'j':
                    return 'u';
                case 'k':
                    return 'i';
                case 'l':
                    return 'g';
                case 'm':
                    return 'l';
                case 'n':
                    return 'b';
                case 'o':
                    return 'k';
                case 'p':
                    return 'r';
                case 'q':
                    return 'z';
                case 'r':
                    return 't';
                case 's':
                    return 'n';
                case 't':
                    return 'w';
                case 'u':
                    return 'j';
                case 'v':
                    return 'p';
                case 'w':
                    return 'f';
                case 'x':
                    return 'm';
                case 'y':
                    return 'a';
                case 'z':
                    return 'q';
                default:
                    throw new ApplicationException("A new character?");
            }
        }
    }
}
