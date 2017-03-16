using System;
using System.Collections.Generic;

namespace GCJ._2016.C
{
    class b
    {
        static long[] checkList = new long[20];
        static void Main(string[] args)
        {
            checkList[0] = 0;
            checkList[1] = 1;
            for (var i = 2; i < 20; ++i)
            {
                checkList[i] = checkList[i - 1] * (i - 1);
            }
            var T = int.Parse(System.Console.ReadLine().Trim());
            for (int i = 0; i < T; ++i)
            {
                var line = Console.ReadLine().Trim();
                Console.WriteLine("Case #{0:D}: {1:D}", i + 1, solve(line));
            }
        }

        static string solve(string n)
        {
            var parse = n.Split(' ');
            var B = int.Parse(parse[0]);
            var M = long.Parse(parse[1]);
            if (B < 20 && M > checkList[B - 1]) return "IMPOSSIBLE";

            var str = "POSSIBLE";
            var ans = "";
            long cnt = 0;
            for (var i = B; i > 0; --i)
            {
                var tmp = "";
                tmp += "\n";
                if (B - i < 2) cnt = 0;
                else if (B - i == 2) cnt = 1;
                else cnt += 2;
                if (M < cnt)
                {
                    if (M <= 0)
                    {
                        for (var j = 0; j < B; ++j)
                        {
                            if (j == i) tmp += "1";
                            else tmp += "0";
                        }
                    }
                    else
                    {
                        for (var j = 0; j < i; ++j)
                        {
                            tmp += "0";
                        }
                        tmp += "1";
                        var cnv = Convert.ToString(M, 2);
                        for (var k = 0; k < B - i - cnv.Length - 1; ++k)
                        {
                            cnv = "0" + cnv;
                        }
                        tmp += cnv;
                    }
                }
                else
                {
                    for (var j = 0; j < i; ++j)
                    {
                        tmp += "0";
                    }
                    for (var j = i; j < B; ++j)
                    {
                        tmp += "1";
                    }
                }
                ans = tmp + ans;
                M -= cnt;
            }
            return str + ans;
        }
    }
}
