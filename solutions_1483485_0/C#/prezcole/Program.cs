using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Program
    {
        private const string INPUT = "A-small-attempt0.in";
        private const string OUTPUT = "A-small-attempt0.out";
        private const string MAP_INPUT = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvz";
        private const string MAP_OUTPT = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upq";

        static void Main(string[] args)
        {
            IDictionary<char, char> tongueMap = GetTongueMap();
            Console.WriteLine(tongueMap.Count);
            foreach (var x in tongueMap.OrderBy(n => n.Value))
            {
                Console.WriteLine(x.Key + " " + x.Value);
            }
            
            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            for (int i = 1; i < input.Length; i++)
            {
                var builder = new StringBuilder();
                builder.Append("Case #" + i + ": ");
                for (int j = 0; j < input[i].Length; j++)
                {
                    builder.Append(tongueMap[input[i][j]]);
                }
                output.Add(builder.ToString());
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);

        }

        private static IDictionary<char, char> GetTongueMap()
        {
            var tongueMap = new Dictionary<char, char>();
            tongueMap.Add('y', 'a');
            tongueMap.Add('e', 'o');
            tongueMap.Add('q', 'z');

            for(int i = 0; i < MAP_OUTPT.Length; i++)
            {
                char eng = MAP_OUTPT[i];
                char goo = MAP_INPUT[i];

                if (!tongueMap.ContainsKey(goo))
                {
                    tongueMap.Add(goo, eng);
                }
            }

            return tongueMap;
        }
    }
}
