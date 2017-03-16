using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012E1
{
    class Program
    {
        public class StatusResult
        {
            public int score;
            public HashSet<int> solvedL1;
            public HashSet<int> solvedL2;

            public override int GetHashCode()
            {
                return score.GetHashCode() ^ solvedL1.GetHashCode() ^ solvedL2.GetHashCode();
            }

            public override bool Equals(object obj)
            {
                StatusResult res = (StatusResult)obj;

                return ((score == res.score) && (solvedL1.Equals(res.solvedL1)) && (solvedL2.Equals(res.solvedL2)));
            }
        }


        static void Main(string[] args)
        {
            var games = ReadFile(@"C:\Users\Roy\Downloads\B-small-attempt1.in");

            StreamWriter writer;

            using (writer = new StreamWriter(@"C:\temp\output.txt"))
            {
                for (int i = 0; i < games.Count; i++)
                {
                    Console.WriteLine("Game " + i.ToString());
                    Dictionary<StatusResult, int> results = new Dictionary<StatusResult, int>();

                    Game game = games[i];

                    try
                    {
                        game.Output = CalcGame(0, 0, new HashSet<int>(), new HashSet<int>(), game, results);

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, game.Output));
                    }
                    catch (ArgumentException e)
                    {
                        if (e.Message == "Too BAD")
                        {
                            writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, "Too Bad"));
                        }
                        else
                        {
                            throw;
                        }
                    }
                }
            }
        }

        static int CalcGame(int count, int score, HashSet<int> solvedL1, HashSet<int> solvedL2, Game g, Dictionary<StatusResult, int> results)
        {
            List<int> s = new List<int>();

            int c;

            if (solvedL2.Count == g.Count)
            {
                return count;
            }

            int cachecount = 0;

            if (results.TryGetValue(new StatusResult() { score = score, solvedL1 = solvedL1, solvedL2 = solvedL2 }, out cachecount))
            {
                return cachecount;
            }

            bool success = false;

            for (int i = 0; i < g.Count; i++)
            {
                if ((!solvedL2.Contains(i)) && (score >= g.Star2[i]))
                {
                    if (!solvedL1.Contains(i))
                    {
                        HashSet<int> h = new HashSet<int>(solvedL2);
                        h.Add(i);

                        return CalcGame(count + 1, score + 2, solvedL1, h, g, results);
                    }
                }
            }

            for (int i = 0; i < g.Count; i++)
            {
                if ((!solvedL2.Contains(i)) && (score >= g.Star2[i]))
                {
                    HashSet<int> h = new HashSet<int>(solvedL2);
                    h.Add(i);

                    return CalcGame(count + 1, score + 1, solvedL1, h, g, results);
                }
            }

            for (int i = 0; i < g.Count; i++)
            {
                if ((!solvedL1.Contains(i) && (!solvedL2.Contains(i))) && (score >= g.Star1[i]))
                {
                    HashSet<int> h = new HashSet<int>(solvedL1);
                    h.Add(i);

                    s.Add(CalcGame(count + 1, score + 1, h, solvedL2, g, results));

                    success = true;
                }
            }

            if (!success) { throw new ArgumentException("Too BAD"); }

            int min = s.Min();

            results.Add(new StatusResult() { score = score, solvedL1 = solvedL1, solvedL2 = solvedL2 }, min);

            return min;
        }

        static List<Game> ReadFile(string file)
        {
            List<Game> games = new List<Game>();

            using (var reader = new StreamReader(file))
            {
                string n = reader.ReadLine();
                int count = Convert.ToInt32(n);

                for (int i = 0; i < count; i++)
                {
                    Game g = new Game();

                    int c = Convert.ToInt32(reader.ReadLine());

                    g.Count = c;

                    for (int j = 0; j < c; j++)
                    {
                        string l1 = reader.ReadLine();

                        var starsplit = l1.Split(' ');

                        g.Star1.Add(Convert.ToInt32(starsplit[0]));
                        g.Star2.Add(Convert.ToInt32(starsplit[1]));
                    }

                    games.Add(g);
                }
            }

            return games;
        }
    }

    public class Game
    {
        public int Output;
        public int Count;
        public List<int> Star1 = new List<int>();
        public List<int> Star2 = new List<int>();
    }
}

