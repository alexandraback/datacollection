import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        int maxNum = 1000000;
        boolean[] isP = new boolean[maxNum + 10];
        int[] prm = new int[maxNum + 10];
        int[] save = new int[11];
        ArrayList<String> arr = new ArrayList<String>();

        public void getprms() {
            int k = 0;
            for (int i = 0; i < maxNum; i++) {
                isP[i] = true;
            }
            isP[0] = false;
            isP[1] = false;
            for (int i = 2; i <= maxNum; i++) {
                if (isP[i] == false)
                    continue;
                prm[k++] = i;
                for (int j = i * i; j <= maxNum && i <= 1000; j += i) {
                    isP[j] = false;
                }
            }
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int d = in.nextInt();
            int n = in.nextInt();
            out.println("Case #1:");
            StringBuilder sb = new StringBuilder();
            sb.append("1");
            dfs(sb, 1);
            getprms();

            for (String s : arr) {
                if (n == 0)
                    break;
                int flag = 0;
                for (int i = 2; i <= 10; i++) {
                    long tmp = gao(s, i);
                    for (int p : prm) {
                        if (p >= tmp || p == 0)
                            break;
                        if ((tmp % p) == 0) {
                            flag++;
                            save[i] = p;
                            break;
                        }
                    }
                }
                if (flag == 9) {
                    out.print(s + " ");
                    for (int i = 2; i <= 10; i++)
                        out.print(save[i] + " ");
                    out.println();
                    n--;
                }
            }
        }

        public void dfs(StringBuilder sb, int n) {
            if (n == 15) {
                sb.append("1");
                arr.add(sb.toString());
                sb.deleteCharAt(15);
                return;
            }
            sb.append("0");
            dfs(sb, n + 1);
            sb.deleteCharAt(n);
            sb.append("1");
            dfs(sb, n + 1);
            sb.deleteCharAt(n);
        }

        public long gao(String s, int n) {
            long ans = 0;
            long a = 1;
            for (int i = s.length() - 1; i >= 0; i--) {
                ans += a * (s.charAt(i) - '0');
                a *= n;
            }
            return ans;
        }

    }
}

