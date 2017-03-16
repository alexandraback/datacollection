using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test.in", "A-small-attempt0.in", "A-large.in" }[1];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round1A(input, output);
            }
        }

        static void Round1A(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var S = fileInput.ReadLine();

                var A = new List<char>();
                var Z = new List<char>();
                for (int i = S.Length; --i >= 0; )
                {
                    int max = i;
                    for (int j = i; --j >= 0; )
                        if (S[max] < S[j]) max = j;
                    A.Add(S[max]);
                    for (; i > max; i--)
                        Z.Add(S[i]);
                }
                Z.Reverse();
                A.AddRange(Z);
                var Last = new string(A.ToArray());

                var result = string.Format("Case #{0}: {1}", t + 1, Last);
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
