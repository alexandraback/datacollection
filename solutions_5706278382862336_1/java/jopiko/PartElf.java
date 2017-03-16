import java.util.Scanner;

public class PartElf {

    public String solve(Scanner scanner) {

        String l = scanner.nextLine();
        String[] pts = l.split("/");

        long P = Long.parseLong(pts[0]);
        long Q = Long.parseLong(pts[1]);

        long m = Math.min(Q, 2 * P);
        long n = 2 * P - m;

        long r = Math.min(dfs(m, Q, 1), dfs(n, Q, 1));

        if (r > 0) {
            return "" + r;
        } else {
            return "impossible";
        }

    }

    private long dfs(long P, long Q, long d) {

        if (d > 40) {
            return -1;
        }

        if (P == Q) {
            return d;
        }

        if (P == 0) {
            return 100;
        }

        long m = Math.min(Q, 2 * P);
        long n = 2 * P - m;

        return Math.min(dfs(m, Q, d+1), dfs(n, Q, d+1));

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        scanner.nextLine();

        for (int cs = 1; cs <= T; cs++) {
            System.out.printf("Case #%d: %s\n", cs, new PartElf().solve(scanner));
        }

        scanner.close();
    }

}
