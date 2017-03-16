// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class B_NewLotteryGame {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt0";
  private static String STAGE="round1b";
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
      StringTokenizer tokenizer=new StringTokenizer(reader.readLine());
      long A=Long.parseLong(tokenizer.nextToken());
      long B=Long.parseLong(tokenizer.nextToken());
      long K=Long.parseLong(tokenizer.nextToken());
      output.println("Case #"+c+": "+slowSolution(A,B,K));
    }
  }
  private static long slowSolution(long A, long B, long K) {
    long count=0;
    for (long a=0; a<A; a++) {
      for (long b=0; b<B; b++) {
        if ((a&b)<K) count++;
      }
    }
    return count;
  }
}
