import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Reordering {

    int N;
    String[] cars;
    int[] p;
    int cnt;

    public String solve(Scanner scanner) {

        N = scanner.nextInt();
        scanner.nextLine();
        String l = scanner.nextLine();
        cars = l.split(" ");

        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }

        perm(0);

        cnt %= 1000000007;

        return "" + cnt;

    }

    private void perm(int k) {
        if (k == N) {
            check();
        } else {

            for (int i = k; i < N; i++) {

                swap(i, k);
                perm(k + 1);
                swap(i, k);

            }
        }
    }

    private void swap(int i, int j) {
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
    }

    private void check() {

        StringBuilder sb = new StringBuilder();
        for (int x : p) {
            sb.append(cars[x]);
        }

        Set<Character> seen = new HashSet<Character>();
        seen.add(sb.charAt(0));
        for (int i = 1; i < sb.length(); i++) {
            if (sb.charAt(i) != sb.charAt(i - 1) && seen.contains(sb.charAt(i))) {
                return;
            }
            seen.add(sb.charAt(i));
        }

        cnt++;

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        for (int cs = 1; cs <= T; cs++) {
            System.out.printf("Case #%d: %s\n", cs, new Reordering().solve(scanner));
        }

        scanner.close();
    }

}
