using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace T9Spelling
{
    class Program
    {
        static Dictionary<char, char> CharacterMap = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            // File IO
            StreamReader input = new StreamReader(@"..\input.in");
            StringBuilder result = new StringBuilder();

            // Build CharacterMap
            CharacterMap.Add(' ', ' ');
            CharacterMap.Add('a', 'y');
            CharacterMap.Add('b', 'h');
            CharacterMap.Add('c', 'e');
            CharacterMap.Add('d', 's');
            CharacterMap.Add('e', 'o');
            CharacterMap.Add('f', 'c');
            CharacterMap.Add('g', 'v');
            CharacterMap.Add('h', 'x');
            CharacterMap.Add('i', 'd');
            CharacterMap.Add('j', 'u');
            CharacterMap.Add('k', 'i');
            CharacterMap.Add('l', 'g');
            CharacterMap.Add('m', 'l');
            CharacterMap.Add('n', 'b');
            CharacterMap.Add('o', 'k');
            CharacterMap.Add('p', 'r');
            CharacterMap.Add('q', 'z');
            CharacterMap.Add('r', 't');
            CharacterMap.Add('s', 'n');
            CharacterMap.Add('t', 'w');
            CharacterMap.Add('u', 'j');
            CharacterMap.Add('v', 'p');
            CharacterMap.Add('w', 'f');
            CharacterMap.Add('x', 'm');
            CharacterMap.Add('y', 'a');
            CharacterMap.Add('z', 'q');


            // Number of cases
            byte numCases = Convert.ToByte(input.ReadLine());
            // Loop through each case
            for (byte n = 0; n < numCases; n++)
            {
                result.AppendFormat("Case #{0}: ", n+1);
                // Read message
                char[] msg = input.ReadLine().ToCharArray();
                // Translate characters
                foreach (char c in msg)
                {
                    result.Append(CharacterMap[c]);
                }
                result.AppendLine();
            }

            // Print result
            Console.Write(result.ToString());
            File.WriteAllText(@"..\output.txt", result.ToString());
        }
    }
}
