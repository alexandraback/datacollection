package jam2016;

import java.util.*;
import java.io.*;
import java.lang.invoke.MethodHandles;
/**
 *
 * @author David
 */
public class QualB {
  public static void main(String[] args) {
    try {
      String input = "inputs/"+MethodHandles.lookup().lookupClass().getName();
      input = input.replace(".", "/");
      Scanner in = new Scanner(new File(input+".in"));
      FileWriter out = new FileWriter(new File(input+".out"));
      int t = in.nextInt();
      
      for(int i=1; i<=t; i++) {
        int result = 0;
        char[] stack = in.next().toCharArray();
        for(int j=0; j<stack.length-1; j++) {
          if (stack[j]!=stack[j+1]) {
            flip(stack, j+1);
            result++;
          }
        }
        if (stack[0]=='-') result++;
        print(stack);
        System.out.println("Case #"+i+": "+result);
        out.write("Case #"+i+": "+result+"\n");
      }
      out.close();
      
    } catch(Exception e) {
      e.printStackTrace();
    }
  }
  
  static void flip(char[] stack, int position) {
    
    for(int j=0; j<position; j++) {
      if (stack[j]=='+') stack[j] = '-';
      else stack[j] = '+';
    }
    if (position<2) return;
    int mid = (int)Math.ceil(position/2.0);
    for(int j=0; j<mid; j++) {
      //System.out.println("swap "+j+" position: "+position+"  mid:"+mid);
      char tmp = stack[j];
      stack[j] = stack[position-j-1];
      stack[position-j-1] = tmp;
      //print(stack);
    }
  }
  static void print(char[] stack) {
    for(int j=0; j<stack.length; j++) {
      System.out.print(stack[j]);
    }
    System.out.println();
  }
  
}
