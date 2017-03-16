import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.StringTokenizer;

public class Cj2012_r1c_b_java {
  // <Common Declarations>
  //private static final String IN_FILE = "test.in";
  private static final String IN_FILE = "test_small.in";
  // private static final String IN_FILE = "test_large.in";
  private static final String OUT_FILE = IN_FILE + ".out";
  private static final DateFormat DATE_FORMAT = new SimpleDateFormat("HH:mm.ss");

  private static long lBeginTimeMillis;
  private static BufferedReader bufferedReader;
  private static PrintWriter printWriter;

  private static int nNbCases, nIndexCase;

  // </Common Declarations>

  // <Specific Declarations>
  private static double D, t[] = new double[2000], x[] = new double[2000],
      a[] = new double[250], s[] = new double[250];
  private static int N, A;

  // private static char ;
  // private static boolean ;
  // private static String ;
  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_r1c_b_java.class.toString());
    System.out.println("Begin: "
        + DATE_FORMAT.format(new Date(lBeginTimeMillis)) + ".");

    bufferedReader = new BufferedReader(new FileReader(IN_FILE));
    printWriter = new PrintWriter(new BufferedWriter(new FileWriter(OUT_FILE)));
    // </Common Commands>

    // <Specific Commands>
    nNbCases = Integer.parseInt(bufferedReader.readLine());
    // </Specific Commands>
  }

  private static void end() throws Exception {
    // <Specific Commands>
    // ...

    // </Specific Commands>

    // <Common Commands>
    bufferedReader.close();
    printWriter.close();

    long lEndTimeMillis = System.currentTimeMillis();
    System.out.println("End:   " + DATE_FORMAT.format(new Date(lEndTimeMillis))
        + ".");
    System.out.println((lEndTimeMillis - lBeginTimeMillis) + ".");
    // </Common Commands>
  }

  private static void readCase() throws Exception {
    // <Specific Commands>
    StringTokenizer strTokenizer = new StringTokenizer(
        bufferedReader.readLine(), " ");

    D = Double.parseDouble(strTokenizer.nextToken());
    N = Integer.parseInt(strTokenizer.nextToken());
    A = Integer.parseInt(strTokenizer.nextToken());

    for (int i = 0; i < N; i++) {
      strTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
      t[i] = Double.parseDouble(strTokenizer.nextToken());
      x[i] = Double.parseDouble(strTokenizer.nextToken());
    }

    strTokenizer = new StringTokenizer(bufferedReader.readLine(), " ");
    for (int i = 0; i < A; i++)
      a[i] = Double.parseDouble(strTokenizer.nextToken());
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    if (x[0] > D)
      x[0] = D;

    for (int i = 1; i < N; i++) {
      if (x[i] > D) {
        double dx = x[i] - x[i - 1];
        double dt = t[i] - t[i - 1];

        x[i] = D;
        t[i] = t[i - 1] + dt * (D - x[i - 1]) / dx;
      }
    }

    for (int i = 0; i < A; i++) {
      double sec = 0;
      double xi = 0;
      double vi = 0;
      double acc = a[i];

      for (int j = 0; j < N; j++) {
        if (x[j] >= D) {
          double a = acc / 2;
          double b = vi;
          double c = xi - D;

          double dt = (Math.sqrt(b * b - 4 * a * c) - b) / (2 * a);
          sec += dt;

          break;
        }
        else {
          double dt = t[j + 1] - t[j];
          double nx = xi + vi * dt + acc * dt * dt / 2;
          
          if (nx > x[j + 1]) {
            xi = x[j + 1];
            vi = (x[j + 1] - x[j]) / dt;
          }
          else {
            xi = nx;
            vi += acc * dt;
          }

          sec = t[j + 1];
        }
      }

      s[i] = sec;
    }
    // </Specific Commands>
  }

  private static void writeCase(int nIndexCase) throws Exception {
    // <Common Commands>
    printWriter.print("Case #");
    printWriter.print(nIndexCase + 1);
    printWriter.print(":");
    // </Common Commands>

    // <Specific Commands>
    printWriter.println();
    for (int i = 0; i < A; i++) {
      printWriter.print(s[i]);
      printWriter.println();
    }
    // </Specific Commands>
  }

  public static void main(String[] args) throws Exception {
    // <Common Commands>
    begin();
    for (nIndexCase = 0; nIndexCase < nNbCases; nIndexCase++) {
      readCase();
      processCase();
      writeCase(nIndexCase);
    }
    end();
    // </Common Commands>
  }

  static long fact(int n) {
    long l = n < 0 ? -1 : 1;
    n *= l;
    while (n > 1)
      l *= n--;
    return l;
  }

  static int pgcd(int N, int M) {
    if (N < M)
      return pgcd(M, N);
    if (N % M == 0)
      return M;
    return pgcd(N % M, M);
  }
}

class A_class {
  boolean b;
  int i;
  double d;
  String str;

  public A_class(boolean b, int i, double d, String str) {
    this.b = b;
    this.i = i;
    this.d = d;
    this.str = str;
  }
}

class Item implements Comparable<Item> {
  public int n, p;

  Item(int n, int p) {
    this.n = n;
    this.p = p;
  }

  public int compareTo(Item o) {
    return this.p - o.p;
  }
}
