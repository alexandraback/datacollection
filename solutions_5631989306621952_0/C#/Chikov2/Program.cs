using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam1
{
    class Program
    {
        private static bool finished(List<bool> l)
        {
            for (int i = 0; i < l.Count; i++)
            {
                if (!l[i]) return false;
            }

            return true;
        }

        static void Main(string[] args)
        {
            string inputPath = @"C:\Users\pchikov\Desktop\GoogleCodeJam1\input.txt";
            string outputPath = @"C:\Users\pchikov\Desktop\GoogleCodeJam1\output.txt";

            using (StreamWriter sw = File.CreateText(outputPath))
            {
                using (StreamReader sr = File.OpenText(inputPath))
                {
                    string numCases = sr.ReadLine().Trim();
                    

                    for (int i = 1; i < Int32.Parse(numCases) + 1; i++)
                    {
                        string word = sr.ReadLine().Trim();
                        string begin = ""; string end = "";
                        int place = 0;

                        do
                        {
                            char largest = word[0]; place = -1;
                            for (int l = 0; l < word.Length; l++)
                            {
                                if (word[l] >= largest) { largest = word[l]; place = l; }
                            }

                            begin = begin + largest;
                            end = word.Substring(place + 1) + end;

                            word = word.Substring(0, place);
                        } while (word.Length > 1);

                        string result = begin; if (word.Length == 1) result += word[0]; result += end;

                        sw.WriteLine("Case #" + i + ": " + result);
                    }
                }
            }
        }
    }
}
