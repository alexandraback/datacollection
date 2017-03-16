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
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("b.out");
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

    static class TaskB {
        ArrayList<String> res = new ArrayList<>();
        int flag = 0;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            res.clear();
            flag = 0;
            int n = in.nextInt();
            long m = in.nextLong();
            int[][] ans = new int[n + 1][n + 1];
            for (int i = 2; i <= n; i++) {
                dfs(i, 1, "1", n, m);
                if (flag == 1)
                    break;
            }
            if (flag != 1) {
                out.println("IMPOSSIBLE");
            } else {
                out.println("POSSIBLE");
                for (String s : res) {
                    for (int i = 0; i < s.length() - 1; i++) {
                        ans[s.charAt(i) - '0'][s.charAt(i + 1) - '0'] = 1;
                    }
                }
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++)
                        out.print(ans[i][j]);
                    out.println();
                }
            }

        }

        public void dfs(int len, int pre, String tmp, int n, long ans) {
            if (tmp.length() == len - 1) {
                tmp += String.valueOf(n);
                res.add(tmp);
                if (res.size() == ans) {
                    flag = 1;
                    return;
                }
            } else {
                for (int i = pre + 1; i < n; i++) {
                    if ((n - i) < len - 1 - tmp.length())
                        return;
                    else {
                        dfs(len, i, tmp += String.valueOf(i), n, ans);
                        if (res.size() == ans)
                            return;
                        tmp = tmp.substring(0, tmp.length() - 1);
                    }
                }
            }


        }

    }
}

