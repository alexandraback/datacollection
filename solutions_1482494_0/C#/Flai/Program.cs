using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        private const string inFilePath = @"A:\Users\Zeikko\Desktop\B-small-attempt8.in";
        private const string outFilePath = "C:\\file.out";

        public class Requirement : IComparable<Requirement>
        {
            public int Req1, Req2;
            public bool FirstTaken, SecondTaken;

            public Requirement(int req1, int req2)
            {
                this.Req1 = req1;
                this.Req2 = req2;
            }

            #region Implementation of IComparable<in Requirement>

            public int CompareTo(Requirement other)
            {
                int f = this.Req1.CompareTo(other.Req1);
                if (f == 0)
                {
                    return other.Req2.CompareTo(Req2);
                }

                return f;
            }

            #endregion

            public override string ToString()
            {
                return Req1 + " " + Req2;
            }
        }

        static void Main(string[] args)
        {
            var reader = OpenReader();
            var writer = OpenWriter();
            int cases = int.Parse(reader.ReadLine());

            int c = 1;
            while (c <= cases)
            {
                int levelCount = int.Parse(reader.ReadLine());

                List<Requirement> levels = new List<Requirement>(levelCount);

                for (int x = 0; x < levelCount; x++)
                {
                    string[] reqs = reader.ReadLine().Split(' ');

                    levels.Add(new Requirement(int.Parse(reqs[0]), int.Parse(reqs[1])));
                }

                levels.Sort();

                int stars = 0;
                int plays = 0;
                bool didntSuccesful = false;
                int secondsLeft = levels.Count;
                while (true)
                {
                    if (secondsLeft == 0)
                        break;

                    Requirement id;
                    if (TryGetTwoStar(levels, stars, out id))
                    {
                        if(id.FirstTaken)
                        {
                            stars += 1;                 
                        }
                        else
                        {
                            stars += 2;
                        }

                        levels.Remove(id);

                        secondsLeft--;
                        plays++;
                    }
                    else if (TryGetOneStar(levels, stars))
                    {
                        stars += 1;
                        plays++;
                    }
                    else
                    {
                        didntSuccesful = true;
                        break;
                    }
                }

                String s = "Case #" + c + ": " + (didntSuccesful ? "Too Bad" : plays.ToString());

                writer.WriteLine(s);
                c++;
            }
            writer.Flush();
        }

        public static bool TryGetTwoStar(List<Requirement> seconds, int stars, out Requirement id)
        {
            int bestOption = -1;
        
            for (int x = 0; x < seconds.Count; x++)
            {
                if (seconds[x].Req2 <= stars && !seconds[x].SecondTaken)
                {
                    if (bestOption == -1)
                        bestOption = x;
                    else
                    {
                        bool currTaken = seconds[bestOption].FirstTaken;
                        bool newTaken = seconds[x].FirstTaken;

                        if (currTaken && !newTaken)
                            bestOption = x;
                        else if (seconds[x].Req2 - seconds[x].Req1 < seconds[bestOption].Req2 - seconds[bestOption].Req1)
                            bestOption = x;

                    }

                }
            }

            if(bestOption != -1)
            {
                id = seconds[bestOption];
                id.SecondTaken = true;
                return true;
            }

            id = null;
            return false;
        }

        public static bool TryGetOneStar(List<Requirement> firsts, int stars)
        {
            for (int x = 0; x < firsts.Count; x++)
            {
                if (firsts[x].Req1 <= stars && !firsts[x].FirstTaken)
                {
                    firsts[x].FirstTaken = true;
                    return true;

                }
            }

            return false;
        }



        public static StreamReader OpenReader()
        {
            return new StreamReader(inFilePath);
        }

        public static StreamWriter OpenWriter()
        {
            return new StreamWriter(outFilePath) { AutoFlush = true };
        }
    }
}


