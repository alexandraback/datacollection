package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
@SuppressWarnings("FieldCanBeLocal")
public class DLarge {
    @SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
    private int caseNumber;
    private static Scanner sc;
    private static PrintStream out;
    private static boolean PRINT_TO_CONSOLE = true;
//    private static boolean PRINT_TO_CONSOLE = false;

    void solve() {
        int k = sc.nextInt();
        int c = sc.nextInt();
        int s = sc.nextInt();

        c = Math.min(c, k);

        int ans = (k + c - 1) / c;
        if (ans > s) {
            out.printf("IMPOSSIBLE\n");
            return;
        }

        for (int i = 0; i < ans; ++i) {
            int left0 = Math.min(i * c, k - c);
            long left = left0;
            for (int j = 2; j <= c; ++j) {
                left = left * k + left0 + j - 1;
            }

            long pos = left + 1;

            if (i != 0) {
                out.printf(" ");
            }
            out.printf("%d", pos);
        }
        out.println();
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test";
//        String file = "D-small-attempt0";
//        String file = "D-small-attempt1";
        String file = "D-large";

        String outFileName = file + ".out";
        out = PRINT_TO_CONSOLE ? new CJPrintStream(outFileName) : new PrintStream(outFileName);

        String inFile = file + ".in";
        sc = new Scanner(new File(inFile));

        int cases = sc.nextInt();
        for (int caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            out.printf("Case #%s: ", caseNumber);
            DLarge template = new DLarge();
            template.caseNumber = caseNumber;
            template.solve();
            out.flush();
        }

        sc.close();
    }

    static class CJPrintStream extends PrintStream {
        public CJPrintStream(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        @SuppressWarnings("NullableProblems")
        @Override
        public PrintStream printf(String format, Object... args) {
            System.out.printf(format, args);
            return super.printf(format, args);
        }

        @Override
        public void println() {
            System.out.println();
            super.println();
        }

        @Override
        public void flush() {
            System.out.flush();
            super.flush();
        }
    }
}
