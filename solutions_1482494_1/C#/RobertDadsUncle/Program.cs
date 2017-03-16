using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1A_Problem_A
{
    public class CaseData
    {
        public class Level
        {
            private int m_StarsRequiredFor1Star;
            private int m_StarsRequiredFor2Star;
            private bool m_FullySolved = false;
            private bool m_HalfSolved = false;

            public Level(int starsRequiredFor1Star, int starsRequiredFor2Star)
            {
                m_StarsRequiredFor1Star = starsRequiredFor1Star;
                m_StarsRequiredFor2Star = starsRequiredFor2Star;
            }
            
            public int StarsRequiredFor1Star
            {
                get { return m_StarsRequiredFor1Star; }
            }

            public int StarsRequiredFor2Star
            {
                get { return m_StarsRequiredFor2Star; }
            }

            public bool FullySolved
            {
                get { return m_FullySolved; }
            }

            public bool HalfSolved
            {
                get { return m_HalfSolved; }
            }


            public void SetFullSolved()
            {
                m_FullySolved = true;
                m_HalfSolved = true;
            }


            public void SetHalfSolved()
            {
                m_HalfSolved = true;
            }
        }
        private List<Level> m_Levels;
        private List<Level> m_LevelsSortedBy2Star;
        private List<Level> m_LevelsSortedBy1Star;
        private int m_NumTimesLevelCompleted = 0;
        private int m_StarsCollected = 0;

        public CaseData(List<Level> levels)
        {
            m_Levels = levels;
            m_LevelsSortedBy1Star = new List<Level>(m_Levels);
            m_LevelsSortedBy1Star.Sort(SortLevel1Star);
            m_LevelsSortedBy2Star = new List<Level>(m_Levels);
            m_LevelsSortedBy2Star.Sort(SortLevel2Star);
        }

        private static int SortLevel1Star(Level x, Level y)
        {
            if (x.StarsRequiredFor1Star == y.StarsRequiredFor1Star)
            {
                return x.StarsRequiredFor2Star - y.StarsRequiredFor2Star;
            }
            return x.StarsRequiredFor1Star - y.StarsRequiredFor1Star;
        }

        private static int SortLevel2Star(Level x, Level y)
        {
            return x.StarsRequiredFor2Star - y.StarsRequiredFor2Star;
        }

        private bool SolveBestLevel()
        {
            var solved2ndLevel = Solve2ndLevel();
            if(!solved2ndLevel)
            {
                var solve1stLevel = Solve1stLevel();
                if(solve1stLevel)
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
            return false;
        }


        private bool Solve1stLevel()
        {
            int highest2ndStar = -1;
            Level lastSolvable = null;
            foreach (var level in m_LevelsSortedBy1Star)
            {
                // early break;
                if (level.StarsRequiredFor1Star > m_StarsCollected)
                {
                    if (lastSolvable != null)
                    {
                        m_StarsCollected += 1;
                        lastSolvable.SetHalfSolved();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (!level.HalfSolved)
                {
                    if (level.StarsRequiredFor2Star >= highest2ndStar)
                    {
                        lastSolvable = level;
                        highest2ndStar = level.StarsRequiredFor2Star;
                    }
                }
            }
            if (lastSolvable != null)
            {
                m_StarsCollected += 1;
                lastSolvable.SetHalfSolved();
                return true;
            }
            else
            {
                return false;
            }
        }


        private bool Solve2ndLevel()
        {
            Level lastSolvable = null;
            foreach(var level in m_LevelsSortedBy2Star)
            {
                // early break;
                if (level.StarsRequiredFor2Star > m_StarsCollected)
                {
                    if (lastSolvable != null)
                    {
                        m_StarsCollected += lastSolvable.HalfSolved ? 1 : 2;
                        lastSolvable.SetFullSolved();
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                if(!level.FullySolved)
                {
                    lastSolvable = level;
                }
            }
            if (lastSolvable != null)
            {
                m_StarsCollected += lastSolvable.HalfSolved ? 1 : 2;
                lastSolvable.SetFullSolved();
                return true;
            }
            else
            {
                return false;
            }
        }


        public string Solve()
        {
            while(m_StarsCollected < (m_Levels.Count*2))
            {
                var success = SolveBestLevel();
                if(!success)
                {
                    return "Too Bad";
                }
                m_NumTimesLevelCompleted++;
            }
            return m_NumTimesLevelCompleted.ToString();
        }
    }
    class Program
    {
        const string INPUT_FILE = "B-large.in";
        const string OUTPUT_FILE = "B-large.out";

        static void Main(string[] args)
        {
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<int>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count == 1);
                var numLevels = ints[0];

                var levels = new List<CaseData.Level>();

                for(int levelIndex = 0; levelIndex < numLevels; levelIndex++)
                {
                    var levelData = lines[currentLineNumber];
                    currentLineNumber++;
                    var tokens = levelData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    var stars = new List<int>();
                    foreach (var token in tokens)
                    {
                        stars.Add(int.Parse(token));
                    }
                    Debug.Assert(stars.Count == 2);
                    levels.Add(new CaseData.Level(stars[0], stars[1]));
                }
                cases.Add(new CaseData(levels));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }
    }
}
