using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace A
{
    class Program
    {
        public const string PATH = @"C:\Users\HanziQ\Downloads\";
        public const string EXERCISE = "C-small-attempt0.in";
        public const string EXERCISE_O = "C-small-0.txt";

        public static TextWriter OutputWriter;

        public static TextReader ExerciseReader;

        public class Tribe
        {
            public int startDay, attackCount, dayDelta, posDelta, strengthDelta;
            public int attacked = 0;
            public int w, e, strength;
            public Tribe(int d, int n, int w, int e, int s, int delta_d, int delta_p, int delta_s)
            {
                this.startDay = d;
                this.attackCount = n;
                this.dayDelta = delta_d;
                this.posDelta = delta_p;
                this.strengthDelta = delta_s;
                this.w = w;
                this.e = e;
                strength = s;
            }

            public Tribe(Tribe t)
            {
                startDay = t.startDay;
                attackCount = t.attackCount;
                dayDelta = t.dayDelta;
                posDelta = t.posDelta;
                strengthDelta = t.strengthDelta;
                w = t.w;
                e = t.e;
                strength = t.strength;
            }

            public Tribe Next()
            {
                return new Tribe(startDay + dayDelta, attackCount, w + posDelta, e + posDelta, strength + strengthDelta, dayDelta, posDelta, strengthDelta);
            }

            public override string ToString()
            {
                return string.Format("Day {0}, [{1},{2}] with {3}", startDay, w, e, strength);
            }

        }

        static void Main(string[] args)
        {
            ExerciseReader = new StreamReader(PATH + EXERCISE);
            OutputWriter = new StreamWriter(File.Open(PATH + EXERCISE_O, FileMode.Create));
            int numTestCases = int.Parse(ExerciseReader.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                int num = int.Parse(ExerciseReader.ReadLine());
                List<Tribe> tribes = new List<Tribe>();
                for (int j = 0; j < num; j++)
                {
                    string[] fline = ExerciseReader.ReadLine().Split(' ');
                    tribes.Add(new Tribe(int.Parse(fline[0]), int.Parse(fline[1]), int.Parse(fline[2]), int.Parse(fline[3]), int.Parse(fline[4]), int.Parse(fline[5]), int.Parse(fline[6]), int.Parse(fline[7])));
                }

                string res = Process(i + 1, tribes);
                Console.WriteLine("Case #" + (i + 1).ToString() + ": " + res);
                OutputWriter.WriteLine("Case #" + (i + 1).ToString() + ": " + res);
            }

            OutputWriter.Close();
            ExerciseReader.Close();
            Console.ReadLine();
        }

        static Dictionary<double, int> wall;

        public static string Process(int numCase, List<Tribe> tribes)
        {
            int counter = 0;
            wall = new Dictionary<double, int>();
            Dictionary<int, List<Tribe>> attackingDays = new Dictionary<int, List<Tribe>>();
            foreach (Tribe t in tribes)
            {
                Tribe next = t.Next();
                bool start = true;
                for (int i = 0; i < t.attackCount; i++)
                {
                    if (!attackingDays.ContainsKey(t.startDay + i * t.dayDelta))
                    {
                        attackingDays.Add(t.startDay + i * t.dayDelta, new List<Tribe>());
                        attackingDays[t.startDay + i * t.dayDelta].Add(start ? new Tribe(t) : next);
                    }
                    else
                        attackingDays[t.startDay + i * t.dayDelta].Add(start ? new Tribe(t) : next);
                    if (!start)
                        next = next.Next();
                    start = false;

                }
            }
            Dictionary<double, int> newWall = new Dictionary<double, int>();
            foreach (KeyValuePair<int, List<Tribe>> pair in attackingDays.OrderBy(t => t.Key))
            {
                foreach (Tribe t in pair.Value)
                {
                    bool succeeded = false;

                    for (int i = t.w; i <= t.e; i++)
                    {
                        int height = wget(i);
                        if (height < t.strength || (i != t.e && wget(i + 0.5) < t.strength))
                            succeeded = true;


                        if (!newWall.ContainsKey(i))
                            newWall.Add(i, t.strength);
                        else
                            newWall[i] = Math.Max(t.strength, newWall[i]);

                        if (i == t.e)
                            break;

                        if (!newWall.ContainsKey(i + 0.5))
                            newWall.Add(i + 0.5, t.strength);
                        else
                            newWall[i + 0.5] = Math.Max(t.strength, newWall[i + 0.5]);
                    }
                    if (succeeded)
                        counter++;
                }
                foreach (KeyValuePair<double, int> pair2 in newWall)
                {
                    wset(pair2.Key, Math.Max(pair2.Value, wget(pair2.Key)));
                }
            }
            return counter.ToString();
        }

        static int wget(double pos)
        {
            int res;
            if (wall.TryGetValue(pos, out res))
            {
                return res;
            }
            //wall.Add(pos, 0);
            return 0;
        }

        static void wset(double pos, int val)
        {
            if (!wall.ContainsKey(pos))
                wall.Add(pos, val);
            else
                wall[pos] = val;
        }
    }
}
