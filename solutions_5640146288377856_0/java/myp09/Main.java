import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int r = s.nextInt(), c = s.nextInt(), w = s.nextInt();
      int[] a = new int[c + 1];
      System.out.println(String.format("Case #%d: %d", t, find(w, c, a)));
    }
  }

  public static int find(int w, int c, int[] a) {
    if (w == c) {
      return c;
    } else if (w * 2 > c) {
      return w + 1;
    } else {
      if (a[c] == 0) {
        a[c] = Math.max(w + 1, find(w, c - w, a) + 1);
      }
      return a[c];
    }
  }
}