using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace a1
{
	class Program
	{
		static void Main(string[] args)
		{
			if (args.Length < 1) return;

			TextReader reader = new StreamReader(args[0], Encoding.UTF8);
			var n = int.Parse(reader.ReadLine());
            var results = new string[n];

            for (int i = 0; i < results.Length; i++)
            {
                results[i] = "No";
            }
            
            for (var i = 0; i < n; i++)
			{
                var inhCount = int.Parse(reader.ReadLine());
			    var inhMass = new List<int>[inhCount];
                for(int j = 0; j < inhCount; j++)
                {
                    var inheritage = reader.ReadLine().Split(' ');
                    int cn = int.Parse(inheritage[0]);
                    var values = new List<int>();

                    for(int k = 0; k < cn; k++)
                    {
                        values.Add(int.Parse(inheritage[k + 1]) - 1);
                    }

                    inhMass[j] = values;
                }

                for (int j = 0; j < inhMass.Length; j++)
                {
                    for (int k = 0; k < inhMass.Length; k++)
                    {
                        int pathCount = 0;
                        PathCount(inhMass, j, k, ref pathCount);
                        if (pathCount < 2) continue;

                        results[i] = "Yes";
                        break;
                    }

                    if (results[i] == "Yes") break;
                }             
			}

			reader.Close();

            TextWriter writer = new StreamWriter(args[1]);
            for (var i = 0; i < n; i++)
            {
                writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, results[i]));
            }
            writer.Close();
		}

        static void PathCount(List<int>[] inheritages, int first, int second, ref int pathCount)
        {
            if (inheritages[first].Contains(second))
            {
                pathCount++;
            }

            foreach (var nextParent in inheritages[first])
            {
                PathCount(inheritages, nextParent, second, ref pathCount);
            }
        }
	}
}
