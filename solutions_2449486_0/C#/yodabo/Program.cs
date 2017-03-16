using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lawnmower
{
    class Program
    {
        static bool CanGetHeight(ref int[,] nums, int n, int m, int N, int M)
        {
            // we can only achieve a height if there is a path to the edge that doesn't have higher numbers

            bool updown = true;
            for (int i = 0; i < N && updown; ++i)
            {
                if (nums[i, m] > nums[n, m])
                    updown = false;
            }
            if (updown) return true;

            bool leftRight = true;
            for (int i = 0; i < M && leftRight; ++i)
            {
                if (nums[n, i] > nums[n, m])
                    leftRight = false;
            }
            if (leftRight) return true;

            return false;
        }

        static void solve(int testnum, int N, int M, ref int[,] nums)
        {
            bool solvable = true;

            for (int i = 0; i < N && solvable; ++i)
            {
                for (int j = 0; j < M && solvable; ++j)
                {
                    solvable = CanGetHeight(ref nums, i, j, N, M);
                }
            }

            Console.WriteLine("Case #{0}: {1}", 1 + testnum, solvable ? "YES" : "NO");
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] nums = Console.ReadLine().Split(' ');
                int N = int.Parse(nums[0]); // how many lines to read
                int M = int.Parse(nums[1]); // how many numbers per line

                int[,] h = new int[N, M];
                for (int j = 0; j < N; ++j)
                {
                    nums = Console.ReadLine().Split(' ');
                    for (int k = 0; k < M; ++k)
                    {
                        h[j, k] = int.Parse(nums[k]);
                    }
                }

                solve(i, N, M, ref h);
            }
        }
    }
}
