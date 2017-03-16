using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Jam2B
{
    class Program
    {
        static List<Group> boxes = new List<Group>();
        static List<Group> toys = new List<Group>();
        static HashSet<long> scores = new HashSet<long>();
 
        static void Main()
        {
            const string exercise = "C";
            const bool isLarge = false;

            var input = File.ReadAllLines(GetFileName(exercise, isLarge, true));
            var numberOfCases = int.Parse(input[0]);

            var start = DateTime.Now;

            var output = HandleInput(input, numberOfCases);
            File.WriteAllLines(GetFileName(exercise, isLarge, false), output.ToArray());

            var end = DateTime.Now;
            var span = end - start;
            Console.WriteLine("Milliseconds spent = " + span.TotalMilliseconds);
            Console.ReadKey();
        }

        static List<string> HandleInput(string[] input, int numberOfCases)
        {
            var output = new List<string>();
            int lineNr = 1;
            for (var cse = 0; cse < numberOfCases; cse++)
            {
                Console.WriteLine("Case " + (cse + 1));
                var line = input[lineNr++];
                var parts = line.Split(' ');
                var nrOfBoxGroups = int.Parse(parts[0]);
                var nrOfToyGroups = int.Parse(parts[1]);

                var boxLine = input[lineNr++];
                var boxParts = boxLine.Split(' ');
                boxes = new List<Group>();
                for (int j = 0; j < nrOfBoxGroups; j++)
                    boxes.Add(new Group { Index = j, Number = long.Parse(boxParts[j * 2]), Type = boxParts[j * 2 + 1] });

                var toyLine = input[lineNr++];
                var toyParts = toyLine.Split(' ');
                toys = new List<Group>();
                for (int m = 0; m < nrOfToyGroups; m++)
                    toys.Add(new Group { Index = m, Number = long.Parse(toyParts[m * 2]), Type = toyParts[m * 2 + 1] });

                scores = new HashSet<long>();
                HandleCase(0, 0, 0, new List<int>());
                output.Add(String.Format("Case #{0}: {1}", cse + 1, scores.Count == 0 ? 0 : scores.Max()));
            }
            return output;
        }

        static void HandleCase(int boxIndex, int toyIndex, long score, List<int> trail)
        {
            if (boxIndex >= boxes.Count)
            {
                //Console.WriteLine("score = " + score);
                //for (int i = 0; i < trail.Count; i++)
                //    Console.Write(trail[i] + ", ");
                //Console.WriteLine();

                scores.Add(score);
                return;
            }

            foreach (var box in boxes.Where(b => b.Index >= boxIndex))
            {
                // Wel.
//                trail.Add(box.Index);
                var matchingToys = toys.Where(toy => toy.Index >= toyIndex && toy.Type == box.Type).ToList();
                var sum = 0L;
                for (int q = 0; q < matchingToys.Count; q++)
                {
                    sum += matchingToys[q].Number;
                    if (box.Number < sum)
                    {
                        var old = matchingToys[q].Number;
                        matchingToys[q].Number = sum - box.Number;
                        HandleCase(box.Index + 1, matchingToys[q].Index, score + Math.Min(box.Number, sum), trail);
                        matchingToys[q].Number = old;
                    }
                    else
                        HandleCase(box.Index + 1, matchingToys[q].Index + 1, score + Math.Min(box.Number, sum), trail);
                }
//                trail.RemoveAt(trail.Count - 1);

                // Niet.
                HandleCase(boxIndex + 1, toyIndex, score, trail);
            }
        }

        static string GetFileName(string exercise, bool isLarge, bool isInput)
        {
            return string.Format(@"C:\data\{0}-{1}-attempt1.{2}", exercise, isLarge ? "large" : "small", isInput ? "in" : "out");
        }

        [DebuggerDisplay("{Index}: {Number} x {Type}")]
        class Group
        {
            public int Index;
            public string Type;
            public long Number;
        }
    }
}
