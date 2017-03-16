import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by xianran on 5/11/14.
 */
public class A {

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static public void main(String[] args) throws Exception {
        int ntest;
        Scanner scanner = new Scanner(System.in);
        ntest = scanner.nextInt();
        PrintWriter writer = new PrintWriter(new FileWriter("answer.txt"));

        scanner.nextLine();
        for (int nt = 1; nt <= ntest; nt++) {
            long P, Q;
            String line = scanner.nextLine();
            P = Long.parseLong(line.split("/")[0]);
            Q = Long.parseLong(line.split("/")[1]);


            long gong = gcd(P, Q);

            P /= gong;
            Q /= gong;

            boolean Qvalid = false;

            for (int t = 0;  t <= 41; t++) {
                if (Math.abs(Math.pow(2, t) - Q) < 1e-6) {
                    Qvalid = true;
                    break;
                }
            }

            int ans = 0;

            if (Qvalid) {
                while (P < Q) {
                    Q = Q / 2;
                    ans += 1;
                }
            }
//
//            if (P > Q/2) {
//                P -= Q/2;
//            }
//
//            int ans = -1;
//


            if (ans > 0) {
                writer.println("Case #" + nt + ": " + ans);
            } else {
                writer.println("Case #" + nt + ": " + "impossible");
            }
        }

        scanner.close();
        writer.close();
    }

}
