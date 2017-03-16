using System;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace pogo
{

    class Program
    {
        public static string name = "pogo";
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"C:\codejam\" + name + @"\input.txt");
            int cases = int.Parse(reader.ReadLine());

            StringBuilder result = new StringBuilder();

            for (int i = 0; i < cases; i++)
            {
                solveCase(result, i, reader);
            }

            reader.Close();

            StreamWriter sw = new StreamWriter(@"C:\codejam\" + name + @"\result.txt", false);
            sw.Write(result.ToString());
            sw.Flush();
            sw.Close();
        }

        public static void solveCase(StringBuilder result, int caseno, StreamReader reader)
        {

            string[] row = reader.ReadLine().Split(' ');

            int x = int.Parse(row[0]);
            int y = int.Parse(row[1]);

            for (int i = 1; i < 505; i += 10)
            {
                if (i > 500) i = 500;
                string res = solve(1, "", 0, 0, x, y, i);
                if (res != null)
                {
                    addResult(result, res.ToString(), caseno);
                    return;
                }
                if (i == 500) return;
            }
        
        }

        public static string solve(int c_turn, string current, int c_x, int c_y, int target_x, int target_y, int max)
        {
            if (target_x == c_x && target_y == c_y)
                return current;
            if (c_turn > max)
                return null;


                if (target_x != c_x)
                {
                    string west = solve(c_turn + 1, current + "W", c_x - c_turn, c_y, target_x, target_y, max);
                    if (west != null) return west;


                    string east = solve(c_turn + 1, current + "E", c_x + c_turn, c_y, target_x, target_y, max);
                    if (east != null) return east;
                }

                else
                {
                    string south = solve(c_turn + 1, current + "S", c_x, c_y - c_turn, target_x, target_y, max);
                    if (south != null) return south;

                    string north = solve(c_turn + 1, current + "N", c_x, c_y + c_turn, target_x, target_y, max);
                    if (north != null) return north;
                }
     

            return null;
        }

        public static void addResult(StringBuilder result, string result_to_add, int caseno)
        {
            result.AppendLine("Case #" + (caseno + 1) + ": " + result_to_add);
        }
    }
}
