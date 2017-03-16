/**
 * Author: Chan Jun Wei
 */

import java.io.FileReader;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.*;

public class PartElf
{
  static String fileName = "PartElf";
  static final String OUTPUT_VALID = "Case #%d: %d";
  static final String OUTPUT_INVALID = "Case #%d: impossible";
  
  private static long gcd(long a, long b){
    if (b == 0){
      return a;
    } else {
      return gcd(b, a % b);
    }
  }
  
  private static long calNoOfOneInBits(long number){
    long noOfOneInBits = 0;
    
    if (number == 1){
      return noOfOneInBits;
    }
    
    for (int i = 1; i < number; i *= 2){
      noOfOneInBits++;
    }
    //System.out.println(noOfOneInBits - 1);
    return noOfOneInBits - 1;
  }
  
  private static long calTwoPower(long number){
    long powerOfTwo = -1;
    long inc = 0;
    
    //System.out.println("number: " + number);
    while (number > 1){
      if (number % 2 == 0){
        inc++;
        number /= 2;
      } else {
        break;
      }
    }
    if (number > 1){
      powerOfTwo = -1;
    } else {
      powerOfTwo = inc;
    }
    return powerOfTwo;
  }
  
  public static void main( String [ ] args )
  {
    File file=new File(fileName + ".in");
    try
    {
      // Opening of files for input and output
      Scanner sc=new Scanner(file);
      PrintWriter writer = new PrintWriter(fileName + ".out");
      
      //Scanner sc = new Scanner(System.in);
      //PrintWriter writer = new PrintWriter(System.out);
            
      int T;
      long p, q;
      long noOfAncestors = 0;
      boolean isPossible;
      
      T = sc.nextInt();
      
      for (int cases = 1; cases <= T; cases++){
        String input = sc.next();
        String[] inputs = input.split("/");
        p = Long.parseLong(inputs[0]);
        q = Long.parseLong(inputs[1]);
        
        //System.out.println(p + " " + q);
        
        noOfAncestors = 0;
        isPossible = true;
        
        long hcf = gcd(p , q);
        p /= hcf;
        q /= hcf;
        
        //System.out.println(hcf);
        
        if (p == 1 && q == 1){
          noOfAncestors = 1;
          writer.println(String.format(OUTPUT_VALID, cases, noOfAncestors));
          continue;
        }
        
        q = calTwoPower(q);
        isPossible = isPossible && p % 2 == 1;
        isPossible = isPossible && q > 0;
        
        if (isPossible){
          //System.out.println("q: " + q);
          noOfAncestors = q - calNoOfOneInBits(p);
        } else {
          writer.println(String.format(OUTPUT_INVALID, cases));
          continue;
        }
        
        //System.out.println(noOfAncestors);
        
        isPossible = isPossible && noOfAncestors > 0;
        
        if (isPossible){
          writer.println(String.format(OUTPUT_VALID, cases, noOfAncestors));
        } else {
          writer.println(String.format(OUTPUT_INVALID, cases));
        }
      }
      
      sc.close();
      writer.close();
    }
    catch( Exception e )  
    { e.printStackTrace(System.out); }
    finally  
    {// Close the files if they have been opened.
      //file.delete();
    }
  }
}