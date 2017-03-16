using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CodeJam1b
{
    class Problem1
    {
        public static void Main()
        {
            new Problem1().Start();
        }

        void Start()
        {
            new Thread(() =>
            {
                var fileName = "A-small-attempt1";
                using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
                using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
                {
                    var TC = int.Parse(input.ReadLine());
                    for (var testCase = 1; testCase <= TC; testCase++)
                    {
                        Console.WriteLine("Case #" + testCase);

                        var res = DP(0, int.Parse(input.ReadLine()));
                        Console.WriteLine("Case #" + testCase + ": " + res);
                        output.WriteLine("Case #" + testCase + ": " + res);
                        memo.Clear();
                    }
                }
            }, 1000000000).Start();
        }

        static Dictionary<int, int> memo = new Dictionary<int, int>();
        static int DP(int num, int target)
        {
            if (memo.ContainsKey(num))
                return memo[num];

            if (num == target)
                return memo[num] = 0;
            if (num > target)
                return memo[num] = 10000000;

            var t = num.ToString();
            t = new string(t.Reverse().ToArray());
            var num2 = int.Parse(t);

            return memo[num] = Math.Min(num2 != num && num2 > num ? DP(num2, target) + 1 : 10000000, DP(num + 1, target) + 1);
        }
    }
}
