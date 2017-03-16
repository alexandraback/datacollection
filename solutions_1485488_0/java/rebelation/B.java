import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    private static final double INF = 1e30;
    int H;
    int N, M; // height, width
    int[][] ceil;
    int[][] floor;
    private final int[] dx = new int[]{1, 0, -1, 0};
    private final int[] dy = new int[]{0, -1, 0, 1};
    double[][] dp;

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            int H = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();
            ceil = new int[N][M];
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    ceil[i][j] = sc.nextInt();
            floor = new int[N][M];
            for(int i = 0; i < N; i++)
                for(int j = 0; j < M; j++)
                    floor[i][j] = sc.nextInt();
            dp = new double[N][M];
            for(int i = 0; i < N; i++)Arrays.fill(dp[i], INF);
            dp[0][0] = 0;
            PriorityQueue<E> q = new PriorityQueue<E>();
            q.offer(new E(0, 0, 0));
            while(!q.isEmpty()){
                E e = q.poll();
                if(abs(dp[e.y][e.x] - e.time) > 1e-9)continue;
                if(e.y == N-1 && e.x == M-1){
                    System.out.printf("Case #%d: %.9f\n", o, e.time);
                    break;
                }
                for(int i = 0; i < dx.length; i++){
                    int ny = e.y + dy[i];
                    int nx = e.x + dx[i];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= M)
                        continue;
                    if(ceil[ny][nx] - floor[e.y][e.x] < 50)continue;
                    if(ceil[ny][nx] - floor[ny][nx] < 50)continue;
                    if(ceil[e.y][e.x] - floor[ny][nx] < 50)continue;
                    double cur = max(floor[e.y][e.x], H-e.time*10);
                    double t = e.time;
                    if(ceil[ny][nx] - cur < 50)
                        t += (50 - (ceil[ny][nx] - cur)) / 10.0;
                    double water = H - t*10;
                    if(t > 0){
                        if(water - floor[e.y][e.x] >= 20)
                            t += 1;
                        else
                            t += 10;
                    }
                    if(dp[ny][nx] > t){
                        dp[ny][nx] = t;
                        q.offer(new E(ny, nx, t));
                    }
                }
            }
        }
    }
}

class E implements Comparable<E>{
    int y, x;
    double time;
    E(int a, int b, double c){
        y = a; x = b; time = c;
    }
    public int compareTo(E e){
        return Double.compare(time, e.time);
    }
}
