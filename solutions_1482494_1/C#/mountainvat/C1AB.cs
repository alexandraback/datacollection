using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    public class C1AB
    {
        private string mInputFile = @"E:\work\codejam2012\data\1A\B-large.in";

        static void Main(string[] args)
        {
            var p = new C1AB();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (StreamWriter sw = new StreamWriter(mInputFile + ".out"))
            using (StreamReader sr = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(sr.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    RunTest(i + 1, sr, sw);
                }
            }
        }

        private int[] ReadIntsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings(StreamReader sr)
        {
            string line = null;
            while ((line = sr.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void RunTest(int testNum, StreamReader sr, StreamWriter sw)
        {
            int N = ReadIntsFromLine(sr)[0];
            int[] a = new int[N];
            int[] b = new int[N];

            for (int i = 0; i< N;i++)
            {
                var ints = ReadIntsFromLine(sr);
                a[i] = ints[0];
                b[i] = ints[1];
            }

            sw.WriteLine(string.Format("Case #{0}: {1}", testNum, Do(N, a, b)));
        }

        private object Do(int N, int[] a, int[] b)
        {
            int games = 0;
            int stars = 0;

            int[] levels = new int[N];

            while (true)
            {
                // find next best level to play
                int levelToPlay = -1;

                // find 2* rating
                for (int i = 0; i < N; i++)
                {
                    if (b[i] <= stars && levels[i] == 0)
                    {
                        levelToPlay = i;
                        break;
                    }
                }

                if (levelToPlay == -1)
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (b[i] <= stars && levels[i] == 1)
                        {
                            levelToPlay = i;
                            break;
                        }
                    }
                }

                if (levelToPlay != -1)
                {
                    stars += levels[levelToPlay] == 0 ? 2 : 1;
                    levels[levelToPlay] = 2;
                    //Console.WriteLine(levelToPlay + " **");
                    games++;
                } 
                else
                {
                    // 1 star
                    int bStars = int.MaxValue;
                    for (int i = 0; i < N; i++)
                    {
                        if (a[i] <= stars && levels[i] == 0)
                        {
                            if (levelToPlay == -1 || b[levelToPlay] < b[i])
                            {
                                levelToPlay = i;
                            }
                            //Console.WriteLine(levelToPlay + " *");
                        }
                    }

                    if (levelToPlay != -1)
                    {
                        stars += 1;
                        levels[levelToPlay] = 1;
                        games++;

                    }
                }
                if (levelToPlay == -1)
                    break;
            }

            return levels.All(x => x == 2) ? games.ToString() : "Too Bad";
        }
    }

}
