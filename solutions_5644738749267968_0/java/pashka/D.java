
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        double[] a = new double[n];
        double[] b = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextDouble();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int j = n - 1;
        int res1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[j] > b[i]) {
                res1++;
                j--;
            }
        }
        j = 0;
        int res2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[j] < b[i]) {
                res2++;
                j++;
            }
        }
        return res1 + " " + (n - res2);
    }
}