import java.util.*;

class Hiker {
  int d;
  long m;
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int n = sc.nextInt();
      List<Hiker> hikers = new ArrayList<Hiker>();
      for (int i = 0; i < n; ++i) {
        int d = sc.nextInt();
        int h = sc.nextInt();
        long m = sc.nextLong();
        for (int j = 0; j < h; ++j) {
          Hiker hiker = new Hiker();
          hiker.d = d;
          hiker.m = m;
          hikers.add(hiker);
        }
      }
      int ans = 0;
      if (hikers.size() >= 2) {
        Hiker a = hikers.get(0);
        Hiker b = hikers.get(1);
        long sa = (360 - a.d) * a.m;
        long sb = (360 - b.d) * b.m;
        if (sa + 360 * a.m <= sb ||
            sb + 360 * b.m <= sa) ans = 1;
      }
      System.out.printf("Case #%d: %s\n", tc, ans);
    }
  }
}
