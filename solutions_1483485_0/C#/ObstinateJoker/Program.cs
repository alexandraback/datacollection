using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA_Small
{
    class Program
    {
        static Dictionary<char, char> googleese = new Dictionary<char, char>()
        {
            {'Y','A'}, {'N','B'}, {'F','C'}, {'I','D'}, {'C','E'}, {'W','F'}, {'L','G'},
            {'B','H'}, {'K','I'}, {'U','J'}, {'O','K'}, {'M','L'}, {'X','M'}, {'S','N'},
            {'E','O'}, {'V','P'}, {'Z','Q'}, {'P','R'}, {'D','S'}, {'R','T'}, {'J','U'},
            {'G','V'}, {'T','W'}, {'H','X'}, {'A','Y'}, {'Q','Z'},
            
            {'y','a'}, {'n','b'}, {'f','c'}, {'i','d'}, {'c','e'}, {'w','f'}, {'l','g'},
            {'b','h'}, {'k','i'}, {'u','j'}, {'o','k'}, {'m','l'}, {'x','m'}, {'s','n'},
            {'e','o'}, {'v','p'}, {'z','q'}, {'p','r'}, {'d','s'}, {'r','t'}, {'j','u'},
            {'g','v'}, {'t','w'}, {'h','x'}, {'a','y'}, {'q','z'}
        };

        static void Main(string[] args)
        {
            int numLines = int.Parse(Console.ReadLine());

            string output = "";
            for (int i = 0; i < numLines; i++)
            {
                string input = Console.ReadLine();

                output += "Case #" + (i + 1) + ": ";

                foreach (char a in input)
                {
                    char outputChar;
                    if (googleese.TryGetValue(a, out outputChar))
                        output += outputChar;
                    else
                        output += a;
                }

                output += "\n";
            }

            Console.WriteLine(output);
        }
    }
}
