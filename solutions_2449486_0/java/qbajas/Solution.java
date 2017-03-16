import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 21:55
 * To change this template use File | Settings | File Templates.
 */
public class Solution {

    private boolean[][] canGo;
    private boolean[][] cut;
    private int n;
    private int m;

    public String solve(int caseNo) {
        for (int i = 0; i < n; i++) {
            cutRow(i);
        }
        for (int i = 0; i < m; i++) {
            cutColumn(i);
        }
        String msg = "YES";
        if (untouchedSpotsLeft()) {
            msg = "NO";
        }
        return "Case #" + caseNo + ": " + msg;
    }

    private boolean untouchedSpotsLeft() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (canGo[i][j] && !cut[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }

    private void cutRow(int i) {
        boolean canCutRow = true;
        for (int j = 0; j < m; j++) {
            if (!canGo[i][j]) {
                canCutRow = false;
                break;
            }
        }
        if (canCutRow) {
            for (int j = 0; j < m; j++) {
                cut[i][j] = true;
            }
        }
    }

    private void cutColumn(int i) {
        boolean canCutColumn = true;
        for (int j = 0; j < n; j++) {
            if (!canGo[j][i]) {
                canCutColumn = false;
                break;
            }
        }
        if (canCutColumn) {
            for (int j = 0; j < n; j++) {
                cut[j][i] = true;
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
            boolean[][] arr = new boolean[n][m];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    arr[j][k] = scanner.nextInt()==1;
                }
            }
            setCanGo(arr);
            System.out.println(solve(i));
        }
//        canGo = new boolean[n][m];
//        cut = new boolean[n][m];
    }

    public void setCanGo(boolean[][] canGo) {
        this.canGo = canGo;
        n = canGo.length;
        m = canGo[0].length;
        cut = new boolean[n][m];
    }

}
