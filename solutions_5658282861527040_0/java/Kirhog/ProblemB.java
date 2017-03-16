import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
public class ProblemB {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

        String file = "B-small-attempt0";
//        String file = "problem-b-test";

        String inFile = file + ".in";
        System.setOut(new PrintStream(file + ".out"));

        Scanner scan = new Scanner(new File(inFile));

        ProblemB problem = new ProblemB();

        int tests = scan.nextInt();
        for (int test = 1; test <= tests; ++test) {
            problem.solve(test, scan);
        }

        scan.close();
    }

    void solve(int test, Scanner scan) {
        int s = 0;
        int a = scan.nextInt();
        int b = scan.nextInt();
        int k = scan.nextInt();
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if ((i & j) < k) {
                    ++s;
                }
            }
        }
        System.out.printf("Case #%s: %s\n", test, s);
    }
}
