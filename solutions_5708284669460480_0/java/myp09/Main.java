import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int K = s.nextInt(), L = s.nextInt(), S = s.nextInt();
      s.nextLine();
      String dict = s.nextLine(), target = s.nextLine();
      List<String> list = new ArrayList<String>();
      int[] a = new int[S];
      find(list, a, 0, dict, K, S);
      long sum = 0;
      int max = 0;
      for (String str : list) {
        int tmp = count(str, target);
        sum += tmp;
        max = Math.max(max, tmp);
      }
      int m = list.size();
      double ans = (max * 1.0 * m - sum) / m;
      System.out.println(String.format("Case #%d: %.7f", t, ans));
    }
  }

  public static void find(List<String> list, int[] a, int cur, String dict, int K, int S) {
    if (cur == S) {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < S; i++) {
        sb.append(dict.charAt(a[i]));
      }
      list.add(sb.toString());
    } else {
      for (int i = 0; i < K; i++) {
        a[cur] = i;
        find(list, a, cur + 1, dict, K, S);
      }
    }
  }

  public static int count(String a, String b) {
    int aLen = a.length(), bLen = b.length();
    int ret = 0;
    for (int i = 0; i <= aLen - bLen; i++) {
      ret++;
      for (int j = 0; j < bLen; j++) {
        if (a.charAt(i + j) != b.charAt(j)) {
          ret--;
          break;
        }
      }
    }
    return ret;
  }
}