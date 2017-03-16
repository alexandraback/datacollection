import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Round 1C. Problem A.
 */
public class ProblemA {

    public static void main(String[] args) throws Exception {
        new ProblemA().run();
    }

    private void run() throws Exception {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int testCount = in.nextInt();
        in.nextLine();
        for (int test = 1; test <= testCount; test++) {
            String str = in.nextLine();
            int n = Integer.valueOf(str.substring(str.indexOf(" ") + 1));
            str = str.substring(0, str.indexOf(" "));
            int res = 0;
            for (int i = 0; i < str.length(); i++) {
                for (int j = i + n - 1; j < str.length(); j++) {
                    int cnt = 0;
                    int max = 0;
                    for (int k = i; k <= j; k++) {
                       if ("aeiou".indexOf(str.charAt(k)) < 0) {
                           cnt++;
                           if (cnt > max) {
                               max = cnt;
                           }
                       } else {
                           cnt = 0;
                       }
                    }
                    if (max >= n) {
                        res++;
                    }
                }
            }

            out.print("Case #" + test + ": " + res);
            if (test < testCount) {
                out.println();
            }
        }

        in.close();
        out.close();
    }
}
