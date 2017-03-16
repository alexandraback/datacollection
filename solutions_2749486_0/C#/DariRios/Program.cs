using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C
{
    class Program
    {
        static void Main(string[] args)
        {
            /* CONSONANTS 
            StringBuilder outputFile = new StringBuilder();
            string[] lines = System.IO.File.ReadAllLines(args[0]);
            int problemsNumber = 0;
            if (int.TryParse(lines[0], out problemsNumber))
            {
                for (int i = 1; i <= problemsNumber; ++i)
                {
                    string[] tokens = lines[i].Split();
                    string name = "";
                    int n = 0;

                    name = tokens[0];
                    int.TryParse(tokens[1], out n);
                    outputFile.AppendLine("Case #" + i + ": " + Consonants.CalculateN(name,n));
                }
            }


            using (StreamWriter outfile = new StreamWriter(args[1] + @"\output.txt"))
            {
                outfile.Write(outputFile.ToString());
            }
             * 
             */


            /* POGO */ 
            StringBuilder outputFile = new StringBuilder();
            string[] lines = System.IO.File.ReadAllLines(args[0]);
            int problemsNumber = 0;
            if (int.TryParse(lines[0], out problemsNumber))
            {
                for (int i = 1; i <= problemsNumber; ++i)
                {
                    string[] tokens = lines[i].Split();
                    int x = 0;
                    int y = 0;

                    int.TryParse(tokens[0], out x);
                    int.TryParse(tokens[1], out y);
                    outputFile.AppendLine("Case #" + i + ": " + Pogo.GetMovements(x,y));
                }
            }


            using (StreamWriter outfile = new StreamWriter(args[1] + @"\output.txt"))
            {
                outfile.Write(outputFile.ToString());
            }
            
        }
    }
}
