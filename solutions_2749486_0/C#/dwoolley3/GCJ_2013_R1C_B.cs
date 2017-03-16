using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_R1C_B
    {
        static int[] dx = { 1, 0, -1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        static char[] d = { 'E', 'N', 'W', 'S' };
        static int X, Y;
        static string ans;

        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_B_sm.txt");
            TextWriter writer = new StreamWriter("../../output_B_sm.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                string[] s = reader.ReadLine().Split();
                X = int.Parse(s[0]);
                Y = int.Parse(s[1]);
                ans = "";

                int xNum = Math.Abs(X) * 2 - 1;
                for (int i = 0; i < xNum; i++)
                {
                    if (X > 0)
                        if (i % 2 == 0) ans += "E"; else ans += "W";
                    else
                        if (i % 2 == 0) ans += "W"; else ans += "E";
                }

                int yNum = Math.Abs(Y) * 2;
                for (int i = 0; i < yNum; i++)
                {
                    if (Y > 0)
                        if (i % 2 == 0) ans += "S"; else ans += "N";
                    else
                        if (i % 2 == 0) ans += "N"; else ans += "S";
                }


                //move(0,0, 0, "");

                Console.WriteLine("Case #" + tc + ": " + ans);
                writer.WriteLine("Case #" + tc + ": " + ans);
            }

            reader.Close();
            writer.Close();
        }
        
        //static private void move(int x, int y, int inc, string sol)
        //{
        //    if (inc > 11) return;
        //    if (x == X && y == Y)
        //    {
        //        ans = sol;
        //        return;
        //    }

        //    inc++;
        //    int nx1, ny1;
        //    for (int i = 0; i < 4; i++)
        //    {
        //        nx1 = x + dx[i]*inc;
        //        ny1 = y + dy[i]*inc;
        //        move(nx1, ny1, inc, sol + d[i]);
        //    }
        //    return;
        //}

    }
}
