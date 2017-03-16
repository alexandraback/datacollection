import com.google.common.primitives.Ints;

import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            int d = scanner.nextInt();
            int[] ps = new int[d];
            for (int di = 0; di < d; di++) {
                ps[di] = scanner.nextInt();
            }
            int rMin = solve(ps);
            System.out.printf("Case #%d: %d\n", ti, rMin);
        }
    }

    static int solve(int... ps) {
        List<Integer> integersList = Ints.asList(ps);
        Collections.sort(integersList, Collections.reverseOrder());

        int rMax = ps[0];
        int rMin = rMax;
        for (int i = rMax; i > 0; i--) {
            int r = calcR(i, ps);
//            System.out.printf("r[%d] = %d\n", i, r);
            if (r < rMin) {
                rMin = r;
            }
        }
        return rMin;
    }

    private static int calcR(int l, int[] ps) {
        int s = 0;
        for (int p : ps) {
            if (p > l) {
//                s += p / l - (p % l == 0 ? 1 : 0);
                s += (p - 1) / l;// - (p % l == 0 ? 1 : 0);
            } else {
                break;
            }
        }
        return s + l;
    }
}
