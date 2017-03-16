using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace P_D
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var local = false;

            var input = new Input();
            var output = new Output();

            if (local)
            {
                input.loadString(
                    @"4
2 2 2
2 1 3
4 4 1
3 2 3
");
            }
            else
            {
                input.loadFile(@"C:\Users\talal\Downloads\D-small-attempt0.in");
                output.setSaveFile(@"C:\Users\talal\Downloads\D-Small-0.out");
            }

            var testCaseCount = input.readInt();
            for (int testCaseIdx = 0; testCaseIdx < testCaseCount; testCaseIdx++)
            {
                //load info
                var dataArr = input.readIntArr();
                var x = dataArr[0];
                var r = dataArr[1];
                var c = dataArr[2];

                //analize
                bool canFill = true;

                if (
                    x > 6 ||
                    r * c % x != 0 ||
                    x > r && x > c ||
                    (x + 1)/2 > Math.Min(r, c) ||
                    false
                    )
                    canFill = false;

                else if (x < 4)
                    canFill = true;

                else if (x == 4)
                    canFill = Math.Min(r, c) > 2;

                else if (x == 5)
                {
                    if (Math.Min(r, c) == 3 && Math.Max(r, c) == 5)
                        canFill = false;
                    else
                        canFill = true;
                }

                else if (x == 6)
                    canFill = Math.Min(r, c) > 3;

                output.writeLine(canFill ? "Gabriel" : "Richard");
            }
            output.end();
        }
    }
}