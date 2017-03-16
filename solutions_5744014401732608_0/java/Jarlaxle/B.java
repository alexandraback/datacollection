import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("B-small-attempt0.in.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("B-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            int b = scanner.nextInt();
            int m = scanner.nextInt();
            writer.printf("Case #%d: %s\n", testCase, solve(b, m));
        }
        writer.close();
    }

    private static String solve(int b, int m) {
        int[][] a = new int[b][b];
        int n = (b*b - b) / 2;

        String res = "IMPOSSIBLE";
        for (int x = 0; x < (1 << n); ++x) {
            int idx = 0;
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j <= i; ++j) {
                    a[i][j] = 0;
                }
                for (int j = i + 1; j < b; ++j) {
                    a[i][j] = ((1 << (idx++)) & x) > 0 ? 1 : 0;
                }
            }

            for (int k = 0; k < b; ++k) {
                for (int i = 0; i < b; ++i) {
                    for (int j = 0; j < b; ++j) {
                        a[i][j] += a[i][k]*a[k][j];
                    }
                }
            }
            if (a[0][b - 1] == m) {
                res = "POSSIBLE\n";
                idx = 0;
                for (int i = 0; i < b; ++i) {
                    for (int j = 0; j <= i; ++j) {
                        res += '0';
                    }
                    for (int j = i + 1; j < b; ++j) {
                        res += ((1 << (idx++)) & x) > 0 ? '1' : '0';
                    }
                    if (i != b - 1) {
                        res += '\n';
                    }
                }
                break;
            }
        }
        return res;
    }


}
