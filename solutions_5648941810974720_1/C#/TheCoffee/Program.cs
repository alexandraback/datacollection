using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static StreamWriter output;
        static string root = @"C:\Users\Michael\Documents\Visual Studio 2015\Projects\ConsoleApplication1\";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(root + "A-large.in");
            output = new StreamWriter(root + "out.txt");

            int cases = int.Parse(input[0]);

            for (int i = 1; i < input.Length; i++)
            {
                Say("Case #" + i + ": " + Process(input[i]));
            }

            output.Close();
            Console.ReadLine();
        }

        static string Process(string n)
        {
            var numbers = new List<int>();
            var sb = new StringBuilder(n);

            while (n.LastIndexOf('Z') != -1)
            {
                n = n.Remove(n.LastIndexOf('Z'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                n = n.Remove(n.LastIndexOf('R'), 1);
                n = n.Remove(n.LastIndexOf('O'), 1);
                numbers.Add(0);
            }

            while (n.LastIndexOf('W') != -1)
            {
                n = n.Remove(n.LastIndexOf('T'), 1);
                n = n.Remove(n.LastIndexOf('W'), 1);
                n = n.Remove(n.LastIndexOf('O'), 1);
                numbers.Add(2);
            }

            while (n.LastIndexOf('X') != -1)
            {
                n = n.Remove(n.LastIndexOf('S'), 1);
                n = n.Remove(n.LastIndexOf('I'), 1);
                n = n.Remove(n.LastIndexOf('X'), 1);
                numbers.Add(6);
            }

            while (n.LastIndexOf('G') != -1)
            {
                n = n.Remove(n.LastIndexOf('E'), 1);
                n = n.Remove(n.LastIndexOf('I'), 1);
                n = n.Remove(n.LastIndexOf('G'), 1);
                n = n.Remove(n.LastIndexOf('H'), 1);
                n = n.Remove(n.LastIndexOf('T'), 1);
                numbers.Add(8);
            }

            while (n.LastIndexOf('S') != -1)
            {
                n = n.Remove(n.LastIndexOf('S'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                n = n.Remove(n.LastIndexOf('V'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                n = n.Remove(n.LastIndexOf('N'), 1);
                numbers.Add(7);
            }

            while (n.LastIndexOf('H') != -1)
            {
                n = n.Remove(n.LastIndexOf('T'), 1);
                n = n.Remove(n.LastIndexOf('H'), 1);
                n = n.Remove(n.LastIndexOf('R'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                numbers.Add(3);
            }

            while (n.LastIndexOf('V') != -1)
            {
                n = n.Remove(n.LastIndexOf('F'), 1);
                n = n.Remove(n.LastIndexOf('I'), 1);
                n = n.Remove(n.LastIndexOf('V'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                numbers.Add(5);
            }

            while (n.LastIndexOf('R') != -1)
            {
                n = n.Remove(n.LastIndexOf('F'), 1);
                n = n.Remove(n.LastIndexOf('O'), 1);
                n = n.Remove(n.LastIndexOf('U'), 1);
                n = n.Remove(n.LastIndexOf('R'), 1);
                numbers.Add(4);
            }

            while (n.LastIndexOf('O') != -1)
            {
                n = n.Remove(n.LastIndexOf('O'), 1);
                n = n.Remove(n.LastIndexOf('N'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                numbers.Add(1);
            }

            while (n.LastIndexOf('I') != -1)
            {
                n = n.Remove(n.LastIndexOf('N'), 1);
                n = n.Remove(n.LastIndexOf('I'), 1);
                n = n.Remove(n.LastIndexOf('N'), 1);
                n = n.Remove(n.LastIndexOf('E'), 1);
                numbers.Add(9);
            }

            numbers.Sort();

            string numbersString = "";
            foreach(int number in numbers)
            {
                numbersString += number.ToString();
            }

            return n + "" + numbersString;
        }


        

        static void Say(string text)
        {
            Console.WriteLine(text);
            output.WriteLine(text);
        }
    }
}
