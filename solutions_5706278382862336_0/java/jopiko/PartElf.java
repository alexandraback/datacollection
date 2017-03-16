import java.util.Scanner;

public class PartElf {

    public String solve(Scanner scanner) {

        String l = scanner.nextLine();
        String[] pts = l.split("/");

        int P = Integer.parseInt(pts[0]);
        int Q = Integer.parseInt(pts[1]);

        int m = Math.min(Q, 2 * P);
        int n = 2 * P - m;

        int r = Math.min(dfs(m, Q, 1), dfs(n, Q, 1));

        if (r > 0) {
            return "" + r;
        } else {
            return "impossible";
        }

    }

    private int dfs(int P, int Q, int d) {

        if (d > 40) {
            return -1;
        }

        if (P == Q) {
            return d;
        }

        if (P == 0) {
            return 100;
        }

        int m = Math.min(Q, 2 * P);
        int n = 2 * P - m;

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
