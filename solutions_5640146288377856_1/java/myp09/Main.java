import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int r = s.nextInt(), c = s.nextInt(), w = s.nextInt();
      System.out.println(String.format("Case #%d: %d", t, find(r, w, c, c)));
    }
  }

  public static int find(int w, int c) {
    if (w == c) {
      return c;
    } else if (w * 2 > c) {
      return w + 1;
    } else {
      return Math.max(w + 1, find(w, c - w) + 1);
    }
  }

  public static int find(int r, int w, int c, int C) {
    if (r == 1) {
      return find(w, c);
    }
    if (w == c) {
      return Math.max(c, find(r - 1, w, C, C) + 1);
    } else if (w * 2 > c) {
      return Math.max(w + 1, find(r - 1, w, C, C) + 1);
    } else {
      return Math.max(w + 1, find(r, w, c - w, C) + 1);
    }
  }
}