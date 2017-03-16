/**
 * Created by Tanya on 11.05.14.
 */
import java.io.*;
import java.util.Scanner;


public class ProblemA {
    static long deg2 = 0;
    static long calculateDegree( long Q ) {
        long rest;
        deg2 = 0;
        while (Q % 2 == 0) {
            Q /= 2;
            deg2++;
        }
        rest = Q;
        return rest;
    }
    public static void main( String[] arg ) throws IOException {
        int T;
        FileReader fr = new FileReader("a-small-attempt0.in"); /* c-large.in */
        FileWriter fw = new FileWriter("a.out");
        Scanner sc = new Scanner(fr);
        T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            fw.write("Case #" + t + ": ");
            String   s = sc.nextLine();
            int i = s.indexOf("/");
            String sP = s.substring(0, i);
            String sQ = s.substring(i + 1, s.length());
            long P = Long.parseLong(sP);
            long Q = Long.parseLong(sQ);
            if (Q % P == 0) {
                Q /= P;
                P = 1;
            }
            long res = calculateDegree(Q);
            if (P % res == 0) {
                P /= res;
                Q /= res;
            }
            else {
                fw.write("impossible\n");
                continue;
            }
            res = Q / 2;
            long ans = 1;
            while (res > P) {
                res /= 2;
                ans++;
            }
            fw.write("" + ans + "\n");
        }
        fr.close();
        fw.close();
    }
}
