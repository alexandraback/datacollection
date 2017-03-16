using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            byte[] googlereseToEnglish = ASCIIEncoding.ASCII.GetBytes("yhesocvxduiglbkrztnwjpfmaq");
            
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= numberOfCases; currentCase++)
            {
                byte[] characters = ASCIIEncoding.ASCII.GetBytes(input.ReadLine());
                for (int position = 0; position < characters.Length; position++)
                {
                    if (characters[position] >= (byte)'a' && characters[position] <= (byte)'z')
                    {
                        characters[position] = googlereseToEnglish[characters[position] - (byte)'a'];
                    }
                }
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, ASCIIEncoding.ASCII.GetString(characters)));
            }
        }
    }
}
