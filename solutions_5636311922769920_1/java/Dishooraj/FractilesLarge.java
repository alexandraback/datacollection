
import java.util.*;
import java.math.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class FractilesLarge
{
 public static void main (String[] args) throws java.lang.Exception
 {
  // your code goes here
  Scanner input = new Scanner(System.in);
  int cases = Integer.parseInt(input.nextLine());

  for(int i=0;i<cases;i++)
  {

    String data = input.nextLine();
    String[] nums = data.split(" ");

    double K,C,S;
    K = Double.parseDouble(nums[0]);
    C = Double.parseDouble(nums[1]);
    S = Double.parseDouble(nums[2]);   
    long[][] positions = new long[(int)S][(int)C];
    int counter = 1;
    int minPositions = (int)Math.ceil(K/C);

    System.out.print("Case #"+(i+1)+": ");
    
    if(S<K/C)
    {
      System.out.print("IMPOSSIBLE");
    }
    else
    {
      for(int j=0;j<minPositions;j++)
      {
        for(int k=0;k<C;k++)
        {
          positions[j][k] = counter;
          counter++;
          if(counter>K)
          {
            counter = 1;
          }
        }
        
      }
      
      for(int j=0;j<minPositions;j++)
      {
        BigInteger position = BigInteger.ZERO;
        for(int k=0;k<C;k++)
        {
          if(k<(C-1))
          {
          
            position = position.add(BigInteger.valueOf((positions[j][k]-1)*(long)Math.pow(K,C-k-1)));
           
          }
          else
          {
            position = position.add(BigInteger.valueOf(positions[j][k]));
           
          }
        }
        System.out.print(position+" ");
      }

    }

      
    System.out.println();
    
  }
    
 }
}

 