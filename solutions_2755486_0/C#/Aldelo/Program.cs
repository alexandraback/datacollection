using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamRound1C2013Console
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime start = DateTime.Now;

            //ProblemA_Consonants.Run("input.txt", "output.txt");
            //ProblemA_Consonants.Run("A-small-attempt0.in", "A-small-attempt0.out"); // pass correct
            //ProblemA_Consonants.Run("A-large.in", "A-large.out"); //cannot run in time

            //ProblemB_Pogo.Run("input.txt", "output.txt");
            //ProblemB_Pogo.Run("B-small-attempt0.in", "B-small-attempt0.out"); // mem exploded

            //ProblemB_Pogo_2ndAttempt.Run("input.txt", "output.txt");
            //ProblemB_Pogo_2ndAttempt.Run("B-small-attempt0.in", "B-small-attempt0.out"); //  ok didn't sent in time
            //ProblemB_Pogo_2ndAttempt.Run("B-small-attempt1.in", "B-small-attempt1.out"); // correct 

            //ProblemC_The_Great_Wall.Run("input.txt", "output.txt");
            //ProblemC_The_Great_Wall.Run("C-small-attempt0.in", "C-small-attempt0.out"); // not correct
            ProblemC_The_Great_Wall.Run("C-small-attempt1.in", "C-small-attempt1.out"); // not correct
            //ProblemC_The_Great_Wall.Run("inputLarge.txt", "output.txt"); //pass ?
            //ProblemC_The_Great_Wall.Run("C-large-1.in", "C-large-1.out"); // pass ?

                    

            DateTime stop = DateTime.Now;
            Console.Out.WriteLine(stop - start);
            Console.ReadLine();
        }

    }
}
