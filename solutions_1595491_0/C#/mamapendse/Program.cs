using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{

    enum score_type
    {
        WITHOUT_SURPRISE,
        WITH_SURPRISE,
        NEVER
    };

    class GoogleScore
    {
        int my_total_score;
        public GoogleScore(int score)
        {
            my_total_score = score;
        }

        public score_type GetScoreType(int max_score)
        {
            if (GetMaxScoreWithoutSurprise() >= max_score)
            {
                return score_type.WITHOUT_SURPRISE;
            }
            else
            {
                if (GetMaxScoreWithSurprise() >= max_score)
                {
                    return score_type.WITH_SURPRISE;
                }
                else
                {
                    return score_type.NEVER;
                }
            }

        }
        public int GetMaxScoreWithoutSurprise()
        {
            if (my_total_score == 0) return 0;
            int rem = my_total_score % 3;

            if (rem == 0)
            {
                //devisible by 3
                return my_total_score / 3;
            }

            
            return my_total_score / 3 + 1;
            
        }

        public int GetMaxScoreWithSurprise()
        {
            if (my_total_score == 0) return 0;
            int rem = my_total_score % 3;

            if (rem == 2)
            {
                //devisible by 3
                return my_total_score / 3 + 2;
            }


            return my_total_score / 3 + 1;
            
        }

        public void print()
        {
            Console.WriteLine("{0}:{1}:{2}", my_total_score, GetMaxScoreWithoutSurprise(), GetMaxScoreWithSurprise());
        }
    }

    class Googlers
    {
        public int num;
        public int surprises;
        public int max_score;
        public GoogleScore[] scores;

        public void print()
        {
            Console.WriteLine("Num Contestants = {0}", num);
            Console.WriteLine("Cutoff Score = {0}",max_score);
            Console.WriteLine("Total surprises = {0}", surprises);
            Console.WriteLine("Scores ...");
            int j = 0;
            for (j = 0; j < num; j++)
            {
                scores[j].print();
            }
            Console.WriteLine("******************");

        }

        public int GetMaxNumOfAchievers()
        {
            int j = 0;
            int num_surprises = surprises;

            int Without_surprise = 0;
            int With_Surprise = 0;
            int below_cutoff = 0;
            for (j = 0; j < num; j++)
            {
                if (scores[j].GetScoreType(max_score ) == score_type.WITHOUT_SURPRISE )
                {
                    Without_surprise++;
                }
                else
                {
                    if (scores[j].GetScoreType(max_score ) == score_type.WITH_SURPRISE )
                    {
                        With_Surprise++;
                    }
                    else
                    {
                        below_cutoff++;
                    }
                }

               
            }

            Console.WriteLine("{0}:{1}:{2}:{3}:{4}", num,Without_surprise, With_Surprise, below_cutoff,surprises);

            
            if (Without_surprise + With_Surprise <= surprises)
            {
                return Without_surprise + With_Surprise;
            }

            if (With_Surprise > surprises)
            {
                return surprises + Without_surprise;
            }

            if (surprises >= With_Surprise)
            {
                return Without_surprise + With_Surprise;
            }
            
            return 0;
        }

    }
    class Program
    {

        static void ParseFile(string file)
        {
            TextReader tr = new StreamReader(file);
            TextWriter of = new StreamWriter(@"c:\bhargav\out.txt");
            string line = tr.ReadLine();

            int numCases = 0;
            try
            {
                numCases = Int32.Parse(line);
            }
            catch (Exception e)
            {
                Console.Out.WriteLine("Parse exception while getting count");
            }

            int i = 0;
            for (i = 0; i < numCases; i++)
            {
                Console.Out.WriteLine("Reading case {0}", i+1);
                line = tr.ReadLine();
                string[] words = line.Split(' ');

                Googlers g = new Googlers();
                int num = Int32.Parse(words[0]);
                int s = Int32.Parse(words[1]);
                int p = int.Parse(words[2]);
                g.scores = new GoogleScore[num];

                int j = 0;
                for (j = 0; j < num; j++)
                {
                    g.scores[j] = new GoogleScore(int.Parse(words[3 + j]));
                }

                g.num = num;
                g.surprises = s;
                g.max_score = p;
               
                g.print();
                int answer = g.GetMaxNumOfAchievers();
                Console.WriteLine("Final Answer = {0}", answer);
                of.WriteLine("Case #{0}: {1}", i + 1, answer);
                of.Flush();
            }
            of.Close();
        }
        static void Main(string[] args)
        {
            ParseFile(@"c:\bhargav\B-small-attempt0.in");
        }
    }
}
