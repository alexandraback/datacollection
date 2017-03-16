import java.io.*;
import java.util.*;

public class B {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    String solveOne() {
        int sizeI = in.nextInt();
        int sizeJ = in.nextInt();
        int a[][] = new int[sizeI][sizeJ];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                a[i][j] = in.nextInt();
                Assert.check(1 <= a[i][j] && a[i][j] <= 100);
            }
        }
        int maxValueSameI[] = new int[sizeI];
        int maxValueSameJ[] = new int[sizeJ];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                maxValueSameI[i] = Math.max(maxValueSameI[i], a[i][j]);
                maxValueSameJ[j] = Math.max(maxValueSameJ[j], a[i][j]);
            }
        }
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                if (a[i][j] < maxValueSameI[i] && a[i][j] < maxValueSameJ[j]) {
                    return "NO";
                }
            }
        }
        return "YES";
    }

    void solve() {
        int nCases = in.nextInt();
        for (int iCase = 1; iCase <= nCases; iCase++) {
            out.println("Case #" + iCase + ": " + solveOne());
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new B().run();
    }
}
