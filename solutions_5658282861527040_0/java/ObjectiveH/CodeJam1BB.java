import java.util.*;
import java.io.*;

public class CodeJam1BB
{
   public static void main(String[] args)
   {
      Scanner s = new Scanner(System.in);
      
      int T = s.nextInt();
      
      for(int t = 1; t<=T; t++)
      {
         int A = s.nextInt();
         int B = s.nextInt();
         int K = s.nextInt();
         
         ArrayList<Integer> possible = new ArrayList<Integer>();
         
         for(int i = 0; i<A; i++)
         {
            for(int j = 0; j<B; j++)
            {
               possible.add(i&j);
            }
         }
         
         int count = 0;
         for(Integer i: possible)
         {
            if(i<K)
               count++;
         }
         System.out.printf("Case #%d: %d\n", t, count);
      }
   }
}