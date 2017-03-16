using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var local = false;

            var input = new Input();
            var output = new Output();

            if (local)
            {
                input.loadString(
                    @"3
1
3
4
1 2 1 2
1
4
");
            }
            else
            {
                input.loadFile(@"C:\Users\talal\Downloads\B-small-attempt2.in");
                output.setSaveFile(@"C:\Users\talal\Downloads\B-Small.out");
            }
        
            var testCaseCount = input.readInt();
            for (int testCaseIdx = 0; testCaseIdx < testCaseCount; testCaseIdx++)
            {
                //load info
                var D = input.readInt();
                var P = input.readIntArr();

                //Solve
                int result = -1;
                foreach (var i in P)
                {
                    result = Math.Max(result, i);
                }

                var timer = 2;
                while (timer < result)
                {
                    var total = 0;
                    foreach (var i in P)
                    {
                        total += (i - 1)/timer;
                    }
                    result = Math.Min(result, total + timer);
                    timer++;
                }

                output.writeLine(result.ToString());
            }
            output.end();
        }
    }
}
