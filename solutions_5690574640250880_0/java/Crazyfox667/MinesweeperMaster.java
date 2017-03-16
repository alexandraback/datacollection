import java.io.*;
import java.util.Arrays;
import java.util.Date;

/**
 * Date: 12/04/2014
 * Time: 12:37
 */

public class MinesweeperMaster {

    String imp = "\nImpossible";

    public static void main(String[] args) throws IOException {
        new MinesweeperMaster().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File("").getAbsoluteFile();
            File[] inList = test.listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.toLowerCase().contains(".in");
                }
            });
            File fIn = inList[0];
            for (int i = 1; i < inList.length; i++) {
                if (new Date(fIn.lastModified()).compareTo(new Date(inList[i].lastModified())) < 0) {
                    fIn = inList[i];
                }
            }
            File fOut = new File("MinesweeperMaster.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    String build(int r, int c, int m) {

        int[][] field = new int[r][c];
        int k = m;

        if ((r * c) - m == 1) {
            for (int i = 0; i < r; i++) {
                Arrays.fill(field[i], 2);
            }
        } else if (r == 1) {
            for (int i = 0; i < m; i++) {
                field[0][i] = 2;
            }
        } else if (c == 1) {
            for (int i = 0; i < m; i++) {
                field[i][0] = 2;
            }
        } else if (r == 2) {
            for (int i = 0; i < m / 2; i++) {
                field[0][i] = 2;
                field[1][i] = 2;
            }
        } else {
            for (int i = 0; k > 0 && i < r - 3; i++) {
                for (int j = 0; k > 0 && j < c; j++) {
                    if (k == 1 && j == (c - 2)) {
                        field[i + 1][0] = 2;
                    } else {
                        field[i][j] = 2;
                    }
                    k--;
                }
            }

            for (int j = 0; k > 0 && j < c; j++) {
                for (int i = r - 3; k > 0 && i < r; i++) {
                    if (k == 1 && i == (r - 2) ) {
                        field[i - 1][j + 1] = 2;
                    } else {
                        field[i][j] = 2;
                    }
                    k--;
                }
            }
        }
        field[r - 1][c - 1] = 5;

        String s = "";
        for (int i = 0; i < field.length; i++) {
            s += "\n";
            for (int j = 0; j < field[0].length; j++) {
                if (field[i][j] == 5) {
                    s += "c";
                } else if (field[i][j] == 0) {
                    s += ".";
                } else if (field[i][j] == 2) {
                    s += "*";
                }
            }
        }
        return s;
    }

    String solve(BufferedReader in) throws IOException {
        String[] read = in.readLine().split(" ");
        int r = Integer.valueOf(read[0]);
        int c = Integer.valueOf(read[1]);
        int m = Integer.valueOf(read[2]);

        int size = r * c;
        int free = size - m;

        if (free == 1 || r == 1 || c == 1) {
            // don't return impossible
        } else if (free < 4 || free == 5 || free == 7) {
            return imp;
        } else if ((r == 2 || c == 2) && (free % 2) == 1) {
            return imp;
        }
        return build(r, c, m);

    }
}
