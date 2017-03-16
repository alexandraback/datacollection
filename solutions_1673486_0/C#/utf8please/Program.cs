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

namespace Meow.Contest.GCJ2012.QualificationRound
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
    class PasswordProblem : CodeJamProblem
    {
        static void Main(string[] args)
        {
            new CodeJamConsole().Run(new PasswordProblem(), args);
            Console.ReadLine();
        }
        public override void Solve(Scanner sc, TextWriter w)
        {
            var a = sc.ReadInt();
            var b = sc.ReadInt();
            var p = sc.ReadArrayDecimal();

            int keystrokesLeft = b - a + 1;

            var giveUpExpected = a + 1;

            decimal minExpect = giveUpExpected;

            decimal allCorrect = 1;
            for (int back = a; back >= 0; back--)
            {
                decimal right = allCorrect * back * 2;
                decimal wrong = (1 - allCorrect) * (back * 2 + keystrokesLeft + giveUpExpected - 1);
                minExpect = Math.Min(right + wrong, minExpect);
                if (back > 0) allCorrect = allCorrect * p[a - back];
            }

            w.WriteLine("{0:0.000000}", minExpect + keystrokesLeft);
        }
    }
}