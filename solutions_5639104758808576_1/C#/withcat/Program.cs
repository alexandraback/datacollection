using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var T = int.Parse(Console.ReadLine());
        for (var t = 0; t < T; t++)
        {
            var r1 = Console.ReadLine().Split().ToArray();
            var S = r1[1].Select(v => int.Parse(v.ToString())).ToArray();

            var need = 0;
            var sum = 0;
            for (var i = 0; i < S.Length; i++)
            {
                if (sum < i)
                {
                    if (need < i - sum) need = i - sum;
                }
                sum += S[i];
            }
            Console.WriteLine("Case #{0}: {1}", t + 1, need);
        }
    }
}
