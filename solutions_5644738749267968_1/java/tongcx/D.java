import java.util.*;

class D {
  static int N;
  static double[] namio;
  static double[] ken;

  static int war() {
    int ret = 0;
    NavigableSet<Double> kenSet = new TreeSet<Double>();
    for (double x : ken)
      kenSet.add(x);
    for (double x : namio) {
      Double t = kenSet.higher(x);
      if (t == null) {
        kenSet.pollFirst();
        ret++;
      } else {
        kenSet.remove(t);
      }
    }
    return ret;
  }

  static int deceitful() {
    int ret = 0;
    NavigableSet<Double> kenSet = new TreeSet<Double>();
    for (double x : ken)
      kenSet.add(x);
    NavigableSet<Double> namioSet = new TreeSet<Double>();
    for (double x : namio)
      namioSet.add(x);

    while (!namioSet.isEmpty()) {
      double n = namioSet.pollFirst();
      if (kenSet.first() < n) {
        ret++;
        kenSet.pollFirst();
      } else {
        kenSet.pollLast();
      }
    }
    return ret;
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      N = cin.nextInt();
      namio = new double[N];
      for (int i = 0; i < N; i++) namio[i] = cin.nextDouble();
      ken = new double[N];
      for (int i = 0; i < N; i++) ken[i] = cin.nextDouble();
      System.out.format("Case #%d: %d %d\n",
          caseNo,
          deceitful(),
          war());
    }
  }
}
