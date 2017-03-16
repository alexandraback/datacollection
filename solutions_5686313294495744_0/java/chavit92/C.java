import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by vitalii on 30.04.2016.
 */
public class C {
    PrintWriter out;
    Scanner in;

    public void solve() {
        int n = in.nextInt();
        String[] firsts = new String[n];
        String[] seconds = new String[n];
        for (int i=  0; i < n; i++) {
            firsts[i] = in.next();
            seconds[i] = in.next();
        }
        int best = 0;
        for (int i = 0; i < (1 << n); i++) {
            Set<String> wasFirst = new HashSet<>();
            Set<String> wasSecond = new HashSet<>();
            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) != 0) {
                    wasFirst.add(firsts[j]);
                    wasSecond.add(seconds[j]);
                }
            }
            boolean fl = true;
            for (int j = 0; j < n; j++) {
                fl &=  wasFirst.contains(firsts[j]);
                fl &=  wasSecond.contains(seconds[j]);
            }
            if (fl) {
                best = Math.max(best, n - Integer.bitCount(i));
            }
        }
        out.print(best);
    }

    public void run() throws IOException {
        in = new Scanner(new File("C.in"));
        out = new PrintWriter("C.out");
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            System.err.println(i);
            out.print("Case #" + i + ": ");
            solve();
//            out.print(" ");
//            solveStupid();
            out.println();
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
