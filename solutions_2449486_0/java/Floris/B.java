
import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws Exception {
        System.setOut(new PrintStream("/home/floris/temp/dev/codejam2013/in/out.txt"));
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/in/B-small-attempt0.in"));
        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int[][] v = new int[r][c];
            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) v[i][j] = sc.nextInt();
            System.out.printf("Case #%d: %s%n", current, solve(v));
        }
    }
    public static String solve(int[][] field) {
        int[] maxOnColumn = new int[field[0].length];
        int[] maxOnRow = new int[field.length];

        Arrays.fill(maxOnColumn, 1);
        Arrays.fill(maxOnRow,1);

        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                if (field[i][j] > maxOnRow[i]) maxOnRow[i] = field[i][j];
                if (field[i][j] > maxOnColumn[j]) maxOnColumn[j] = field[i][j];
            }
        }

        for (int i = 0; i < maxOnColumn.length; i++) if (maxOnColumn[i]>100) return "NO";
        for (int i = 0; i < maxOnRow.length; i++) if (maxOnRow[i]>100) return "NO";

        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                if (field[i][j] != Math.min(maxOnRow[i], maxOnColumn[j])) return "NO";
            }
        }
        return "YES";
    }

    public static boolean test(char v, String[] lines) {
        for (int i = 0; i < 4; i++) {
            boolean a = true, b = true;
            for (int j = 0; j < 4; j++) {
                a &= (lines[j].charAt(i) == v) || (lines[j].charAt(i) == 'T');
                b &= (lines[i].charAt(j) == v) || (lines[i].charAt(j) == 'T');
            }
            if (a || b) return true;
        }
        boolean a = true, b = true;
        for (int i = 0; i < 4; i++) {
            a &= lines[i].charAt(i) == v || lines[i].charAt(i) == 'T';
            b &= lines[i].charAt(3-i) == v || lines[i].charAt(3-i) == 'T';
        }
        return a || b;
    }
}
