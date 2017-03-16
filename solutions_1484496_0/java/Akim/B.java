import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    Scanner in;
    PrintWriter out;

    void doit(int tnum) {
        out.println("Case #" + tnum + ":");
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += a[i];
        int[] b = new int[sum + 1];
        for (int mask = 0; mask < (1 << n); ++mask) {
            int t = 0;
            for (int i = 0; i < n; ++i)
                if ((mask & (1 << i)) != 0) t += a[i];
            if (b[t] != 0) {
                for (int i = 0; i < n; ++i) if ((mask & (1 << i)) != 0) out.print(a[i] + " ");
                out.println();
                for (int i = 0; i < n; ++i) if ((b[t] & (1 << i)) != 0) out.print(a[i] + " ");
                out.println();
                return;
            }
            b[t] = mask;
        }
        out.println("Impossible");
    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("C-small-attempt0.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            System.err.println(i + 1);
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new B().doit();
    }
}
