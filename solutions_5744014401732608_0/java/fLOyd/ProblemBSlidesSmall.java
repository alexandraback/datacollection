package CodeJam._2016.R1C;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by locheng on 5/8/16.
 */

public class ProblemBSlidesSmall {
    private static Scanner in;
    private static PrintStream out;

    private static final int theta = 0;

    private int b;
    private long m;
    private int levelCount = 0;
    private int[] level = new int[60];
    private int[][] g;
    private boolean done;


    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemBSlidesSmall solver = new ProblemBSlidesSmall();
            solver.getInput(in);
            out.print("Case #" + t + ": ");
            solver.solve();
        }
        out.close();
    }
    
    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1C/BInput.001");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1C/BOutput.001");
        out = new PrintStream(outputFile);
    }

    private void interateLevel(int p) {
        if (p < b - 1) {
            level[p] = levelCount;
            interateLevel(p + 1);
            if (done) { return; }
            levelCount++;
            level[p] = levelCount;
            interateLevel(p + 1);
            if (done) { return; }
        } else {
            level[b - 1] = level[b - 2] + 1;
            levelCount = level[b - 1];
            resetG();
            for (int i = 1; i < b - 1; ++i) {
                if (level[i] == 1) {
                    g[0][i] = 1;
                }
                if (level[i] == levelCount) {
                    g[i][b - 1] = 1;
                }
            }
            interateEdge(0, 1);
            if (done) { return; }
        }

    }

    private void interateEdge(int p0, int p) {
        if (p <= b - 1) {
            if (p0 < p && level[p0] < level[p]) {
                interateEdge(p0 + 1, p);
                if (done) { return; }
                g[p0][p] = 1;
                interateEdge(p0 + 1, p);
                if (done) { return; }
                g[p0][p] = 0;
            } else {
                interateEdge(0, p + 1);
                if (done) { return; }
            }
        } else {
            if (calc() == m) {
                done = true;
                out.println("POSSIBLE");
                for (int i = 0; i < b; ++i) {
                    for (int j = 0; j < b; ++j) {
                        out.print(g[i][j]);
                    }
                    out.println();
                }
            }
        }
    }

    private long calc() {
        int[] count = new int[b + theta];
        count[b - 1] = 1;
        for (int i = b - 2; i >= 0; --i) {
            for (int j = i + 1; j < b; ++j) {
                if (g[i][j] == 1) {
                    count[i] += count[j];
                }
            }
        }
        return count[0];
    }
    
    private void getInput(Scanner in) {
        b = in.nextInt();
        m = in.nextLong();
    }

    private void resetG() {
        for (int i = 0; i < b + theta; ++i) {
            for (int j = 0; j < b + theta; ++j) {
                g[i][j] = 0;
            }
        }
    }
    
    private void solve() {
        g = new int[b][b];
        done = false;
        levelCount = 1;
        interateLevel(1);
        if (!done) {
            out.println("IMPOSSIBLE");
        }
    }
}
       