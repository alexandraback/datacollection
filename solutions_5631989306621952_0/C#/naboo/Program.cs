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
                            targetStream.WriteLine("Case #{0}: {1}", t, Work(sourceStream));
                        }
                    }
                }

            }
        }
    }

    private static string Work(StreamReader sr)
    {
        string s = sr.ReadLine();
        StringBuilder sb = new StringBuilder();

        sb.Append(s[0]);
        for (int i = 1; i < s.Length; i++)
        {
            char c = s[i];
            if (c >= sb[0])
                sb.Insert(0, c);
            else
                sb.Append(c);

        }
        return sb.ToString();
    }
}
