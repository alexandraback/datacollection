import java.util.*;

public class D {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for (int test = 1; test <= t; ++test) {
      int size = in.nextInt();
      int[] naomi = new int[size];
      int[] ken = new int[size];
      for (int i = 0; i < size; ++i) {
        naomi[i] = (int)(in.nextDouble() * 1000000);
      }
      for (int i = 0; i < size; ++i) {
        ken[i] = (int)(in.nextDouble() * 1000000);
      }
      Arrays.sort(naomi);
      Arrays.sort(ken);
      //System.out.println(Arrays.toString(naomi));
      //System.out.println(Arrays.toString(ken));
      int bestDeceit = deceitful(naomi, ken);
      int bestWar = war(naomi, ken);
      //int bestWar = bruteWar(naomi, ken);
      System.out.printf("Case #%d: %d %d\n", test, bestDeceit, bestWar);
    }
  }
  
  // for given input of D1small.in, same in every single case, every permutation = good
  // means the error is in deceitful play
  public static int bruteWar(int[] naomi, int[] ken) {
    int best = war(naomi, ken);
    do {
      if (best != war(naomi, ken)) {
        System.out.printf("Best = %d, war=%d\n", best, war(naomi, ken));
        System.out.println(Arrays.toString(naomi));
        System.out.println(Arrays.toString(ken));
        throw new RuntimeException();
      }
    } while (permute(naomi));
    return best;
  }
  
  public static boolean permute(int[] n) {
    int idx = -1;
    for (int i = 0; i < n.length-1; ++i) {
      if (n[i] < n[i+1])
        idx = i;
    }
    if (idx == -1) return false;
    int jj = -1;
    for (int j = idx+1; j < n.length; ++j) {
      if (n[j] > n[idx])
        jj = j;
    }
    int temp = n[idx];
    n[idx] = n[jj];
    n[jj] = temp;
    for (int k = idx+1, m = n.length-1; k < m; ++k, --m) {
      temp = n[k];
      n[k] = n[m];
      n[m] = temp;
    }
    return true;
  }
  
  // assumes inputs are already sorted
  public static int deceitful(int[] naomi, int[] ken) {
    // naomi's strat = take her lowest, kill ken's highest
    // then, if what's left of naomi's, sorted, is in place higher than ken's sorted, she wins all
    int nIdx = 0;
    int kHigh = ken.length-1;
    int kLow = 0;
    int count = 0;
    while (kHigh >= kLow && nIdx < naomi.length) {
      if (naomi[nIdx] > ken[kLow]) {
        ++count;
        ++nIdx;
        ++kLow;
        continue;
      }
      ++nIdx;
      --kHigh;
    }
    return count;
  }
  
  // naomi's choices don't matter.
  public static int war(int[] naomi, int[] ken) {
    boolean[] used = new boolean[ken.length];
    int count = 0;
    for (int i = 0; i < naomi.length; ++i) {
      // largest non-used idx > naomi[i], or smallest non-used idx < naomi[i]
      int small = -1;
      int large = -1;
      for (int j = 0; j < ken.length; ++j) {
        if (used[j]) continue;
        if (ken[j] < naomi[i] && small == -1)
          small = j;
        if (ken[j] > naomi[i] && large == -1)
          large = j;
      }
      if (large != -1) {
        used[large] = true;
      } else {
        ++count;
        used[small] = true;
      }
    }
    return count;
  }
}