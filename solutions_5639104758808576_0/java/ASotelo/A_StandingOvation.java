// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class A_StandingOvation {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
  private static String STAGE="qualification";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      StringTokenizer st=new StringTokenizer(reader.readLine());
      Integer.parseInt(st.nextToken());
      char string[]=st.nextToken().toCharArray();
      int t=0,u=0;
      for (int i=0; i<string.length; i++) {
        if (t<i) {
          int j=i-t;
          u+=j;
          t+=j;
        }
        t+=string[i]-'0';
      }
      
      output.println("Case #"+c+": "+u);
    }
  }
}
