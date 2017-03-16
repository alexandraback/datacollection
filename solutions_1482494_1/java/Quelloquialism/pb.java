import java.util.*;

public class pb {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      int N = in.nextInt();
      int[] a = new int[N], b = new int[N];
      for (int i = 0; i < N; i++) {
        a[i] = in.nextInt();
        b[i] = in.nextInt();
      }
      int turns = 0;
      int stars = 0;
      thejoke:while (stars < 2*N) {
        for (int i = 0; i < N; i++) {
          if (b[i] >= 0 && b[i] <= stars) {
            b[i] = -1;
            stars++;
            if (a[i] >= 0) {
              a[i] = -1;
              stars++;
            }
            turns++;
            continue thejoke;
          }
        }
        int bind = -1;
        for (int i = 0; i < N; i++) {
          if (a[i] >= 0 && a[i] <= stars) {
            if (bind < 0) {
              bind = i;
            } else {
              if (b[bind] < b[i]) {
                bind = i;
              }
            }
          }
        }
        if (bind != -1) {
          a[bind] = -1;
          stars++;
          turns++;
          continue thejoke;
        }
        break thejoke;
      }
      System.out.printf("Case #%d: %s\n", tc, stars != 2*N ? "Too Bad" : ("" + turns));
    }
  }
}

class Pair implements Comparable<Pair> {
  int a, b;
  
  public int compareTo(Pair o) {
    return a - o.a == 0 ? b - o.b : a - o.a;
  }
}