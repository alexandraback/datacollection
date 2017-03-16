using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var dir = new DirectoryInfo(@"C:\Users\Arnau\Downloads");
            var file = dir.EnumerateFiles("*.in").OrderByDescending(f => f.LastWriteTime).First();
            Console.WriteLine(file.Name);
            Console.ReadLine();
            var lines = File.ReadAllLines(file.FullName);
            var count = int.Parse(lines[0]);
            var results = new List<string>();
            for (var t = 0; t < count; t++)
            {
                Console.WriteLine("Test {0}/{1}", t + 1, count);
                var J = int.Parse(lines[t + 1].Split(' ')[0]);
                var P = int.Parse(lines[t + 1].Split(' ')[1]);
                var S = int.Parse(lines[t + 1].Split(' ')[2]);
                var K = int.Parse(lines[t + 1].Split(' ')[3]);

                var outfits = new List<Outfit>();
                for (var j = 1; j <= J; j++)
                {
                    for (var p = 1; p <= P; p++)
                    {
                        for (var s = 1; s <= S; s++)
                        {
                            outfits.Add(new Outfit {J = j, P = p, S = s});
                        }
                    }
                }
                var remove1 = outfits.GroupBy(o => new {o.J, o.P}).SelectMany(g => g.Skip(K));
                outfits = outfits.Except(remove1).ToList();
                remove1 = outfits.GroupBy(o => new {o.J, o.S}).SelectMany(g => g.Skip(K));
                outfits = outfits.Except(remove1).ToList();
                remove1 = outfits.GroupBy(o => new {o.P, o.S}).SelectMany(g => g.Skip(K));
                outfits = outfits.Except(remove1).ToList();
                results.Add($"Case #{t + 1}: {outfits.Count}");
                foreach (var o in outfits)
                {
                    results.Add($"{o.J} {o.P} {o.S}");
                }
            }
            File.WriteAllLines(@"output.txt", results);
        }
    }

    internal class Outfit
    {
        public int J;
        public int P;
        public int S;
    }
}