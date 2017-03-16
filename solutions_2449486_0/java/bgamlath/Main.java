
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author bgamlath
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("in.txt"));
        out = new PrintWriter("out.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int i = 1; i <= T; i++) {
            printf("Case #%d: %s\n", i, proc());
        }


        // End of User Code
        in.close();
        out.close();
    }
    static int M, N;
    static int[][] medow = new int[100][100];
    static Block[] blocks = new Block[100 * 100];

    static String proc() throws Exception {
        N = ni();
        M = ni();
        int cc = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                medow[i][j] = ni();
                blocks[cc++] = new Block(i, j, medow[i][j]);
            }
        }
        Arrays.sort(blocks, 0, cc);
        boolean possible = true;

        for (int i = 0; i < cc; i++) {
            Block b = blocks[i];
            if (medow[b.r][b.c] != -1) {
                boolean sameHeight;

                sameHeight = true;
                for (int r = 0; r < N; r++) {
                    if (!(medow[r][b.c] == b.h || medow[r][b.c] == -1)) {
                        sameHeight = false;
                        break;
                    }
                }
                if (sameHeight) {
                    for (int r = 0; r < N; r++) {
                        medow[r][b.c] = -1;
                    }
                    continue;
                }

                sameHeight = true;
                for (int c = 0; c < M; c++) {
                    if (!(medow[b.r][c] == b.h || medow[b.r][c] == -1)) {
                        sameHeight = false;
                        break;
                    }
                }
                if (sameHeight) {
                    for (int c = 0; c < M; c++) {
                        medow[b.r][c] = -1;
                    }
                    continue;
                }
                possible = false;
                break;
            }
        }


        if (possible) {
            return "YES";
        } else {
            return "NO";
        }
    }

    static void printf(String format, Object... args) {
        System.out.printf(format, args);
        out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }
}

class Block implements Comparable<Block> {

    int r, c, h;

    public Block(int r, int c, int h) {
        this.r = r;
        this.c = c;
        this.h = h;
    }

    @Override
    public int compareTo(Block o) {
        return ((Integer) (this.h)).compareTo(o.h);
    }
}
