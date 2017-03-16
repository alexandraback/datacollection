/*
 * Copyright 2012 @_catus <https://twitter.com/_catus>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Meow.CodeJam;

namespace Meow.Contest.GCJ2012.Round1B
{
    /// <summary>
    /// A simple class for solving one code jam problem.
    /// </summary>
    /// <remarks>
    /// This class needs a C# 4 compiler to compile.
    /// This class depends on Meow.CodeJam.dll. If you haven't recieved a copy of the library,
    /// you can download it at http://jam.shyc2001.com/lib/ .
    /// 
    /// To run the compiled program, use the following command-line.
    /// <![CDATA[
    /// /path/to/program <name> <mode> <attempt>
    /// ]]>
    /// name => the letter for the problem (A, B, C, ...).
    /// mode => sample/small/large
    /// attempt => the attempt count. -1 for practice.
    /// <example>
    /// The following command-line solves the first problem in GCJ 2012 QR.
    ///   SpeakingInTongues.exe A small 0
    /// (If you get it wrong, increase the attempt count for the next input.)
    /// </example>
    /// </remarks>
    class EqualSums : CodeJamProblem
    {
        static void Main(string[] args)
        {
            new CodeJamConsole().Run(new EqualSums(), args);
            Console.ReadLine();
        }

        IEnumerable<int> outputSet(int set, int[] a)
        {
            var pos = 1;
            for (int i = 0; i < a.Length; i++)
            {
                if ((pos & set) > 0)
                {
                    yield return a[i];
                }
                pos <<= 1;
            }
        }
        public override void Solve(Scanner sc, TextWriter w)
        {
            var n = sc.ReadInt();
            var s = sc.ReadArrayInt();
            var max = (1 << n);
            var sum = 0;
            var lastFlag = 0;
            Dictionary<int, int> values = new Dictionary<int, int>();
            
            w.WriteLine();

            for (int flags = 0; flags < max; flags++)
            {
                var pos = 1;
                for (int i = 0; i < n; i++)
                {
                    if ((pos & flags) > 0 && (pos & lastFlag) == 0)
                    {
                        sum += s[i];
                    }
                    else if ((pos & flags) == 0 && (pos & lastFlag) > 0)
                    {
                        sum -= s[i];
                    }
                    pos <<= 1;
                }
                int set;
                if (values.TryGetValue(sum, out set))
                {
                    w.WriteLine(string.Join(" ", outputSet(set, s)));
                    w.WriteLine(string.Join(" ", outputSet(flags, s)));
                    return;
                }
                else
                {
                    values.Add(sum, flags);
                }
                lastFlag = flags;
            }
            w.WriteLine("Impossible");
        }
    }
}