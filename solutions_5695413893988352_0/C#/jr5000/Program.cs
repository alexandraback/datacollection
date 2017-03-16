using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1b
{
    class Program
    {
        static void Main(string[] args)
        {
            char question = 'B';
            using (var reader = new StreamReader("C:/CodeJam/1b/Problem" + question + "/B-small-attempt0 (2).in"))
            {
                using (var writer = new StreamWriter("C:/CodeJam/1b/Problem" + question + "/output.txt"))
                {
                    var numTC = int.Parse(reader.ReadLine());
                    for (var tc = 1; tc <= numTC; tc++)
                    {
                        Console.Write("Case #{0}: ", tc);
                        writer.Write("Case #{0}: ", tc);
                        if (question == 'A')
                            Solve1(reader, writer);
                        else if (question == 'B')
                            Solve2(reader, writer);
                        else if (question == 'C')
                            Solve3(reader, writer);
                    }
                }
            }
            Console.WriteLine("DONE!");
            Console.ReadKey();
        }

        static Dictionary<char, string> _characterRepresentations = new Dictionary<char, string>() { { '0', "ZERO" }, { '1', "ONE" }, { '2', "TWO" }, { '3', "THREE" }, { '4', "FOUR" }, { '5', "FIVE" }, { '6', "SIX" }, { '7', "SEVEN" }, { '8', "EIGHT" }, { '9', "NINE" } };

        static void Solve1(StreamReader reader, StreamWriter writer)
        {
            string number = reader.ReadLine();
            Dictionary<char, int> characterCounts = new Dictionary<char, int>();
            foreach(var c in number)
            {
                if (!characterCounts.ContainsKey(c))
                    characterCounts.Add(c, 0);
                characterCounts[c]++;
            }

            List<char> output = new List<char>();

            while (characterCounts.Any())
            {
                Dictionary<char, List<char>> possibleMappings = new Dictionary<char, List<char>>();
                foreach (var c in characterCounts)
                {
                    foreach (var d in _characterRepresentations)
                    {
                        var containsC = false;
                        Dictionary<char, int> wordCounts = new Dictionary<char, int>();
                        foreach(var e in d.Value)
                        {
                            if (e == c.Key)
                                containsC = true;
                            if (!wordCounts.ContainsKey(e))
                                wordCounts.Add(e, 0);
                            wordCounts[e]++;
                        }
                        if (!containsC)
                            continue;
                        var canMake = true;
                        foreach(var e in wordCounts)
                        {
                            if (!characterCounts.ContainsKey(e.Key) || characterCounts[e.Key] < e.Value)
                                canMake = false;
                        }
                        if (canMake)
                        {
                            if (!possibleMappings.ContainsKey(c.Key))
                                possibleMappings.Add(c.Key, new List<char>());
                            possibleMappings[c.Key].Add(d.Key);
                        }
                    }
                }
                var foundOne = false;
                foreach(var num in possibleMappings)
                {
                    if(num.Value.Count == 1)
                    {
                        output.Add(num.Value[0]);
                        foundOne = true;
                        foreach(var letter in _characterRepresentations[num.Value[0]])
                        {
                            characterCounts[letter]--;
                            if (characterCounts[letter] == 0)
                                characterCounts.Remove(letter);
                        }
                        break;
                    }
                }
                if (!foundOne)
                    throw new Exception("DAFUQ?");
            }
            Console.WriteLine(output.OrderBy(a => a).ToArray());
            writer.WriteLine(output.OrderBy(a => a).ToArray());
        }

        static void Solve2(StreamReader reader, StreamWriter writer)
        {
            var line = reader.ReadLine().Split(' ');
            var c = line[0];
            var j = line[1];
            //var res = Recurse(c, j);
            //Console.WriteLine(res.Item1 + " " + res.Item2);
            //writer.WriteLine(res.Item1 + " " + res.Item2);

            bestDiff = int.MaxValue;
            BruteForce(new List<char>(), new List<char>(), c, j);
            Console.WriteLine(bestC + " " + bestJ);
            writer.WriteLine(bestC + " " + bestJ);
        }

        static int bestDiff;
        static string bestC;
        static string bestJ;

        static void BruteForce(List<char> cl, List<char> jl, string c, string j)
        {
            int i = cl.Count;
            if(i == c.Length)
            {
                var cs = new string(cl.ToArray());
                var js = new string(jl.ToArray());
                var diff = Diff(cs, js);
                var isBetter = false;
                if (diff < bestDiff)
                    isBetter = true;
                else if(diff == bestDiff)
                {
                    if (int.Parse(cs) < int.Parse(bestC))
                        isBetter = true;
                    else if(int.Parse(cs) == int.Parse(js))
                    {
                        if (int.Parse(js) < int.Parse(bestJ))
                            isBetter = true;
                    }
                }
                if (isBetter)
                {
                    bestDiff = diff;
                    bestC = cs;
                    bestJ = js;
                }
                return;
            }
            if(c[i] == '?')
            {
                for (char a = '0'; a <= '9'; a++)
                {
                    cl.Add(a);
                    if (j[i] == '?')
                    {
                        for (char b = '0'; b <= '9'; b++)
                        {
                            jl.Add(b);
                            BruteForce(cl, jl, c, j);
                            jl.RemoveAt(i);
                        }
                    }
                    else
                    {
                        jl.Add(j[i]);
                        BruteForce(cl, jl, c, j);
                        jl.RemoveAt(i);
                    }
                    cl.RemoveAt(i);
                }
            }
            else
            {
                cl.Add(c[i]);
                if (j[i] == '?')
                {
                    for (char b = '0'; b <= '9'; b++)
                    {
                        jl.Add(b);
                        BruteForce(cl, jl, c, j);
                        jl.RemoveAt(i);
                    }
                }
                else
                {
                    jl.Add(j[i]);
                    BruteForce(cl, jl, c, j);
                    jl.RemoveAt(i);
                }
                cl.RemoveAt(i);
            }
        }

        static Tuple<string, string, int> Recurse(string c, string j, int mod = 0)
        {
            if (c.Length == 0)
                return new Tuple<string, string, int>("", "", 0);
            if (c[0] != '?' && j[0] != '?')
            {
                var res = Recurse(c.Substring(1, c.Length - 1), j.Substring(1, j.Length - 1), c[0].CompareTo(j[0]));
                return new Tuple<string, string, int>(c[0] + res.Item1, j[0] + res.Item2, Diff(c[0] + res.Item1, j[0] + res.Item2));
            }
            else if (c[0] == '?' && j[0] == '?')
            {
                var res = Recurse(c.Substring(1, c.Length - 1), j.Substring(1, j.Length - 1), mod);
                if (mod == 0)
                {
                    var diff = res.Item3;
                    var logUp = (int)Math.Pow(10, c.Length - 1);
                    if (logUp - diff < diff)
                    {
                        return new Tuple<string, string, int>('0' + res.Item1, '1' + res.Item2, logUp - diff);
                    }
                    else
                    {
                        return new Tuple<string, string, int>('0' + res.Item1, '0' + res.Item2, logUp - diff);
                    }
                }
                else if(mod < 0)
                {
                    return null;
                }
                return null;
            }
            else if (c[0] == '?')
            {
                var res = Recurse(c.Substring(1, c.Length - 1), j.Substring(1, j.Length - 1));
                var diff = res.Item3;
                var logUp = (int)Math.Pow(10, c.Length - 1);
                if (logUp - diff < diff)
                {
                    if (j[0] > '0')
                        return new Tuple<string, string, int>((j[0] - 1) + res.Item1, j[0] + res.Item2, logUp - diff);
                    else
                        return new Tuple<string, string, int>('9' + res.Item1, '9' + res.Item2, logUp - diff);
                }
                else
                {
                    return new Tuple<string, string, int>(j[0] + res.Item1, j[0] + res.Item2, logUp - diff);
                }
            }
            else
            {
                var res = Recurse(c.Substring(1, c.Length - 1), j.Substring(1, j.Length - 1));
                var diff = res.Item3;
                var logUp = (int)Math.Pow(10, c.Length - 1);
                if (logUp - diff < diff)
                {
                    if (c[0] < '9')
                        return new Tuple<string, string, int>(c[0] + res.Item1, (c[0] + 1) + res.Item2, logUp - diff);
                    else
                        return new Tuple<string, string, int>(c[0] + res.Item1, '0' + res.Item2, logUp - diff);
                }
                else
                {
                    return new Tuple<string, string, int>(c[0] + res.Item1, c[0] + res.Item2, logUp - diff);
                }
            }
        }

        static int Diff(string a, string b)
        {
            return Math.Abs(int.Parse(a) - int.Parse(b));
        }

        static void Solve3(StreamReader reader, StreamWriter writer)
        {
            var numPairs = int.Parse(reader.ReadLine());
            var pairs = new List<Tuple<string, string>>();
            for(int i = 0; i < numPairs; i++)
            {
                var line = reader.ReadLine().Split(' ');
                pairs.Add(new Tuple<string, string>(line[0], line[1]));
            }
            var firstWords = new Dictionary<string, List<Tuple<string, string>>>();
            foreach (var v in pairs)
            {
                if (!firstWords.ContainsKey(v.Item1))
                    firstWords.Add(v.Item1, new List<Tuple<string, string>>());
                firstWords[v.Item1].Add(v);
            }
            var secondWords = new Dictionary<string, List<Tuple<string, string>>>();
            foreach (var v in pairs)
            {
                if (!secondWords.ContainsKey(v.Item2))
                    secondWords.Add(v.Item2, new List<Tuple<string, string>>());
                secondWords[v.Item2].Add(v);
            }
            int numReal = 0;
            int numFake = 0;
            var realFirsts = new HashSet<string>();
            var realSeconds = new HashSet<string>();
            foreach (var word in firstWords)
            {
                if (word.Value.Count == 1)
                {
                    realFirsts.Add(word.Key);
                    realSeconds.Add(word.Value[0].Item2);
                    pairs.Remove(word.Value[0]);
                    numReal++;
                }
            }
            foreach (var word in secondWords)
            {
                if (word.Value.Count == 1)
                {
                    realSeconds.Add(word.Key);
                    realSeconds.Add(word.Value[0].Item1);
                    pairs.Remove(word.Value[0]);
                    numReal++;
                }
            }
            for (int i = pairs.Count - 1; i >= 0; i--)
            {
                if (realFirsts.Contains(pairs[i].Item1) && realSeconds.Contains(pairs[i].Item2))
                {
                    numFake++;
                    pairs.RemoveAt(i);
                }
            }
            Console.WriteLine(numFake + (Math.Max(pairs.Select(a => a.Item1).Distinct().Count(), pairs.Select(a => a.Item2).Distinct().Count())));
            writer.WriteLine(numFake + (Math.Max(pairs.Select(a => a.Item1).Distinct().Count(), pairs.Select(a => a.Item2).Distinct().Count())));
        }
    }
}
