import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Ap {
    static int T, A, B;
    static List<BigDecimal> p = new ArrayList<BigDecimal>();

    static BigDecimal m1() {
        BigDecimal s = BigDecimal.ONE;
        for (int i = 0; i < A; i++) s = s.multiply(p.get(i));
        return s.multiply(new BigDecimal(B - A + 1)).add(
                (BigDecimal.ONE.subtract(s).multiply(new BigDecimal(B - A + 1 + B + 1))));
    }

    static BigDecimal m3() {
        return new BigDecimal(B + 2);
    }

    static BigDecimal m2(int k) {
        BigDecimal s = BigDecimal.ONE;
        for (int i = 0; i < A - k; i++) s = s.multiply(p.get(i));
        return s.multiply(new BigDecimal(k + (B - (A - k) + 1))).add(
                BigDecimal.ONE.subtract(s).multiply(new BigDecimal(k + (B - (A - k) + 1) + B + 1)));
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        T = s.nextInt();
        for (int t = 0; t < T; t++) {
            p.clear();

            A = s.nextInt();
            B = s.nextInt();
            for (int i = 0; i < A; i++)
                p.add(new BigDecimal(s.nextDouble()));

            BigDecimal min = new BigDecimal(100000000.0);
            BigDecimal a = m1();
            if (a.compareTo(min) == -1) min = a;
            a = m3();
            if (a.compareTo(min) == -1) min = a;
            for (int i = 1; i <= A; i++) {
                a = m2(i);
                if (a.compareTo(min) == -1) min = a;
            }
            System.out.println("Case #" + (t + 1) + ": " + min);


        }
    }
}