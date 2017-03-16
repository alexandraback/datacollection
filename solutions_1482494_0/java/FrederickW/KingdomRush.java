import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Frederick
 * Date: 4/28/12
 * Time: 7:43 AM
 * To change this template use File | Settings | File Templates.
 */
public class KingdomRush {

    private static String solve(int levels, int[][] stars) {
        int count = 0;
        boolean[][] done = new boolean[levels][2];
        int earned = 0;
        outer:
        for (; ; ) {
            int h1 = -1, h1s = -1, h2 = -1, h2s = -1;
            for (int s = earned; s >= 0; s--) {
                for (int i = 0; i < levels; i++) {
                    boolean[] d = done[i];
                    int[] st = stars[i];
                    int s1 = st[0];
                    int s2 = st[1];
                    if (!d[0] && s1 <= s && (h1 == -1 || s1 > h1s)) {
                        h1 = i;
                        h1s = s1;
                    }
                    if (!d[1] && s2 <= s && (h2 == -1 || s2 > h2s)) {
                        h2 = i;
                        h2s = s2;
                    }
                }
            }

            if (h2 != -1) {
                done[h2][1] = true;
                if (!done[h2][0]) {
                    done[h2][0] = true;
                    earned += 2;
                } else {
                    earned += 1;
                }
                count++;
                continue outer;
            } else if (h1 != -1) {
                done[h1][0] = true;
                earned += 1;
                count++;
                continue outer;
            } else {
                for (boolean[] bool : done) {
                    for (boolean b : bool) {
                        if (!b) {
                            return "Too Bad";
                        }
                    }
                }
                return Integer.toString(count);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        File input = new File("C:\\Users\\Frederick\\Downloads\\B-small-attempt1.in");
        File output = new File(input.getAbsolutePath() + ".out");
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(input)));
        PrintStream out = new PrintStream(output);
        int cases = Integer.parseInt(in.readLine());
        for (int i = 1; i <= cases; i++) {
            int levels = Integer.parseInt(in.readLine());
            int[][] stars = new int[levels][2];
            for (int l = 0; l < levels; l++) {
                String[] s = in.readLine().split(" ");
                int a = Integer.parseInt(s[0]);
                int b = Integer.parseInt(s[1]);
                stars[l][0] = a;
                stars[l][1] = b;
            }
            String solution = solve(levels, stars);
            String print = "Case #" + i + ": " + solution;
            System.out.println(print);
            out.println(print);
        }
    }

}
