
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Coin
{
 public static void main (String[] args) throws java.lang.Exception
 {
  // your code goes here
  Scanner input = new Scanner(System.in);
  int cases = Integer.parseInt(input.nextLine());

  for(int i=0;i<cases;i++)
  {
    System.out.println("Case #"+(i+1)+": ");

    String data = input.nextLine();
    String[] nums = data.split(" ");

    int N,J,count=0,index=1;
    N = Integer.parseInt(nums[0]);
    J = Integer.parseInt(nums[1]);

    int[] powers = new int[16];
    powers[0] = 1;
    powers[15] = 1;

    long total,div;
    double mod;
    String answer = new String();
    String divisors = new String();

    while(count<50)
    {
      //generating binary combinations
      for(int j=1;j<=14;j++)
      {
        powers[j] = 0;
        mod = index%(Math.pow(2,j));
        if(mod>=(Math.pow(2,j)/2))
        {
          powers[j] = 1;
        }
      }

      answer = new String();
      for(int j=15;j>=0;j--)
      {
        answer = answer + Integer.toString(powers[j]);
      }

      //checking whether the numbers with diff bases are non-prime are not
      divisors = new String();
      for(int j=2;j<=10;j++)
      {
        total = 0;
        
        
        for(int l=0;l<16;l++)
        {
          total = total + powers[l]*((long)Math.pow(j,l));
          
        }
        //System.out.println("total "+total+" answer="+answer);
        div = getDivisor(total);
        if(div==-1)
        {
          index++;
          break;
        } else
        {
          divisors = divisors + Long.toString(div) + " ";
        }

        if(j==10 && div!=-1)
        {
          System.out.println(answer+" "+divisors);
          index++;
          count++;
        }

      }

    }
       
  }
   
 }

 public static long getDivisor(long num)
 {
  long temp = 2;
  boolean exist = false;
  while(temp<=Math.sqrt(num))
  {
    if(num%temp==0)
    {
      exist = true;
      break;
    }
    temp++;
  }

  if(exist)
  {
    return temp;
 }
  else
  {
    return -1;
  }
 }

}

