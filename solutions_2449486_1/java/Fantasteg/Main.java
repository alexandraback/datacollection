import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Dzmitry Paulenka
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task_B solver = new Task_B();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task_B {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int T = in.nextInt();
        for (int k = 1; k <= T; ++k) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[n][m];
            int cmx[] = new int[m];
            int rmx[] = new int[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = in.nextInt();
                    cmx[j] = Math.max(cmx[j], a[i][j]);
                    rmx[i] = Math.max(rmx[i], a[i][j]);
                }
            }

            boolean yes = true;
            TOP: for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != Math.min(rmx[i], cmx[j])) {
                        yes = false;
                        break TOP;
                    }
                }
            }
            out.print("Case #" + k + ": ");
            out.println(yes ? "YES" : "NO");
        }
    }
}

