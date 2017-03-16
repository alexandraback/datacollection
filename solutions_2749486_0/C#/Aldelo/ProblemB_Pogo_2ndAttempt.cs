using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1C2013Console
{
    class ProblemB_Pogo_2ndAttempt
    {

        public static void Run(string fname, string ofname)
        {
            string[] solution = ReadProblemA(fname);

            string[] output = new string[solution.Length];
            for (int i = 0; i < solution.Length; i++)
            {
                output[i] = String.Format("Case #{0}: {1}", i + 1, solution[i]);

                Console.Out.WriteLine(output[i]);

            }
            Helpers.IO.WriteOutput(ofname, output.Length, output);

            //Console.ReadLine();
        }

        public static string[] ReadProblemA(string fname)
        {
            string[] outputStr = null;
            int inputlength = 0;
            int count = 0;
            StreamReader fr = new StreamReader("..\\..\\" + fname);
            while (!fr.EndOfStream)
            {
                if (inputlength == 0) // read total case
                {
                    string s = fr.ReadLine();
                    inputlength = Convert.ToInt32(s);
                    outputStr = new string[inputlength];
                }
                else
                {
                    /*
                     *  2
                        3 4
                        -3 4
                     */
                    PogoCase input = new PogoCase();
                    string[] temp = fr.ReadLine().Split(' ');
                    input.x = Convert.ToInt32(temp[0]);
                    input.y = Convert.ToInt32(temp[1]);

                    outputStr[count] = AnswerOfCase(input);

                    ++count;
                }
            }
            fr.Close();
            return outputStr;
        }

        public class PogoCase
        {
            public int x;
            public int y;
            public string path;

            public PogoCase moveEast(int move)
            {
                return new PogoCase { x = this.x + move, y = this.y, path = this.path + "E" };
            }
            public PogoCase moveWest(int move)
            {
                return new PogoCase { x = this.x - move, y = this.y, path = this.path + "W" };
            }
            public PogoCase moveNorth(int move)
            {
                return new PogoCase { x = this.x, y = this.y + move, path = this.path + "N" };
            }
            public PogoCase moveSouth(int move)
            {
                return new PogoCase { x = this.x, y = this.y - move, path = this.path + "S" };
            }

            public bool correctPoint(PogoCase c)
            {
                return c.x == this.x && c.y == this.y;
            }
        }

        private static string AnswerOfCase(PogoCase c)
        {
            string ret = "";
            PogoCase start = new PogoCase { x = 0, y = 0, path = "" };
            Queue<PogoCase> allMove = new Queue<PogoCase>();            
            int move = 1;
            if (c.x > 0)
            {
                while (c.x > start.x)
                {
                    start = start.moveEast(move);
                    move++;
                }
            }
            else
            {
                while (c.x < start.x)
                {
                    start = start.moveWest(move);
                    move++;
                }
            }
            if (c.y > 0)
            {
                while (c.y > start.y)
                {
                    start = start.moveNorth(move);
                    move++;
                }
            }
            else
            {
                while (c.y < start.y)
                {
                    start = start.moveSouth(move);
                    move++;
                }
            }

            allMove.Enqueue(start);
            while (true)
            {
                Queue<PogoCase> newQueue = new Queue<PogoCase>();
                while (allMove.Count > 0)
                {                    
                    PogoCase a = allMove.Dequeue();
                    if (c.correctPoint(a))
                    {
                        if (a.path.Length <= 500)
                        return a.path;
                    }
                    newQueue.Enqueue(a.moveEast(move));
                    newQueue.Enqueue(a.moveWest(move));
                    newQueue.Enqueue(a.moveNorth(move));
                    newQueue.Enqueue(a.moveSouth(move));
                }
                move++;
                allMove = newQueue;
            }            
        }

    }
}
