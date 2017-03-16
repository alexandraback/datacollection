import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class CC {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("C-small-attempt0.in.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("C-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            int n = scanner.nextInt();
            String[] a = new String[n];
            String[] b = new String[n];
            for (int i = 0; i < n; ++i) {
                a[i] = scanner.next();
                b[i] = scanner.next();
            }
            writer.printf("Case #%d: %d\n", testCase, solve(a, b));
        }
        writer.close();
    }

    private static int solve(String[] a, String[] b) {
        int n = a.length;
        Set<String> ua = new HashSet<>();
        Set<String> ub = new HashSet<>();
        int res = 0;
        for (int i = 0; i < (1 << n); ++i) {
            ua.clear();
            ub.clear();
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) == 0) {
                    ua.add(a[j]);
                    ub.add(b[j]);
                }
            }
            boolean good = true;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    if (!ua.contains(a[j]) || !ub.contains(b[j])) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) {
                res = Math.max(res, bc(i));
            }
        }
        return res;
    }

    static int bc(int n) {
        int res = 0;
        while (n > 0) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
}
