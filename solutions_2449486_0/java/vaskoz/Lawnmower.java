package qual2013;

import java.io.File;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Lawnmower {
    private final int[][] desiredLawn;
    private final int row;
    private final int col;
    private final Integer[] hiLo;
    private final int[] maxRow;
    private final int[] maxCol;

    public Lawnmower(int[][] lawn, int row, int col) {
        this.desiredLawn = lawn;
        this.row = row;
        this.col = col;
        this.maxRow = new int[row];
        this.maxCol = new int[col];

        Set<Integer> numbers = new HashSet<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                numbers.add(lawn[i][j]);
                if (lawn[i][j] > maxRow[i]) maxRow[i] = lawn[i][j];
                if (lawn[i][j] > maxCol[j]) maxCol[j] = lawn[i][j];
            }
        }
        this.hiLo = numbers.toArray(new Integer[] {});
        Arrays.sort(this.hiLo, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
    }

    public boolean isPossible() {
        for (int height : this.hiLo) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (desiredLawn[i][j] == height) {
                        if (height < maxRow[i] && height < maxCol[j])
                            return false;
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new FileReader(new File(args[0])));
        int N = input.nextInt();

        for (int i = 1; i <= N; i++) {
            int n = input.nextInt();
            int m = input.nextInt();
            int[][] lawn = new int[n][m];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    lawn[j][k] = input.nextInt();
                }
            }
            Lawnmower lawnmower = new Lawnmower(lawn, n, m);
            System.out.println("Case #" + i + ": " + (lawnmower.isPossible() ? "YES" : "NO"));
        }
    }
}
