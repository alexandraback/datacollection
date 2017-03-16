import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Scanner;

public class A {

    private static Scanner sc;
    private static PrintWriter pw;

    private String run_case() {
        int smax = sc.nextInt();
        String ss = sc.next();
        int clapping = 0;
        int add = 0;
        for (int i = 0; i < ss.length(); ++i) {
            int sq = ss.charAt(i) - '0';
            if (clapping < i) {
                add += i - clapping;
                clapping = i;
            }
            clapping += sq;
        }
        return "" + add;
    }

    private void run() {
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            String res = run_case();
            pw.println("Case #" + (i + 1) + ": " + res);
        }
        pw.flush();
    }

    public static void main(String[] args) throws Exception {
        if (args.length == 2) {
            sc = new Scanner(Paths.get(args[0]));
            pw = new PrintWriter(args[1]);
        } else {
            sc = new Scanner(System.in);
            pw = new PrintWriter(System.out);
        }
        new A().run();
    }
}
