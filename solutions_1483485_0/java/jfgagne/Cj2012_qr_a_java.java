import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Cj2012_qr_a_java {
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
  private static char Tr[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
      'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f',
      'm', 'a', 'q' };
  private static String str;
  private static StringBuffer stringBuffer;

  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_qr_a_java.class.toString());
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
    str = bufferedReader.readLine();
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    stringBuffer = new StringBuffer(str.length());

    for (int i = 0; i < str.length(); i++) {
      stringBuffer.append(str.charAt(i) == ' ' ? ' ' : Tr[str.charAt(i) - 'a']);
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
    printWriter.print(" ");
    printWriter.print(stringBuffer);
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
