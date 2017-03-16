using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace GoogleCodeJam2012
{
    class MyPair : ICloneable
    {
        public long Type { get; set; }
        public long Count { get; set; }

        public MyPair(long c, long t) { Count = c; Type = t; }
        public object Clone()
        {
            return new MyPair(Count, Type);
        }
    }
    class A
    {
        static void Main(string[] args)
        {
            // Open Reader/Writer
            TextReader fileIn = new StreamReader("c.in");
            TextWriter fileOut = new StreamWriter("c.out");

            int countNum = Int32.Parse(fileIn.ReadLine());

            for (int caseCount = 0; caseCount < countNum; caseCount++)
            {
                string[] inVals = fileIn.ReadLine().Split(' ');

                long N = Int64.Parse(inVals[0]);
                long M = Int64.Parse(inVals[1]);

                string[] nVals = fileIn.ReadLine().Split(' ');
                List<MyPair> nPairs = new List<MyPair>();
                for (int i = 0; i < 2 * N; i += 2)
                {
                    MyPair newPair = new MyPair(Int64.Parse(nVals[i]), Int64.Parse(nVals[i + 1]));
                    nPairs.Add(newPair);
                }

                string[] mVals = fileIn.ReadLine().Split(' ');
                List<MyPair> mPairs = new List<MyPair>();
                for (int i = 0; i < 2 * M; i += 2)
                {
                    MyPair newPair = new MyPair(Int64.Parse(mVals[i]), Int64.Parse(mVals[i + 1]));
                    mPairs.Add(newPair);
                }

                fileOut.WriteLine("Case #" + (caseCount + 1) + ": " + Rec(nPairs, mPairs, 0, ""));
                //Console.WriteLine("\n\n\n");
            }

            // Close Reader/Writer
            fileIn.Close();
            fileOut.Close();
        }

        public static long Rec(List<MyPair> nP, List<MyPair> mP, long matches, string move)
        {
            if (nP.Count == 0 || mP.Count == 0)
            {
                //Console.WriteLine(move + "--- F: " + matches);
                
                return matches;
            }

            List<MyPair> nPairs = nP.Select(i => (MyPair)i.Clone()).ToList();
            List<MyPair> mPairs = mP.Select(i => (MyPair)i.Clone()).ToList();

            if (nPairs[0].Type == mPairs[0].Type)
            {
                long matched = Math.Min(nPairs[0].Count, mPairs[0].Count);
                nPairs[0].Count -= matched;
                mPairs[0].Count -= matched;

                if (nPairs[0].Count == 0)
                {
                    nPairs.RemoveAt(0);
                }
                if (mPairs[0].Count == 0)
                {
                    mPairs.RemoveAt(0);
                }

                //Console.WriteLine(move + "Matched (" + (matches + matched) + ")| ");
                return Rec(nPairs, mPairs, matches + matched, move + "Matched (" + (matches + matched) + ")| ");
            }
            else
            {
                //Console.WriteLine(move + "Dropped N |");
                long nDropped = Rec(nPairs.GetRange(1, nPairs.Count - 1), mPairs, matches, move + "Dropped N | ");
                //Console.WriteLine(move + "Dropped M |");
                long mDropped = Rec(nPairs, mPairs.GetRange(1, mPairs.Count - 1), matches, move + "Dropped M | ");

                return Math.Max(nDropped, mDropped);
            }
        }

    }
}
