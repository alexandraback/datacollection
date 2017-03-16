using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Googleeze
{
    class Program
    {

        

        static void Main(string[] args)
        {

            
            var mapping = CreateDictionary();

            var line1 = Console.ReadLine();

            var numTestCases = Int32.Parse(line1);

            for (int test = 0; test < numTestCases; test++)
            {

                var testCase = Console.ReadLine();

                Console.Write("Case #{0}: ", test + 1);
                    
                for (int i = 0; i < testCase.Length; i++)
                {
                    if (testCase[i] == ' ')
                    {
                        Console.Write(testCase[i]);
                    }
                    else
                    {
                        Console.Write(mapping[testCase[i]]);
                    }
                    
                }
                Console.WriteLine();
            }
        }

        private static Dictionary<char, char>  CreateDictionary()
        {
            Dictionary<char, char> mapping = new Dictionary<char, char>();

            mapping.Add('y', 'a');
            mapping.Add('n', 'b');
            mapping.Add('f', 'c');
            mapping.Add('i', 'd');
            mapping.Add('c', 'e');
            mapping.Add('w', 'f');
            mapping.Add('l', 'g');
            mapping.Add('b', 'h');
            mapping.Add('k', 'i');
            mapping.Add('u', 'j');
            mapping.Add('o', 'k');
            mapping.Add('m', 'l');
            mapping.Add('x', 'm');
            mapping.Add('s', 'n');
            mapping.Add('e', 'o');
            mapping.Add('v', 'p');
            mapping.Add('z', 'q');
            mapping.Add('p', 'r');
            mapping.Add('d', 's');
            mapping.Add('r', 't');
            mapping.Add('j', 'u');
            mapping.Add('g', 'v');
            mapping.Add('t', 'w');
            mapping.Add('h', 'x');
            mapping.Add('a', 'y');
            mapping.Add('q', 'z');

            return mapping;
        }
    }
}
