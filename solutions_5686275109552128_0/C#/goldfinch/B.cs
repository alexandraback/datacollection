using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ15
{
    using System.Globalization;

    class B
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            for (int test = 0; test < cases; test++)
            {
                int ne = int.Parse(lines[test * 2 + 1]);
                var li = lines[test * 2 + 2].Split(' ').Select(d => int.Parse(d, CultureInfo.InvariantCulture)).ToArray();
                Array.Sort(li);

                int[] all = new int[1001];
                foreach (var i in li)
                {
                    all[i]++;
                }

                int cur = 0;
                int min = li[li.Length - 1];

                for (int cuts = 1; cuts < 1001; cuts++)
                {
                    int left = 1, right = 1000;
                    while (left < right)
                    {
                        int mid = (left + right) / 2;
                        int k = 0;
                        for (int i = 0; i < li.Length; i++)
                        {
                            k += Math.Max((li[i] + mid - 1) / mid - 1, 0);
                        }
                        if (k > cuts)
                            left = mid + 1;
                        else
                            right = mid;
                    }
                    min = Math.Min(min, cuts + left);
                }

                res[test] = string.Format(
                    "Case #{0}: {1}",
                    (test + 1).ToString(CultureInfo.InvariantCulture),
                    min.ToString(CultureInfo.InvariantCulture));
            }

            return res;
        }
    }
}
