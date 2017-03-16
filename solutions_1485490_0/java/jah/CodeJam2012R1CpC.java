package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam2012R1CpC {

  static final String fileIn = "/Users/jhorwitz/Documents/workspace/project/src/codejam/data/2012/R1C/C-small-attempt1.in";
  static final String fileOut = "/Users/jhorwitz/Documents/workspace/project/src/codejam/data/2012/R1C/2012-1C-C-out.txt";

  public static void main(String[] args) throws Exception {
    BufferedReader r = new BufferedReader(new FileReader(fileIn));
    BufferedWriter w = new BufferedWriter(new FileWriter(fileOut));
    String line = r.readLine();
    int T = Integer.parseInt(line);
    for (int caseNum = 1; caseNum <= T; caseNum++) {
      String str = "Case #" + caseNum + ": " + solve(r);
      w.write(str + "\n");
      System.out.println(str);
    }
    w.close();
    r.close();
  }

  private static String solve(BufferedReader r) throws IOException {
    String line = r.readLine();
    String[] NM = line.split(" ");
    int N = Integer.valueOf(NM[0]);
    int M = Integer.valueOf(NM[1]);

    line = r.readLine();
    String[] AVector = line.split(" ");
    long[] a = new long[N];
    int[] A = new int[N];
    for (int i=0; i<N; ++i) {
      a[i] = Long.valueOf(AVector[2*i]);
      A[i] = Integer.valueOf(AVector[2*i+1]);
    }

    line = r.readLine();
    String[] BVector = line.split(" ");
    long[] b = new long[M];
    int[] B = new int[M];
    for (int i=0; i<M; ++i) {
      b[i] = Long.valueOf(BVector[2*i]);
      B[i] = Integer.valueOf(BVector[2*i+1]);
    }

    return Long.toString(maxToys(a,A,b,B));
  }

  private static long maxToys(long[] a, int[] A, long[] b, int[] B) {
    if (a.length == 0 || b.length == 0) {
      return 0L;
    }

    long ret = 0L;

    if (A[0] == B[0]) {
      if (a[0] > b[0]) { // take b[0] of both
        ret = b[0];

        long[] newa = new long[a.length];
        long[] newb = new long[b.length-1];
        int[] newB = new int[B.length-1];

        System.arraycopy(a, 0, newa, 0, a.length);
        newa[0] = a[0]-b[0];
        System.arraycopy(b, 1, newb, 0, b.length - 1);
        System.arraycopy(B, 1, newB, 0, B.length - 1);

        return ret+maxToys(newa, A, newb, newB);
      } else { // take a[0] of both
        ret = a[0];

        long[] newa = new long[a.length-1];
        int[] newA = new int[A.length-1];
        long[] newb = new long[b.length];

        System.arraycopy(b, 0, newb, 0, b.length);
        newb[0] = b[0]-a[0];
        System.arraycopy(a, 1, newa, 0, a.length - 1);
        System.arraycopy(A, 1, newA, 0, A.length - 1);
        return ret+maxToys(newa, newA, b, B);
      }
    } else { // now we branch and try two possibilities, recursively
      // try throwing out the box
      long[] newa = new long[a.length-1];
      int[] newA = new int[A.length-1];
      System.arraycopy(a, 1, newa, 0, a.length - 1);
      System.arraycopy(A, 1, newA, 0, A.length - 1);
      long maxIfDropBox = maxToys(newa, newA, b, B);

      // try throwing out the toy
      long[] newb = new long[b.length-1];
      int[] newB = new int[B.length-1];
      System.arraycopy(b, 1, newb, 0, b.length - 1);
      System.arraycopy(B, 1, newB, 0, B.length - 1);
      long maxIfDropToy = maxToys(a, A, newb, newB);

      return (maxIfDropBox > maxIfDropToy) ? ret + maxIfDropBox : ret + maxIfDropToy;
    }
  }
}