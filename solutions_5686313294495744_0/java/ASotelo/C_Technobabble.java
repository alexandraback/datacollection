// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class C_Technobabble { // small: OK, large:
  private static final String FILENAME="src/round1b/C-small-attempt0";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int test=1,TESTS=Integer.parseInt(in.readLine()); test<=TESTS; test++) {
          int N=Integer.parseInt(in.readLine());
          String[][] topics=new String[N][2];
          for (int i=0; i<N; i++) {
            StringTokenizer tokenizer=new StringTokenizer(in.readLine());
            topics[i][0]=tokenizer.nextToken();
            topics[i][1]=tokenizer.nextToken();
          }
          out.println("Case #"+test+": "+solveSlow(N,topics));
        }
      }
    }
  }
  static int solveSlow(int N, String[][] topics) {
    int max=0;
    loop: for (int mask=0; mask<(1<<N); mask++) {
      List<Set<String>> words=Arrays.<Set<String>>asList(new HashSet<String>(),new HashSet<String>());
      for (int i=0; i<N; i++) {
        if (((mask>>>i)&1)==1) {
          for (int j=0; j<2; j++) {
            words.get(j).add(topics[i][j]);
          }
        }
      }
      for (int i=0; i<N; i++) {
        if (((mask>>>i)&1)==0) {
          for (int j=0; j<2; j++) {
            if (!words.get(j).contains(topics[i][j])) continue loop;
          }
        }
      }
      max=Math.max(max,N-Integer.bitCount(mask));
    }
    return max;
  }
}
