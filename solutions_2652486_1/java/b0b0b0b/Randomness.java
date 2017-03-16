package r1a.c;

import java.io.*;
import java.util.*;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

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
      long elapsed = 0;
      for (int r=0; r<R; r++) {
        int[] ks = new int[K];
        for (int k=0; k<K; k++) {
          ks[k] = s.nextInt();
        }
        System.err.println(r);
        long start = System.currentTimeMillis();
        println(foo(N, M, ks));
        long minus = System.currentTimeMillis() - start;
        elapsed += minus;
        System.err.println("expected seconds left: " + (R/1000.-r/1000.) * (elapsed / (1+r)));
      }
    }
    s.close();
    out.close();
  }


  static class MCMC implements Runnable {
    final int n, m;
    int[] nums;
    int score = 0;
    final int[]ks;
    final Random r = new Random();
    final CountDownLatch aha;
    final AtomicInteger bestscore;
    boolean turbo;
    public MCMC(int n, int m, int[] ks, CountDownLatch aha, AtomicInteger bestscore, boolean turbo) {
      this.n = n;
      this.m = m;
      this.ks = ks;
      this.aha = aha;
      this.bestscore = bestscore;
      this.turbo = turbo;
    }

    public void run() {
      if (turbo) {
        aha.countDown();
        return;
      }
      nums = new int[n];
      Random r = new Random();
      int fuck = 0;
      do {
        fuck++;
        for (int i=0; i<n; i++) {
          nums[i] = r.nextInt(m-1) + 2;
        }
        if (fuck>(turbo?1:100)) {
          aha.countDown();
          return;
        }
      } while ((score=score(nums, ks)) == 0);

      int rejectstreak = 0;
      for (int x=0; x<(turbo?1:99); x++) {
        int idx = r.nextInt(n);
        int prev = nums[idx];
        if (idx>0) {
          int left = nums[idx-1];
          nums[idx] = r.nextInt(m-left+1) + left;
        } else {
          int right = nums[idx+1];
          nums[idx] = r.nextInt(right-1) + 2;
        }
        int proposal = score(nums, ks);
        int flip = r.nextInt(proposal + score);
        if (flip <= score) {
          nums[idx] = prev;
          rejectstreak++;
          // reject
        } else {
          // accept
          score = proposal;
          rejectstreak = 0;
        }
      }
      aha.countDown();
    }
  }


  static int didntbail = 0;
  private static String foo(int n, int m, int[] ks) throws InterruptedException {
    CountDownLatch aha = new CountDownLatch(16);
    MCMC[] arr = new MCMC[16];
    AtomicInteger bestsscore = new AtomicInteger(0);
    boolean foo = new Random().nextBoolean();
    for (int i=0; i<16;i++) {
      arr[i] = new MCMC(n, m, ks, aha, bestsscore, didntbail>2000 || foo);
      Thread t = new Thread(arr[i]);
      t.start();
    }

    aha.await();

    int bestscore = 0;
    int[]bestnums = null;
    for (int i=0; i<arr.length; i++) {
      if (arr[i].score > bestscore) {
        System.err.println(arr[i].score +" " + Arrays.toString(arr[i].nums));
        bestnums = arr[i].nums;
        bestscore = arr[i].score;
      } else if (arr[i].score == bestscore) {
        System.err.println("same " + Arrays.toString(arr[i].nums));
      }
    }

    //if (!keepgoing.get()) return;
    if (bestnums == null) {
      String s = "";
      for (int i=0; i<n; i++) {
        s+="2";
      }
      return s;
    }
    didntbail++;


    String s = "";
    for (int i=0; i<n; i++) {
      s += bestnums[i];
    }
    System.err.println(Arrays.toString(ks));
    return s;
  }

  private static int score(int[] nums, int[] ks) {
    for (int x=0; x<nums.length; x++) {
      if (ks[x] % nums[x] != 0) return 0;
    }
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
