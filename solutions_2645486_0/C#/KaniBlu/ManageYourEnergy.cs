using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamTest
{
    class ManageYourEnergy : CodeJamTemplate
    {
        protected override void _run()
        {
            int T = readInt();
            for (int i = 0; i < T; i++)
            {
                write("Case #{0}: ", i + 1);
                int[] tokens = readIntTokens();
                int E = tokens[0];
                int R = tokens[1];
                int N = tokens[2];
                tokens = readIntTokens();
                List<int> activities = new List<int>();
                foreach (int token in tokens)
                    activities.Add(token);

                SortedSet<int> orderActivities = new SortedSet<int>();
                foreach (int a in activities)
                    orderActivities.Add(a);

                int sum = 0;
                foreach(int a in orderActivities)
                    sum += a;

                int largest = orderActivities.Last();

                writeLine("{0}", largest * E + (sum - largest) * R);
            }
        }
    }
}
