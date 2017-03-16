import java.util.*;

class B {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tc = 1, tcc = sc.nextInt(); tc <= tcc; ++tc) {
      int n = sc.nextInt();
      String[] words = new String[n];
      int[] perm = new int[n];
      for (int i = 0; i < n; ++i) {
        words[i] = sc.next().replaceAll("([a-z])(\\1+)", "$1");
        perm[i] = i;
      }
      long ans = 0;
      for (;;) {
        StringBuilder sb = new StringBuilder(100);
        for (int i: perm) sb.append(words[i]);
        boolean good = true;
        String res = sb.toString();
        int[] last = new int[26];
        for (int i = 0; i < res.length(); ++i) {
          int c = res.charAt(i) - 'a';
          if (last[c] != 0 && last[c] != i) {
            good = false;
            break;
          }
          last[c] = i + 1;
        }
        if (good) ans = (ans + 1) % 1000000007L;
        if (!nextPerm(perm)) break;
      }
      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }

  static boolean nextPerm(int[] arr) {
    int n = arr.length;
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) --i;
    if (i < 0) return false;
    int j = n - 1;
    while (arr[i] >= arr[j]) --j;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    Arrays.sort(arr, i + 1, n);
    return true;
  }
}
