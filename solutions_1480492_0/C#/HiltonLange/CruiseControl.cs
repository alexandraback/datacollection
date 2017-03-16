using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class CruiseControl : GCJBase
    {
        private double dEps = 1e-10;
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int N = int.Parse(s);
                int[] speed = new int[N];
                int[] pos = new int[N];
                char[] lane = new char[N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine();
                    speed[i] = int.Parse(s.Split(' ')[1]);
                    pos[i] = int.Parse(s.Split(' ')[2]);
                    lane[i] = s.Split(' ')[0][0];
                }
                string ret = MaxSecs(N, speed, pos, lane);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private class Event : IComparable
        {
            public double time;
            public int car1;
            public int car2;
            public char EventType;

            public int CompareTo(object obj)
            {
                return this.time.CompareTo(((Event)obj).time);
            }
        }

        private string MaxSecs(int N, int[] speed, int[] pos, char[] lane)
        {
            for (int i = 0; i < N; i++)
            {
                if (lane[i] == 'R')
                {
                    bool leftopen = true;
                    for (int j = 0; j < N; j++)
                    {
                        if (i == j) continue;
                        if (pos[j] > pos[i] - 5 && pos[j] < pos[i] + 5)
                        {
                            leftopen = false;
                            break;
                        }
                    }
                    if (leftopen) lane[i] = 'L';
                }
            }

            List<Event> events = new List<Event>();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    double d = touchtime(speed[i], speed[j], pos[i], pos[j]);
                    if (d >= 0)
                    {
                        Event e = new Event()
                        {
                            time = d,
                            car1 = i,
                            car2 = j,
                            EventType = 'T',
                        };
                        events.Add(e);
                    }

                    d = untouchtime(speed[i], speed[j], pos[i], pos[j]);
                    if (d >= 0)
                    {
                        Event e = new Event()
                        {
                            time = d,
                            car1 = i,
                            car2 = j,
                            EventType = 'U',
                        };
                        events.Add(e);
                    }
                }
            }

            string[] s = PrintPos(N, 1.72274881516588, speed, pos);
            events.Sort();

            double best = BestTime(N, events, 0, speed, pos, lane);
            if (best == double.MaxValue)
            {
                return "Possible";
            }
            else
            {
                return best.ToString();
            }
        }

        Dictionary<string, double> mem = new Dictionary<string, double>();
        private double BestTime(int N, List<Event> events, int eventidx, int[] speed, int[] pos, char[] lane)
        {
            if (eventidx == events.Count) return double.MaxValue;
            string key = new string(lane) + eventidx.ToString();
            Event e = events[eventidx];
            double best = e.time;
            if (mem.ContainsKey(key)) return mem[key];

            if (e.EventType == 'T')
            {
                if (lane[e.car1] == lane[e.car2])
                {
                    int fastcar;
                    int othercar;
                    if (speed[e.car2] > speed[e.car1])
                    {
                        fastcar = e.car2;
                        othercar = e.car1;
                    }
                    else
                    {
                        fastcar = e.car1;
                        othercar = e.car2;
                    }

                    if (lane[e.car1] == 'R' && lane[e.car2] == 'R')
                    {
                        if (!overlap(N, othercar, fastcar, speed, pos, lane, e.time))
                        {
                            // RR, slow car moves left
                            lane[othercar] = 'L';
                            best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                            lane[othercar] = 'R';
                        }
                        if (!overlap(N, fastcar, othercar, speed, pos, lane, e.time))
                        {
                            // RR, fast car moves left
                            lane[fastcar] = 'L';
                            best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                            lane[fastcar] = 'R';
                        }
                    }
                    else
                    {
                        if (!overlap(N, fastcar, othercar, speed, pos, lane, e.time))
                        {
                            // LL, fast car moves right
                            lane[fastcar] = 'R';
                            best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                            lane[fastcar] = 'L';
                        }
                        if (!overlap(N, othercar, fastcar, speed, pos, lane, e.time))
                        {
                            // LL, slow car moves right
                            lane[othercar] = 'R';
                            best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                            lane[othercar] = 'L';
                        }
                    }
                }
                else
                {
                    // 2 cars in different lanes, do nothing
                    best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                }

            }
            else
            {
                // 2 cars end passing
                if (lane[e.car1] == 'R')
                {
                    if (!overlap(N, e.car1, e.car2, speed, pos, lane, e.time))
                    {
                        lane[e.car1] = 'L';
                        best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                        lane[e.car1] = 'R';
                    }
                }

                if (lane[e.car2] == 'R')
                {
                    if (!overlap(N, e.car2, e.car1, speed, pos, lane, e.time))
                    {
                        lane[e.car2] = 'L';
                        best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                        lane[e.car2] = 'R';
                    }
                }

                if (lane[e.car1] == lane[e.car2] && lane[e.car1]=='L')
                {
                    best = Math.Max(best, BestTime(N, events, eventidx + 1, speed, pos, lane));
                }
            }

            mem[key] = best;
            return best;
        }

        private string[] PrintPos(int N, double time, int[] speed, int[] pos)
        {
            string s = "";
            double[] temppos = new double[N];
            string[] carpos = new string[N];
            for (int i = 0; i < N; i++)
            {
                carpos[i] = string.Format("Car {0}: pos {1}, speed {2}\n", i, pos[i] + speed[i] * time, speed[i]);
                temppos[i] = pos[i] + speed[i] * time;
            }
            Array.Sort(temppos, carpos);
            return carpos;
        }

        private bool overlap(int N, int car, int exclude, int[] speed, int[] pos, char[] lane, double time)
        {
            for (int a = 0; a < 2; a++)
            {
                if (a == 1) time += 1e-8;
                double carpos = pos[car] + speed[car] * time;
                for (int i = 0; i < N; i++)
                {
                    if (i == car) continue;
                    if (i == exclude) continue;
                    double otherpos = pos[i] + speed[i] * time;
                    if (otherpos >= carpos - 5 + dEps && otherpos <= carpos + 5 - dEps)
                    {
                        return true;
                    }
                }

            }
            return false;
        }

        private double touchtime(int s1, int s2, int p1, int p2)
        {
            // Car 1 catches Car 2
            if (s1 == s2) return -1;
            if (p1 > p2)
            {
                int temp = p1;
                p1 = p2;
                p2 = temp;
                temp = s1;
                s1 = s2;
                s2 = temp;
            }
            if (p1 > p2 - 5) return -1;

            if (s1 <= s2) return -1;
            double dis = p2 - p1;
            double speed = s1 - s2;
            return (dis - 5) / speed;
        }

        private double untouchtime(int s1, int s2, int p1, int p2)
        {
            // Car 1 leaves Car 2 behind
            if (s1 == s2) return -1;
            if (s1 < s2)
            {
                int temp = p1;
                p1 = p2;
                p2 = temp;
                temp = s1;
                s1 = s2;
                s2 = temp;
            }

            if (p1 > p2 + 5) return -1;
            double dis = p2 + 5 - p1;
            double speed = s1 - s2;
            return (dis - 5) / speed;
        }
    }
}
