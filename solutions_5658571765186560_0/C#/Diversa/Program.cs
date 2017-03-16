using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam2015
{
    class Program
    {
        static List<int> audienceList = new List<int>();
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("D-small-attempt7.in", FileMode.Open, FileAccess.Read);
            FileStream fs2 = new FileStream("output2.out", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs2);
            StreamReader sr = new StreamReader(fs);

            int T = int.Parse(sr.ReadLine());
            int ans = 0;
            string result;
            for (int i = 0; i < T; i++)
            {
                string[] inputs = sr.ReadLine().Split(' ');
                int X = int.Parse(inputs[0]);
                int R = int.Parse(inputs[1]);
                int C = int.Parse(inputs[2]);
                int aria = R * C;
                int difference = aria - X;
                /* if (difference != 0 && difference % X == 0)
                 {
                     result = "GABRIEL";
                 }
                 else
                 {
                     result = "RICHARD";
                 }
                 if (Math.Round(Math.Sqrt(X), 0) > R || Math.Round(Math.Sqrt(X), 0) > C)
                 {
                   //  result = "RICHARD";

                 }
                 if (Math.Max(R, C) <= X && Math.Min(R, C) <= (X / 2))
                 {
                  //   result = "RICHARD";
                 }
                 if (X == 4 && R+C<8 )
                 {
                     result = "RICHARD";
                 }*/
                result = "GABRIEL";

                if (X >= 7)
                {
                    result = "RICHARD";
                }
                else if (X > R && X > C)
                {
                    result = "RICHARD";
                }
                else if (R * C % X != 0)
                {
                    result = "RICHARD";
                }

                else if ((X + 1) / 2 > Math.Min(R, C))
                {
                    result = "RICHARD";
                }
                else if (X == 1 || X == 2 || X == 3)
                {
                    result = "GABRIEL";
                }
                else if (X == 4)
                {
                    if (Math.Min(R, C) > 2)
                    {
                        result = "GABRIEL";
                    }
                    else
                    {
                        result = "RICHARD";
                    }
                }
                else if (X == 5)
                {
                    if (Math.Min(R, C) == 3 && Math.Max(R, C) == 5)
                    {
                        result = "RICHARD";
                    }
                    else
                    {
                        result = "GABRIEL";
                    }

                }

                else if (X == 6)
                {
                    if (Math.Min(R, C) > 3)
                    {
                        result = "GABRIEL";
                    }
                    else
                    {
                        result = "RICHARD";
                    }

                }

                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, result));
            }
            sr.Close();
            sw.Close();
            fs.Close();
            fs2.Close();
        }
    }
}
