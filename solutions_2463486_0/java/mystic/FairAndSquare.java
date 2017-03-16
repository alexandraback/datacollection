package contest;

import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class FairAndSquare {
    final static String PROBLEM_NAME = "palin";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    String from, to;
    BigInteger L, R;
    int res = 0;

    static char[] data;

    static List<BigInteger> sol = new ArrayList<BigInteger>();

    static void go(int l, int r, int sum) {
        if (sum>=10) return;
        if (l>r) {
            BigInteger num = new BigInteger(new String(data));
            sol.add(num.multiply(num));
            return;
        }
        for (int d = (l==0?1:0); d < 10; d++) {
            data[l] = data[r] = (char)((int)'0' + d);
            go(l+1, r-1, sum+(l==r?d*d:2*d*d));
        }
    }

    void solve(Scanner sc, PrintWriter pw) {
        String from = sc.next();
        String to = sc.next();

        L = new BigInteger(from);
        R = new BigInteger(to);

        int res = 0;
        for (BigInteger num : sol) {
            if (num.compareTo(L) >= 0 && num.compareTo(R) <= 0) res++;
        }

        pw.println(res);
    }

    public static void preprocess() {
        for (int len=1; len<=51; len++) {
            data = new char[len];
            go(0, len-1, 0);
            System.out.println("len = " + len + ", sz = " + sol.size());
        }
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new FairAndSquare().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
