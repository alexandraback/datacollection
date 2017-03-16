using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace C
{
    class Attack
    {
        public int Day { get; private set; }
        public int West { get; private set; }
        public int East { get; private set; }
        public int Height { get; private set; }

        public Attack(int day, int west, int east, int strength)
        {
            this.Day = day;
            this.West = west;
            this.East = east;
            this.Height = strength;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int numTestCases = 0;

            StreamReader r = new StreamReader(@"../../files/C-small-attempt1.in");
            StreamWriter w = new StreamWriter(@"../../files/C-small-attempt1.out");

            string line;
            bool isFirstLine = true;
            int index = 1;
            while ((line = r.ReadLine()) != null)
            {
                if (isFirstLine)
                {
                    isFirstLine = false;
                    int.TryParse(line, out numTestCases);
                }
                else
                {
                    int N = 0;
                    int.TryParse(line, out N);

                    SortedDictionary<int, List<Attack>> attacks = new SortedDictionary<int, List<Attack>>();

                    for (int i = 0; i < N; ++i)
                    {
                        line = r.ReadLine();
                        string[] inputNumbers = line.Split(new Char[] { ' ' });
                        int len = inputNumbers.Length;

                        int d = 0;
                        int n = 0;
                        int wi = 0;
                        int ei = 0;
                        int s = 0;
                        int deltad = 0;
                        int deltap = 0;
                        int deltas = 0;

                        int.TryParse(inputNumbers[0], out d);
                        int.TryParse(inputNumbers[1], out n);
                        int.TryParse(inputNumbers[2], out wi);
                        int.TryParse(inputNumbers[3], out ei);
                        int.TryParse(inputNumbers[4], out s);
                        int.TryParse(inputNumbers[5], out deltad);
                        int.TryParse(inputNumbers[6], out deltap);
                        int.TryParse(inputNumbers[7], out deltas);

                        for (int j = 0; j < n; ++j)
                        {
                            int day = d + j * deltad;
                            if(!attacks.ContainsKey(day))
                            {
                                attacks[day] = new List<Attack>();
                            }
                            attacks[day].Add(new Attack(d, wi + j * deltap, ei + j * deltap, s + j * deltas));
                        }
                    }

                    Dictionary<int, int> wallHeights = new Dictionary<int, int>();
                    int succeedCount = 0;
                    foreach (KeyValuePair<int, List<Attack>> kvp in attacks)
                    {
                        List<Attack> attackOnDay = kvp.Value;
                        Dictionary<int, int> updatedHeights = new Dictionary<int, int>();

                        foreach (Attack attack in attackOnDay)
                        {

                            bool succeeded = false;
                            for (int pos = attack.West; pos < attack.East; ++pos)
                            {
                                if ((wallHeights.ContainsKey(pos) && (wallHeights[pos] < attack.Height)) ||
                                    !wallHeights.ContainsKey(pos))
                                {
                                    if ((updatedHeights.ContainsKey(pos) && updatedHeights[pos] < attack.Height) ||
                                        !updatedHeights.ContainsKey(pos))
                                    {
                                        updatedHeights[pos] = attack.Height;
                                    }
                                    succeeded = true;
                                }
                            }

                            if (succeeded)
                            {
                                succeedCount++;
                            }
                        }

                        foreach (KeyValuePair<int, int> kvp2 in updatedHeights)
                        {
                            wallHeights[kvp2.Key] = updatedHeights[kvp2.Key];
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", index, succeedCount);
                    w.WriteLine("Case #{0}: {1}", index, succeedCount);

                    ++index;
                }
            }

            r.Close();
            w.Close();

        }
    }
}