using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamQualification
{
    class ProblemB
    {
        public void Execute(string[] args)
        {

            Dictionary<int, int> maxNoSurprise = new Dictionary<int, int>();
            Dictionary<int, int> maxSurprise = new Dictionary<int, int>();

            for (int i = 0; i <= 30; i++)
            {
                maxNoSurprise[i] = Math.Min(((i - 1) / 3) + 1, i);
            }

            for (int i = 0; i <= 30; i++)
            {
                maxSurprise[i] = Math.Min(((i + 1) / 3) + 1, i);
            }

            StringBuilder output = new StringBuilder();


            using (StreamReader read = new StreamReader(File.OpenRead(args[0])))
            {
                int lines = int.Parse(read.ReadLine());

                for (int k = 0; k < lines; k++)
                {

                    string[] line = read.ReadLine().Split(' ');
                    int dancers = int.Parse(line[0]);
                    int surprises = int.Parse(line[1]);
                    int bestResult = int.Parse(line[2]);

                    int possibleNoSurprise = 0;
                    int possibleSurpriseOnly = 0;

                    for (int i = 3; i < 3 + dancers; i++)
                    {
                        int total = int.Parse(line[i]);

                        if (maxNoSurprise[total] >= bestResult)
                        {
                            possibleNoSurprise++;
                        }
                        else if (maxSurprise[total] >= bestResult)
                        {
                            possibleSurpriseOnly++;
                        }
                    }

                    int totalPossible = possibleNoSurprise + Math.Min(possibleSurpriseOnly, surprises);
                    output.AppendLine("Case #" + (k + 1) + ": " + totalPossible);
                }
            }
            File.WriteAllText("output.txt", output.ToString());
        }
    }
}
