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
    class BoxFactory : CodeJamProblem
    {
        static void Main(string[] args)
        {
            new CodeJamConsole().Run(new BoxFactory(), args);
            Console.ReadLine();
        }

        long[] boxNum;
        long[] boxType;
        long[] toyNum;
        long[] toyType;
        
        int n, m;
        long max = 0;
        void Search(int i, int j, long count, long boxOffset, long toyOffset)
        {
            if (i >= n || j >= m)
            {
                max = Math.Max(max, count);
                return;
            }
            if (boxType[i] == toyType[j])
            {
                if (boxNum[i] - boxOffset < toyNum[j] - toyOffset)
                {
                    Search(i + 1, j, count + boxNum[i] - boxOffset, 0, toyNum[j] - boxNum[i] + boxOffset);
                }
                else if (boxNum[i] - boxOffset > toyNum[j] - toyOffset)
                {
                    Search(i, j + 1, count + toyNum[j] - toyOffset, boxNum[i] - toyNum[j] + toyOffset, 0);
                }
                else
                {
                    Search(i + 1, j + 1, count + boxNum[i] - boxOffset, 0, 0);
                }
            }
            else
            {
                Search(i + 1, j, count, 0, toyOffset);
                Search(i, j + 1, count, boxOffset, 0);
            }
        }
        
        public override void Solve(Scanner sc, TextWriter w)
        {
            n = sc.ReadInt();
            m = sc.ReadInt();
            boxNum = new long[n];
            boxType = new long[n];
            toyNum = new long[m];
            toyType = new long[m];
            var line = sc.ReadArrayLong();
            for (int i = 0; i < n; i++)
            {
                boxNum[i] = line[2 * i];
                boxType[i] = line[2 * i + 1];
            }
            line = sc.ReadArrayLong();
            for (int i = 0; i < m; i++)
            {
                toyNum[i] = line[2 * i];
                toyType[i] = line[2 * i + 1];
            }
            max = 0;
            Search(0, 0, 0, 0, 0);
            w.WriteLine(max);
        }
    }
}