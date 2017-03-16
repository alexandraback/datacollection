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
        result = "";
        int k = in.nextInt();
        int c = in.nextInt();
        int s = in.nextInt();
        for(int j=1; j<=s; j++) {
          result += " "+j;
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
