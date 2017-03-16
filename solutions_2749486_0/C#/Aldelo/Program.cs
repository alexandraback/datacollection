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
            //ProblemA_Consonants.Run("A-large.in", "A-large.out"); //pass cannot run in time

            //ProblemB_Pogo.Run("input.txt", "output.txt");
            //ProblemB_Pogo.Run("B-small-attempt0.in", "B-small-attempt0.out"); // mem exploded

            //ProblemB_Pogo_2ndAttempt.Run("input.txt", "output.txt");
            //ProblemB_Pogo_2ndAttempt.Run("B-small-attempt0.in", "B-small-attempt0.out"); //  ok didn't sent in time
            ProblemB_Pogo_2ndAttempt.Run("B-small-attempt1.in", "B-small-attempt1.out"); // incorrect for unknown reason

            //ProblemC_Fair_and_Square<long>.Run("input.txt", "output.txt");            
            //ProblemC_Fair_and_Square<long>.Run("inputLarge.txt", "output.txt"); //fail
            //ProblemC_Fair_and_Square<long>.Run("C-small-attempt0.in", "C-small-attempt0.out"); // pass correct
            //ProblemC_Box_Factory.Run("C-large.in", "C-large.out"); // fail

            //ProblemC_Fair_and_Square_Large1.Run("input.txt", "output.txt"); 
            //ProblemC_Fair_and_Square_Large1.Run("C-small-attempt0.in", "C-small-attempt00.out"); // pass correct
            //ProblemC_Fair_and_Square_Large1.Run("inputLarge.txt", "output.txt"); //pass ?
            //ProblemC_Fair_and_Square_Large1.Run("C-large-1.in", "C-large-1.out"); // pass ?

            //ProblemC_Fair_and_Square_Large2.Run("inputLarge.txt", "output.txt"); //pass ?
            //ProblemC_Fair_and_Square_Large2.Run("C-large-2.in", "C-large-2.out"); //not run in time actually not finish at all
            

            DateTime stop = DateTime.Now;
            Console.Out.WriteLine(stop - start);
            Console.ReadLine();
        }

    }
}
