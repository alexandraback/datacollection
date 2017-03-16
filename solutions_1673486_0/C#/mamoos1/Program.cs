using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012E2
{
    class Program
    {
        static void Main(string[] args)
        {
            var games = ReadFile(@"C:\Users\Roy\Downloads\A-small-attempt0.in");

            StreamWriter writer;

            using (writer = new StreamWriter(@"C:\temp\output.txt"))
            {
                for (int i = 0; i < games.Count; i++)
                {
                    Game game = games[i];

                    double typingCase = 0;

                    int bestTypingCase = (game.total - game.typed) + 1;
                    double d = 1;
                    foreach (double d2 in game.odds)
                    {
                        d *= d2;
                    }

                    double best = double.MaxValue;

                    for (int j = 1; j <= game.typed; j++)
                    {
                        double dp = 1;
                        for (int k = 1; k < game.typed; k++)
                        {
                            dp *= game.odds[game.odds.Count - k - 1];
                        }

                        best = Math.Min(best, dp * (j * 2 + (game.total - game.typed) + 1) + ((1 - dp) * (2 * j + ((game.total - game.typed) + 2 + game.total))));
                    }

                    typingCase = (bestTypingCase * d) + (((game.total - game.typed) + 2 + game.total) * (1.0 - d));
                    int enterCase = + game.total + 2;

                    double min = Math.Min(Math.Min(best, typingCase), enterCase);

                    writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, min));
                }
            }
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

                    string l = reader.ReadLine();

                    string[] vals =  l.Split(' ');

                    g.typed = Convert.ToInt32(vals[0]);
                    g.total = Convert.ToInt32(vals[1]);

                    var odds = reader.ReadLine().Split(' ');
                    foreach (string odd in odds)
                    {
                        g.odds.Add(Convert.ToDouble(odd));
                    }

                    games.Add(g);
                }
            }

            return games;
        }
    }

    public class Game
    {
        public int typed;
        public int total;
        public List<double> odds = new List<double>();
        public double bestOdd;
    }
}
