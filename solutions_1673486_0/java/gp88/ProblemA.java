package com.google.codejam._2012;

import java.io.File;
import java.text.DecimalFormat;
import java.util.Scanner;

public class ProblemA
{

   
   
   

   
   public void solveCases() throws Exception
   {
      Scanner s = new Scanner(new File("./input/A-small-attempt0.in"));
//      Scanner s = new Scanner(new File("./input/A-small.in"));
//      Scanner s = new Scanner(new File("./input/A-large.in"));

      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      int a = s.nextInt();
      int b = s.nextInt();
      
      double[] cc = new double[a];
      
      for(int i = 0; i < a; i++)
         cc[i] = s.nextDouble();

      // chance first wrong char
      double[] cfw = new double[a];
      // chance all correct
      double cac = 1;
      
      for(int i = 0; i < a; i++)
         cac *= cc[i];
      
      
      for(int i = 0; i < a; i++)
      {
         double chance = 1;
         
         for(int j = 0; j < i; j++)
            chance *= cc[j]; 

         chance *= (1 - cc[i]);
         
         cfw[i] = chance;
      }
      
      int[][] ks = new int[a+2][a];
      
      for(int i = 0; i < a + 2; i++)
      {
         if (i < a)
         {
            int cutoff = a - (i + 1);
            
            for(int j = 0; j < a; j++)
            {
               // backspaces
               int strokes = i + 1;
               if (j < cutoff )
               {
                  strokes += (b - a) + (i + 1) + 1 + b + 1; 
               }
               else
               {
                  strokes += (b - a) + i + 2; 
               }
               
               ks[i][j] = strokes; 
            }
         }
         else if (i == a)
         {
            for(int j = 0; j < a; j++)
               ks[i][j] = (b - a) + 1 + b + 1;
         }
         else if (i == a + 1)
         {
            for(int j = 0; j < a; j++)
               ks[i][j] = 1 + b + 1;
         }
      }
      
      double[] expected = new double[a+2];
      
      for(int i = 0; i < a + 2; i++)
      {
         for(int j = 0; j < a; j++)
            expected[i] += cfw[j] * ks[i][j]; 
         
         if (i < a)
         {
            expected[i] += cac * ((i + 1) + (b - a) + (i + 1) + 1);
         }
         else if (i == a)
         {
            expected[i] += cac * ((b - a) + 1);
         }
         else if (i == a + 1)
         {
            expected[i] += cac * (1 + b + 1);
         }         
      }

      double leastE = Double.MAX_VALUE;
      
      for(double e : expected)
         leastE = Math.min(e, leastE);
      
      DecimalFormat df = new DecimalFormat();
      df.setMinimumFractionDigits(6);
      df.setMaximumFractionDigits(6);
      
      System.out.println(df.format(leastE));
   }

   
   
   
   
   public static void main(String[] args)
   {
      ProblemA pa = new ProblemA();
      
      try
      {
         pa.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
