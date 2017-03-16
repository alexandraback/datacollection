   import java.io.*;
   import java.util.*;

    public class A 
   {
      public static PrintWriter out;
       public static void main(String[] args) throws Exception
      {
         BufferedReader in = new BufferedReader(new FileReader(new File("A.in")));
         out = new PrintWriter(new FileWriter(new File("A.out")));
      
         int testcases = Integer.parseInt(in.readLine());
         
         for(int cass = 1; cass <= testcases; cass++)
         {
            String[] input = in.readLine().split(" ");   
            out.println("Case #"+cass+": "+runProgram(Integer.parseInt(input[0]),Integer.parseInt(input[1])));
         	
         }
      
      
         out.flush();
         out.close();
         System.exit(0);
      }
      
       public static int runProgram(int initialRadius, int totalPaint)
      {
         int cR = initialRadius;
         int count = 0;
         int paintLeft = totalPaint;
         while(true)
         {
            paintLeft -= (cR+1)*(cR+1)-cR*cR;
            if(paintLeft < 0)
               break;
            count++;
            cR+=2;
         }
         return count;
         
      }
   }