import java.util.*;
import java.io.*;

public class Recycle
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(new BufferedInputStream(System.in));
    int T = in.nextInt();
    for(int i=0; i <T;i++)
    {
      int A = in.nextInt();
      int B = in.nextInt();
      
      int x = A;
      int digits = 1;
      while(x >=10)
      {
        x = x/10;
        digits++;
      }
      //System.out.println("digits: " + digits);
      int sum = 0;
      int[] m = new int[digits-1];
      for(int k = 0; k < m.length; k++)
        m[k] = (k+1)*-1;
      
      for(int j = A; j < B; j++) 
      {
        //reset m 
        for(int k = 0; k < m.length; k++)
          m[k] = (k+1)*-1;
        
        //try every possible combination
        //count it if j < combo < B
        for(int k = 1; k < digits; k++)
        {
          int divisor = (int) Math.pow(10,k);
          int multiplier = (int)Math.pow(10,digits-k);
          int temp = (j%divisor)*multiplier + j/divisor;
          
          //if all digits the same skip
          String number = Integer.toString(temp);
          if(number.matches("^([0-9])\\1*$")) continue;
          
          if(temp > j && temp <= B) 
          {
            m[k-1] = temp;
            sum++;
          }
        }
        //if redundancy subtract
        Arrays.sort(m);
        for(int k = 1; k < m.length; k++)
          if(m[k] == m[k-1]) sum--;
      }
      System.out.printf("Case #%d: %d\n",i+1,sum);
    }
  }
}