
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int a = in.nextInt();
        int b = in.nextInt();

        int k = 1;
        int c = 1;
        while (k * 10 <= b) {
            k *= 10;
            c++;
        }

        int[] num = new int[10000000];

        for (int n = a; n <= b; n++) {
            int min = n;
            int nn = n;
            for (int i = 0; i < c; i++) {
                nn = (nn / 10) + (nn % 10) * k;
                if (nn >= k) {
                    min = Math.min(min, nn);
                }
            }
            num[min]++;
        }

        long res = 0;

        for (int n : num) {
            res += (1L * n * (n - 1)) / 2;
        }
        return "" + res;
    }
}