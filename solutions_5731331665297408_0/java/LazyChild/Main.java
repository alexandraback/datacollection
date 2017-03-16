import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
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
			final String regex = "C.*.in";
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
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    String ans;
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        String[] zipcodes = new String[n];
        for (int i = 0; i < n; ++i) {
            zipcodes[i] = in.next();
        }
        int[][] g = new int[n][n];
        while (m-- > 0) {
            int u = in.nextInt();
            int v = in.nextInt();
            --u;
            --v;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        ans = "a";
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = true;
            dfs(i, g, zipcodes[i], vis, zipcodes);
            vis[i] = false;
        }
        out.printf("Case #%d: %s\n", testNumber, ans);
    }

    private int compare(String a, String b) {
        int len = Math.min(a.length(), b.length());
        for (int i = 0; i < len; ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                return a.charAt(i) - b.charAt(i);
            }
        }
        return 0;
    }

    private void dfs(int u, int[][] g, String temp, boolean[] vis, String[] zipcodes) {
        int n = g.length;
        if (temp.length() == n * 5) {
            if (compare(ans, temp) > 0) {
                ans = temp;
            }
            return;
        }
        if (compare(ans, temp) < 0) {
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (g[u][i] == 1) {
                if (!vis[i]) {
                    g[u][i] = 0;
                    g[i][u] = 2;
                    vis[i] = true;
                    dfs(i, g, temp + zipcodes[i], vis, zipcodes);
                    vis[i] = false;
                    g[i][u] = 1;
                    g[u][i] = 1;
                }
            } else if (g[u][i] == 2) {
                g[u][i] = 0;
                dfs(i, g, temp, vis, zipcodes);
                g[u][i] = 2;
            }
        }
    }
}

