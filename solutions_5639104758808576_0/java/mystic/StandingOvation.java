import java.util.*;
import java.io.*;
import java.math.*;

public class StandingOvation {
    final static String PROBLEM_NAME = "standing";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        String s = sc.next();
        List<Integer> A = new ArrayList<Integer>();
        for (int i=0; i<=N; i++) {
            for (int j=0; j < s.charAt(i)-'0'; j++) {
                A.add(i);
            }
        }
        int ans = 0;
        int cur = 0;
        for (int x : A) {
            while (cur < x) {
                cur++;
                ans++;
            }
            cur++;
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
            new StandingOvation().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
