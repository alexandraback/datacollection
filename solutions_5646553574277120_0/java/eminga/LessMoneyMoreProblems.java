
import java.util.ArrayList;
import java.util.Scanner;

public class LessMoneyMoreProblems {

    static int v;
    static boolean[] possible;
    static ArrayList<Integer> denominations;
    static int b;

    static boolean evaluate() {
        for (int i = 1; i < possible.length; i++) {
            if (!possible[i]) {
                return false;
            }
        }
        return true;
    }

    static void init() {
        possible = new boolean[v + 1];
        possible[0] = true;
        for (Integer denomination : denominations) {
            add(denomination);
        }
    }

    static boolean add(int x) {
        boolean result = false;
        for (int i = possible.length - 1; i >= x; i--) {
            if (possible[i - x] && !possible[i]) {
                result = true;
                possible[i] = true;
            }
        }
        return result;
    }

    static int test(int min, int max) {
        if (min >= max || evaluate()) {
            return min;
        }
        ArrayList<Integer> candidates = new ArrayList<>();
        for (int i = 1; i <= v; i++) {
            if (!denominations.contains(i)) {
                if (add(i)) {
                    candidates.add(i);
                }
                init();
            }
        }
        int best = max;
        for (Integer candidate : candidates) {
            denominations.add(candidate);
            init();
            int x = test(min + 1, best);
            denominations.remove(candidate);
            init();
            if (x < best) {
                best = x;
            }
        }

        return best;

    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            int c = s.nextInt();
            int d = s.nextInt();
            v = s.nextInt();

            denominations = new ArrayList<>(d);
            for (int j = 0; j < d; j++) {
                denominations.add(s.nextInt());
            }

            b = 0;
            if (!denominations.contains(1)) {
                denominations.add(1);
                b++;
            }
            if (v > 1 && !denominations.contains(2)) {
                denominations.add(2);
                b++;
            }

            init();
            System.out.println("Case #" + i + ": " + test(b, Integer.MAX_VALUE));
        }
    }

}
