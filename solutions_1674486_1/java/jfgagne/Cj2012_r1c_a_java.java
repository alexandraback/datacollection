import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Cj2012_r1c_a_java {
  // <Common Declarations>
  // private static final String IN_FILE = "test.in";
  // private static final String IN_FILE = "test_small.in";
  private static final String IN_FILE = "test_large.in";
  private static final String OUT_FILE = IN_FILE + ".out";
  private static final DateFormat DATE_FORMAT = new SimpleDateFormat("HH:mm.ss");

  private static long lBeginTimeMillis;
  private static BufferedReader bufferedReader;
  private static PrintWriter printWriter;

  private static int nNbCases, nIndexCase;

  // </Common Declarations>

  // <Specific Declarations>
  // ...
  private static int N;
  private static AClass Classes[] = new AClass[1000];

  // private static char ;
  private static boolean d;

  // private static String ;
  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_r1c_a_java.class.toString());
    System.out.println("Begin: "
        + DATE_FORMAT.format(new Date(lBeginTimeMillis)) + ".");

    bufferedReader = new BufferedReader(new FileReader(IN_FILE));
    printWriter = new PrintWriter(new BufferedWriter(new FileWriter(OUT_FILE)));
    // </Common Commands>

    // <Specific Commands>
    nNbCases = Integer.parseInt(bufferedReader.readLine());
    for (int i = 0; i < Classes.length; i++)
      Classes[i] = new AClass();
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
    N = Integer.parseInt(bufferedReader.readLine());

    for (int i = 0; i < N; i++) {
      StringTokenizer strTokenizer = new StringTokenizer(
          bufferedReader.readLine(), " ");

      Classes[i].i = i;
      Classes[i].nNbParents = Integer.parseInt(strTokenizer.nextToken());
      for (int j = 0; j < Classes[i].nNbParents; j++)
        Classes[i].parents[j] = Integer.parseInt(strTokenizer.nextToken()) - 1;
      Classes[i].children.clear();
    }
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    d = false;
    try {
      for (int i = 0; i < N; i++) {
        computeChildren(i, Classes[i]);
      }
    }
    catch (RuntimeException e) {

    }
    // </Specific Commands>
  }

  private static void computeChildren(int init, AClass current) {
    for (int i = 0; i < current.nNbParents; i++) {
      AClass parent = Classes[current.parents[i]];
      if (parent.children.contains(init)) {
        d = true;
        throw new RuntimeException();
      }
      parent.children.add(init);
      computeChildren(init, parent);
    }
  }

  private static void writeCase(int nIndexCase) throws Exception {
    // <Common Commands>
    printWriter.print("Case #");
    printWriter.print(nIndexCase + 1);
    printWriter.print(":");
    // </Common Commands>

    // <Specific Commands>
    printWriter.print(" ");
    printWriter.print(d ? "Yes" : "No");
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

class AClass {
  int i, parents[] = new int[1000], nNbParents;
  HashSet<Integer> children = new HashSet<Integer>();
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
