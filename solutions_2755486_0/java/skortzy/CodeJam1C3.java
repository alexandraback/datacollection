import java.io.*;
import java.util.Arrays;
import java.util.Vector;

public class CodeJam1C3 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("C-small.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");
                line = br.readLine();
                int N = Integer.parseInt(line);
                int[] d = new int[N];
                int[] n = new int[N];
                int[] w = new int[N];
                int[] e = new int[N];
                int[] s = new int[N];
                int[] deltad = new int[N];
                int[] deltap = new int[N];
                int[] deltas = new int[N];
                for (int j = 0; j < N; j++) {
                    line = br.readLine();
                    String[] values = line.split(" ");
                    d[j] = Integer.parseInt(values[0]);
                    n[j] = Integer.parseInt(values[1]);
                    w[j] = Integer.parseInt(values[2]);
                    e[j] = Integer.parseInt(values[3]);
                    s[j] = Integer.parseInt(values[4]);
                    deltad[j] = Integer.parseInt(values[5]);
                    deltap[j] = Integer.parseInt(values[6]);
                    deltas[j] = Integer.parseInt(values[7]);
                }

                long result = solve(N, d, n, w, e, s, deltad, deltap, deltas);

                pw.println("Case #" + (i + 1) + ": " + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long solve(int N, int[] d, int[] n, int[] w, int[] e, int[] s, int[] deltad, int[] deltap, int[] deltas) {
        int[] wall = new int[2000];
        int[] nextWall = Arrays.copyOf(wall, wall.length);
        int[] nextAttackDay = new int[N];
        int[] nextAttackW = new int[N];
        int[] nextAttackE = new int[N];
        int[] nextAttackS = new int[N];
        int attacks = 0;
        for (int i = 0; i < N; i++) {
            nextAttackDay[i] = d[i];
            nextAttackW[i] = w[i];
            nextAttackE[i] = e[i];
            nextAttackS[i] = s[i];
            attacks += n[i];
        }

        int result = 0;

        for (int day = 0; attacks > 0; day++) {
            for (int i = 0; i < N; i++) {
                boolean success = false;
                if (nextAttackDay[i] == day) {
                    System.out.println("Tribe " + i + " attacks on day " + day + " at height " + nextAttackS[i]);
                    for (int j = 2 * nextAttackW[i]; j <= 2 * nextAttackE[i]; j++) {
                        System.out.print(wall[1000 + j] + " \t");
                        if (wall[1000 + j] < nextAttackS[i]) {
                            success = true;
                        }
                    }
                    if (success) {
                        for (int j = 2 * nextAttackW[i]; j <= 2 * nextAttackE[i]; j++) {
                            nextWall[1000 + j] = Math.max(nextWall[1000 + j], nextAttackS[i]);
                        }
                    }
                    System.out.println(success);
                    n[i]--;
                    attacks--;
                    if (n[i] > 0) {
                        nextAttackDay[i] += deltad[i];
                        nextAttackW[i] += deltap[i];
                        nextAttackE[i] += deltap[i];
                        nextAttackS[i] += deltas[i];
                    }
                }
                if (success) {
                    result++;
                }
            }
            wall = Arrays.copyOf(nextWall, wall.length);
        }
        return result;

    }
}
