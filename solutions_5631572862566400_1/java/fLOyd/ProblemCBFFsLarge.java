package CodeJam._2016.R1A;
import java.io.*;
import java.util.*;

/**
 *
 * Created by locheng on 4/16/16.
 *
 */

public class ProblemCBFFsLarge {
    private static Scanner in;
    private static PrintStream out;

    int result;
    int n;
    int bff[];
    boolean expanded[];
    int count = 0;
    
    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemCBFFsLarge solver = new ProblemCBFFsLarge();
            getInput(solver);
            out.println("Case #" + t + ": " + solver.solve());
        }
        out.close();
    }
    
    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1A/CInput.002");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1A/COutput1.002");
        out = new PrintStream(outputFile);
    }
    
    private static void getInput(ProblemCBFFsLarge solver) {
        solver.n = in.nextInt();
        solver.bff = new int[solver.n];
        solver.expanded = new boolean[solver.n];
        solver.result = 0;
        for (int i = 0; i < solver.n; ++i) {
            solver.bff[i] = in.nextInt() - 1;
            solver.expanded[i] = false;
        }
    }

    private int expand(int node) {
        int result = 1;
        for (int i = 0; i < n; ++i) {
            if (!expanded[i] && bff[i] == node) {
                expanded[i] = true;
                result = java.lang.Math.max(result, expand(i) + 1);
            }
        }
        return result;
    }

    private int findCircle(int node) {
        int[] step = new int[n];
        for (int i = 0; i < n; ++i) {
            step[i] = -1;
        }
        step[node] = 0;
        int last = node;
        int current = bff[last];
        while (!expanded[current] && step[current] == -1) {
            step[current] = step[last] + 1;
            last = current;
            current = bff[last];
        }
        for (int i = 0; i < n; ++i) {
            if (step[i] != -1) {
                expanded[i] = true;
            }
        }
        return (step[current] != -1) ? step[last] - step[current] + 1 : 0;
    }
    
    private String solve() {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && bff[i] == j && bff[j] == i) {
                    count++;
                    expanded[i] = true;
                    expanded[j] = true;
                    result = java.lang.Math.max(result, expand(i) + expand(j) + (count - 1)*2);
                }
            }
        }
        result = java.lang.Math.max(result, count*2);
        for (int i = 0; i < n; ++i) {
            if (!expanded[i]) {
                result = java.lang.Math.max(result, findCircle(i));
            }

        }
        return String.valueOf(result);
    }
}
       