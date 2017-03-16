package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class CookieClicker {
    final static String PROBLEM_NAME = "cookie";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        double C = Double.parseDouble(sc.next());
        double F = Double.parseDouble(sc.next());
        double X = Double.parseDouble(sc.next());

        double ans = X / 2.0;
        double curTime = 0;
        double curSpeed = 2.0;
        while (true) {
            curTime += C / curSpeed;
            curSpeed += F;
            ans = Math.min(ans, curTime + X / curSpeed);
            if (curTime >= ans) {
                break;
            }
        }

        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new CookieClicker().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
