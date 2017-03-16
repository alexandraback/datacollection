using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012_C
{
    class Program
    {
        static void Main(string[] args)
        {
            string line = string.Empty;
            System.IO.StreamReader file = new System.IO.StreamReader("C:\\googleCodeJam\\C\\test.in");
            System.IO.StreamWriter resultFile = new StreamWriter("C:\\googleCodeJam\\C\\result.txt");
            line = file.ReadLine();
            int T = int.Parse(line);

            for (int i = 0; i < T; i++)
            {
                int res = 0;
                string resultLine = "Case #" + (i + 1).ToString() + ": ";
                line = file.ReadLine();
                string[] inputs = line.Split(' ');
                int A = int.Parse(inputs[0]);
                int B = int.Parse(inputs[1]);
                

                for (int j = A; j < B; j++)
                {
                    string start = j.ToString();
                    List<int> check = new List<int>();
                    for (int k = 1; k < start.Length; k++)
                    {                        
                        int movedDigits = int.Parse(start.Substring(k) + start.Substring(0, k));
                        if (movedDigits>j && movedDigits<=B && !check.Contains(movedDigits))
                        {
                            res++;
                            check.Add(movedDigits);
                        }
                    }
                }
                resultLine = resultLine + res.ToString();
                resultFile.WriteLine(resultLine);
                
            }
            file.Close();
            resultFile.Close();
            Console.WriteLine("Done");
            Console.ReadLine();
        }
    }
}
