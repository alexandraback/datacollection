
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int s = in.nextInt();
        int p = in.nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = in.nextInt();
        }
        int k = 0;
        int rem = s;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] >= 2) k++;
            int mx = (t[i] + 2) / 3;
            if (mx >= p) {
                res++;
            } else if (rem > 0 && t[i] >= 2) {
                mx = (t[i] + 4) / 3;
                if (mx >= p) {
                    res++;
                    rem--;
                }
            }
        }
        if (k < s) throw new RuntimeException("!!!");
        return "" + res;
    }
}