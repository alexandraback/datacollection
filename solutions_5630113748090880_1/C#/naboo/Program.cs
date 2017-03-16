using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        foreach (var source in Directory.GetFiles(@"..\..", "*.in"))
        {
            var target = Path.ChangeExtension(source, ".out");
            if (!File.Exists(target))
            {
                using (var sourceStream = new StreamReader(source))
                {
                    using (var targetStream = new StreamWriter(target))
                    {
                        int T = int.Parse(sourceStream.ReadLine());
                        for (int t = 1; t <= T; t++)
                        {
                            targetStream.WriteLine("Case #{0}:{1}", t, Work(sourceStream));
                        }
                    }
                }

            }
        }
    }

    private static string Work(StreamReader sr)
    {
        int n = int.Parse(sr.ReadLine());
        int l = 2 * n - 1;
        var freq = new Dictionary<int, int>();
        for (int i = 0; i < l; i++)
        {
            var line = sr.ReadLine().Split(' ');
            for (int j = 0; j < line.Length; j++)
            {
                int x = int.Parse(line[j]);
                if (freq.ContainsKey(x))
                    freq[x]++;
                else
                    freq.Add(x, 1);
            }
        }
        var result = new List<int>();
        foreach (var x in freq.Keys)
        {
            if (freq[x] % 2 == 1)
                result.Add(x);
        }
        result.Sort();
        var sb = new StringBuilder();
        foreach (var x in result)
            sb.Append(' ').Append(x);
        return sb.ToString();
    }
}
