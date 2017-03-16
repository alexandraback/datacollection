using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SpeakingInTongues
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());

            map.Add('y', 'a');
            map.Add('n', 'b');
            map.Add('f', 'c');
            map.Add('i', 'd');
            map.Add('c', 'e');
            map.Add('w', 'f');
            map.Add('l', 'g');
            map.Add('b', 'h');
            map.Add('k', 'i');
            map.Add('u', 'j');
            map.Add('o', 'k');
            map.Add('m', 'l');
            map.Add('x', 'm');
            map.Add('s', 'n');
            map.Add('e', 'o');
            map.Add('v', 'p');
            map.Add('z', 'q');
            map.Add('p', 'r');
            map.Add('d', 's');
            map.Add('r', 't');
            map.Add('j', 'u');
            map.Add('g', 'v');
            map.Add('t', 'w');
            map.Add('h', 'x');
            map.Add('a', 'y');
            map.Add('q', 'z');

            for (int i = 0; i < testCaseCount; i++)
                ProcessTestCase(i + 1);
        }

        private static Dictionary<char, char> map = new Dictionary<char, char>();

        private static void ProcessTestCase(int caseNumber)
        {
           
            
            // Read in the next line of the program
            string line = Console.ReadLine();

            Console.Write("Case #" + caseNumber + ": ");

            foreach (char c in line.ToCharArray())
            {
                if (c == ' ')
                    Console.Write(' ');
                else
                    Console.Write(map[c]);
            }
                Console.WriteLine();
        }
    }
}
