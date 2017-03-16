package com.google.codejam._2012;

import java.io.File;
import java.util.Scanner;

public class SpeakingInTongues
{
   char[] map = 
   { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 
     'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
   };
   
   
   private void setup()
   {
   }
   

   
   public void solveCases() throws Exception
   {
      setup();
      
      Scanner s = new Scanner(new File("./input/A-small-attempt3.in"));

      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      String text = s.nextLine();
      
      for(char c : text.toCharArray())
      {
         if (c == ' ')
            System.out.print(c);
         else
            System.out.print(map[c - 97]);
      }
      
      System.out.println();
   }

   
   
   
   
   public static void main(String[] args)
   {
      SpeakingInTongues sit = new SpeakingInTongues();
      
      try
      {
         sit.solveCases();
      }
      catch (Exception e)
      {
         e.printStackTrace();
      }
      
   }
}
