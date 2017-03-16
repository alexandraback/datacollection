package codejam.y2013.r1b;

import java.io.*;
import java.text.*;
import java.util.*;

public class P1 {

  public static void main(String[] args) throws Exception {
    BufferedReader inputFile = new BufferedReader(new InputStreamReader(
        new FileInputStream(args[0])));
    int cases = Integer.parseInt(inputFile.readLine());

    PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
    for (int caseNumber = 1; caseNumber <= cases; caseNumber++) {
      String[] line1 = tokenize(inputFile.readLine());
      String[] line2 = tokenize(inputFile.readLine());

      int A = Integer.parseInt(line1[0]);
      int N = Integer.parseInt(line1[1]);

      int[] otherMotes = new int[N];
      for (int i = 0; i < otherMotes.length; i++) {
        otherMotes[i] = Integer.parseInt(line2[i]);
      }

      Arrays.sort(otherMotes);

      int decision = computeDecision(A, N, otherMotes);
      outFile.println("Case #" + caseNumber + ": " + decision);
    }
    outFile.close();
    inputFile.close();
  }

  // DP
  private static int computeDecision(int A, int N, int[] otherMotes) {
    int[] cost = new int[N];
    for (int i = 0; i < N; i++) {
      cost[i] = 1000000;
    }

    int currentMoteSize = A;
    for (int i = 0; i < N; i++) {
      int prevCost = i == 0 ? 0 : cost[i - 1];

      if (currentMoteSize > otherMotes[i]) {
        currentMoteSize += otherMotes[i];
        cost[i] = prevCost;
        continue;
      }

      if (currentMoteSize == 1) // nothing you can do
        continue;// or break

      // build up
      int addCost = 0;
      while (currentMoteSize <= otherMotes[i]) {
        addCost++;
        // add a convenient mote - best size possible
        currentMoteSize += currentMoteSize - 1;
      }
      currentMoteSize += otherMotes[i];
      cost[i] = prevCost + addCost;
    }

    int best = N;
    for (int i = 0; i < N; i++) {
      int here = cost[i] + (N - i - 1);
      if (here < best)
        best = here;
    }
    return best;
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
