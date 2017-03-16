using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

namespace GCJ
{
    struct Hiker
    {
        public long initpos;
        public long sp;

        public long curPos(long t)
        {
            long moved = t/sp;
            initpos += moved;
            return (initpos % 720);
        }

        public long nextTimeAtPos(long pos, long t)
        {
            long diff = curPos(t) - pos;

            if (diff <= 0)
            {
                diff = 720 + diff;
            }

            return t + diff * sp;

        }
    }

    class Program
    {
        static List<Hiker> hikers = new List<Hiker>();
        static long maxHikerSp = 0;


        static long dfs(long hp, long t, long curEnc, long lastMove)
        {
            long minNextTime = long.MaxValue;
            foreach(var h in hikers)
            {
                if(hp == h.curPos(t))
                {
                    curEnc++;
                }

                minNextTime = Math.Min(minNextTime, h.nextTimeAtPos(hp, t));
            }

            if (curEnc >= hikers.Count)
            {
                return hikers.Count;
            }

            if(hp == 720)
            {
                return curEnc;
            }

            long moveForwardEnc = 0;
            foreach(var h in hikers)
            {
                if( hp + 1 == h.curPos(t + 1))
                {
                    moveForwardEnc++;
                }
            }

            if(moveForwardEnc == 0)
            {
                return dfs(hp + 1, t + 1, curEnc, t + 1);
            }
            else
            {
                return Math.Min(dfs(hp + 1, t + 1, curEnc, t + 1), dfs(hp, minNextTime, curEnc, lastMove));
            }
        }


        static void Main(string[] args)
        {

            Thread T = new Thread(() =>
                {
                    var root = @"D:\gcj\p3\";

                    string[] input = System.IO.File.ReadAllLines(root + "small.txt");
                    StreamWriter output = new StreamWriter(root + "out.txt");

                    long[] data = input.SelectMany(x => x.Split(' ').Select(y => long.Parse(y))).ToArray();
                    IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
                    scanner.MoveNext();
                    long numCases = scanner.Current;
                    for (int nc = 0; nc < numCases; ++nc)
                    {
                        hikers.Clear();
                        scanner.MoveNext();
                        long n = scanner.Current;
                        for (long i = 0; i < n; ++i)
                        {
                            scanner.MoveNext();
                            long d = scanner.Current;
                            scanner.MoveNext();
                            long h = scanner.Current;
                            scanner.MoveNext();
                            long s = scanner.Current;

                            for (long j = 0; j < h; j++)
                            {
                                hikers.Add(new Hiker() { initpos = d * 2, sp = s * 2 });
                            }
                        }
                        maxHikerSp = hikers.Max(x => x.sp);

                        var res = dfs(0, 0, 0, -1);

                        output.WriteLine("Case #{0}: {1}", nc + 1, res);
                        Console.WriteLine("Case #{0}: {1}", nc + 1, res);


                    }

                    output.Close();

                    string readOut = File.ReadAllText(root + "out.txt");
                    string pOut = File.ReadAllText(root + "outP.txt");

                    if (readOut.Equals(pOut))
                    {
                        Console.WriteLine("Match found");
                    }
                    else
                    {
                        Console.WriteLine("Match not found");
                        Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
                    }

                }, 1024 * 1024 * 50);
            T.Start();
         
        }
    }
}
