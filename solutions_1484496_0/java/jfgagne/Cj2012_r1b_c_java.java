import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.StringTokenizer;

public class Cj2012_r1b_c_java {
  // <Common Declarations>
  // private static final String IN_FILE = "test.in";
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
  // ...
  private static int N, nX, nY;
  private static long S[] = new long[500], X[] = new long[500],
      Y[] = new long[500];

  // private static char ;
  private static boolean found;

  // private static String ;
  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_r1b_c_java.class.toString());
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
    N = Integer.parseInt(strTokenizer.nextToken());
    for (int i = 0; i < N; i++)
      S[i] = Long.parseLong(strTokenizer.nextToken());
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    long l = 0;

    for (int i = 0; i < N; i++)
      l += S[i];

    nX = 0;
    nY = 0;
    found = find(0, 0, 0, l);

    // </Specific Commands>
  }

  private static boolean find(int i, long A, long B, long l) {
    if (A == B && A != 0)
      return true;

    if (i >= N)
      return false;

    if (Math.abs(A - B) > l)
      return false;

    if (find(i + 1, A, B, l - S[i]))
      return true;

    X[nX] = S[i];
    nX++;
    if (find(i + 1, A + S[i], B, l))
      return true;
    nX--;

    Y[nY] = S[i];
    nY++;
    if (find(i + 1, A, B + S[i], l))
      return true;
    nY--;

    return false;
  }

  private static void writeCase(int nIndexCase) throws Exception {
    // <Common Commands>
    printWriter.print("Case #");
    printWriter.print(nIndexCase + 1);
    printWriter.print(":");
    // </Common Commands>

    // <Specific Commands>
    if (!found) {
      printWriter.println();
      printWriter.print("Impossible");
      printWriter.println();
    }
    else {
      printWriter.println();

      printWriter.print(X[0]);
      for (int i = 1; i < nX; i++) {
        printWriter.print(" ");
        printWriter.print(X[i]);
      }
      printWriter.println();

      printWriter.print(Y[0]);
      for (int i = 1; i < nY; i++) {
        printWriter.print(" ");
        printWriter.print(Y[i]);
      }
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
