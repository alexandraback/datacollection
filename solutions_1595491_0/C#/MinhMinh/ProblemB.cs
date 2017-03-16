using System;
using System.Collections.Generic;
using System.IO;

class ProblemB
{
    static String input = "B-small-attempt0.in";
    static String output = "b.out";

    static void Main(string[] args)
    {
        int numOfCases;
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);

        int[] surprise = new int[] { -1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, -1, -1};
        int[] normal = new int[] {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10 };

        numOfCases = int.Parse(reader.ReadLine());
        for (int index = 1; index <= numOfCases; index++)
        {
            String[] sArray = reader.ReadLine().Split(' ');
            int N = int.Parse(sArray[0]);
            int S = int.Parse(sArray[1]);
            int p = int.Parse(sArray[2]);

            int[] b = new int[N];
            int[] c = new int[N];
            for (int i = 0; i < N; i++)
            {
                int v = int.Parse(sArray[3 + i]);
                if (p <= surprise[v]) b[i] = 1;
                if (p <= normal[v]) c[i] = 1;
            }

            int ans = 0;
            int bCnt = 0;
            int cCnt = 0;
            for (int i = 0; i < N; i++)
            {
                if (b[i] == 1 && c[i] == 0) bCnt++;
                if (b[i] == 1 && c[i] == 1) cCnt++;
                if (b[i] == 0 && c[i] == 1) ans++;
            }
            ans += Math.Min(bCnt, S) + cCnt;
            
            writter.WriteLine("Case #" + index + ": " + ans);
        }

        reader.Close();
        writter.Close();
    }
}

