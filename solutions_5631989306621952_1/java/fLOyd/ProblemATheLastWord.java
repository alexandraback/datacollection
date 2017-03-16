package CodeJam._2016.R1A;
import java.io.*;
import java.util.*;

/**
 *
 * Created by locheng on 4/16/16.
 *
 */

public class ProblemATheLastWord {
    private static Scanner in;
    private static PrintStream out;
    private String s;
    
    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemATheLastWord solver = new ProblemATheLastWord();
            getInput(solver);
            out.println("Case #" + t + ": " + solver.solve());
        }
        out.close();
    }
    
    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1A/AInput.002");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1A/AOutput.002");
        out = new PrintStream(outputFile);
    }
    
    private static void getInput(ProblemATheLastWord solver) {
        solver.s = in.next();
        
    }

    private String helper(String s) {
        if (!s.isEmpty()) {
            char maxChar = 'A';
            int maxCharPos = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (s.charAt(i) >= maxChar) {
                    maxChar = s.charAt(i);
                    maxCharPos = i;
                }
            }
            StringBuilder sb = new StringBuilder().append(maxChar);
            sb.append(helper(s.substring(0, maxCharPos)));
            sb.append(s.substring(maxCharPos + 1));
            return sb.toString();
        } else {
            return "";
        }
    }
    
    private String solve() {
        return helper(s);
    }
}
       