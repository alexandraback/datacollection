package CodeJam._2016.R1C;
import java.io.*;
import java.util.*;

/**
 * Created by locheng on 5/8/16.
 */

public class ProblemCFashionPoliceSmall {
    private static Scanner in;
    private static PrintStream out;

    private int jean, p, s, kLimit;

    private boolean[]  valid;

    private int[][] count0 = new int[10][10];
    private int[][] count1 = new int[10][10];
    private int[][] count2 = new int[10][10];
    private int[] trace = new int[30];
    private int[] ans = new int[30];

    private int total, result;

    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemCFashionPoliceSmall solver = new ProblemCFashionPoliceSmall();
            solver.getInput(in);
            out.print("Case #" + t + ": ");
            solver.solve();
        }
        out.close();
    }
    
    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1C/CInput.002");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1C/COutput.002");
        out = new PrintStream(outputFile);
    }
    
    private void getInput(Scanner in) {
        jean = in.nextInt();
        p = in.nextInt();
        s = in.nextInt();
        kLimit = in.nextInt();

        total = jean * p * s;
        valid = new boolean[total];
        for (int i = 0; i < total; ++i) {
            valid[i] = true;
        }
    }

    private void search(int count, int first) {
        int jj = 0, pp = 0, ss = 0;
        if (count > result) {
            result = count;
            System.arraycopy(trace, 0, ans, 0, count);
            if (count == total) {
                return;
            }
        }
        for (int i = first; i < total; ++i) {
            jj = i / (p * s);
            pp = i % (p * s) / s;
            ss = i % s;
            if (valid[i] && count0[jj][ss] < kLimit && count1[pp][ss] < kLimit && count2[jj][pp] < kLimit) {
                count0[jj][ss]++;
                count1[pp][ss]++;
                count2[jj][pp]++;
                valid[i] = false;
                trace[count] = i;
                search(count + 1, i + 1);
                if (result == total) {
                    return;
                }
                valid[i] = true;
                count0[jj][ss]--;
                count1[pp][ss]--;
                count2[jj][pp]--;
            }
        }


    }
    
    private void solve() {
        result = 0;
        search(0, 0);
        out.println(result);
        for (int ii = 0; ii < result; ++ii) {
            int jj = 0, pp = 0, ss = 0, i = ans[ii];
            jj = i / (p * s);
            pp = i % (p * s) / s;
            ss = i % s;
            out.println(String.valueOf(jj + 1) + " " + String.valueOf(pp + 1) + " " + String.valueOf(ss + 1));
        }
    }
}
       