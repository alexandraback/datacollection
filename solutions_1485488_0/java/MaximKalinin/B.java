import java.util.*;

class Cell implements Comparable<Cell> {
    public int i, j;
    public int t;

    Cell(int i, int j, int t) {
        this.i = i; this.j = j; this.t = t;
    }
    @Override
    public int compareTo(Cell o) {
        if (t < o.t) return -1;
        if (t > o.t) return 1;
        return 0;
    }
}

public class B {
    public static void main(String[] args) {
        Locale.setDefault(Locale.ENGLISH);
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int H = in.nextInt(), N = in.nextInt(), M = in.nextInt();
            int[][] ceiling = new int[N][M];
            int[][] floor = new int[N][M];
            for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
                ceiling[i][j] = in.nextInt();
            }
            for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
                floor[i][j] = in.nextInt();
            }
            double res = new B().solve(H, floor, ceiling);
            System.out.print("Case #");
            System.out.print(t);
            System.out.print(": ");
            System.out.printf("%.8f\n", res / 10);
        }
    }

    final static int[] dx = new int[]{-1, 0, 1, 0};
    final static int[] dy = new int[]{0, 1, 0, -1};

    int[][] floor, ceiling;
    int H, N, M;

    int maxWaterLevel(int i0, int j0, int i1, int j1) {
        if (i1 < 0 || i1 >= N || j1 < 0 || j1 >= M)
            return -1;
        if (floor[i1][j1] > ceiling[i0][j0] - 50)
            return -1;
        if (floor[i0][j0] > ceiling[i1][j1] - 50)
            return -1;
        if (floor[i1][j1] > ceiling[i1][j1] - 50)
            return -1;
        return ceiling[i1][j1] - 50;
    }

    int[][] d;


    private double solve(int H, int[][] floor, int[][] ceiling) {
        this.H = H;
        this.N = floor.length;
        this.M = floor[0].length;
        this.floor = floor;
        this.ceiling = ceiling;
        this.d = new int[N][M];
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
            d[i][j] = Integer.MAX_VALUE;
        d[0][0] = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        PriorityQueue<Cell> queue = new PriorityQueue<Cell>();
        q.add(0); q.add(0);
        queue.add(new Cell(0, 0, 0));
        while (!q.isEmpty()) {
            int i0 = q.poll(), j0 = q.poll();
            for (int p = 0; p < 4; ++p) {
                int i1 = i0 + dx[p], j1 = j0 + dy[p];
                if (H < maxWaterLevel(i0, j0, i1, j1)) {
                    if (d[i1][j1] != 0) {
                        d[i1][j1] = 0;
                        q.add(i1); q.add(j1);
                        queue.add(new Cell(i1, j1, 0));
                    }
                }
            }
        }
        q = null;
        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            int i0 = cell.i, j0 = cell.j;
            if (i0 == N-1 && j0 == M-1)
                break;
            if (cell.t > d[i0][j0])
                continue;
            for (int p = 0; p < 4; ++p) {
                int i1 = i0 + dx[p], j1 = j0 + dy[p];
                int maxLevel = maxWaterLevel(i0, j0, i1, j1);
                if (maxLevel >= 0) {
                    int curLevel = getWaterLevelAtTime(cell.t);
                    int waitTime = getWaitTime(curLevel, maxLevel);
                    int nextLevel = getWaterLevelAtTime(cell.t + waitTime);
                    int remainedWater = nextLevel - floor[i0][j0];
                    int t = cell.t + waitTime;
                    if (remainedWater >= 20)
                        t += 10;
                    else
                        t += 100;
                    if (t < d[i1][j1]) {
                        d[i1][j1] = t;
                        queue.add(new Cell(i1, j1, t));
                    }
                }
            }
        }
        return d[N-1][M-1];
    }

    private int getWaitTime(int curLevel, int wantedLevel) {
        if (curLevel < wantedLevel)
            return 0;
        return (curLevel - wantedLevel);
    }

    private int getWaterLevelAtTime(int t) {
        int res = H - t;
        if (res < 0) res = 0;
        return res;
    }

}
