import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 21:55
 * To change this template use File | Settings | File Templates.
 */
public class Solution {

    private int[][] desired;
    private int[][] current;
    private int n;
    private int m;

    public String solve(int caseNo) {

        for (int level = 1; level <= 100; level++) {
            for (int i = 0; i < n; i++) {
                cutRow(i, level);
            }
            for (int i = 0; i < m; i++) {
                cutColumn(i, level);
            }
        }

        String msg = "YES";
        if (!currentEqualDesired()) {
            msg = "NO";
        }
//        debug();
        return "Case #" + caseNo + ": " + msg;
    }

    private void debug() {
        System.out.println("Desired:");
        for (int[] arr : desired) {
            System.out.println(Arrays.toString(arr));
        }
        System.out.println("Current:");
        for (int[] arr : current) {
            System.out.println(Arrays.toString(arr));
        }
    }

    private boolean currentEqualDesired() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (desired[i][j] != current[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    private void cutRow(int i, int level) {
        boolean canCutRow = true;
        for (int j = 0; j < m; j++) {
            if (!canCut(i, j, level)) {
                canCutRow = false;
                break;
            }
        }
        if (canCutRow) {
            for (int j = 0; j < m; j++) {
                current[i][j] = Math.min(level, current[i][j]);
            }
        }
    }

    private boolean canCut(int i, int j, int level) {
        return desired[i][j] <= level;
    }

    private void cutColumn(int i, int level) {
        boolean canCutColumn = true;
        for (int j = 0; j < n; j++) {
            if (!canCut(j, i, level)) {
                canCutColumn = false;
                break;
            }
        }
        if (canCutColumn) {
            for (int j = 0; j < n; j++) {
                current[j][i] = Math.min(level, current[j][i]);
            }
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.parse();
    }

    private void parse() {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        for (int i = 1; i <= testCases; i++) {
            n = scanner.nextInt();
            m = scanner.nextInt();
            int[][] arr = new int[n][m];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    arr[j][k] = scanner.nextInt();
                }
            }
            setBoard(arr);
            System.out.println(solve(i));
        }
    }

    public void setBoard(int[][] desired) {
        this.desired = desired;
        n = desired.length;
        m = desired[0].length;
        current = new int[n][m];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                current[j][k] = 100;
            }
        }
    }

}
