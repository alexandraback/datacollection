using System;
using System.IO;
using System.Collections.Generic;

namespace GoogleCodeJam2012
{
    class Contestant
    {
        public int i { get; set; }
        public double score { get; set; }
        public double toSave { get; set; }
    }

    class A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("a.in");
            TextWriter fileOut = new StreamWriter("a.out");


            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 0; caseCount < countNum; caseCount++)
            {
                // Parse input
                string[] info = fileIn.ReadLine().Split(' ');
                int contestantCount = Int32.Parse(info[0]);
                List<Contestant> contestants = new List<Contestant>();
                contestants.Capacity = contestantCount;
                
                for (int i = 0; i < info.Length - 1; i++)
                {
                    Contestant contestant = new Contestant();
                    contestant.i = i;
                    contestant.score = double.Parse(info[i + 1]);
                    contestants.Add(contestant);
                }

                contestants.Sort((a, b) => a.score.CompareTo(b.score));

                double scoreTotal = 0;
                double scoreRemaining = 0;
                foreach (Contestant c in contestants) { scoreTotal += c.score; }
                scoreRemaining = scoreTotal;

                for (int i = 1; i < contestantCount; i++)
                {
                    double scoreDiff = contestants[i].score - contestants[i - 1].score;

                    if (scoreDiff * i > scoreRemaining)
                    {
                        contestants[i].toSave = 0.0f;
                        for (int j = 0; j < i; j++)
                        {
                            contestants[j].toSave += scoreRemaining / i;
                        }
                        scoreRemaining = 0.0f;
                    }
                    else
                    {
                        for (int j = 0; j < i; j++)
                        {
                            contestants[j].toSave += scoreDiff;
                            scoreRemaining -= scoreDiff;
                        }
                    }
                }

                if (scoreRemaining > 0.0f)
                {
                    for (int i = 0; i < contestantCount; i++)
                    {
                        contestants[i].toSave += scoreRemaining / contestantCount;
                    }
                }

                contestants.Sort((a, b) => a.i.CompareTo(b.i));

                double toSaveTotal = 0;
                foreach (Contestant c in contestants) { toSaveTotal += c.toSave / scoreTotal; }
               

                fileOut.Write("Case #" + (caseCount + 1) + ": ");
                for (int i = 0; i < contestantCount; i++)
                {
                    double val = 100 * (contestants[i].toSave / scoreTotal);
                    fileOut.Write(val.ToString("0.000000"));
                    if (i != contestantCount - 1) { fileOut.Write(" ");  }
                }
                fileOut.WriteLine("");

                Console.WriteLine("Case #" + (caseCount + 1) + " completed!");
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();
        }       
    }

}
