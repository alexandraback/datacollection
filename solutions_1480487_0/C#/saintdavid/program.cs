using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Prj_a
{
    class program
    {
        public static void Main()
        {
            //string[] lines = funcs.getInputDocs(@"A.txt");
            string[] lines = funcs.getInputDocs(@"A-small-attempt0.in");
            int size = int.Parse(lines[0]);
            List<string> newlines = new List<string>();

            for (int i = 1; i < lines.Length; i++)
            {
                string thisline = lines[i];
                string[] words = thisline.Split();
                int N = int.Parse(words[0]);

                double sum = 0;
                List<double> score = new List<double>();
                List<double> rank_score = new List<double>();
                List<double> percentage = new List<double>();
                for (int j = 1; j < words.Length; j++)
                {
                    sum = sum + double.Parse(words[j]);
                    score.Add(double.Parse(words[j]));
                    rank_score.Add(double.Parse(words[j]));                    
                }

                //Sorting all scores.
                for (int j = 0; j < N; j++)
                    for (int k = j + 1; k < N; k++)
                        if (rank_score[j] < rank_score[k])
                        {
                            double t = rank_score[j];
                            rank_score[j] = rank_score[k];
                            rank_score[k] = t;
                        }

                //OK. Here we begin calculating.
                //From top rank down, possibility of quit.
                for (int j = 0; j < N; j++)
                {
                    double balance = rank_score[j];
                    double dist = 0;
                    int member = 0;
                    for (int k = 0; k < N; k++)
                        if (balance >= score[k])
                        {
                            dist = dist + (balance - score[k]);
                            member++;
                        }

                    if (dist <= sum)
                    {
                        //we can start calculating. This is balance position. 
                        double all_reach = balance + (sum - dist) / (double)member;
                        for (int k = 0; k < N; k++)
                        {
                            if (all_reach >= score[k])
                            {
                                double add_value = (all_reach - score[k]) / sum;
                                percentage.Add(add_value);
                            }
                            else
                                percentage.Add(0);

                        }
                        break;
                    }
                }

                string s = "Case #" + (i).ToString() + ":";
                for (int j = 0; j < N; j++)
                    s = s + " " + (percentage[j] * 100).ToString("#0.000000");

                newlines.Add(s);                
            }
            funcs.WriteLines(@"A-small-attempt0.out", newlines);
        }
    }
}
