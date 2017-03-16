using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam1ab
{
    class CodeJam1ab
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            using (StreamReader reader = new StreamReader("../../in.1ab.txt"))
            {
                int numberOfCases = int.Parse(reader.ReadLine());

                for (int currentCase = 1; currentCase <= numberOfCases; currentCase++)
                {
                    int levels = int.Parse(reader.ReadLine());

                    List<LevelScore> levelScores = new List<LevelScore>();

                    for (int x = 0; x < levels; x++)
                    {
                        int[] inputs = reader.ReadLine().Split(' ').Select(o => int.Parse(o)).ToArray();
                        levelScores.Add(new LevelScore
                                        {
                                            OneStar = inputs[0],
                                            OneStarAvailable = true,
                                            TwoStar = inputs[1],
                                            TwoStarAvailable = true,
                                        });
                    }
                    GameTree gameTree = new GameTree
                                            {
                                                CurrentStars = 0,
                                                GamesPlayed = 0,
                                                LevelScores = levelScores
                                            };

                    List<GameTree> currentGames = new List<GameTree>();
                    currentGames.Add(gameTree);

                    int bestCase = 3000;

                    while (currentGames.Count > 0)
                    {
                        GameTree currentGame = currentGames.First();
                        currentGames.RemoveAt(0);

                        bool canPlay = false;

                        foreach (LevelScore levelScore in currentGame.LevelScores.Where(o => o.OneStarAvailable && o.OneStar <= currentGame.CurrentStars || o.TwoStarAvailable && o.TwoStar <= currentGame.CurrentStars))
                        {
                            canPlay = true;
                            int points = 0;
                            if (levelScore.OneStarAvailable && levelScore.OneStar <= currentGame.CurrentStars)
                            {
                                points += 1;
                                levelScore.OneStarAvailable = false;
                            }
                            if (levelScore.TwoStarAvailable && levelScore.TwoStar <= currentGame.CurrentStars)
                            {
                                points += 1;
                                levelScore.TwoStarAvailable = false;
                            }

                            GameTree newGame = currentGame.Copy();
                            newGame.CurrentStars += points;
                            newGame.GamesPlayed++;

                            if (newGame.LevelScores.Count() == 0)
                            {
                                if (newGame.GamesPlayed < bestCase)
                                {
                                    bestCase = newGame.GamesPlayed;
                                }
                            }
                            else
                            {
                                currentGames.Add(newGame);
                            }
                        }
                    }


                    output.AppendLine("Case #" + currentCase + ": " + (bestCase == 3000 ? "Too Bad" : bestCase.ToString()));


                }

                reader.Close();
            }

            using (StreamWriter writer = new StreamWriter("../../out.1ab.txt"))
            {
                writer.Write(output.ToString());
                writer.Close();
            }
        }
    }

    internal class GameTree
    {
        public int CurrentStars;
        public int GamesPlayed;
        public List<LevelScore> LevelScores;

        public GameTree Copy()
        {
            return new GameTree
                               {
                                   CurrentStars = CurrentStars,
                                   GamesPlayed = GamesPlayed,
                                   LevelScores = LevelScores.Where(o => o.OneStarAvailable || o.TwoStarAvailable).Select(o => o.Copy()).ToList()
                               };
        }
    }

    internal class LevelScore
    {
        public int TwoStar;
        public int OneStar;
        public bool TwoStarAvailable;
        public bool OneStarAvailable;

        public LevelScore Copy()
        {
            return new LevelScore
                   {
                       TwoStar = TwoStar,
                       OneStar = OneStar,
                       TwoStarAvailable = TwoStarAvailable,
                       OneStarAvailable = OneStarAvailable
                   };
        }
    }
}
