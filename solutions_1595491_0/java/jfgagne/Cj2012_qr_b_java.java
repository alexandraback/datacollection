import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.StringTokenizer;

public class Cj2012_qr_b_java {
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
  private static int N, S, p, t[] = new int[100], nP;

  // </Specific Declarations>

  private static void begin() throws Exception {
    // <Common Commands>
    lBeginTimeMillis = System.currentTimeMillis();
    System.out.println(Cj2012_qr_b_java.class.toString());
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
    S = Integer.parseInt(strTokenizer.nextToken());
    p = Integer.parseInt(strTokenizer.nextToken());

    for (int i = 0; i < N; i++)
      t[i] = Integer.parseInt(strTokenizer.nextToken());
    // </Specific Commands>
  }

  private static void processCase() {
    // <Specific Commands>
    Arrays.sort(t, 0, N);

    nP = 0;
    for (int i = N - 1; i >= 0; i--) {
      int n = t[i] / 3;
      if (n >= p)
        nP++;
      else {
        int n1 = t[i] % 3;
        switch (n1) {
        case 0:
          if (t[i] > 0 && n + 1 >= p && n + 1 <= 10 && S > 0) {
            nP++;
            S--;
          }
          break;
        case 1:
          if (n + 1 >= p && n + 1 <= 10) {
            nP++;
          }
          else if (n + 1 >= p && n + 1 <= 10 && S > 0) {
            nP++;
            S--;
          }
          break;
        case 2:
          if (n + 1 >= p && n + 1 <= 10) {
            nP++;
          }
          else if (n + 2 >= p && n + 2 <= 10 && S > 0) {
            nP++;
            S--;
          }
          break;
        }
      }
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
    printWriter.print(nP);
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
}
