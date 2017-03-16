using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Qualification
{
    public class Fractiles
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Qualification\";
        private const string Impossible = "IMPOSSIBLE";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_D.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var ps = textReader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    result.AppendLine($"Case #{t}: {Solve(ps[0], ps[1], ps[2])}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_D.txt"))
            {
                textWriter.Write(result.ToString());
            }
        }

        private static string Solve(int K, int C, int S)
        {
            if (C == 1)
                return S < K 
                    ? Impossible 
                    : string.Join(" ", Enumerable.Range(1, K));

            if (K <= C)
                return GetPosition(0, K, C).ToString();

            var i = 0;
            var bucketDisplacement = (long) Math.Pow(K, C - 1) * C;
            var result = new List<long>();
            var p = K;
            while (p >= C)
            {
                result.Add(bucketDisplacement * i + GetPosition(i, K, C));
                ++i;
                p -= C;
            }
            if (p > 0)
                result.Add(bucketDisplacement * i + GetPosition(i, K, C));
            
            return result.Count <= S 
                ? string.Join(" ", result) 
                : Impossible;
        }

        private static long GetPosition(int i, int K, int C)
        {
            long displacement = i * C + 2;
            if (displacement > K)
                displacement = K;

            for (var j = 3; j <= C; ++j)
            {
                long t = i * C + j;
                if (t > K)
                    t = K;

                displacement = (displacement - 1) * K + t;
            }

            return displacement;
        }
    }
}