/*
100
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6
 * 
1
0 2
9
10 11
12 14
5 8
3 16
2 15
4 13
0 7
1 6
9 17
 * 
6
0 0
7 8
7 11
0 6
0 1
6 7
1
0 1
7
0 13
0 3
0 4
0 7
0 2
0 6
0 1
4
4 7
3 5
0 2
1 6
1
0 2
8
7 13
2 5
0 5
5 13
3 9
11 15
1 10
7 11
8
2 2
0 12
14 15
0 3
7 13
7 7
5 7
5 12
2
0 1
2 3
1
0 0
5
0 4
0 1
0 9
0 4
0 3
9
12 13
0 12
9 12
3 9
0 9
0 12
0 8
0 4
8 13
10
3 7
16 16
9 13
1 7
2 3
7 13
14 17
5 7
0 5
12 16
1
0 1
3
0 3
3 3
0 3
3
0 2
0 2
0 1
1
0 1
7
6 8
0 4
8 12
10 12
2 7
1 5
2 9
7
11 12
3 7
7 10
3 3
9 12
0 1
2 7
3
1 2
0 1
1 3
5
1 1
7 7
3 7
0 3
1 7
3
0 5
3 4
1 2
7
5 5
12 12
8 10
0 2
8 10
3 5
0 2
1
0 2
6
4 5
3 6
3 11
0 3
0 10
7 8
7
548 1177
234 241
1531 1798
406 1227
667 902
286 369
484 1522
5
388 1403
96 364
868 984
34 34
538 1625
6
2 8
7 10
0 5
9 11
0 2
2 2
7
0 1
0 6
0 2
0 2
0 6
0 13
0 5
3
19 1645
638 649
1154 1563
1
0 0
3
744 1456
799 854
685 959
8
0 3
0 7
0 7
0 3
0 2
0 6
0 1
0 15
7
1 5
12 13
9 10
1 2
2 4
4 10
7 7
8
10 11
12 14
4 12
9 15
1 6
4 6
0 8
2 3
9
824 898
7 918
108 243
1621 1772
267 772
201 573
268 385
205 1074
855 1139
2
1 2
0 3
6
117 304
1000 1736
352 380
383 769
403 1404
391 473
10
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
2001 2001
4
2 4
0 3
2 5
2 3
7
7 10
7 8
2 11
1 2
4 7
5 7
0 7
4
201 1883
363 1392
189 435
55 1256
6
1054 1426
174 227
111 279
151 175
144 1502
1582 1717
2
1 3
0 3
9
8 12
2 3
7 10
0 6
14 15
4 5
1 11
13 16
9 17
1
0 1
4
217 477
943 1574
209 648
30 42
6
491 1985
172 737
631 1378
1115 1258
108 237
199 675
9
0 3
0 17
0 7
0 9
0 7
0 8
0 3
0 1
0 6
9
527 698
310 1349
14 290
81 1818
81 329
4 36
573 1936
69 133
438 1499
2
0 1
0 3
5
0 1
3 5
7 8
3 8
2 3
6
6 9
0 2
2 5
7 10
0 7
2 5
4
1 5
2 3
0 4
6 7
5
6 7
3 6
0 1
2 7
3 8
2
0 1
0 3
5
0 1
1 3
3 4
3 9
0 2
9
0 2
2 4
0 5
0 3
6 12
6 16
4 14
12 16
4 13
1
0 1
5
0 3
3 3
3 7
5 7
1 8
5
2 7
0 2
1 4
8 8
4 6
5
0 6
7 7
1 8
3 6
0 1
9
9 14
0 1
8 17
0 16
0 5
1 13
7 11
0 10
11 15
3
1 3
1 4
0 3
7
0 10
5 8
0 4
12 13
0 0
1 8
6 10
6
2 4
1 3
9 9
6 6
6 6
0 5
7
220 1290
918 1024
254 1252
1469 1680
970 1975
53 60
421 658
1
0 1
2
0 1
0 3
6
7 8
0 3
1 4
5 9
1 4
5 10
4
1 5
4 6
0 2
2 5
4
279 708
99 1256
287 498
852 1882
6
5 5
3 5
0 1
4 7
9 9
2 9
5
1 9
0 6
2 4
7 8
0 3
1
0 2
10
8 9
0 2
6 8
17 19
14 15
9 16
0 12
6 10
2 5
5 16
2
0 2
2 3
6
4 5
6 7
3 10
5 11
1 10
0 2
4
0 0
0 0
0 0
0 0
2
0 2
1 3
2
0 2
2 3
7
292 993
91 129
76 721
113 205
965 1642
574 987
725 912
5
0 9
0 5
0 1
0 2
0 5
8
0 7
3 4
0 6
2 11
13 14
1 7
7 9
11 13
2
0 2
1 3
6
2 2
4 4
9 10
0 10
0 4
4 8
4
0 2
0 7
0 3
0 1
6
4 6
8 9
3 10
1 2
0 7
5 11
10
2 15
11 19
3 13
7 10
1 17
12 14
0 9
5 8
16 18
4 6
1
0 1
8
0 15
0 5
0 6
0 8
0 1
0 5
0 2
0 4
3
0 2
0 3
2 5
2
0 2
1 3
2
0 0
0 4
5
6 6
2 6
2 5
2 3
0 2
691

*/