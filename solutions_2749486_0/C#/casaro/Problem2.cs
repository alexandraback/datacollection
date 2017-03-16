using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Problem2
    {
        static StreamReader Input;
        static StreamWriter Output;

        static int n;

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());

            for (int tc = 1; tc <= testcases; tc++)
            {
                string[] input = Input.ReadLine().Split(' ');

                int x = Convert.ToInt32(input[0]);
                int y = Convert.ToInt32(input[1]);

                n = 1;
                string xPath = SolveX(0, x, new StringBuilder());
                string yPath = SolveY(0, y, new StringBuilder());

                Output.WriteLine("Case #{0}: {1}", tc, xPath + yPath);
            }

            Output.Close();
        }

        static string SolveX(int position, int target, StringBuilder moves)
        {
            if (position == target)
            {
                return moves.ToString();
            }
            else if (position < target)
            {
                moves.Append('W');
                position -= n;
                ++n;
                moves.Append('E');
                position += n;
                ++n;
                return SolveX(position, target, moves);
            }
            else
            {
                moves.Append('E');
                position += n;
                ++n;
                moves.Append('W');
                position -= n;
                ++n;
                return SolveX(position, target, moves);
            }
        }

        static string SolveY(int position, int target, StringBuilder moves)
        {
            if (position == target)
            {
                return moves.ToString();
            }
            else if (position > target)
            {
                moves.Append('N');
                position += n;
                ++n;
                moves.Append('S');
                position -= n;
                ++n;
                return SolveY(position, target, moves);
            }
            else
            {
                moves.Append('S');
                position -= n;
                ++n;
                moves.Append('N');
                position += n;
                ++n;
                return SolveY(position, target, moves);
            }
        }
    }
}
