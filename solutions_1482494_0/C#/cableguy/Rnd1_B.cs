using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Util;

namespace Rnd1_B
{
    class Rnd1_B
    {
        class State : IComparable<State>
        {
            public int m_numGamesPlayed;
            public int m_weightedCost;  // numPlayed + # not 2 stars
            public int[] m_levelStarsAchieved;
            public int m_numStars;

            // Seed state
            public State(int numLevels)
            {
                m_numGamesPlayed = 0;
                m_weightedCost = numLevels;
                m_levelStarsAchieved = new int[numLevels];
                m_numStars = 0;
            }

            public State(int numGamesPlayed, int[] levelStarsAchieved)
            {
                m_numGamesPlayed = numGamesPlayed;
                m_numStars = levelStarsAchieved.Sum();
                m_levelStarsAchieved = levelStarsAchieved;
                m_weightedCost = m_numGamesPlayed + m_levelStarsAchieved.Count(i => i < 2);
            }

            public bool IsFinished { get { return m_weightedCost == m_numGamesPlayed; } }

            public int CompareTo(State other)
            {
                return m_weightedCost.CompareTo(other.m_weightedCost);
            }
        }

        class AchivementComparer : IComparer<int[]>
        {
            public int Compare(int[] x, int[] y)
            {
 	            for (int i = 0; i < x.Length; i++)
                {
                    int cmp = x[i].CompareTo(y[i]);
                    if (cmp != 0)
                        return cmp;
                }
                return 0;
            }
        }

        class Game
        {
            public int[] m_starsRequired1Star;
            public int[] m_starsRequired2Star;
            public int m_numLevels;
            public SortedSet<int[]> m_achievementsReached = new SortedSet<int[]>(new AchivementComparer());

            public int Play()
            {
                var seed = new State(m_starsRequired1Star.Length);
                var q = new PQueue<State>();
                q.Enqueue(seed);

                while (!q.IsEmpty)
                {
                    var top = q.Dequeue();

                    if (top.IsFinished)
                        return top.m_numGamesPlayed;

                    if (m_achievementsReached.Add(top.m_levelStarsAchieved))
                    {
                        Extend(top, q);
                    }
                }

                return int.MaxValue;
            }


            private void Extend(State top, PQueue<State> q)
            {
                for (int i = 0; i < m_numLevels; i++)
                {
                    if ((top.m_levelStarsAchieved[i] < 2) && (top.m_numStars >= m_starsRequired2Star[i]))
                    {
                        var newAchieved = (int[]) top.m_levelStarsAchieved.Clone();
                        newAchieved[i] = 2;
                        var child = new State(top.m_numGamesPlayed + 1, newAchieved);
                        q.Enqueue(child);
                    }
                    else if ((top.m_levelStarsAchieved[i] == 0) && (top.m_numStars >= m_starsRequired1Star[i]))
                    {
                        var newAchieved = (int[])top.m_levelStarsAchieved.Clone();
                        newAchieved[i] = 1;
                        var child = new State(top.m_numGamesPlayed + 1, newAchieved);
                        q.Enqueue(child);
                    }
                }
            }

            public static Game Load(TextReader rd)
            {
                var result = new Game();
                result.m_numLevels = int.Parse(rd.ReadLine());

                result.m_starsRequired1Star = new int[result.m_numLevels];
                result.m_starsRequired2Star = new int[result.m_numLevels];

                for (int i = 0; i < result.m_numLevels; i++)
                {
                    var tokens = rd.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    result.m_starsRequired1Star[i] = tokens[0];
                    result.m_starsRequired2Star[i] = tokens[1];
                }

                return result;
            }
        }

        static string ProcessCase(TextReader rd)
        {
            var g = Game.Load(rd);
            int minGames = g.Play();
            if (minGames == int.MaxValue)
                return "Too Bad";
            else
                return minGames.ToString();
        }

        static void Main(string[] args)
        {
            //const string InFile = @"C:\Users\Owen\Downloads\B-Eg.txt";
            const string InFile = @"C:\Users\Owen\Downloads\B-small-attempt0 (1).in";
            //const string InFile = @"C:\Users\Owen\Downloads\B-large.in";

            using (var rd = File.OpenText(InFile))
            using (var wr = File.CreateText(@"C:\Users\Owen\Documents\Visual Studio 2010\Projects\Jam\Rnd1_B\Out.txt"))
            {
                int t = int.Parse(rd.ReadLine());

                for (int i = 1; i <= t; i++)
                {
                    var result = ProcessCase(rd);
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    wr.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
