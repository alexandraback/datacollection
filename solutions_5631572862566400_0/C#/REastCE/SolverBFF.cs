using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolverLib
{
   class Student
   {
      public Student Require;
      public List<Student> Fulfill = new List<Student>();
   }

   class SolverBFF : ISolver
   {
      private static char[] _splitCharSpace = new char[] { ' ' };
      
      public string Solve(string input)
      {
         string output = "";

         string[] inputSplit = input.Split('\n');

         string[] studentStrSplit = inputSplit[1].Split(_splitCharSpace, StringSplitOptions.RemoveEmptyEntries);

         int[] studentBffs = new int[studentStrSplit.Length];

         for (int i = 0; i < studentStrSplit.Length; i++)
         {
            studentBffs[i] = int.Parse(studentStrSplit[i]) - 1;
         }

         Dictionary<int, int> mutualBffs = new Dictionary<int, int>();

         for (int i = 0; i < studentBffs.Length; i++)
         {
            if (i == studentBffs[studentBffs[i]])
            {
               mutualBffs.Add(i, studentBffs[i]);
            }
         }

         bool[] taken = new bool[studentBffs.Length];
         bool[] bestTaken = new bool[studentBffs.Length];
         int bestLength = 0;

         // Find the longest chain
         for (int i = 0; i < studentBffs.Length; i++)
         {
            bool[] curTaken = new bool[studentBffs.Length];
            taken.CopyTo(curTaken, 0);

            int curLength = 0;
            int curStudent = i;

            while (!taken[curStudent])
            {
               curLength++;
               taken[curStudent] = true;
               curStudent = studentBffs[curStudent];
            }

            if (curLength > bestLength)
            {
               bestLength = curLength;
               bestTaken = curTaken;
            }
         }

         taken = bestTaken;

         return (bestLength + mutualBffs.Count / 2).ToString();         

         /*
         Student[] studentSet = new Student[studentStrSplit.Length];

         for (int i = 0; i < studentSet.Length; i++)
         {
            studentSet[i] = new Student();
         }

         for (int i = 0; i < studentSet.Length; i++)
         {
            int bff = int.Parse(studentStrSplit[i]);
            studentSet[i].Require = studentSet[bff];
            studentSet[bff].Fulfill.Add(studentSet[i]);
         }

         int bestCircle = 0;

         for (int i = 0; i < studentSet.Length; i++)
         {
            List<Student> curCircle = new List<Student>();

            Student curStudent = studentSet[i];

            while (!curCircle.Contains(curStudent))
            {
               curCircle.Add(curStudent);
               curStudent = curStudent.Require;

            }
            curCircle.Add(studentSet[i].Require);

            studentSet[i]
         }
           
         return output;
         */         
      }
   }
}
