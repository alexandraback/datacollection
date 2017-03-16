import java.io.*;
import java.text.MessageFormat;
import java.util.Set;
import java.util.TreeSet;

public class B {
    private String yes = "YES";
    private String no = "NO";

    public static void main(String[] args) {
        B instance = new B();
        instance.start();
    }

    private void start() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("B-small.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("B-small.out"));
            String s = reader.readLine().trim();
            int t = Integer.parseInt(s);
            for (int i = 0; i < t; ++i) {
                String[] strs = reader.readLine().trim().split(" +");
                int n = Integer.parseInt(strs[0]);
                int m = Integer.parseInt(strs[1]);
                int[][] field = new int[n][m];
                for (int j = 0; j < n; j++) {
                    String line = reader.readLine().trim();
                    strs  = line.split(" +");
                    for (int k = 0; k < m; k++) {
                        field[j][k] = Integer.parseInt(strs[k]);
                    }
                }

                Set<Integer> set = new TreeSet<Integer>();
                loadSet(field, set);
                boolean isAv = true;
                for (Integer v : set) {
                    if (!isV(field, v)) {
                        isAv = false;
                        break;
                    }
                }
                writer.write("Case #" + (i + 1) + ": " + (isAv ? yes : no));
                if (i < t - 1) {
                    writer.write("\n");
                }
            }
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private boolean isV(int[][] field, Integer v) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                if (field[i][j] == v) {
                    if (!check(field, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private boolean check(int[][] field, int x, int y) {
        boolean isA = true;
        boolean isB = true;
        for (int i = 0; i < field[0].length; i++) {
            if (field[x][i] > field[x][y]) {
                isA = false;
            }
        }
        if (!isA) {
            for (int i = 0; i < field.length; i++) {
                if (field[i][y] > field[x][y]) {
                    isB = false;
                }
            }
        }
        return isA || isB;
    }

    private void loadSet(int[][] field, Set<Integer> set) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                set.add(field[i][j]);
            }
        }
    }
}