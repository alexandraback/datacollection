import java.io.File;
import java.io.FileInputStream;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.LinkedBlockingQueue;

import org.junit.Assert;

public class MinesweeperMaster {

    // private static String file = "data/q3sample.txt";
    // private static String file = "data/C-small-attempt1.in";
    private static String file = "data/C-large.in";

    private static final String IMPOSSIBLE = "Impossible\n";

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int mine = scanner.nextInt();
            String ans = solve(r, c, mine);
            out(t, ans);
        }
    }

    static String solve2(int t, Solver solver) {
        int len = solver.getLength();
        int mineCount = solver.getMineCount();
        boolean ok = false;
        String ans = "";
        // System.out.println(len);
        for (int i = 0; i < (1 << len); i++) {
            // System.out.println(i + "<=>" + Integer.bitCount(i));
            if (Integer.bitCount(i) == mineCount) {
                solver.setData(i);
                if (solver.check()) {
                    ans = "" + i;
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            return ans;
        } else {
            return IMPOSSIBLE;
        }
    }

    static String solve(int r, int c, int mine) {
        int blanks = r * c - mine;
        int small = Math.min(r, c);
        if (small == 1) {
            return ansOne(r, c, mine);
        }
        if (blanks == 1) {
            return ansOne(r, c, mine);
        }
        if (small == 2 && blanks % 2 == 1) {
            return IMPOSSIBLE;
        }
        if (blanks == 2 || blanks == 3 || blanks == 5 || blanks == 7) {
            return IMPOSSIBLE;
        }

        return ans(r, c, mine);
    }

    static String ans(int r, int c, int mine) {
        int blanks = r * c - mine;
        char ans[][] = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = '*';
            }
        }
        ans[0][0] = 'c';

        int start = -1;
        if (blanks % 2 == 1) {
            ans[0][1] = '.';
            ans[0][2] = '.';
            ans[1][0] = '.';
            ans[1][1] = '.';
            ans[1][2] = '.';
            ans[2][0] = '.';
            ans[2][1] = '.';
            ans[2][2] = '.';
            start = 3;
            blanks -= 9;
        } else {
            ans[0][1] = '.';
            ans[1][0] = '.';
            ans[1][1] = '.';
            start = 2;
            blanks -= 4;
        }

        for (int i = start; i < r && blanks > 0; i++) {
            blanks -= 2;
            ans[i][0] = '.';
            ans[i][1] = '.';
        }

        for (int i = start; i < c && blanks > 0; i++) {
            blanks -= 2;
            ans[0][i] = '.';
            ans[1][i] = '.';
        }

        // debug(ans);

        for (int j = 2; j < c && blanks > 0; j++) {
            for (int i = 2; i < r && blanks > 0; i++) {
                if (ans[i][j] == '.') {
                    continue;
                }
                blanks--;
                ans[i][j] = '.';
            }
        }

        Assert.assertTrue(blanks == 0);

        String res = "";
        for (int i = 0; i < r; i++) {
            String s = new String(ans[i]);
            res += s + "\n";
        }
        return res;
    }

    static void debug(char[][] ans) {
        String res = "";
        for (int i = 0; i < ans.length; i++) {
            String s = new String(ans[i]);
            res += s + "\n";
        }
        System.out.println("===");
        System.out.println(res);
        System.out.println("===");
    }

    static String ansOne(int r, int c, int mine) {
        String ans = "c";
        int blanks = r * c - mine - 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (blanks > 0) {
                    ans += ".";
                    blanks--;
                } else {
                    ans += "*";
                }
            }
            ans += "\n";
        }
        Assert.assertTrue(blanks == 0);
        return ans;
    }

    static void out(int t, Object ans) {
        System.out.print("Case #" + (t + 1) + ":\n" + ans);
    }

    static class Solver {
        private static final int MINE = 1;
        private int data;
        private int r;
        private int c;
        private final int mineCount;
        // private final Set<Integer> dirs = new HashSet<Integer>();
        private final int[] rDirs = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
        private final int[] cDirs = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };
        private final int length;

        public Solver(final int r, final int c, int mine) {
            this.length = r * c;
            this.mineCount = mine;
            this.r = r;
            this.c = c;
        }

        public boolean check() {
            // System.out.println(" check:" + data);
            int rensa = 0;
            int checked = 0;
            Queue<Integer> q = new LinkedBlockingQueue<Integer>();
            for (int i = 0; i < length; i++) {
                if (getDataAtIndex(i) != MINE && checkZero(i)) {
                    // System.out.println(" visit(start):" + i);
                    q.add(i);
                    checked |= (1 << i);
                    rensa++;
                    break;
                }
            }
            while (!q.isEmpty()) {
                int index = q.poll();
                int row = getRow(index);
                int col = getCol(index);
                for (int i = 0; i < rDirs.length; i++) {
                    int newRow = row + rDirs[i];
                    int newCol = col + cDirs[i];
                    if (!isValid(newRow, newCol)) {
                        continue;
                    }
                    int newIndex = getIndex(newRow, newCol);
                    if ((checked >> newIndex & 1) >= 1) {
                        continue;
                    }
                    checked |= (1 << newIndex);
                    rensa++;
                    // System.out.println(" visit:" + newIndex);
                    if (checkZero(newIndex)) {
                        q.add(newIndex);
                    }
                }
            }
            if (rensa == 0) {
                return getLength() - getMineCount() == 1;
            } else {
                return rensa == (getLength() - getMineCount());
            }
        }

        boolean isValid(int row, int col) {
            return row >= 0 && row < r && col >= 0 && col < c;
        }

        int getRow(int index) {
            return index / c;
        }

        int getCol(int index) {
            return index % c;
        }

        int getIndex(int row, int col) {
            return row * c + col;
        }

        boolean checkZero(int index) {
            boolean ok = true;
            // System.out.println("  checkZero:" + index);
            int row = getRow(index);
            int col = getCol(index);
            for (int i = 0; i < rDirs.length; i++) {
                int newRow = row + rDirs[i];
                int newCol = col + cDirs[i];
                if (!isValid(newRow, newCol)) {
                    continue;
                }
                int newIndex = getIndex(newRow, newCol);

                // System.out.println("  checkZeroVisit:" + newIndex + "  " + getDataAtIndex(newIndex));
                if (getDataAtIndex(newIndex) == MINE) {
                    ok = false;
                    break;
                }
            }
            return ok;
        }

        int getDataAtIndex(int index) {
            int res = (data >> index) & 1;
            // System.out.println(" getData: data=" + data + ", index=" + index + " => " + res);
            return res;
        }

        public int getData() {
            return data;
        }

        public void setData(int data) {
            this.data = data;
        }

        public int getLength() {
            return length;
        }

        public int getMineCount() {
            return mineCount;
        }
    }

}
