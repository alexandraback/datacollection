using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012
{
    class Program
    {

        private static char[] chars = new char[] { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());

            for (int i = 0; i < size; i++)
            {
                Console.Write("Case #");
                Console.Write(i+1);
                Console.Write(": ");
                string inputs = Console.ReadLine();
                foreach (char c in inputs.ToCharArray())
                {
                    if (c == ' ')
                    {
                        Console.Write(c);
                    }
                    else
                    {
                        Console.Write(chars[(int)c - 97]);
                    }
                }
                Console.WriteLine();
            }
        }

    }
}
