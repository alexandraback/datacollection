package jam2016;

import java.util.*;
import java.io.*;
import java.lang.invoke.MethodHandles;
/**
 *
 * @author David
 */
public class QualD {
  public static void main(String[] args) {
    try {
      String input = "inputs/"+MethodHandles.lookup().lookupClass().getName();
      input = input.replace(".", "/");
      Scanner in = new Scanner(new File(input+".in"));
      FileWriter out = new FileWriter(new File(input+".out"));
      int t = in.nextInt();
      for(int i=1; i<=t; i++) {
        String result = " IMPOSSIBLE";
        int k = in.nextInt();
        int c = in.nextInt();
        int s = in.nextInt();
        
        int start = 1;
        if (k>1 && c>1) start = 2; // complexity > 1 must start with G so we can skip that
        //if (k==2 && c>1 && s==1) start=1;
        
        if (k<=s+start-1) { // not enough students
          result = "";
          for(int j=start; j<=k; j++) {
            result += " "+j;
          }
        }
        System.out.println("Case #"+i+":"+result);
        out.write("Case #"+i+":"+result+"\n");
      }
      out.close();
      
    } catch(Exception e) {
      e.printStackTrace();
    }
  }

}
