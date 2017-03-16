using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_0_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var K = parts[0];
                var C = parts[1];
                var S = parts[2];
                if (S < K) throw new Exception("Unsupported");
                Console.WriteLine("Case #{0}: {1}", testN, String.Join(" ", Enumerable.Range(1, S)));
            }
        }
    }
}
