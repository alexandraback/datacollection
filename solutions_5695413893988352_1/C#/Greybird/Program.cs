using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Round1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"..\..\input.txt");
            var count = int.Parse(lines[0]);
            var results = new List<string>();
            for (var l = 0; l < count; l++)
            {
                var val = lines[l + 1];
                var c = val.Split(' ')[0];
                var j = val.Split(' ')[1];
                Status? s = null;
                var values = new List<Tuple<string, string>>();
                Fill(values, c, j, 0, s, "", "");
                var res = values.Select(t => new {Tu = t, C = decimal.Parse(t.Item1), J = decimal.Parse(t.Item2)})
                    .GroupBy(g => Math.Abs(g.C - g.J))
                    .OrderBy(g => g.Key)
                    .First()
                    .OrderBy(h => h.C).ThenBy(h => h.J)
                    .First();
                results.Add($"Case #{l + 1}: {res.Tu.Item1} {res.Tu.Item2}");
            }
            File.WriteAllLines(@"..\..\output.txt", results);
        }

        private static void Fill(List<Tuple<string, string>> values, string c, string j, int i, Status? s, string currentC, string currentJ)
        {
            if (i == c.Length)
            {
                values.Add(new Tuple<string, string>(currentC, currentJ));
                return;
            }
            var cNew = '?';
            var jNew = '?';
            if (c[i] == '?' && j[i] == '?')
            {
                if (s == null)
                {
                    Fill(values, c, j, i + 1, s, currentC + "0", currentJ + "0");
                    Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + "0", currentJ + "1");
                    Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + "1", currentJ + "0");
                }
                else
                {
                    switch (s.Value)
                    {
                        case Status.SameLeft:
                            Fill(values, c, j, i + 1, s, currentC + "0", currentJ + "0");
                            Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + "0", currentJ + "1");
                            Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + "1", currentJ + "0");
                            break;
                        case Status.CGreaterThanJ:
                            Fill(values, c, j, i + 1, s, currentC + "0", currentJ + "9");
                            break;
                        case Status.CLowerThanJ:
                            Fill(values, c, j, i + 1, s, currentC + "9", currentJ + "0");
                            break;
                    }
                }
                return;
            }
            if (c[i] != '?' && j[i] != '?')
            {
                cNew = c[i];
                jNew = j[i];
                var s2 = s;
                if ((s == null && (c[i] != '0' || j[i] != '0')) || s == Status.SameLeft)
                {
                    if (cNew == jNew)
                    {
                        s2 = Status.SameLeft;
                    }
                    else if (cNew < jNew)
                    {
                        s2 = Status.CLowerThanJ;
                    }
                    else
                    {
                        s2 = Status.CGreaterThanJ;
                    }
                }
                Fill(values, c, j, i + 1, s2, currentC + c[i], currentJ + j[i]);
                return;
            }
            if (c[i] == '?')
            {
                if (s == null)
                {
                    var jVal = j[i];
                    Fill(values, c, j, i + 1, jVal != '0' ? Status.SameLeft : (Status?) null, currentC + jVal, currentJ + j[i]);
                    if (jVal > '0')
                    {
                        var jVal2 = (char) (jVal - 1);
                        Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + jVal2, currentJ + j[i]);
                    }
                    if (jVal < '9')
                    {
                        var jVal2 = (char) (jVal + 1);
                        Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + jVal2, currentJ + j[i]);
                    }
                }
                else
                {
                    switch (s.Value)
                    {
                        case Status.SameLeft:
                            var jVal = j[i];
                            Fill(values, c, j, i + 1, s, currentC + jVal, currentJ + j[i]);
                            if (jVal > '0')
                            {
                                var jVal2 = (char) (jVal - 1);
                                Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + jVal2, currentJ + j[i]);
                            }
                            if (jVal < '9')
                            {
                                var jVal2 = (char) (jVal + 1);
                                Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + jVal2, currentJ + j[i]);
                            }
                            break;
                        case Status.CGreaterThanJ:
                            Fill(values, c, j, i + 1, s, currentC + "0", currentJ + j[i]);
                            break;
                        case Status.CLowerThanJ:
                            Fill(values, c, j, i + 1, s, currentC + "9", currentJ + j[i]);
                            break;
                    }
                }
            }
            else if (j[i] == '?')
            {
                if (s == null)
                {
                    var cVal = c[i];
                    Fill(values, c, j, i + 1, cVal != '0' ? Status.SameLeft : (Status?) null, currentC + c[i], currentJ + cVal);
                    if (cVal > '0')
                    {
                        var cVal2 = (char) (cVal - 1);
                        Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + c[i], currentJ + cVal2);
                    }
                    if (cVal < '9')
                    {
                        var cVal2 = (char) (cVal + 1);
                        Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + c[i], currentJ + cVal2);
                    }
                    return;
                }
                switch (s.Value)
                {
                    case Status.SameLeft:
                        var cVal = c[i];
                        Fill(values, c, j, i + 1, s, currentC + c[i], currentJ + cVal);
                        if (cVal > '0')
                        {
                            var cVal2 = (char) (cVal - 1);
                            Fill(values, c, j, i + 1, Status.CGreaterThanJ, currentC + c[i], currentJ + cVal2);
                        }
                        if (cVal < '9')
                        {
                            var cVal2 = (char) (cVal + 1);
                            Fill(values, c, j, i + 1, Status.CLowerThanJ, currentC + c[i], currentJ + cVal2);
                        }

                        break;
                    case Status.CGreaterThanJ:
                        Fill(values, c, j, i + 1, s, currentC + c[i], currentJ + "9");
                        break;
                    case Status.CLowerThanJ:
                        Fill(values, c, j, i + 1, s, currentC + c[i], currentJ + "0");
                        break;
                }
            }
        }
    }

    enum Status
    {
        SameLeft,
        CGreaterThanJ,
        CLowerThanJ
    }
}