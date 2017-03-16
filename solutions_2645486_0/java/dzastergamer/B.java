   import java.io.*;
   import java.util.*;

    public class B 
   {
      public static PrintWriter out;
       public static void main(String[] args) throws Exception
      {
         BufferedReader in = new BufferedReader(new FileReader(new File("B.in")));
         out = new PrintWriter(new FileWriter(new File("B.out")));
      
         int testcases = Integer.parseInt(in.readLine());
         
         for(int cass = 1; cass <= testcases; cass++)
         {
            String[] input = in.readLine().split(" ");   
            int energy = Integer.parseInt(input[0]);
            int regen = Integer.parseInt(input[1]);
            int num = Integer.parseInt(input[2]);
            int[] worths = new int[num];
            input = in.readLine().split(" ");
            for(int i = 0; i < num; i++)
               worths[i] = Integer.parseInt(input[i]);
               
            out.println("Case #"+cass+": "+runProgram(energy,regen,num,worths));
         	
         }
      
      
         out.flush();
         out.close();
         System.exit(0);
      }
      
       public static int runProgram(int energy, int regen, int num, int[] values)
      {
         return recur(energy,regen,0,values,energy);
      }
      
       public static int recur(int e, int r, int ind, int[] values, int emax)
      {
         if(ind == values.length) 
            return 0;
         int max = 0;
         for(int espent = e; espent >= 0; espent--)
         {
            max = Math.max( max, espent*values[ind] + recur(Math.min(emax, e-espent+r), r, ind+1, values, emax));
         }
         return max;
      }
   }