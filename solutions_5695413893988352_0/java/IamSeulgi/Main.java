import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        final Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("input.in")));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(new FileOutputStream("output.out")));

        int T = scanner.nextInt();

        for (int cid = 1; cid <= T; cid++) {
            String C = scanner.next();
            String J = scanner.next();

//            Solver solver = new Solver(C, J);
//            writer.printf("Case #%d: %s\n", cid, solver.solve());
            Brute  brute = new Brute(C, J);
            writer.printf("Case #%d: %s\n", cid, brute.solve());
        }
        writer.flush();
    }

}

class Brute {

    char[] C;
    char[] J;
    String bestCStr = null;
    String bestJStr;
    int bestC;
    int bestJ;
    int bestDiff;

    public Brute(String c, String j) {
        C = c.toCharArray();
        J = j.toCharArray();
    }

    public String solve() {
        solve(0, "", "");

        return String.format("%s %s", bestCStr, bestJStr);
    }

    private void solve(int idx, String curC, String curJ) {

        if (idx == C.length) {

            int curCInt = Integer.valueOf(curC);
            int curJInt = Integer.valueOf(curJ);
            int curDiff = Math.abs(curCInt - curJInt);

            if (bestCStr == null || curDiff < bestDiff ||
                (curDiff == bestDiff && curCInt < bestC) ||
                (curDiff == bestDiff && curCInt == bestC && curJInt < bestJ)) {
                bestCStr = curC;
                bestJStr = curJ;
                bestC = curCInt;
                bestJ = curJInt;
                bestDiff = curDiff;
            }
            return;
        }

        boolean cQ = C[idx] == '?';
        boolean jQ = J[idx] == '?';

        if (cQ && jQ) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    solve(idx + 1, curC + String.valueOf(i), curJ + String.valueOf(j));
                }
            }
        } else if(!cQ && !jQ) {
            solve(idx+1, curC + C[idx], curJ + J[idx]);
        } else {
            if(cQ) {
                for(int i=0; i < 10; i++) {
                    solve(idx+1, curC + String.valueOf(i), curJ + J[idx]);
                }
            } else {
                for(int i=0; i < 10; i++) {
                    solve(idx+1, curC + C[idx], curJ + String.valueOf(i));
                }
            }
        }
    }
}

/*
 If there is more than one way to attain the minimum absolute difference,
  choose the way that minimizes the Coders' score.
  If there is more than one way to attain the minimum absolute difference while also minimizing the Coders' score,
  choose the way that minimizes the Jammers' score.

  C and J always have the same length.

  We process from left to right ( highest digit to lowest digit ).
  For each position x, the below cases

  1) x is '?' for both C and J
     We fill '0'

  2) x is '?' for only one of C and J.
     We will '?' with the same value that one of C and J has.

  3) in position x, C has value 'a', and J and value 'b'

     a == b : Nothing to do, move one

     a > b : For position x+1 ( if it exists ), give '0' for C and give '9' for J

     a < b : For position x+1 ( if it exists ), give '9' for C and give '0' for J
 */


class Solver {
    private static final BigInteger TEN = BigInteger.TEN;
    private static final BigInteger ONE = BigInteger.ONE;
    private static final BigInteger ZERO = BigInteger.ZERO;
    char[] C;
    char[] J;
    BigInteger cBest = null;
    BigInteger jBest;
    BigInteger bestDiff;


    public Solver(String c, String j) {
        C = c.toCharArray();
        J = j.toCharArray();
    }


    public String solve() {

        for (int i = 0; i < C.length; i++) {
            boolean cQ = C[i] == '?';
            boolean jQ = J[i] == '?';

            if (cQ && jQ) {
                C[i] = J[i] = '0';
            } else if (!cQ && !jQ) {
                int cVal = Integer.valueOf(C[i]);
                int jVal = Integer.valueOf(J[i]);
                if ((i + 1) < C.length) {
                    if (cVal > jVal) {
                        C[i + 1] = '0';
                        J[i + 1] = '9';
                    } else if (cVal < jVal) {
                        C[i + 1] = '9';
                        J[i + 1] = '0';
                    }
                }
            } else {
                if (jQ) {
                    J[i] = C[i];
                } else {
                    C[i] = J[i];
                }
            }
        }

        return String.format("%s %s", new String(C), new String(J));
    }


    private void solve(int idx, BigInteger curC, BigInteger curJ) {
        if (idx == C.length) {

            BigInteger diff = curC.subtract(curJ).abs();

            if (cBest == null || diff.compareTo(bestDiff) == -1 ||
                (diff.compareTo(bestDiff) == 0 && curC.compareTo(cBest) == -1) ||
                (diff.compareTo(bestDiff) == 0 && curC.compareTo(cBest) == 0 && curJ.compareTo(jBest) == -1)) {
                cBest = curC;
                jBest = curJ;
                bestDiff = diff;
            }
            return;
        }

        boolean cQ = C[idx] == '?';
        boolean jQ = J[idx] == '?';

        if (cQ && jQ) {
            solve(idx + 1, curC.multiply(TEN), curJ.multiply(TEN));
            solve(idx + 1, curC.multiply(TEN).add(ONE), curJ.multiply(TEN));
            solve(idx + 1, curC.multiply(TEN), curJ.multiply(TEN).add(ONE));

        } else if (!cQ && !jQ) {
            BigInteger cVal = new BigInteger("" + C[idx], 10);
            BigInteger jVal = new BigInteger("" + J[idx], 10);

            solve(idx + 1, curC.multiply(TEN).add(cVal), curJ.multiply(TEN).add(jVal));
        } else {
            if (cQ) {
                BigInteger cVal = new BigInteger("" + C[idx], 10);
            } else {
                BigInteger jVal = new BigInteger("" + J[idx], 10);
            }
        }

    }

}