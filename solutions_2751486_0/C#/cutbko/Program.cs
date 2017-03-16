using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam_Round1C
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFile = args[0];
            string outputFile = args[1];

            string[] lines = File.ReadAllLines(inputFile);

            int casesNumber = int.Parse(lines[0]);
            using (StreamWriter streamWriter = File.CreateText(outputFile))
            {
                for (int i = 1; i <= casesNumber; i++)
                {
                    string name = lines[i].Split(' ')[0];
                    int n = int.Parse(lines[i].Split(' ')[1]);
                    int result = Calculate(name, n);

                    streamWriter.WriteLine("Case #" + i + ": " + result);
                }
            }
        }

        private static int Calculate(string name, int n)
        {
            var vowels = new[] {'a', 'e', 'i', 'o', 'u' };
            int result = 0;

            for (int i = 0; i < name.Length-n+1; i++)
            {
                for (int j = n; j < name.Length - i+1; j++)
                {
                    string substring = name.Substring(i, j);

                    int currentCons = 0;
                    for (int k = 0; k < substring.Length; k++)
                    {
                        if (!vowels.Contains(substring[k]))
                        {
                            currentCons++;
                            if (currentCons >= n)
                            {
                                result++;
                                break;
                            }
                        }
                        else
                        {
                            currentCons = 0;
                        }
                    }
                }
            }

            return result;
        }
    }
}
