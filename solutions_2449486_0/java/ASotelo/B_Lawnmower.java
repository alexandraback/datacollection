// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;

public class B_Lawnmower {
  // --------------------------------------------------------------------------------
  private static String ID="B";
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
      String line[]=reader.readLine().trim().split(" +");
      int N=Integer.parseInt(line[0]),M=Integer.parseInt(line[1]);
      int terrain[][]=new int[N][M],maxI[]=new int[N],maxJ[]=new int[M];
      for (int i=0; i<N; i++) {
        line=reader.readLine().trim().split(" +");
        for (int j=0; j<M; j++) {
          int value=Integer.parseInt(line[j]);
          terrain[i][j]=value;
          maxI[i]=Math.max(maxI[i],value);
          maxJ[j]=Math.max(maxJ[j],value);
        }
      }
      boolean ok=true;
      loop: for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
          if (Math.min(maxI[i],maxJ[j])!=terrain[i][j]) {
            ok=false;
            break loop;
          }
        }
      }
      output.println("Case #"+c+": "+(ok?"YES":"NO"));
    }
  }
}
