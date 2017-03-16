package CodeJam._2016.R1A;
import java.io.*;
import java.util.*;

/**
 * Created by locheng on 4/16/16.
 */

public class ProblemCBFFs {
    private static Scanner in;
    private static PrintStream out;
    private int n;
    private ArrayList<Integer> bff;
    private boolean[] mark;
    private Stack<Integer> circle;
    private int result = 0;

    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemCBFFs solver = new ProblemCBFFs();
            getInput(solver);
            out.println("Case #" + t + ": " + solver.solve());
        }
        out.close();
    }

    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1A/CInput.001");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1A/COutput.001");
        out = new PrintStream(outputFile);
    }
    
    private static void getInput(ProblemCBFFs solver) {
        solver.n = in.nextInt();
        solver.bff = new ArrayList<>();
        for (int i = 0; i < solver.n; ++i) {
            solver.bff.add(in.nextInt() - 1);
        }
    }

    private boolean check(Stack<Integer> circle) {
        for (int i = 0; i < circle.size(); i++) {
            int left = (i + circle.size() - 1) % circle.size();
            int right = (i + 1) % circle.size();
            if ((!bff.get(circle.get(i)).equals(circle.get(left))) && (!bff.get(circle.get(i)).equals(circle.get(right)))) {
               return false;
            }
        }
        return true;
    }

    private void iterate(int d, int len) {
        if (d < len) {
            for (int i = 0; i < n; ++i) {
                if (mark[i]) {
                    mark[i] = false;
                    circle.push(i);
                    iterate(d + 1, len);
                    circle.pop();
                    mark[i] = true;
                }
            }
        } else {
            if (check(circle)) {
                result = len;
            }
        }
    }
    
    private String solve() {
        mark = new boolean[n];
        circle = new Stack<>();
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                mark[i] = true;
            }
            iterate(0, len);
        }
        return String.valueOf(result);
    }
}
       