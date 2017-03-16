// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.util.*;

public class C_CoinJam {
  // --------------------------------------------------------------------------------
  private static final String FILENAME="data/qualification/C-small-attempt0";
  private static final boolean STANDARD_OUTPUT=false;
  private static BufferedReader in=null;
  private static PrintStream out=null;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader reader=in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream writer=out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int caseNumber=1,T=Integer.parseInt(in.readLine()); caseNumber<=T; caseNumber++) {
      StringTokenizer tokenizer=new StringTokenizer(in.readLine());
      int N=Integer.parseInt(tokenizer.nextToken());
      int J=Integer.parseInt(tokenizer.nextToken());
      out.println("Case #"+caseNumber+":");
      long[][] solutions=solveSlow(N,J);
      for (int j=0; j<solutions.length; j++) {
        out.print(solutions[j][1]);
        for (int base=2; base<=10; base++) {
          out.print(" "+solutions[j][base]);
        }
        out.println();
      }
    }
  }
  private static long[][] solveSlow(int N, int J) {
    List<long[]> solutions=new ArrayList<>(J);
    loop:for (int i=0,t=(1<<(N-2)); solutions.size()<J&&i<t; i++) {
      long x=(((long)i)<<1)|1L|(1L<<(N-1));
      String string=Long.toBinaryString(x);
      long witnesses[]=new long[11];
      witnesses[1]=Long.parseLong(string,10);
      for (int base=2; base<=10; base++) {
        long n=Long.parseLong(string,base);
        for (long f=2L; f*f<=n; f++) {
          if (n%f==0) {
            witnesses[base]=f;
            break;
          }
        }
        if (witnesses[base]==0L) continue loop;
      }
      solutions.add(witnesses);
    }
    return solutions.toArray(new long[0][]);
  }
}
