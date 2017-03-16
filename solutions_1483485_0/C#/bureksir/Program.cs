using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string line;
            string resultLine = string.Empty;
            string keys =   "zqwertyuiopasdfghjklxcvbnm ";
            string values = "qzfotwajdkrynscvxuigmephbl ";
            System.IO.StreamReader file = new System.IO.StreamReader("C:\\googleCodeJam\\1\\A-small-attempt0.in");
            System.IO.StreamWriter resultFile = new StreamWriter("C:\\googleCodeJam\\1\\result.txt");
            line = file.ReadLine();

            int rows = int.Parse(line);


            for (int i = 0; i < rows; i++)
            {
                line = file.ReadLine();
                resultLine = "Case #" + (i+1).ToString() + ": ";
                foreach (var codeChar in line)
                {
                    resultLine = resultLine + values[keys.IndexOf(codeChar)];
                    //Console.Write(values[keys.IndexOf(codeChar)]);
                }
                resultFile.WriteLine(resultLine);
            }

            file.Close();
            resultFile.Close();
            // Suspend the screen.
            Console.WriteLine("Done");
            Console.ReadLine();
        }
    }
}
