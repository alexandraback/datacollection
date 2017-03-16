import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by study on 4/15/16.
 */
public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.print(String.format("Case #%d: ", i));
            solve(scanner);
        }
    }

    public static void solve(Scanner scanner) {
        int N = scanner.nextInt();
        int N2 = 2 * N - 1;
        Map<Integer, Integer> d = new HashMap<>();

        for (int i = 0; i < N2; i++) {
            for (int j = 0; j < N; j++) {
                int num = scanner.nextInt();

                if (d.get(num) == null) {
                    d.put(num, 1);
                } else {
                    d.put(num, d.get(num) + 1);
                }
            }
        }
        List<Integer> missings = new ArrayList<>();

        AtomicInteger ai = new AtomicInteger(0);
        d.forEach((k, v) -> {
            ai.addAndGet(v);
            if (v % 2 != 0) {
                missings.add(k);
            }
        });
        ai.addAndGet(missings.size());
        if(ai.get() != 2* N*N) {
            System.out.println(false);
        }

        Collections.sort(missings);
        missings.forEach(missing -> {
            System.out.print(" " + missing);
        });
        System.out.println();
    }
}
