
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class SheepLarge
{
 public static void main (String[] args) throws java.lang.Exception
 {
  // your code goes here
  Scanner input = new Scanner(System.in);
  int cases = Integer.parseInt(input.nextLine());

  for(int i=0;i<cases;i++)
  {

    long number = Long.parseLong(input.nextLine());
    Long temp;
    String answer = "INSOMNIA";
    int[] digits = new int[10];

    for(int j=1;j<101;j++)
    {
      temp = j*number;
      digits = getDigits(temp,digits);

      /*System.out.println(temp);
      for(int k=0;k<10;k++)
      {
        System.out.println(k+" "+digits[k]);
      }*/
      
      
      if(completeOrNot(digits))
      {
        answer = Long.toString(temp);
        break;
      }
    }

    System.out.println("Case #"+(i+1)+": "+answer);
  }
    
 }

 public static int[] getDigits(long num,int[] dig)
 {
    int index;
    while(num>=1)
    {
      index = (int)num%10;
      dig[index] = 1;
      num = num/10;
    }
    return dig;
 }
 
 public static boolean completeOrNot(int[] dig)
 {
   boolean complete = true;
   for(int l=0;l<10;l++)
   {
     if(dig[l]==0)
     {
       complete = false;
       break;
     }
   }
   
   return complete;
 }
}