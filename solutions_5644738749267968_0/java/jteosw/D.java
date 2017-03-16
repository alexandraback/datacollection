import java.util.*;
public class D {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %s\n", i, solve());
        }
    }

    public static String solve() {
        int n = s.nextInt();
        Double[] a = new Double[n];
        Double[] b = new Double[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            b[i] = s.nextDouble();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int deceit = 0;
        int a1 = 0;
        int b1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[a1] > b[b1]) {
                deceit++;
                a1++;
                b1++;
            } else {
                a1++;
            }
        }

        TreeSet<Double> aa = new TreeSet<Double>(Arrays.asList(a));
        TreeSet<Double> bb = new TreeSet<Double>(Arrays.asList(b));

        for (Double chosen : aa) {
            Double match = bb.ceiling(chosen);
            if (match != null) {
                bb.remove(match);
            } else {
                break;
            }
        }
        int war = bb.size();

        return "" + deceit + " " + war;
    }
}
