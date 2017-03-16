package r1a.a;

import java.io.*;
import java.util.*;

public class Paint {
  static PrintStream out;
  public static final void main(String[]args)throws Exception{
    Scanner s = new Scanner(new File(args[0]));
    out = new PrintStream(new FileOutputStream(args[0]+".out"));
    int T = s.nextInt();
    for (int t=0; t<T; t++) {
      long rr = s.nextLong();
      long tt = s.nextLong();
      println("Case #" + (t+1)+": " + foo(rr,tt));
    }
    s.close();
    out.close();
  }





  private static long foo(long rr, long tt) {
    int ret = 0;
    while (true) {
      tt -= (rr+1) * (rr+1) - rr*rr;
      if (tt >= 0) {
        ret++;
        rr += 2;
      } else {
        return ret;
      }
    }
  }





  public static void println(String s) throws Exception {
    System.out.println(s);
    out.println(s);
  }

}
