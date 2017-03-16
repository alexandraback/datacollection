package r1b.a;

import java.io.*;
import java.util.*;

public class What {
  static PrintStream out;
  public static final void main(String[]args)throws Exception{
    Scanner s = new Scanner(new File(args[0]));
    out = new PrintStream(new FileOutputStream(args[0]+".out"));
    int T = s.nextInt();
    for (int t=0; t<T; t++) {
      int A = s.nextInt();
      int N = s.nextInt();
      int[] motes = new int[N];
      for (int i=0;i<N;i++)
        motes[i] = s.nextInt();
      Arrays.sort(motes);
      println("Case #" + (t+1)+": " + foo(A,motes));
    }
    s.close();
    out.close();
  }


  private static int foo(int a, int[] motes) {
    if (motes.length == 0) return 0;
    if (a > motes[0]) {
      return 0 + foo(a + motes[0], Arrays.copyOfRange(motes, 1, motes.length));
    }
    int y = 1 + foo(a, Arrays.copyOfRange(motes, 0, motes.length - 1));
    if (a == 1) return y;
    int x = 1 + foo(a + (a-1), motes);
    return Math.min(x,  y);
  }








  public static void println(String s) throws Exception {
    System.out.println(s);
    out.println(s);
  }

}
