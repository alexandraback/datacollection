package com.google.codejam._2012;

import java.io.File;
import java.util.Scanner;

public class ProblemB
{
   int[][] levelInfo;
   
   

   
   public void solveCases() throws Exception
   {
//      Scanner s = new Scanner(new File("./input/sample.txt"));
    Scanner s = new Scanner(new File("./input/B-small-attempt0.in"));
//    Scanner s = new Scanner(new File("./input/B-large.in"));


      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      int n = s.nextInt();
      levelInfo = new int[n][3];
      
      for(int i = 0; i < n; i++)
      {
         levelInfo[i][0] = s.nextInt();
         levelInfo[i][1] = s.nextInt();
      }
      
      int starsEarned = 0;
      int levelsComplete = 0;
      int levelsAt2 = 0;
      
      while(levelsAt2 < n)
      {
         boolean did2 = false;
         
         for(int i = 0; i < n; i++)
         {
            if (levelInfo[i][1] <= starsEarned && levelInfo[i][2] != 2)
            {
               starsEarned += 2 - levelInfo[i][2];
               levelsAt2++;
               levelsComplete++;
               levelInfo[i][2] = 2;
               did2 = true;
            }
         }

         if (did2)
            continue;
         
         // greatest diff level 2
         int gdl = -1;
         // max star diff from my stars to required level 2 stars
         int msd = -1;

         for(int i = 0; i < n; i++)
         {
            if (levelInfo[i][2] == 0)
            {
               if (levelInfo[i][0] <= starsEarned)
               {
                  int diff = levelInfo[i][1] - starsEarned;
                  if (diff > msd)
                  {
                     msd = diff;
                     gdl = i;
                  }
               }
            }
         }
         
         if (gdl == -1)
         {
            System.out.println("Too Bad");
            return;
         }
         
         starsEarned++;
         levelsComplete++;
         levelInfo[gdl][2] = 1;
      }
      
      System.out.println(levelsComplete);
      
   }

   
   
   
   
   public static void main(String[] args)
   {
      ProblemB pb = new ProblemB();
      
      try
      {
         pb.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
