package CodeJam._2016.R1A;
import java.io.*;
import java.util.*;

/**
 * Created by locheng on 4/16/16.
 */

public class ProblemBRankAndFile {
    private static Scanner in;
    private static PrintStream out;

    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemBRankAndFile solver = new ProblemBRankAndFile();
            getInput(solver);
            out.println("Case #" + t + ": " + solver.solve());
        }
        out.close();
    }

    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1A/BInput.001");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1A/BOutput.001");
        out = new PrintStream(outputFile);
    }
    
    private static void getInput(ProblemBRankAndFile solver) {
    }
    
    private String solve() {
        StringBuilder sb = new StringBuilder();
        int[] count = new int[2600];
        int n = in.nextInt();
        for (int i = 0; i < (2 * n - 1) * n; ++i) {
            int v = in.nextInt();
            count[v]++;
        }
        for (int i = 0; i < 2600; ++i) {
            if (count[i] % 2 != 0) {
                sb.append(i);
                sb.append(' ');
            }
        }
        return sb.toString();
    }
}
       