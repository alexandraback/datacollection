package qual2014;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Arrays;

public class D {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("qual2014/D-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("qual2014/D-small-0.in"), new FileOutputStream("qual2014/D-small-0.out"));
        io = new Kattio(new FileInputStream("qual2014/D-large-0.in"), new FileOutputStream("qual2014/D-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new D().solve(io);
        }
        io.close();
    }

    private void solve(Kattio io) {
        int N = io.getInt();
        double a[] = new double[N], b[] = new double[N];
        for (int i = 0; i < N; i++) {
            a[i] = io.getDouble();
        }
        for (int i = 0; i < N; i++) {
            b[i] = io.getDouble();
        }

        Arrays.sort(a);
        Arrays.sort(b);

        io.println(deceitfulWarScore(a, b) + " " + warScore(a, b));
    }

    private int warScore(double[] a, double[] b) {
        int n = a.length, score = 0;
        boolean[] taken = new boolean[n];
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < n && (b[j] < a[i] || taken[j])) j++;
            if (j < n) {
                taken[j] = true;
            } else {
                score++;
            }
        }
        return score;
    }

    private int deceitfulWarScore(double[] a, double[] b) {
        int n = a.length;
        int score = 0, lo = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[lo]) {
                score++;
                lo++;
            }
        }
        return score;
    }
}
