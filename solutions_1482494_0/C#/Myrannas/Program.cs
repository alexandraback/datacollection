using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using CodeJamTools;

namespace Round1ProblemB
{
    class Program {
        public static StreamWriter writer;

        static void Main(string[] args)
        {
            writer = new StreamWriter("debug.txt");
            new ProblemB().Run("in.txt");
            writer.Close();
        }
    }

    class ProblemB : CodeJamBase {
        protected override string RunTest(int index) {
            var levels = int.Parse(Lines[0]);
            var requiredRatings = Lines.Skip(1).Take(levels).Select(r =>
                                                                    {
                                                                        var a = r.Split(' ').Select(int.Parse).ToArray();
                                                                        return new Game(a[0], a[1]);
                                                                    }).ToList();

            Lines = Lines.Skip(levels + 1).ToArray();
            
            Program.writer.WriteLine("\n\r\n\r{0}", index);
            var notCompletedOne = new HashSet<Game>(requiredRatings);
            var notCompletedTwo = new HashSet<Game>(requiredRatings);

            var currentRating = 0;
            var gamesPlayed = 0;

//            while (notCompletedTwo.Count > 0) {
//                //Find a 2 star to complete
//                var two = notCompletedTwo.OrderBy(s => s.FinishedOne).FirstOrDefault(s => s.Two <= currentRating);
//                if (two != null) {
//                    if (two.FinishedOne) {
//                        currentRating++;
//                        Program.writer.WriteLine("{0}:{1} - {2},{3} + 1", two.One, two.Two, currentRating, 2);
//                    }
//                    else {
//                        currentRating += 2;
//                        Program.writer.WriteLine("{0}:{1} - {2},{3} + 2", two.One, two.Two, currentRating, 2);
//                        notCompletedOne.Remove(two);
//                    }
//                    gamesPlayed++;
//                    notCompletedTwo.Remove(two);
//                }
//                else {
//                    var one = notCompletedOne.FirstOrDefault(s => s.One <= currentRating);
//                    if (one != null) {
//                        currentRating++;
//                        one.FinishedOne = true;
//                        gamesPlayed++;
//                        Program.writer.WriteLine("{0}:{1} - {2},{3} + 1", one.One, one.Two, currentRating, gamesPlayed);
//                        notCompletedOne.Remove(one);
//                    }
//                    else {
//                        Program.writer.WriteLine("Too Bad");
//                        return "Too Bad";                        
//                    }
//                }
//            }

            while (requiredRatings.Count(s => ! s.FinishedTwo) > 0) {
                var two =
                    requiredRatings.FirstOrDefault(
                        s => s.Two <= currentRating && s.FinishedTwo == false && s.FinishedOne == false);

                if (two != null) {
                    currentRating+=2;
                    two.FinishedTwo = true;
                    two.FinishedOne = true;
                    gamesPlayed++;
                    continue;
                }

                var twoAlreadyOne 
                    = requiredRatings.FirstOrDefault(s => s.Two <= currentRating && s.FinishedTwo == false && s.FinishedOne == true);
                    
                if (twoAlreadyOne != null) {
                    currentRating += 1;
                    twoAlreadyOne.FinishedTwo = true;
                    gamesPlayed++;
                    continue;
                }

                var one =
                    requiredRatings.FirstOrDefault(
                        s => s.One <= currentRating && s.FinishedOne == false && s.FinishedTwo == false);

                if (one != null) {
                    currentRating++;
                    one.FinishedOne = true;
                    gamesPlayed++;
                    continue;
                }

                return "Too Bad";
            }
            
            return gamesPlayed.ToString();
        }
    }

    class Game {
        public int One;
        public int Two;

        public Game(int one, int two)
        {
            Two = two;
            One = one;
        }

        public bool FinishedOne;
        public bool FinishedTwo;
    }
}
