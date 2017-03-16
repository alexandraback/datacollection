using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ15
{
    using System.Globalization;

    class D
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            for (int test = 0; test < cases; test++)
            {
                bool gabriel = false;

                var li = lines[test + 1].Split(' ').Select(d => int.Parse(d, CultureInfo.InvariantCulture)).ToList();
                int x = li[0];
                int r = li[1];
                int c = li[2];

                if (c * r % x == 0 && x < 7)
                {
                    if (x < 3)
                        gabriel = true;
                    if (x == 3 && r > 1 && c > 1)
                        gabriel = true;
                    if (x == 4 && r > 2 && c > 2)
                        gabriel = true;
                    if (x == 5 && r > 2 && c > 2)
                        gabriel = true;
                    if (x == 6 && r > 3 && c > 3)
                        gabriel = true;
                }

                res[test] = string.Format(
                    "Case #{0}: {1}",
                    (test + 1).ToString(CultureInfo.InvariantCulture),
                    gabriel ? "GABRIEL" : "RICHARD");
            }

            return res;
        }
    }
}
