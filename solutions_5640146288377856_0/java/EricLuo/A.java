package GCJ2015.Round1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Zhenyi Luo on 15-5-10.
 */
public class A {
    final static String PROBLEM_NAME = "A-small-attempt0";
    final static String WORK_DIR = "/Users/cecilia/Downloads/" + PROBLEM_NAME;

    public void solve(Scanner sc, PrintWriter pw){
        int R = sc.nextInt();
        int C = sc.nextInt();
        int W = sc.nextInt();
        pw.println(R * solve(C, W));
    }

    public long solve(int c, int w){
        int cur = w;
        long ans = 0;
        while(cur < c){
            cur += w;
            ans ++;
        }
        ans += w;
        return ans;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + ".in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + ".out"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new A().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
