using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    class C_MinesweeperMaster
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            List<string> res = new List<string>();

            for (int i = 0; i < cases; i++)
            {
                var li = lines[i + 1].Split(' ').Select(d => int.Parse(d, CultureInfo.InvariantCulture)).ToList();
                int r = li[0];
                int c = li[1];
                int m = li[2];

                int[,] map = new int[r, c];

                int qr = 0;
                int qc = 0;
                int needm = m;

                if (r * c == m + 1)
                {
                    for (int a = 0; a < r; a++)
                        for (int b = 0; b < c; b++)
                            map[a, b] = 1;
                    needm = 0;
                }

                bool impossible = false;

                for (;needm > 0 && !impossible;)
                {
                    int r1 = r - qr;
                    int c1 = c - qc;

                    if (r1 < c1)
                    {
                        if (c1 < 3)
                        {
                            impossible = true;
                        }
                        else if (r1 == needm + 1)
                        {
                            if (c1 <= 3 || r1 < 3)
                            {
                                impossible = true;
                            }

                            for (int j = qr; j < r - 2; j++)
                            {
                                map[j, qc] = 1;
                            }
                            map[qr, qc + 1] = 1;
                            needm = 0;
                        }
                        else
                        {
                            for (int j = qr; j < r && needm > 0; j++)
                            {
                                map[j, qc] = 1;
                                needm--;
                            }

                            qc++;
                        }
                    }
                    else
                    {
                        if (r1 < 3)
                        {
                            impossible = true;
                        }
                        else if (c1 == needm + 1)
                        {
                            if (r1 <= 3 || c1 < 3)
                            {
                                impossible = true;
                            }

                            for (int j = qc; j < c - 2; j++)
                            {
                                map[qr, j] = 1;
                            }
                            map[qr + 1, qc] = 1;
                            needm = 0;
                        }
                        else
                        {
                            for (int j = qc; j < c && needm > 0; j++)
                            {
                                map[qr, j] = 1;
                                needm--;
                            }
                            qr++;
                        }
                    }
                }

                if (impossible)
                {
                    res.Add(string.Format("Case #{0}:", (i + 1).ToString(CultureInfo.InvariantCulture)));
                    res.Add("Impossible");
                }
                else
                {
                    res.Add(
                        string.Format(
                            "Case #{0}:", (i + 1).ToString(CultureInfo.InvariantCulture)));
                    
                    map[r - 1, c - 1] = 2;
                    for (int a = 0; a < r; a++)
                    {
                        string s = "";
                        for (int b = 0; b < c; b++)
                        {
                            if (map[a, b] == 0)
                            {
                                s += ".";
                            }
                            else if (map[a, b] == 1)
                            {
                                s += "*";
                            }
                            else if (map[a, b] == 2)
                            {
                                s += "c";
                            }
                        }
                        res.Add(s);
                    }
                }
            }

            return res.ToArray();
        }
    }
}
