package com.google.codejam._2012;

import java.io.File;
import java.util.Scanner;

public class ProblemC
{

   
   
   

   
   public void solveCases() throws Exception
   {
      Scanner s = new Scanner(new File("./input/sample.txt"));
//    Scanner s = new Scanner(new File("./input/C-small.in"));
//    Scanner s = new Scanner(new File("./input/C-large.in"));


      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
   }

   
   
   
   
   public static void main(String[] args)
   {
      ProblemC pc = new ProblemC();
      
      try
      {
         pc.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
