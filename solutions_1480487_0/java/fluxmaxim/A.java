import java.io.PrintStream;

public class A extends Worker {

  int n;
  int[] s;

  double p[];

  @Override
  void read(Input input) throws Exception {
    int[] v = input.readints();
    n = v[0];
    s = new int[n];
    for (int i = 0; i < n; i++) {
      s[i] = v[i + 1];
    }
  }

  @Override
  void solve() {
    p = new double[n];
    double x = 0;
    for (int i = 0; i < n; i++) {
      x += s[i];
    }
    for (int i = 0; i < n; i++) {
      int a = s[i];
      double v1 = 1.0 * (2 * x - a * n) / n;
      p[i] = 100 * v1 / x;
      if (p[i] < 0.0) {
        p[i] = 0.0;
      }
    }
  }

  @Override
  void write(PrintStream out) {
    out.printf("Case #%d: ", id);
    for (int i = 0; i < n - 1; i++) {
      out.printf("%.7f ", p[i]);
    }
    out.printf("%.7f\n", p[n-1]);
  }

  public static void main(String[] args) throws Exception {
    Master master = new Master(A.class);
    master.main(args[0]);
  }

}
