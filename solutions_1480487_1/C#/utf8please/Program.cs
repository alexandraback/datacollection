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
    class KingdomRush : CodeJamProblem
    {
        static void Main(string[] args)
        {
            new CodeJamConsole().Run(new KingdomRush(), args);
            Console.ReadLine();
        }

        class HeapKey : IComparable<HeapKey>
        {
            public HeapKey(Int32 value)
            {
                Id = Guid.NewGuid();
                Value = value;
            }

            public Guid Id { get; private set; }
            public Int32 Value { get; private set; }

            public int CompareTo(HeapKey other)
            {
                if (other == null) throw new ArgumentNullException("other");

                var result = Value.CompareTo(other.Value);

                return result == 0 ? Id.CompareTo(other.Id) : result;
            }
            public override string ToString()
            {
                return string.Format("{0} {{ {1} }}", Value, Id);
            }
        }

        class HeapKey2 : IComparable<HeapKey2>
        {
            public HeapKey2(Int32 value)
            {
                Id = Guid.NewGuid();
                Value = value;
            }

            public Guid Id { get; private set; }
            public Int32 Value { get; private set; }

            public int CompareTo(HeapKey2 other)
            {
                if (other == null) throw new ArgumentNullException("other");

                var result = -Value.CompareTo(other.Value);

                return result == 0 ? Id.CompareTo(other.Id) : result;
            }
            public override string ToString()
            {
                return string.Format("{0} {{ {1} }}", Value, Id);
            }
        }
        class Level
        {
            public int Stars;
            public int OneStarRequirement;
            public HeapKey2 OptionalKey;
        }
        public override void Solve(Scanner sc, TextWriter w)
        {
            var n = sc.ReadInt();

            Level[] levels = new Level[n];
            
            SortedList<HeapKey, int> mustPlay = new SortedList<HeapKey, int>();
            SortedList<HeapKey2, int> optionalPlay = new SortedList<HeapKey2, int>();

            for (int i = 0; i < n; i++)
            {
                var p = sc.ReadArrayInt();
                levels[i] = new Level
                {
                    Stars = 2,
                    OneStarRequirement = p[0]
                };
                mustPlay.Add(new HeapKey(p[1]), i);
                if (p[0] < p[1]) 
                    optionalPlay.Add(levels[i].OptionalKey = new HeapKey2(p[1]), i);
            }

            var gameCount = 0;
            var stars = 0;

            while (mustPlay.Count > 0 || optionalPlay.Count > 0)
            {
                KeyValuePair<HeapKey, int> first;
                while (mustPlay.Count > 0 && (first = mustPlay.First()).Key.Value <= stars)
                {
                    stars += levels[first.Value].Stars;
                    if (levels[first.Value].OptionalKey != null)
                    {
                        optionalPlay.Remove(levels[first.Value].OptionalKey);
                    }
                    mustPlay.RemoveAt(0);
                    gameCount++;
                }
                if (mustPlay.Count == 0 && optionalPlay.Count == 0) break;

                HeapKey2 pendingRemoval = null;
                foreach (var pair in optionalPlay)
                {
                    if (levels[pair.Value].OneStarRequirement > stars) continue;
                    levels[pair.Value].Stars--;
                    stars++;
                    levels[pair.Value].OptionalKey = null;
                    pendingRemoval = pair.Key;
                    goto next;
                }

                w.WriteLine("Too Bad");
                return;

            next:
                gameCount++;
                if (pendingRemoval != null) optionalPlay.Remove(pendingRemoval);
            }
            w.WriteLine(gameCount);
        }
    }
}