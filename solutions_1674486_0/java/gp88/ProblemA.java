package com.google.codejam._2012.round1c;

import java.io.File;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;

public class ProblemA
{

   
   
   

   
   public void solveCases() throws Exception
   {
      Scanner s = new Scanner(new File("./input/A-small-attempt1 (1).in"));
//      Scanner s = new Scanner(new File("./input/A-small.in"));
//      Scanner s = new Scanner(new File("./input/A-large.in"));

      
      int t = s.nextInt();
      s.nextLine();
      
      for(int i = 0; i < t; i++)
         solveProblem(s, i + 1);
   }

   
   class Node
   {
      Node(int n)
      {
         reached = new int[n];
      }
      
      int num;
      Vector<Node> from = new Vector<Node>();
      int[] reached;
   }

   
  
   private void solveProblem(Scanner s, int num)
   {
      System.out.print("Case #" + num + ": ");
      
      int n = s.nextInt();
      
      Node[] na = new Node[n];
      
      for(int i = 0; i < n ; i++)
      {
         na[i] = new Node(n);
         na[i].num = i;
      }
      
      for(int i = 0; i < n ; i++)
      {
         int ni = s.nextInt();
         
         for(int j = 0; j < ni; j++)
            na[i].from.add(na[s.nextInt()-1]);
      }

      HashSet<Node> heads = new HashSet<Node>();
      for(Node no : na)
         heads.add(no);
      
      for(Node no : na)
         heads.removeAll(no.from);
      
      for(Node h : heads)
         followPaths(h, h.num);
      
      for(Node no : na)
      {
         for(int r : no.reached)
         {
            if (r <= 1)
               continue;
            else
            {
               System.out.println("Yes");
               return;
            }
         }
      }
      
      System.out.println("No");
   }

   
   void followPaths(Node n, int h)
   {
      if (n.from.isEmpty())
      {
         n.reached[h]++;
         return;
      }
      
      for(Node f : n.from)
         followPaths(f, h);
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
