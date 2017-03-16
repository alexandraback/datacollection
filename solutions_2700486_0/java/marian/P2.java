package codejam.y2013.r1b;

import java.io.*;
import java.text.*;
import java.util.*;

public class P2 {

  public static void main(String[] args) throws Exception {
    BufferedReader inputFile = new BufferedReader(new InputStreamReader(
        new FileInputStream(args[0])));
    int cases = Integer.parseInt(inputFile.readLine());

    PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
    for (int caseNumber = 1; caseNumber <= cases; caseNumber++) {
      String[] line1 = tokenize(inputFile.readLine());

      int N = Integer.parseInt(line1[0]);
      int X = Integer.parseInt(line1[1]);
      int Y = Integer.parseInt(line1[2]);

      double decision = computeDecision(N, X, Y);
      //System.out.println("[" + N + "  " + X + "," + Y + "] decision: " + decision);
      //System.out.println();
      outFile.println("Case #" + caseNumber + ": " + formatDouble(decision, "0.0######"));
    }
    outFile.close();
    inputFile.close();
  }



  private static double computeDecision(int N, int X, int Y) {
    int NN = N;
    int I = (Math.abs(X) + Math.abs(Y))/2;
    //System.out.println("[" + NN + "  " + X + "," + Y + "] iteration " + I);

    // consume N for each iteration till we reach the current one
    for (int iter = 0; iter < I; iter++) {
      N -= iter * 4 + 1;// pieces placed at iteration iter
      // 0->1
      // 1->5
      // 2->9
      // 3->13
    }
    // no pieces left
    if (N <= 0) {
      //System.out.println("[" + NN + "  " + X + "," + Y + "] no pieces: " + N);
      return 0;
    }
    //System.out.println("[" + NN + "  " + X + "," + Y + "] pieces " + N);

    if (N >= I * 4 + 1)
      return 1.0;

    // top piece - only if N >= I * 4 + 1
    if (X == 0) {// or Y == I * 2
        return 0.0;
    }

    // DP per height
    int H = I * 2 + 1; // height for iter I: 2*I + 1
    double[][] prob = new double[H][H];

    prob[0][0] = 1.0; // probability to start with 0 on right and 0 on left: 1.0

    for (int r = 0; r < H; r++) {
      for (int l = 0; l < H; l++) {
        if (r + l == 0)
          continue;// already set to 1.0

        // first test when it goes all one way
        if (r == 0) {
          prob[r][l] = prob[r][l-1] / 2;// half of the probability to put a tower
          continue;
        }
        if (l == 0) {
          prob[r][l] = prob[r-1][l] / 2;// same
          continue;
        }

        // if one side is full, the prob to go the other way is 1 (sliding)
        int dL = 2;
        int dR = 2;
        if (r == H - 1)
          dL = 1;
        if (l == H - 1)
          dR = 1;

        // half chance each way
        prob[r][l] = prob[r][l-1] / dL + prob[r-1][l] / dR;
      }
    }

    double probXY = 0;
    for (int r = 1; r <= N && r < H; r++) {
      //prob[r][N-r];
      if (r > Y && N-r < H)
        probXY += prob[r][N-r];
    }

    return probXY;
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
