using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DancingWithGooglers
{
    class Program
    {

        static Dictionary<char, char> CharacterMap = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            // File IO
            StreamReader input = new StreamReader(@"..\input.in");
            StringBuilder result = new StringBuilder();

            // Number of cases
            byte numCases = Convert.ToByte(input.ReadLine());
            // Loop through each case
            for (byte n = 0; n < numCases; n++)
            {
                // Read parameters
                string[] param = input.ReadLine().Split(new char[] { ' ' });
                int N = Convert.ToInt32(param[0]);
                int S = Convert.ToInt32(param[1]);
                int p = Convert.ToInt32(param[2]);
                List<int> totalPoints = new List<int>();
                for (int i = 3; i < param.Length; i++)
                {
                    totalPoints.Add(Convert.ToInt32(param[i]));
                }
                totalPoints = totalPoints.OrderByDescending(t => t).ToList();

                List<Triplet> finalScores = new List<Triplet>();

                // Find possible scores for each googler
                List<Googler> googlers = new List<Googler>();
                for (int j = 0; j < N; j++)
                {
                    Googler g = new Googler();
                    // Get scores from highest result to lowest
                    g.PossibleScores = GetScores(totalPoints[j]).OrderByDescending(s => s.Result).ToList();
                    googlers.Add(g);
                }

                // Select a final triplet for each googler
                googlers = googlers.OrderByDescending(g => g.PossibleScores[0].Result).ToList();
                foreach (Googler g in googlers)
                {
                    Triplet special = g.PossibleScores.Find(s => s.IsSpecial);
                    Triplet normal = g.PossibleScores.Find(s => !s.IsSpecial);
                    if (S > 0 && special != null && normal.Result < p)
                    {
                        finalScores.Add(special);
                        S--;
                    }
                    else
                        finalScores.Add(normal);
                }

                // Store result
                result.AppendLine(String.Format("Case #{0}: {1}", n + 1, finalScores.Count(s => s.Result >= p)));
            }

            // Print result
            Console.Write(result.ToString());

            File.WriteAllText(@"..\output.txt", result.ToString());
        }

        static List<Triplet> GetScores(int totalPoints)
        {
            List<Triplet> scores = new List<Triplet>();
            scores.AddRange(GetScores(totalPoints, (int)Math.Ceiling(totalPoints / 3.0)));
            scores.AddRange(GetScores(totalPoints, (int)Math.Floor(totalPoints / 3.0)));
            return scores;
        }

        static List<Triplet> GetScores(int totalPoints, int score1)
        {
            List<Triplet> scores = new List<Triplet>();
            for (int i = score1 + 2; i > score1 - 2; i--)
            {
                int score3 = totalPoints - score1 - i;
                Triplet t = new Triplet(score1, i, score3);
                if (t.IsValid)
                    scores.Add(t);
            }
            return scores;
        }
    }

    class Triplet
    {
        List<int> scores = new List<int>(new int[3]);

        public bool IsSpecial
        {
            get { return (scores[2] - scores[0]) == 2; }
        }

        public bool IsValid
        {
            get
            {
                return (scores[0] >= 0 && scores[2] <= 10)
                        && (scores[2] - scores[0]) <= 2;
            }
        }

        public int Result
        {
            get { return scores[2]; }
        }

        public int TotalPoints
        {
            get { return scores.Sum(); }
        }

        public Triplet(int score1, int score2, int score3)
        {
            scores[0] = score1;
            scores[1] = score2;
            scores[2] = score3;
            scores.Sort();
        }

        public void SetScore(int n, int score)
        {
            scores[n] = score;
            scores.Sort();
        }
    }

    class Googler
    {
        public List<Triplet> PossibleScores = new List<Triplet>();
    }
}
