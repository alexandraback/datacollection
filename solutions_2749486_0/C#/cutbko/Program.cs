using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
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
                    int x = int.Parse(lines[i].Split(' ')[0]);
                    int y = int.Parse(lines[i].Split(' ')[1]);
                    string result = Calculate(x, y);

                    streamWriter.WriteLine("Case #" + i + ": " + result);
                }
            }
        }

        private static string Calculate(int x, int y)
        {
            string result = string.Empty;
            
            const string goLeft = "EW";
            const string goRight = "WE";
            const string goTop = "SN";
            const string goBottom = "NS";

            if (x > 0)
            {
                for (int i = 0; i < x; i++)
                {
                    result += goRight;
                }
            }
            else
            {
                for (int i = 0; i < Math.Abs(x); i++)
                {
                    result += goLeft;
                }
            }


            if (y > 0)
            {
                for (int i = 0; i < y; i++)
                {
                    result += goTop;
                }
            }
            else
            {
                for (int i = 0; i < Math.Abs(y); i++)
                {
                    result += goBottom;
                }
            }

            return result;
        }
    }
}
