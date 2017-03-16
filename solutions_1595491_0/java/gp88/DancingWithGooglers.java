package com.google.codejam._2012;

import java.io.File;
import java.util.Scanner;

public class DancingWithGooglers
{

   int[][] maxScores;
   
   
   private void setup()
   {
      maxScores = new int[31][2];
      
      for(int i = 0; i <= 30; i++)
         maxScores[i][1] = -1;
      
      for(int score = 0; score <= 30; score++)
      {
         for(int s1 = 0; s1 <= 10; s1++)
            for(int s2 = 0; s2 <= 10; s2++)
               for(int s3 = 0; s3 <= 10; s3++)
               {
                  if (s1 + s2 + s3 != score)
                     continue;
                  
                  if (s1 > s2 || s1 > s3 || s2 > s3)
                     continue;
                  
                  if (Math.abs(s1 - s2) > 2 || Math.abs(s1 - s3) > 2 || Math.abs(s2 - s3) > 2)
                     continue;
                  
                  if (Math.abs(s1 - s2) == 2 || Math.abs(s1 - s3) == 2 || Math.abs(s2 - s3) == 2)
                     maxScores[score][1] = s3;
                  else
                     maxScores[score][0] = s3;
               }
      }
      
   }
   

   
   public void solveCases() throws Exception
   {
      setup();
      
      Scanner s = new Scanner(new File("./input/B-small-attempt0.in"));

      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      int n = s.nextInt();
      int sur = s.nextInt();
      int p = s.nextInt();

      int totSurprising = 0;
      int totalBest = 0;
      
      for(int i = 0; i < n; i++)
      {
         int score = s.nextInt();
         
         if (maxScores[score][0] >= p)
         {
            totalBest++;
            continue;
         }
         
         if (maxScores[score][1] != -1 && maxScores[score][1] >= p && totSurprising < sur)
         {
            totalBest++;
            totSurprising++;
         }
      }
      
      
      System.out.println(totalBest);
   }

   
   
   
   
   public static void main(String[] args)
   {
      DancingWithGooglers dwg = new DancingWithGooglers();
      
      try
      {
         dwg.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
