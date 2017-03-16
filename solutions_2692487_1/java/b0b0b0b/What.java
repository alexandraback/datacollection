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


  static class State implements Comparable<State> {
    int edits;
    int a;
    int[] motes;

    public State(int edits, int a, int[] motes) {
      this.edits = edits;
      this.a = a;
      this.motes = motes;
    }

    @Override public int compareTo(State o) {
      return edits < o.edits ? -1 : edits > o.edits ? 1 : 0;
    }
  }

  private static int foo(int a, int[] motes) {
    PriorityQueue<State> q = new PriorityQueue<>();
    q.add(new State(0, a, motes));
    while (!q.isEmpty()) {
      State s = q.remove();

      if (s.motes.length == 0) return s.edits;

      if (s.a > s.motes[0]) {
        q.add(new State(s.edits, s.a +s. motes[0], Arrays.copyOfRange(s.motes, 1, s.motes.length)));
      } else {
        if (a > 1) {
          q.add(new State(s.edits + 1, s.a + s.a - 1, s.motes.clone()));
        }
        q.add(new State(s.edits + 1, s.a, Arrays.copyOfRange(s.motes, 0, s.motes.length - 1)));
      }
    }
    throw new Error();
  }








  public static void println(String s) throws Exception {
    System.out.println(s);
    out.println(s);
  }

}
