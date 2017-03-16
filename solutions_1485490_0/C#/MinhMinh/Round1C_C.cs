using System;
using System.Collections.Generic;
using System.IO;

class Round1C_A
{
    static String input = "c-small-attempt0.in";
    static String output = "c-small-attempt0.out";

    //static String input = "c-large.in";
    //static String output = "c-large.out";

    static void Main(string[] args)
    {
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);

        int T = int.Parse(reader.ReadLine());
        for (int index = 1; index <= T; index++)
        {
            String[] lineArray = reader.ReadLine().Split(' ');
            int N = int.Parse(lineArray[0]);
            int M = int.Parse(lineArray[1]);

            List<long> pA = new List<long>();
            List<long> tA = new List<long>();
            List<long> pB = new List<long>();
            List<long> tB = new List<long>();
            lineArray = reader.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                pA.Add(long.Parse(lineArray[2 * i]));
                tA.Add(long.Parse(lineArray[2 * i + 1]));
            }
            lineArray = reader.ReadLine().Split(' ');
            for (int i = 0; i < M; i++)
            {
                pB.Add(long.Parse(lineArray[2 * i]));
                tB.Add(long.Parse(lineArray[2 * i + 1]));
            } 

            /*
            long[] pA = new long[N];
            long[] tA = new long[N];
            long[] pB = new long[M];
            long[] tB = new long[M];

            lineArray = reader.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                pA[i] = long.Parse(lineArray[2 * i]);
                tA[i] = long.Parse(lineArray[2 * i + 1]);
            }
            lineArray = reader.ReadLine().Split(' ');
            for (int i = 0; i < M; i++)
            {
                pB[i] = long.Parse(lineArray[2 * i]);
                tB[i] = long.Parse(lineArray[2 * i + 1]);
            } 
            */

            writter.WriteLine("Case #" + index + ": " + boxedToys(pA, tA, pB, tB));
            //Console.WriteLine("Case #" + index + ": " + boxedToys(pA, tA, pB, tB));
        }

        reader.Close();
        writter.Close();
    }

    static long boxedToys(List<long> pA, List<long> tA, List<long> pB, List<long> tB)
    {
        long r = 0;
        if (tA.Count == 0 || tB.Count == 0) return r;
        if (tA[0] == tB[0])
        {
            r = Math.Min(pA[0], pB[0]);
            pA[0] -= r;
            pB[0] -= r;
            List<long> pC = new List<long>(pA);
            List<long> tC = new List<long>(tA);
            List<long> pD = new List<long>(pB);
            List<long> tD = new List<long>(tB);
            if (pA[0] == 0)
            {
                pC.RemoveAt(0);
                tC.RemoveAt(0);
            }
            if (pB[0] == 0)
            {
                pD.RemoveAt(0);
                tD.RemoveAt(0);                
            }
            r += boxedToys(pC, tC, pD, tD);
        }
        else
        {
            List<long> pC = new List<long>();
            List<long> tC = new List<long>();
            for (int i = 1; i < pA.Count; i++)
            {
                pC.Add(pA[i]);
                tC.Add(tA[i]);
            }
            long r1 = boxedToys(pC, tC, pB, tB);

            pC = new List<long>();
            tC = new List<long>();
            for (int i = 1; i < pB.Count; i++)
            {
                pC.Add(pB[i]);
                tC.Add(tB[i]);
            }
            long r2 = boxedToys(pA, tA, pC, tC);

            r += Math.Max(r1, r2); 
        }
        return r; 
    }
}

