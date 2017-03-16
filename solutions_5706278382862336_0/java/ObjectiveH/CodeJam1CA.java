import java.util.*;
import java.io.*;

public class CodeJam1CA
{
   public static void main(String[] args)
   {
      Scanner s = new Scanner(System.in);
      
      int T = s.nextInt();
      s.nextLine();
      for(int t = 1; t<=T; t++)
      {
         String line = s.nextLine();
         
         String[] nums = line.split("/");  
         int P = Integer.parseInt(nums[0]);
         int Q = Integer.parseInt(nums[1]);
         
         double ones = P*Math.pow(2,40)/Q;
         
         if(Math.floor(ones) == ones)
         {
            System.out.printf("Case #%d: %d\n", t, 40-(int)(Math.log(ones)/Math.log(2)));
         }
         else
         {
            System.out.printf("Case #%d: impossible\n", t);
         }
         
      }
   }
}