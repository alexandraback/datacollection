using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem2
{
    class Program
    {
        class Activity
        {
            public int v;
            public int index;
            public Activity nextHigh = null;
        }

        static int Solve(List<Activity> activities, int Emax, int Ecur, int R)
        {
            // find the max we should spend on this activity            
            // should do at least (Ecur+R)-Emax
            // might want to go higher if we're worth more than the next bunch
            // lookahead to ensure that the next higher time is good

            int Gain = 0;
            // start from then end - walk backwards for each node to find the next "high node" after this one - this is the one we are potentially preserving energy for
            for (int i = activities.Count - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < activities.Count; ++j)
                {
                    if (activities[j].v > activities[i].v)
                    {
                        activities[i].nextHigh = activities[j];
                        break;
                    }
                }
            }

            // now walk forwards, and we use as much as we can as long as we preserve as much as possible for the next highest
            for (int i = 0; i < activities.Count; ++i)
            {
                int EToUse = 0;

                if (activities[i].nextHigh == null)
                {
                    // use maximum energy - noone after us is high
                    EToUse = Ecur;
                }
                else
                {
                    // use what we can so we don't waste any
                    // if we use none, how much energy does nextHigh have?
                    int ENext = Ecur + R * (activities[i].nextHigh.index-i);

                    // This can't be higher than Emax, so take whats left for ourselves.
                    EToUse = Math.Min(Ecur, Math.Max(ENext - Emax, 0)); // use as much as we can, 
                }

                // now use our energy, update the gain
                Gain += activities[i].v * EToUse;
                Ecur -= EToUse;
                if (Ecur < 0)
                    throw new Exception();

                Ecur += R;
            }

            return Gain;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                // read input...
                String[] line = Console.ReadLine().Split(' ');
                int E = int.Parse(line[0]);
                int R = int.Parse(line[1]);
                int N = int.Parse(line[2]);
                List<Activity> activities = new List<Activity>();
                line = Console.ReadLine().Split(' ');
                for (int j = 0; j < N; ++j)
                {
                    Activity a = new Activity();
                    a.v = int.Parse(line[j]);
                    a.index = j;
                    activities.Add(a);
                }

                Console.WriteLine("Case #{0}: {1}", 1 + i, Solve(activities, E, E, R));
            }
        }
    }
}
