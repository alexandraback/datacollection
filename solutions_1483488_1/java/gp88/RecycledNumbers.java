package com.google.codejam._2012;

import java.io.File;
import java.util.HashSet;
import java.util.Scanner;

public class RecycledNumbers
{

   
   private void setup()
   {
   }
   

   
   public void solveCases() throws Exception
   {
      setup();
      
      Scanner s = new Scanner(new File("./input/C-large.in"));

      
      int t = s.nextInt();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      int a = s.nextInt();
      int b = s.nextInt();
      
      int count = 0;
      
      HashSet<String> used = new HashSet<String>();
      
      for(int n = a; n < b; n++)
      {
         used.clear();
         String ns = Integer.toString(n);
         
         for(int split = 1; split < ns.length(); split++)
         {
            String ms = ns.substring(split) + ns.substring(0, split);
            
            if (ms.startsWith("0"))
               continue;
            
            if (used.contains(ms))
               continue;
            
            int m = Integer.parseInt(ms);
            
            if (m > n && m <= b)
            {
               used.add(ms);
               count++;
            }
               
               
         }
      }
      
      
      
      System.out.println(count);
   }

   
   
   
   
   public static void main(String[] args)
   {
      RecycledNumbers rn = new RecycledNumbers();
      
      try
      {
         rn.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
