using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1CB
{
    class Program
    {


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\Users\Trevor\Downloads\input.txt");
            StreamWriter sw = new StreamWriter(@"C:\Users\Trevor\Downloads\output.txt");



            int count = int.Parse(sr.ReadLine());

            for (int x = 0; x < count; x++)
            {
                sw.Write("Case #" + (x + 1) + ": ");

                Do(sr, sw);
            }
            sw.Flush();
        }

        public static long destx;
        public static long desty;

        public class Move : IComparable
        {
            public int moves;

            public string path;

            public long x;

            public long y;

            private double _prediction = 0;

            public double GetPrediction()
            {
                if (_prediction == 0)
                {
                    long my_dist = (Math.Abs(x - destx) + Math.Abs(y - desty));
                    double n = (2 * moves + 1) / 2;
                    double prediction = Math.Sqrt(2 * my_dist + n * n) - n + moves;
                    _prediction = prediction;
                }
                return _prediction;
            }

            public int CompareTo(object obj)
            {
                Move other = (Move)obj;


                if (other.GetPrediction() < GetPrediction())
                    return 1;
                if (other.GetPrediction() > GetPrediction())
                    return -1;
                return 0;


            }

            public Move(long x, long y, int moves, string movelist)
            {
                this.x = x;
                this.y = y;
                this.moves = moves;
                this.path = movelist;
            }
        }


        public static void Do(StreamReader sr, StreamWriter sw)
        {
            string[] splitstr = sr.ReadLine().Split(' ');

            desty = long.Parse(splitstr[0]);
            destx = long.Parse(splitstr[1]);

            List<Move> queue = new List<Move>();

            Move tmp = new Move(0, 0, 0, "");
            queue.Add(tmp);


            int x = 0;
            int y = 0;
            string s = "";

            int moves = 1;
            if (destx < desty)
            {


                while (x != destx)
                {
                    bool down = x + moves > destx;
                    x += (down ? -1 : 1) * moves;
                    s += (down ? "S" : "N");
                    moves++;
                }

                while (y != desty)
                {
                    bool left = y + moves > desty;
                    y += (left ? -1 : 1) * moves;
                    s += (left ? "W" : "E");
                    moves++;
                }


                
            }
            else{

                while (y != desty)
                {
                    bool left = y + moves > desty;
                    y += (left ? -1 : 1) * moves;
                    s += (left ? "W" : "E");
                    moves++;
                }


                while (x != destx)
                {
                    bool down = x + moves > destx;
                    x += (down ? -1 : 1) * moves;
                    s += (down ? "S" : "N");
                    moves++;
                }

            }

            if (x != destx || y != desty)
            {
                Console.WriteLine("x and y don't match destination.");
            }

            int x2 = 0;
            int y2 = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s.Substring(i, 1) == "N")
                {
                    x2 += i + 1;
                }
                if (s.Substring(i, 1) == "S")
                    x2 -= i + 1;
                if (s.Substring(i, 1) == "E")
                    y2 += i + 1;
                if (s.Substring(i, 1) == "W")
                    y2 -= i + 1;
            }

            if (x2 != destx || y2 != desty)
            {
                Console.WriteLine("x and y don't match");
            }

            sw.WriteLine(s);
            return;

            while (true)
            {
                Move m = queue[0];
                queue.RemoveAt(0);

                if (m.x == destx && m.y == desty)
                {
                    sw.WriteLine(m.path);
                    return;
                }


                int len = m.moves + 1;

                tmp = new Move(m.x, m.y + len, len, m.path + "N");
                            queue.Add( tmp);
                tmp =(new Move(m.x, m.y - len, len, m.path + "S"));
                            queue.Add( tmp);

                tmp =(new Move(m.x + len, m.y, len, m.path + "E"));
                            queue.Add( tmp);

                tmp =(new Move(m.x - len, m.y, len, m.path + "W"));
                            queue.Add( tmp);

                            queue.Sort();
            }

        }
    }
}

