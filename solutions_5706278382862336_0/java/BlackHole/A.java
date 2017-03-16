package Round1C.A;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class A {
    public void solve(Scanner sc, PrintWriter pw) throws Exception {
        String s = sc.next();
        String[] t = s.split("/");
        int P = Integer.parseInt(t[0]);
        int Q = Integer.parseInt(t[1]);
        int Qother = Q;
        int maxGen = 0;
        while (Qother % 2 == 0) {
            Qother /= 2;
            maxGen++;
        }
        if (P % Qother != 0) {
            pw.println("impossible");
            return;
        }
        P /= Qother;
        Q /= Qother;

        int gen = maxGen;
        int f = 1;
        while (f <= P) {
            f *= 2;
            gen--;
        }
        pw.println(gen + 1);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
        A solver = new A();
        int T = sc.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(sc, pw);
        }
        pw.flush();
        pw.close();
    }
}
