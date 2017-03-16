using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Chest
        {
            public int key;
            public int[] keys;
        }

        class Solver
        {
            Dictionary<int, byte[]> states;
            Dictionary<int, int> map;

            private bool Check(Chest[] chests, int state)
            {
                Queue<int> queue = new Queue<int>();
                bool [] seen = new bool[1 << chests.Length];
                queue.Enqueue(state);
                seen[state] = true;
                while (queue.Count > 0)
                {
                    state = queue.Dequeue();
                    if (state == seen.Length - 1)
                    {
                        return true;
                    }
                    for (int i = 0; i < chests.Length; i++)
                    {
                        if (((state >> i) & 1) == 0 && states[state][chests[i].key] > 0)
                        {
                            if (!seen[state | (1 << i)])
                            {
                                seen[state | (1 << i)] = true;
                                queue.Enqueue(state | (1 << i));
                            }
                        }
                    }
                }
                return false;
            }

            public string Solve(int[] keys, Chest[] chests)
            {
                map = new Dictionary<int, int>();
                for (int i = 0; i < chests.Length; i++)
                {
                    if (!map.ContainsKey(chests[i].key))
                    {
                        map[chests[i].key] = map.Count;
                    }
                    chests[i].key = map[chests[i].key];
                }

                byte[] keyCounts = new byte[map.Count];
                for (int i = 0; i < keys.Length; i++)
                {
                    int key;
                    if (map.TryGetValue(keys[i], out key))
                    {
                        keyCounts[key] += 1;
                    }
                }

                for (int j = 0; j < chests.Length; j++)
                {
                    int[] counts = new int[map.Count];
                    for (int i = 0; i < chests[j].keys.Length; i++)
                    {
                        int key;
                        if (map.TryGetValue(chests[j].keys[i], out key))
                        {
                            counts[key] += 1;
                        }
                    }
                    chests[j].keys = counts;
                }

                states = new Dictionary<int, byte[]>();
                for (int i = 0; i < 1 << chests.Length; i++)
                {
                    byte[] counts = new byte[keyCounts.Length];
                    for (int j = 0; j < counts.Length; j++)
                    {
                        counts[j] = (byte)keyCounts[j];
                    }
                    for (int j = 0; j < chests.Length; j++)
                    {
                        if (((i >> j) & 1) == 1)
                        {
                            for (int k = 0; k < chests[j].keys.Length; k++)
                            {
                                counts[k] += (byte)chests[j].keys[k];
                            }
                        }
                    }
                    for (int j = 0; j < chests.Length; j++)
                    {
                        if (((i >> j) & 1) == 1)
                        {
                            if (counts[chests[j].key] == 0)
                            {
                                counts = null;
                                break;
                            }
                            counts[chests[j].key] -= 1;
                        }
                    }
                    if (counts != null)
                    {
                        states[i] = counts;
                    }
                }

                int[] answer = new int[chests.Length];
                int mask = 0;
                for (int i = 0; i < chests.Length; i++)
                {
                    bool found = false;
                    for (int j = 0; j < chests.Length; j++)
                    {
                        if (((mask >> j) & 1) == 0 &&
                            states[mask][chests[j].key] > 0 && Check(chests, mask | (1 << j)))
                        {
                            answer[i] = j;
                            mask |= 1 << j;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        return "IMPOSSIBLE";
                    }
                }

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < chests.Length; i++)
                {
                    if (i > 0)
                    {
                        sb.Append(' ');
                    }
                    sb.Append(answer[i] + 1);
                }

                return sb.ToString();
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            string filename = "D-small-attempt0";
            //string filename = "D-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        int k = Int32.Parse(tmp[0]);
                        int n = Int32.Parse(tmp[1]);

                        int[] keys = new int[k];
                        tmp = reader.ReadLine().Split();
                        for (int j = 0; j < k; j++)
                        {
                            keys[j] = Int32.Parse(tmp[j]);
                        }

                        Chest[] chests = new Chest[n];
                        for (int j = 0; j < n; j++)
                        {
                            chests[j] = new Chest();
                            tmp = reader.ReadLine().Split();
                            chests[j].key = Int32.Parse(tmp[0]);
                            chests[j].keys = new int[Int32.Parse(tmp[1])];
                            for (int l = 0; l < chests[j].keys.Length; l++)
                            {
                                chests[j].keys[l] = Int32.Parse(tmp[l + 2]);
                            }
                        }
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(keys, chests));
                    }
                }
            }
        }
    }
}
