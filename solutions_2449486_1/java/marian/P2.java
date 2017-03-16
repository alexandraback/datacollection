package codejam.y2013.q;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.FieldPosition;
import java.util.StringTokenizer;

public class P2 {

  public static void main(String[] args) throws Exception {
    BufferedReader inputFile = new BufferedReader(new InputStreamReader(
        new FileInputStream(args[0])));
    int cases = Integer.parseInt(inputFile.readLine());

    PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
    for (int inputNo = 1; inputNo <= cases; inputNo++) {
      String[] nm = tokenize(inputFile.readLine());
      int n = Integer.parseInt(nm[0]);
      int m = Integer.parseInt(nm[1]);

      int[][] h = new int[n][m];
      for (int i = 0; i < n; i++) {
        String[] l = tokenize(inputFile.readLine());
        for (int j = 0; j < m; j++) {
          h[i][j] = Integer.parseInt(l[j]);
        }
      }

      // calculate maximum on line and column
      int maxL[] = new int[n];
      int maxC[] = new int[m];

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          maxL[i] = Math.max(maxL[i], h[i][j]);
          maxC[j] = Math.max(maxC[j], h[i][j]);
        }
      }

      // check if every square can be cut either horizontally or vertically
      boolean possible = true;
      x: for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (h[i][j] < maxL[i] && h[i][j] < maxC[j]) {
            possible = false;
            break x;
          }
        }
      }

      outFile.println("Case #" + inputNo + ": " + (possible ? "YES" : "NO"));
    }
    outFile.close();
    inputFile.close();
  }


  public static String[] tokenize(String input) {
    StringTokenizer st = new StringTokenizer(input);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String[] tokenize(String input, String sep) {
    StringTokenizer st = new StringTokenizer(input, sep);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String formatDouble(double myDouble, String format) {
    DecimalFormat dfFormat = new DecimalFormat(format);
    FieldPosition f = new FieldPosition(0);
    StringBuffer s = new StringBuffer();
    dfFormat.format(myDouble, s, f);
    return s.toString();
  }
}
