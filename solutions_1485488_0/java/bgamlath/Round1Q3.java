/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;
import java.io.*;

/**
 *
 * @author bgamlath
 */
public class Round1Q3 {

    /**
     * @param args the command line arguments
     * 
     */
    static BufferedReader in;
    static PrintStream out;
    static int[][] floor;
    static int[][] ciel;
    static int H;
    static int M, N;
    static int[][] dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintStream("output.txt");
        int T = Integer.parseInt(in.readLine());
        for (int i = 1; i <= T; i++) {
            out.println("Case #" + i + ": " + proc());
        }
    }

    static double proc() throws Exception {
        getInput();
        System.out.println(H + ", " + N + ", " + M);
        HashSet<Integer>[] reachable = new HashSet[100];

        reachable[0] = getPoints();
        System.out.println(reachable[0]);
        int target = (M - 1) * 200 + N - 1;
        if (reachable[0].contains(target)) {
            return 0.0;
        }
        for (int t = 1;; t++) {
            HashSet<Integer> temp = new HashSet<Integer>();
            int curState = t % 100;
            temp.addAll(reachable[(t-1)%100]);
            if (t >= 10) {
                int prevState = (t - 10) % 100;
                
                for (int cur : reachable[prevState]) {
                    int curr = cur % 200;
                    int curc = cur / 200;
                    for (int[] dir : dirs) {
                        int nextr = curr + dir[0];
                        int nextc = curc + dir[1];
                        if (cost(curr, curc, nextr, nextc, t - 10) == 10) {
                            temp.add(nextc * 200 + nextr);
                        }
                    }
                }
            }
            if (t >= 100) {
                for (int cur : reachable[curState]) {
                    int curr = cur % 200;
                    int curc = cur / 200;
                    for (int[] dir : dirs) {
                        int nextr = curr + dir[0];
                        int nextc = curc + dir[1];
                        if (cost(curr, curc, nextr, nextc, t - 100) == 100) {
                            temp.add(nextc * 200 + nextr);
                        }
                    }
                }
            }
            if (temp.contains(target)) {
                return t / 10.0;
            }
            reachable[curState] = temp;
            System.out.println(" t = " + t);
            System.out.println(temp);
        }
    }

    static void getInput() throws Exception {
        String[] t = in.readLine().split(" ");
        H = Integer.parseInt(t[0]);
        N = Integer.parseInt(t[1]);
        M = Integer.parseInt(t[2]);
        floor = new int[N][M];
        ciel = new int[N][M];
        for (int i = 0; i < N; i++) {
            t = in.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                ciel[i][j] = Integer.parseInt(t[j]);
            }
        }
        for (int i = 0; i < N; i++) {
            t = in.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                floor[i][j] = Integer.parseInt(t[j]);
            }
        }
    }

    static HashSet<Integer> getPoints() {
        HashSet<Integer> reachable = new HashSet<Integer>();
        Stack<Integer> toVisit = new Stack<Integer>();
        toVisit.add(0);

        while (!toVisit.isEmpty()) {
            int cur = toVisit.pop();
            if (!reachable.contains(cur)) {
                reachable.add(cur);
                int curr = cur % 200;
                int curc = cur / 200;
                for (int[] dir : dirs) {
                    int nextr = curr + dir[0];
                    int nextc = curc + dir[1];
                    if (cost(curr, curc, nextr, nextc, 0) > 0) {
                        toVisit.add(nextc * 200 + nextr);
                    }
                }
            }
        }
        return reachable;
    }

    static int cost(int curr, int curc, int nextr, int nextc, int t) {
        int h = H - t;
        if (h < 0) {
            h = 0;
        }
        if (nextr < N && nextr >= 0 && nextc < M && nextc >= 0) {
            if (ciel[nextr][nextc] - h >= 50 && ciel[nextr][nextc] - floor[curr][curc] >= 50 && ciel[nextr][nextc] - floor[nextr][nextc] >= 50 && ciel[curr][curc] - floor[nextr][nextc] >= 50) {
                if (h - floor[curr][curc] >= 20) {
                    return 10;
                }
                return 100;
            }
        }
        return -1;
    }
}
