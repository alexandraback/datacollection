
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Fractiles
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

    int K,C,S;
    K = Integer.parseInt(nums[0]);
    C = Integer.parseInt(nums[1]);
    S = Integer.parseInt(nums[2]);    

    System.out.print("Case #"+(i+1)+": ");
    for(int j=1;j<=S;j++)
    {
      System.out.print(j+" ");
    }

    System.out.println();
    
  }
    
 }
}

 