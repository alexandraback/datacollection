import java.util.Scanner;


/**
 * @author dai
 * 
 */
public class GCJ2014Round1BB {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %d%n", i, new GCJ2014Round1BB().solve(sc));
        }
    }

    private long solve(Scanner sc) throws Exception {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        
        // return solveNaive(a, b, k);
        
        return func(a - 1, b - 1, k - 1, 31);
    }

    private long solveNaive(int a, int b, int k) {
        int count = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int v = i & j;
                if (v < k) count ++;
            }
        }
        return count;
    }

    static final int INF = 1000000000;


    /**
     * @param a
     * @param b
     * @param k
     * @param digit 1-based
     * @param waysSoFar
     * @return
     */
    long func(int a, int b, int k, int digit) {
        if (a < 0 || b < 0 || k < 0) return 0;  // impossible
        if (digit == 0) {
            return 1;
        }

        // ensure a <= b
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        long ret = 0;
        int maxGeneratableNo = (1 << digit) - 1;
        if (maxGeneratableNo <= k) {
            // all pairs are acceptable
            a = Math.min(a, maxGeneratableNo);
            b = Math.min(b, maxGeneratableNo);
            ret = (long) (a + 1) * (b + 1);
//            System.out.println(String.format("f1(a=%d, b=%d, k=%d, d=%d) = %d", a, b, k,
//                    digit, ret));
            return ret;
        }

        // if the digit-th digit is 1
        int minGeneratableNo = (1 << digit - 1);
        ret += func(a - minGeneratableNo, b - minGeneratableNo, k - minGeneratableNo,
                digit - 1);

        // otherwise
        boolean aIsArbitrary = a >= maxGeneratableNo;
        boolean bIsArbitrary = b >= maxGeneratableNo;
        if (aIsArbitrary) {
            ret += func(a, b, k, digit - 1) * 3;
        }
        else if (bIsArbitrary) {
            ret += func(a, b, k, digit - 1) * 2;
            ret += func(a - minGeneratableNo, b, k, digit - 1);
        }
        else {
            ret += func(a, b, k, digit - 1);
            ret += func(a - minGeneratableNo, b, k, digit - 1);
            ret += func(a, b - minGeneratableNo, k, digit - 1);
        }
//        System.out.println(String.format("f2(a=%d, b=%d, k=%d, d=%d) = %d", a, b, k,
//                digit, ret));

        return ret;
    }
}
