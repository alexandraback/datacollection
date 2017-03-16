package Round1A;

import java.io.*;
import java.util.*;

public class A
{
   public static void main(String[] args) throws IOException
   {

      Scanner scan = new Scanner(new File("a_large.in"));
      //System.setOut(new PrintStream(new File("a_large.out")));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int typed = scan.nextInt();
         int total = scan.nextInt();
         double ptyped = typed;
         double ptotal = total;
         double[] mistake = new double[typed];
         for (int i = 0; i < mistake.length; i++)
            mistake[i] = scan.nextDouble();
         
         double bestProbability = total+2;
         double prob = 1.0;
         for (int i = 0; i < mistake.length; i++)
         {
            prob *= (mistake[i]);
            double subProbability = 
                  prob * (ptyped-(i+1)+ptotal-(i+1)+1) + 
                  (1-prob) * (ptyped-(i+1)+ptotal-(i+1)+1+ptotal+1);
            bestProbability = Math.min(bestProbability, subProbability);
         }
         System.out.println("Case #" + z + ": " + bestProbability);
      }
      scan.close();

   }
}

