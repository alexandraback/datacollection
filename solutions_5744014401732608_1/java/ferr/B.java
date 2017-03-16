import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;


public class B {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new B().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

    String consAns(int B, char[][] arr) {
        StringBuilder ans = new StringBuilder();
        for (int i = 1; i <= B; ++i) {
            for (int j = 1; j <= B; ++j) {
                ans.append(arr[i][j]);
            }
            if (i != B) {
                ans.append('\n');
            }
        }
        return ans.toString();
    }

    private String nextCase(int caseNum) {
        int B = sc.nextInt();
        long M = sc.nextLong();
        long[] arr = new long[B + 1];
        arr[B] = 1;
        for (int i = B - 1; i >= 1; --i) {
            for (int j = i + 1; j <= B; ++j) {
                arr[i] += arr[j];
            }
        }
//        System.out.println(Arrays.toString(arr));
        char[][] ans = new char[B + 1][B + 1];
        for (int i = 0; i <= B; ++i) {
            for (int j = 0; j <= B; ++j) {
                ans[i][j] = '0';
            }
        }
        if (M > arr[1]) {
            return "IMPOSSIBLE";
        }
        for (int j = 2; j <= B; ++j) {
            for (int k = j + 1; k <= B; ++k) {
                ans[j][k] = '1';
            }
        }
        for (int j = 2; j <= B; ++j) {
            if (M >= arr[j]) {
                M -= arr[j];
                ans[1][j] = '1';
            }
        }
        if (M != 0) {
            throw new RuntimeException("Achtung!");
        }
        return "POSSIBLE\n" + consAns(B, ans);
    }
}