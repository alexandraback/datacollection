import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    private int maxNonSurprise(int v) {
        switch (v % 3) {
            case 0: return v / 3;
            case 1:
            case 2: return v / 3 + 1;
            default: throw new AssertionError();
        }
    }

    private int maxSurprise(int v) {
        if (v <= 2) {
            return v;
        }
        switch (v % 3) {
            case 0:
            case 1: return v / 3 + 1;
            case 2: return v / 3 + 2;
            default: throw new AssertionError();
        }
    }

    public void run(Scanner in, PrintWriter out, int nCase) {
        int n = in.nextInt();
        int s = in.nextInt();
        int p = in.nextInt();
        int alreadyP = 0;
        int potentialP = 0;
        for (int i = 0; i < n; ++i) {
            int v = in.nextInt();
            if (maxNonSurprise(v) >= p) {
                ++alreadyP;
            } else {
                if (maxSurprise(v) >= p) {
                    ++potentialP;
                }
            }
        }
        int ans = alreadyP + Math.min(s, potentialP);
        out.printf("Case #%d: %d%n", nCase, ans);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = B.class.getSimpleName().toLowerCase();

        Scanner in = new Scanner(new File(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");

        int nCases = in.nextInt();

        for (int i = 1; i <= nCases; ++i) {
            new B().run(in, out, i);
        }

        out.close();
        in.close();
    }
}
