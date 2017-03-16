import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.StringTokenizer;

public class Cj2012_r1b_a_java {
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
  private static int N, X;
  private static Contestant C[] = new Contestant[200];

  // private static long ;
  // private static char ;
  // private static boolean ;
  // private static String ;
  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_r1b_a_java.class.toString());
    System.out.println("Begin: "
        + DATE_FORMAT.format(new Date(lBeginTimeMillis)) + ".");

    bufferedReader = new BufferedReader(new FileReader(IN_FILE));
    printWriter = new PrintWriter(new BufferedWriter(new FileWriter(OUT_FILE)));
    // </Common Commands>

    // <Specific Commands>
    nNbCases = Integer.parseInt(bufferedReader.readLine());

    for (int i = 0; i < C.length; i++)
      C[i] = new Contestant();
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
    for (int i = 0; i < N; i++) {
      C[i].i = i;
      C[i].J = Integer.parseInt(strTokenizer.nextToken());
      C[i].M = 0;
    }
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    Arrays.sort(C, 0, N, new Contestant_cmp_J());

    X = 0;
    for (int i = 0; i < N; i++)
      X += C[i].J;

    int X1 = X;
    for (int i = 0; i < N - 1; i++) {
      int n = C[i + 1].J - C[i].J;

      if (n * i + n <= X1) {
        for (int j = 0; j <= i; j++) {
          C[j].M += n;
          X1 -= n;
        }
      }
      else {
        for (int j = 0; j <= i; j++) {
          C[j].M += X1 / (i + 1.0);
        }
        X1 = 0;
        break;
      }
    }

    for (int i = 0; i < N; i++) {
      C[i].M += X1 / (double) N;
    }

    Arrays.sort(C, 0, N, new Contestant_cmp_i());
    // </Specific Commands>
  }

  private static void writeCase(int nIndexCase) throws Exception {
    // <Common Commands>
    printWriter.print("Case #");
    printWriter.print(nIndexCase + 1);
    printWriter.print(":");
    // </Common Commands>

    // <Specific Commands>
    for (int i = 0; i < N; i++) {
      printWriter.print(" ");
      printWriter.print(100 * C[i].M / X);
    }
    printWriter.println();

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

class Contestant {
  int i, J;
  double M;
}

class Contestant_cmp_i implements Comparator<Contestant> {
  public int compare(Contestant o1, Contestant o2) {
    return o1.i - o2.i;
  }
}

class Contestant_cmp_J implements Comparator<Contestant> {
  public int compare(Contestant o1, Contestant o2) {
    return o1.J - o2.J;
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
