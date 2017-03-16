
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class D {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/D-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/D.out"));
        Scanner sc = new Scanner(in);

        for (int cse = 1, cases = sc.nextInt(); cse <= cases; cse++) {
            int n = sc.nextInt();
            double[] a = new double[n];
            double[] b = new double[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextDouble();
            for (int i = 0; i < n; i++) b[i] = sc.nextDouble();

            int p1 = findWar(a, b);
            Arrays.sort(a);
            int p2 = findWar(a, b);
            double[] aa = new double[a.length];
            for (int i = 0; i < n; i++) aa[i] = a[n-1-i];
            int p3 = findWar(aa, b);
            if (p1!=p2 ||p2!=p3) throw new RuntimeException();

            int pointsWar = findWar(a, b);
            int pointsDeceit = 0;

            Arrays.sort(a);
            Arrays.sort(b);
            for (int i = 0; i < n; i++) {
                int mina = findMin(a);
                int minb = findMin(b);
                if (a[mina] < b[minb]) {
                    a[mina] = -1;
                    b[findMax(b)] = -1;
                } else {
                    a[mina] = -1;
                    b[minb] = -1;
                    pointsDeceit++;
                }
            }

            System.out.printf("Case #%d: %d %d%n", cse, pointsDeceit, pointsWar);
        }
    }

    private static int findAnswer(double[] sorted, double d) {
        for (int i = 0; i < sorted.length; i++) if (sorted[i] >= d) return i;
        for (int i = 0; i < sorted.length; i++) if (sorted[i]>=0) return i;
        throw new RuntimeException();
    }

    private static int findMax(double[] sorted) {
        for (int i = sorted.length-1; i>=0; i--) if (sorted[i] >= 0) return i;
        throw new RuntimeException();
    }

    private static int findMin(double[] sorted) {
        for (int i = 0; i < sorted.length; i++) if (sorted[i]>=0) return i;
        throw new RuntimeException();
    }

    private static int findWar(double[] a, double[] b) {
        double[] c = Arrays.copyOf(b, b.length);
        int points = 0;
        Arrays.sort(c);
        for (int i = 0; i < a.length ; i++) {
            int x = findAnswer(c, a[i]);
            if (a[i]>=c[x]) points++;
            c[x] = -1;
        }
        return points;
    }
}
