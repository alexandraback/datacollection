package r1a.c;

import java.io.*;
import java.util.*;

public class Randomness {
  static PrintStream out;
  public static final void main(String[]args)throws Exception{
    Scanner s = new Scanner(new File(args[0]));
    out = new PrintStream(new FileOutputStream(args[0]+".out"));
    int T = s.nextInt();
    for (int t=0; t<T; t++) {
      int R = s.nextInt();
      int N = s.nextInt();
      int M = s.nextInt();
      int K = s.nextInt();
      println("Case #" + (t+1)+":");
      for (int r=0; r<R; r++) {
        int[] ks = new int[K];
        for (int k=0; k<K; k++) {
          ks[k] = s.nextInt();
        }
        out.println(foo(N, M, ks));
      }
    }
    s.close();
    out.close();
  }


  private static String foo(int n, int m, int[] ks) {
    Random r = new Random();
    int bestscore = 0;
    int[]bestnums = null;
    boolean changed;

    do {
      changed = false;
      int[] nums = new int[n];
      int score = 0;
      do {
        for (int i=0; i<n; i++) {
          nums[i] = r.nextInt(m-1) + 2;
        }
      } while ((score = score(nums, ks)) == 0);
      for (int x=0; x<50000; x++) {
        int idx = r.nextInt(n);
        score = score(nums, ks);
        int prev = nums[idx];
        do {
          nums[idx] = r.nextInt(m-1) + 2;
        } while (nums[idx] == prev);
        int proposal = score(nums, ks);
        int flip = r.nextInt(proposal + score);
        if (flip <= score) {
          nums[idx] = prev;
          // reject
        } else {
          // accept
          score = proposal;
        }
      }
      if (score > bestscore) {
        System.err.println(score +" " + Arrays.toString(nums));
        bestnums = nums;
        bestscore = score;
        changed = true;
      } else if (score == bestscore) {
        System.err.println("same " + Arrays.toString(nums));
      }
    } while (changed);
    String s = "";
    for (int i=0; i<n; i++) {
      s += bestnums[i];
    }
    System.err.println(Arrays.toString(ks));
    return s;
  }


  private static int score(int[] nums, int[] ks) {
    int match []= new int[ks.length];
    for (int mask = 0; mask < 1<<nums.length; mask++) {
      int mult = 1;
      for (int x=0;x<nums.length; x++) {
        if (0 != ((1<<x)&mask)) {
          mult *= nums[x];
        }
      }
      for (int i=0; i<ks.length; i++) {
        if (ks[i] == mult) {
          match[i]++;
        }
      }
    }
    int d = 0;
    for (int i=0; i<ks.length; i++) {
      if (match[i] == 0) {
        return 0;
      }
      d += match[i];
    }
    return d;
  }


  public static void println(String s) throws Exception {
    System.out.println(s);
    out.println(s);
  }

}
