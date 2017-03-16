// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;

public class B_ManageYourEnergy {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt0";
  private static String STAGE="round1";
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
      String line1[]=reader.readLine().split(" "),line2[]=reader.readLine().split(" ");
      int E=Integer.parseInt(line1[0]),R=Integer.parseInt(line1[1]),N=Integer.parseInt(line1[2]),v[]=new int[N];
      for (int i=0; i<N; i++) {
        v[i]=Integer.parseInt(line2[i]);
      }
      long last[]=new long[E+1],current[]=new long[E+1],temp[]=null;
      for (int i=0; i<N; i++,temp=last,last=current,current=temp) {
        for (int e=0; e<=E; e++) {
          long w=last[Math.min(E,e+R)];
          current[e]=e>0?Math.max(w,current[e-1]+v[i]):w;
        }
      }
      long max=0L;
      for (int e=0; e<=E; e++) {
        max=Math.max(max,last[e]);
      }
      output.println("Case #"+c+": "+max);
    }
  }
}
