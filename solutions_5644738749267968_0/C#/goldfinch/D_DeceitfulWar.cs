using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    class D_DeceitfulWar
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            for (int i = 0; i < cases; i++)
            {
                int n = int.Parse(lines[1 + i * 3]);
                var naomi =
                    lines[2 + i * 3].Split(' ').Select(d => double.Parse(d, CultureInfo.InvariantCulture)).ToList();
                var ken =
                    lines[3 + i * 3].Split(' ').Select(d => double.Parse(d, CultureInfo.InvariantCulture)).ToList();

                naomi.Sort();
                ken.Sort();

                bool[] nuse = new bool[n];
                bool[] use = new bool[n];

                int w1 = 0;
                for (int a = 0; a < n; a++)
                {
                    double q = naomi[a];
                    bool beaten = false;
                    for (int b = 0; b < n; b++)
                    {
                        if (!use[b] && ken[b] > q)
                        {
                            use[b] = true;
                            beaten = true;
                            break;
                        }
                    }
                    if (!beaten)
                    {
                        w1++;
                        for (int b = 0; b < n; b++)
                            if (!use[b])
                            {
                                use[b] = true;
                                break;
                            }
                    }
                }

                use = new bool[n];

                int w2 = 0;
                int smallestFree = 0;
                for (int b = n - 1; b >= 0; b--)
                {
                    double w = ken[b];
                    for (int a = n - 1; a >= 0; a--)
                    {
                        if (naomi[a] < w)
                        {
                            use[smallestFree++] = true;

                            break;
                        }
                        else if (!use[a])
                        {
                            use[a] = true;
                            w2++;
                            break;
                        }
                    }
                }

                res[i] = string.Format(
                    "Case #{0}: {1} {2}",
                    (i + 1).ToString(CultureInfo.InvariantCulture),
                    w2.ToString(CultureInfo.InvariantCulture),
                    w1.ToString(CultureInfo.InvariantCulture));
            }

            return res;
        }
    }
}
