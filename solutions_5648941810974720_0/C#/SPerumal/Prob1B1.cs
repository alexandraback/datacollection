using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Prob1B1
    {
        List<char> chars;
        List<int> result;
        internal void Run()
        {
            var lines = File.ReadAllLines("A-small-attempt0.in");

            var n = int.Parse(lines[0]);

            int i = 1;
            using (var sw = File.CreateText("A.out"))
            foreach (var line in lines.Skip(1))
            {
                chars = line.ToUpper().ToList();
                result = new List<int>();
                chars.Sort();

                Process('Z', "ZERO", 0);
                Process('W', "TWO", 2);
                Process('U', "FOUR", 4);
                Process('X', "SIX", 6);
                Process('G', "EIGHT", 8);
                Process('F', "FIVE", 5);
                Process('S', "SEVEN", 7);
                Process('T', "THREE", 3);
                Process('O', "ONE", 1);
                Process('I', "NINE", 9);

                result.Sort();

                sw.WriteLine("Case #{0}: {1}", i++, String.Join("", result));   
            }
        }

        private void Process(char lookup, string remove, int value)
        {
            var groups = chars.GroupBy(c => c).ToLookup(g => g.Key);
            if (groups.Contains(lookup))
            {
                var count = groups[lookup].Sum(a => a.Count());
                for (int i = 0; i < count; i++)
                {
                    foreach (var c2 in remove)
                        chars.Remove(c2);
                    result.Add(value);
                }
            }
        }
    }
}
