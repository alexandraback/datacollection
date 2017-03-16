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
    class SafetyInNumbers : CodeJamProblem
    {
        static void Main(string[] args)
        {
            new CodeJamConsole().Run(new SafetyInNumbers(), args);
            Console.ReadLine();
        }
        
        int[][] parents;
        bool[] visited;

        bool Search(int c)
        {
            foreach (var p in parents[c])
            {
                if (visited[p]) return true;
                visited[p] = true;
                if (Search(p)) return true;
            }
            return false;
        }

        public override void Solve(Scanner sc, TextWriter w)
        {
            var n = sc.ReadInt();
            parents = new int[n][];
            for (int i = 0; i < n; i++)
            {
                parents[i] = sc.ReadArrayInt().Skip(1).Select(x => x - 1).ToArray();
            }
            visited = new bool[n];
            for (int i = 0; i < n; i++)
            {
                Array.Clear(visited, 0, visited.Length);
                if (Search(i))
                {
                    w.WriteLine("Yes");
                    return;
                }
            }
            w.WriteLine("No");
        }
    }
}