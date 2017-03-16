using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamManager
{
    class R1C_2_2013 : SolutionBase
    {
        int time;

        public override void ProcessOne(int processNumber, System.IO.StreamReader input, System.IO.StreamWriter output)
        {
            string reasult = "";
            int[] XY = ReadLineAsIntTable();

            time = 1;

            reasult += moveTo(0, XY[0],  'E', 'W');
            reasult += moveTo(0, XY[1], 'N', 'S');

            base.StoreResults(output, processNumber, reasult);

        }

        string moveTo(int start, int finish, char to, char from)
        {
            
            string result = "";
            int s = Math.Sign(finish - start);
            while (start != finish)
            {
                if (Math.Abs(finish - start) < time) // move avay from finist
                {
                    start -= s * time;
                    result += s < 0 ? to : from;
                }
                else
                {
                    start += s * time;
                    result += s > 0 ? to : from;
                }
                time++;
            }
            return result;
        }
    }
}
