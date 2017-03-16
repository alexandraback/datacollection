using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamRoundOne
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args == null || args.Length < 1)
            {
                Console.WriteLine("Please specify a file.");
                Console.ReadKey();
                return;
            }
            string path = args[0];
            List<string> fileLines = new List<string>();
            try
            {
                fileLines = File.ReadLines(path).ToList<string>();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Could not find file or read from it. " + ex.Message);
                Console.ReadKey();
                return;
            }
            int numberOfLines = Convert.ToInt32(fileLines[0]);
            StringBuilder outputSB = new StringBuilder();
            for (int i = 1; i <= numberOfLines; i++)
            {
                outputSB.AppendLine("Case #" + i + ": " + Translator.Translate(fileLines[i]));
            }
            Console.Write(outputSB.ToString());
            string currentAppPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            File.WriteAllText(currentAppPath + "\\output.txt", outputSB.ToString());
            Console.ReadKey();
        }
    }
}
