import java.util.PriorityQueue;
import java.util.Scanner;


public class R1bB {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            solve(sc, i);
        }
    }
    
    // H heru 10cm/sec;
    // ugoku 1sec/blok if water - floor >= 20 cm, 10sec/blck otherwise
    
    static final int[] dx = {0,1,0,-1};
    static final int[] dy = {-1,0,1,0};
    
    static void solve(Scanner sc, int t) {
        int h = sc.nextInt();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] ceilMap = new int[n][m];
        int[][] floorMap = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ceilMap[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                floorMap[i][j] = sc.nextInt();
            }
        }
        PriorityQueue<State> queue = new PriorityQueue<R1bB.State>();
        queue.add(new State(h, 0, 0));
        State s = null;
        while (!queue.isEmpty()) {
            s = queue.poll();
            visited[s.y][s.x] = true;
            if (s.y == n-1 && s.x == m-1) {
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dx[i];
                int ny = s.y + dy[i];
                double nw = s.waterHeight;
                if (nx < 0 || m <= nx || ny < 0 || n <= ny || visited[ny][nx]) continue;
                
                int ceil = Math.min(ceilMap[s.y][s.x], ceilMap[ny][nx]);
                int floor = Math.max(floorMap[s.y][s.x], floorMap[ny][nx]);
                if (ceil - floor < 50) continue; // 水考えなくてもいけない
                
                double waterFloor = Math.max(s.waterHeight, floor);
                double waterHeightNeededDown = ceil - waterFloor < 50
                        ? (50 + waterFloor - ceil)
                        : 0;
                nw -= waterHeightNeededDown;
                double waterDiff = s.waterHeight - waterHeightNeededDown - floorMap[s.y][s.x];
                if (nw != h) { // 波引く前にいってもいい
                    if (waterDiff >= 20) { // カヤックのる
                        nw -= 10;
                    }
                    else {
                        nw -= 100;
                    }
                }
                queue.add(new State(nw, nx, ny));
                
            }
        }
//        System.out.println(s);
        System.out.println("Case #"+ t + ": " + (h - s.waterHeight) / 10);
    }
    
    static class State implements Comparable<State> {
        final double waterHeight;
        final int x;
        final int y;
        
        public State(double waterHeight, int x, int y) {
            super();
            this.waterHeight = waterHeight;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(State o) {
            return (int) -Math.signum(waterHeight - o.waterHeight);
        }

        @Override
        public String toString() {
            return "State [waterHeight=" + waterHeight + ", x=" + x + ", y=" + y + "]";
        }
        
    }
}
