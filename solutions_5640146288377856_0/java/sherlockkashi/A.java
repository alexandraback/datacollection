import java.io.PrintStream;
import java.util.Scanner;

public class A {

    Scanner             sc       = new Scanner(getClass().getResourceAsStream(IN));
    static final String FILENAME = "A-small";
    static final String IN       = FILENAME + ".in";
    static final String OUT      = FILENAME + ".out";
    PrintStream         out      = System.out;

    private void solve() {
        int ans = 0;
        int R = sc.nextInt();
        int C = sc.nextInt();
        int W = sc.nextInt();

        ans += R * ((C - 1)/W);
        ans += R * W;

        out.println(ans);
    }

    private void run() throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new A().run();
    }
}