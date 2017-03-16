import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			final String regex = "B.*.in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

    long[][][][] dp;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int A = in.nextInt();
        int B = in.nextInt();
        int K = in.nextInt();

        long ans = 0;
        dp = new long[32][2][2][2];
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    Arrays.fill(dp[i][j][k], -1);
                }
            }
        }
        ans = calculate(A, B, K, 31, 1, 1, 1);
        out.printf("Case #%d: %d\n", testNumber, ans);
    }

    private long calculate(int A, int B, int K, int pos, int eA, int eB, int eK) {
        if (pos == -1) {
            if (eA == 0 && eB == 0 && eK == 0) {
                return 1;
            }
            return 0;
        }
        if (dp[pos][eA][eB][eK] != -1) {
            return dp[pos][eA][eB][eK];
        }
        long ans = 0;
        // can choose 1 for k
        if (((K >> pos) & 1) != 0 || eK == 0) {
            // chose 1 for a and b
            if ((eA == 0 || eA == 1 && ((A >> pos) & 1) != 0)
                && (eB == 0 || eB == 1 && ((B >> pos) & 1) != 0)) {
                ans += calculate(A, B, K, pos - 1, eA, eB, eK);
            }

            // choose 0 for k
            // chose 1 for a and 0 for b
            if ((eA == 0 || eA == 1 && ((A >> pos) & 1) != 0)) {
                int newEB = (eB == 1 && ((B >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, eA, newEB, 0);
            }
            // chose 0 for a and 1 for b
            if ((eB == 0 || eB == 1 && ((B >> pos) & 1) != 0)) {
                int newEA = (eA == 1 && ((A >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, newEA, eB, 0);
            }
            // chose 0 for a and 0 for b
            if (true) {
                int newEA = (eA == 1 && ((A >> pos) & 1) == 0) ? 1 : 0;
                int newEB = (eB == 1 && ((B >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, newEA, newEB, 0);
            }
        } else {
            // choose 0 for k
            // chose 1 for a and 0 for b
            if ((eA == 0 || eA == 1 && ((A >> pos) & 1) != 0)) {
                int newEB = (eB == 1 && ((B >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, eA, newEB, eK);
            }
            // chose 0 for a and 1 for b
            if ((eB == 0 || eB == 1 && ((B >> pos) & 1) != 0)) {
                int newEA = (eA == 1 && ((A >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, newEA, eB, eK);
            }
            // chose 0 for a and 0 for b
            if (true) {
                int newEA = (eA == 1 && ((A >> pos) & 1) == 0) ? 1 : 0;
                int newEB = (eB == 1 && ((B >> pos) & 1) == 0) ? 1 : 0;
                ans += calculate(A, B, K, pos - 1, newEA, newEB, eK);
            }
        }
        dp[pos][eA][eB][eK] = ans;
        return ans;
    }
}

