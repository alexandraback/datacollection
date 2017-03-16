using System;
using System.IO;

class Lawnmower
{
    public static void Solve()
    {
        StreamReader input = new StreamReader("B-large.in");
        StreamWriter output = new StreamWriter("B-large.out");
        char[] separators = { ' ', '\t', '\n' };
        int T = int.Parse(input.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] splitLine = input.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);
            int N = int.Parse(splitLine[0]);
            int M = int.Parse(splitLine[1]);
            int[,] height = new int[N, M];
            int[] maxHeightRow = new int[M];
            int[] maxHeightColumn = new int[N];
            for (int i = 0; i < N; i++)
            {
                splitLine = input.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);
                for (int j = 0; j < M; j++)
                {
                    height[i, j] = int.Parse(splitLine[j]);
                    maxHeightRow[j] = Math.Max(maxHeightRow[j], height[i, j]);
                    maxHeightColumn[i] = Math.Max(maxHeightColumn[i], height[i, j]);
                }
            }
            bool possible = true;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    if (height[i, j] < maxHeightColumn[i] && height[i, j] < maxHeightRow[j])
                        possible = false;
            output.Write("Case #{0}: ", t + 1);
            if (possible)
                output.WriteLine("YES");
            else
                output.WriteLine("NO");
        }
        input.Close();
        output.Close();
    }
}

