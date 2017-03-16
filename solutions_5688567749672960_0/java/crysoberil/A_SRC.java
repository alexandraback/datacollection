import java.io.File;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("/home/crysoberil/a"));
        new Main().run(in);
        in.close();
    }

    private void run(Scanner in) {
        int testCase = in.nextInt();

        for (int kase = 1; kase <= testCase; kase++) {
            long n = in.nextLong();
            int res = bfs(n) + 1;
            System.out.println(String.format("Case #%d: %d", kase, res));
        }
    }

    private int bfs(long n) {
        LinkedList<Long> q = new LinkedList<Long>();
        int[] dis = new int[(int) (n + 1)];
        Arrays.fill(dis, Integer.MAX_VALUE);

        q.addLast((long) 1);
        dis[1] = 0;

        while (!q.isEmpty()) {
            long u = q.removeFirst();

            if (u == n)
                return dis[(int) u];

            long v1 = u + 1;
            long v2 = reverse(u, 0);

            if (v1 <= n) {
                if (dis[(int) u] + 1 < dis[(int) v1]) {
                    dis[(int) v1] = dis[(int) u] + 1;
                    q.addLast(v1);
                }
            }

            if (v2 <= n) {
                if (dis[(int) u] + 1 < dis[(int) v2]) {
                    dis[(int) v2] = dis[(int) u] + 1;
                    q.addLast(v2);
                }
            }
        }

        return -2;
    }

    private long reverse(long u, long soFar) {
        if (u == 0)
            return soFar;

        return reverse(u / 10, soFar * 10 + (u % 10));
    }
}
