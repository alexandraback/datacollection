
import java.util.*;
import java.math.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class CoinLarge
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

    int[] powers = new int[N];
    powers[0] = 1;
    powers[N-1] = 1;

    long total,div;
    double mod;
    String answer = new String();
    String divisors = new String();

    while(count<J)
    {
      //generating binary combinations
      for(int j=1;j<=(N-2);j++)
      {
        powers[j] = 0;
        mod = index%(Math.pow(2,j));
        if(mod>=(Math.pow(2,j)/2))
        {
          powers[j] = 1;
        }
      }

      answer = new String();
      for(int j=(N-1);j>=0;j--)
      {
        answer = answer + Integer.toString(powers[j]);
      }

      //checking whether the numbers with diff bases are non-prime are not
      divisors = new String();
      for(int j=2;j<=10;j++)
      {
        total = 0;
        
        
        for(int l=1;l<16;l++)
        {
          total = total + powers[l]*((long)Math.pow(j,l));
          
        }
        
        div = getDivisor(total,j);
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

 public static long getDivisor(long num,int digit)
 {
  long temp = 462;
  
  switch(digit)
  {
    case 2:
    temp = 3;
    break;

    case 3:
    temp = 2;
    break;

    case 4:
    temp = 5;
    break;
    
    case 5:
    temp = 2;
    break;

    case 6:
    temp = 7;
    break;

    case 7:
    temp = 2;
    break;

    case 8:
    temp = 3;
    break;

    case 9:
    temp = 2;
    break;

    case 10:
    temp = 11;
    break;

    default:
    System.out.println("Invalid Digit");
    break;

    
  }
  
  if(num%temp==0)
  {
    return temp;
  }
  else
  {
    return -1;
  }
  
 }

}

