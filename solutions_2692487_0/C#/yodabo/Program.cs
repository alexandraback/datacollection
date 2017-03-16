using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace problem1
{
    class Program
    {
        static UInt64 Solve(UInt64 A, ref UInt64[] sizes)
        {
            // step through from the beginning and find the incremental cost of getting this mote
            UInt64 answer = (UInt64)sizes.Length; // remove everything
            if (A == 0 || A == 1) return answer; // have to remove everything
            UInt64 addedMotes = 0; // how many added so far
            for (int i = 0; i < sizes.Length; ++i)
            {
                // how many more motes have to be added for this one?
                while ((UInt64)A <= sizes[i])
                {
                    A += A - 1;
                    addedMotes++;
                }
                A += sizes[i];
                if (addedMotes + (UInt64)sizes.Length - (UInt64)i - 1 < answer)
                {
                    // how many to add + how many to remove
                    answer = addedMotes + ((UInt64)sizes.Length - (UInt64)i - 1);
                }
            }
            return answer;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                // read input...
                String[] line = Console.ReadLine().Trim(' ').Split(' ');
                int A = int.Parse(line[0]);
                int N = int.Parse(line[1]);
                line = Console.ReadLine().Trim(' ').Split(' ');
                UInt64[] sizes = new UInt64[N];
                for (int j = 0; j < N; ++j)
                {
                    sizes[j] = UInt64.Parse(line[j]);
                }
                List<UInt64> sizesSorted = new List<ulong>();
                sizesSorted.AddRange(sizes);
                sizesSorted.Sort();
                sizes = sizesSorted.ToArray();
                Console.WriteLine("Case #{0}: {1}", 1 + i, Solve((UInt64)A, ref sizes));
            }
        }
    }
}
