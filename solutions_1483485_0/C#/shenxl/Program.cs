using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Speaking_in_Tongues
{
    class Program
    {
        static void Main(string[] args)
        {

            var inputtext = @"E:\Document\JamCode\Speaking_in_Tongues\A-small-attempt3.in";
            var input = readLine(inputtext);
            var testoutput = new List<string>();

            var lettermap = GetLetterMap();
            for (int i = 0; i < input.Length; i++)
            {
                string str = "";
                for (int len = 0; len < input[i].Length; len++)
                {
                    str += lettermap.Where(k => k.Key == input[i][len]).Select(a => a.Value).First();
                }
                testoutput.Add(str);
            }

            var index = 1;
            StreamWriter testfile = File.CreateText(@"E:\Document\JamCode\Speaking_in_Tongues\Cout.txt");
            foreach (var item in testoutput)
            {
                testfile.WriteLine(String.Format("Case #{0}: {1}", index, item));
                index++;
            }
            testfile.Flush();
            testfile.Close();

            foreach (var item in lettermap.OrderBy(a=>a.Key))
            {
                Console.WriteLine(String.Format("K:{0},V:{1}", item.Key, item.Value));
            }
   
            Console.ReadKey();
        }

        private static string[] readLine(string path)
        {
            int counter = 0;

            // Read the file and display it line by line.
            System.IO.StreamReader file =
               new System.IO.StreamReader(path);
            counter = Convert.ToInt32(file.ReadLine());
            string[] line = new string[counter];
            for (int i = 0; i < counter; i++)
            {
                line[i] = file.ReadLine();
            }
            file.Close();

            // Suspend the screen.
            return line;
        }

        private static List<KeyValuePair<char, char>> GetLetterMap()
        {
            var inputtext = @"E:\Document\JamCode\Speaking_in_Tongues\input.txt";
            var outputtext = @"E:\Document\JamCode\Speaking_in_Tongues\output.txt";
            var input = readLine(inputtext);
            var output = readLine(outputtext);

            List<KeyValuePair<char, char>> lettermap = new List<KeyValuePair<char, char>>();
            for (int i = 0; i < 3; i++)
            {
                for (int len = 0; len < input[i].Length; len++)
                {
                    if (!(lettermap.Select(a => a.Key).Contains(input[i][len])))
                    {
                        lettermap.Add(new KeyValuePair<char, char>(input[i][len], output[i][len]));
                    }
                }
            }

            lettermap.Add(new KeyValuePair<char, char>('q', 'z'));
            lettermap.Add(new KeyValuePair<char, char>('z', 'q'));
            return lettermap;
        }
    }
}
