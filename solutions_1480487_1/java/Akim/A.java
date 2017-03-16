import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    Scanner in;
    PrintWriter out;

    void doit(int tnum) {
        out.print("Case #" + tnum + ":");
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        double sum = 0;
        for (int i = 0; i < n; ++i) sum += a[i];
        for (int i = 0; i < n; ++i) {
            double OMAX = 1.0;
            double OMIN = 0.0;
            for (int ttt = 0; ttt < 100; ++ttt) {
                double OTRY = (OMAX + OMIN) / 2.0;
                double score = a[i] + sum * OTRY;
                double rest = 1.0 - OTRY;
                for (int j = 0; j < n; ++j) if (i != j) {
                    if (a[j] > score) continue;
                    rest -= (score - a[j]) / sum;
                }
                if (rest > 0) OMIN = OTRY; else OMAX = OTRY;
            }
            double res = (OMIN + OMAX) * 50.0;
            if (res < 1e-8) out.print(" 0.0"); else
            out.print(" " + res);
        }
        out.println();
    }

    public void doit() throws IOException{
        out = new PrintWriter(new FileOutputStream("output.txt"));
        in = new Scanner(new FileInputStream("A-large.in"));
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            doit(i + 1);
        }
        out.close();

    }
    public static void main(String[] args) throws IOException{
        new A().doit();
    }
}
