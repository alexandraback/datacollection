import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("c.out");
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

    static class TaskC {
        int ans = 0;
        int flag = 0;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            ans = 0;
            int n = in.nextInt();
            int[] s = new int[n + 1];
            int[] vis = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                s[i] = in.nextInt();
            }
            for (int i = 1; i <= n; i++) {
                flag = 0;
                vis[i] = 1;
                dfs(i, s, vis, 1, i, i);
                vis[i] = 0;
            }
            out.print("Case #" + testNumber + ": ");
            out.println(ans);
        }

        public void dfs(int num, int[] s, int[] vis, int tmp, int start, int from) {
            if (s[num] == start || s[num] == from) {
                ans = Math.max(ans, tmp);
            }
            if (vis[s[num]] == 0) {
                flag = 0;
                vis[s[num]] = 1;
                dfs(s[num], s, vis, tmp + 1, start, num);
                vis[s[num]] = 0;
            } else {
                if (from == s[num]) {

                    for (int i = 1; i <= vis.length - 1; i++) {
                        if (vis[i] == 0 && s[i] == num && flag == 0) {
                            flag = 1;
                            vis[i] = 1;
                            dfs(i, s, vis, tmp + 1, start, num);
                            vis[i] = 0;
							flag=0;
                        }
                    }
                }
            }
        }

    }
}

