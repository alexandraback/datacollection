using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1B_kingdom
    {
        public Round1B_kingdom()
        {
            StreamReader reader = File.OpenText("B-small-attempt0.in");
            StreamWriter writer = File.CreateText("B-small-attempt0.out");
            string s = reader.ReadLine();
            string[] tokens;
            char[] sep = { ' ' };
            int stars, best, max2, count;
            int T = Int32.Parse(s);
            int N;
            List<int> stars1 = new List<int>(1000);
            List<int> stars2 = new List<int>(1000);
            List<int> reward = new List<int>(1000);
            string result;
            for (int t = 0; t < T; t++)
            {
                s = reader.ReadLine();
                N = Int32.Parse(s);
                stars1.Clear();
                stars2.Clear();
                reward.Clear();
                for (int i = 0; i < N; i++)
                {
                    s = reader.ReadLine();
                    tokens = s.Split(sep);
                    stars1.Add(Int32.Parse(tokens[0]));
                    stars2.Add(Int32.Parse(tokens[1]));
                    reward.Add(2);
                }
                stars = 0;
                count = 0;
                while(reward.Count > 0)
                {
                    best = -1;
                    max2 = -1;
                    for (int i=0;i<reward.Count;i++)
                    {
                        if (stars2[i] <= stars)
                        {
                            count++;
                            stars += reward[i];
                            stars1.RemoveAt(i);
                            stars2.RemoveAt(i);
                            reward.RemoveAt(i);
                            best = -2;
                            break;
                        }
                        else if ((stars1[i] <= stars) && (reward[i] == 2))
                        {
                            if (best == -1)
                            {
                                best = i;
                                max2 = stars2[i];
                            }
                            else if (max2 < stars2[i])
                            {
                                best = i;
                                max2 = stars2[i];
                            }
                        }
                    }
                    if (best == -2) continue;
                    else if (best == -1)
                    {
                        break;
                    }
                    else
                    {
                        count++;
                        stars++;
                        reward[best]--;
                    }
                }
                if (stars == N*2) result = ""+count;
                else result = "Too Bad";
                
                writer.WriteLine("Case #" + (t + 1) + ": " + result);
            }
            reader.Close();
            writer.Close();
        }
    }
}
