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
            char question = 'A';
            using (var reader = new StreamReader("C:/CodeJam/1b/Problem" + question + "/A-large (2).in"))
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

        }

        static void Solve3(StreamReader reader, StreamWriter writer)
        {

        }
    }
}
