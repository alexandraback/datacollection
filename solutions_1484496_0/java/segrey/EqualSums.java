import java.io.*;
import java.util.*;

public class EqualSums {

    BufferedReader br;
    StringTokenizer st = new StringTokenizer("");

    private void solve() throws IOException {
//        final String IO_FILE = null;
        final String IO_FILE = "./B/C-small-attempt0";
        final PrintWriter pw;
        if (IO_FILE == null) {
            br = new BufferedReader(new InputStreamReader(System.in));
            pw = new PrintWriter(System.out);
        } else {
            br = new BufferedReader(new FileReader(IO_FILE + ".in"));
            pw = new PrintWriter(IO_FILE + ".out");
        }
        int testCases = nextInt();
        for (int ti = 1; ti <= testCases; ti++) {
            int n = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            Answer ans = doSolve(a, n);
            pw.println("Case #" + ti + ":");
            if (ans == null) {
                pw.println("Impossible");
            } else {
                print(pw, ans.myPart1);
                print(pw, ans.myPart2);
            }
        }
        br.close();
        pw.close();
    }

    private void print(PrintWriter pw, List<Integer> part) {
        boolean first = true;
        for (int x : part) {
            if (!first) {
                pw.print(" ");
            }
            first = false;
            pw.print(x);
        }
        pw.println();
    }

    private Answer doSolve(int[] a, int n) {
        int sum = 0;
        for (int x : a) {
            sum += x;
        }
        int[][] d = new int[sum + 1][2];
        for (int i = 0; i < d.length; i++) {
            d[i][0] = d[i][1] = -1;
        }
        d[0][0] = 0;
        for (int x : a) {
            for (int i = sum - x; i >= 0; i--) {
                if (d[i][0] != -1 && (d[i + x][0] == -1 || d[i + x][1] == -1)) {
                    if (d[i + x][0] == -1) {
                        d[i + x][0] = x;
                    }
                    else if (d[i + x][1] == -1) {
                        d[i + x][1] = x;
                    }
                }
            }
        }
        int k = 0;
        for (int i = 2; i <= sum; i++) {
            if (d[i][0] != -1 && d[i][1] != -1) {
                k = i;
                break;
            }
        }
        if (k == 0) {
            return null;
        }
        List<Integer> part1 = new ArrayList<Integer>();
        part1.add(d[k][0]);
        restorePath(d, k - d[k][0], part1);

        List<Integer> part2 = new ArrayList<Integer>();
        part2.add(d[k][1]);
        restorePath(d, k - d[k][1], part2);

        List<Integer> copy1 = new ArrayList<Integer>(part1);
        List<Integer> copy2 = new ArrayList<Integer>(part2);
        part1.removeAll(copy2);
        part2.removeAll(copy1);
        return new Answer(part1, part2);
    }

    private void restorePath(int[][] d, int k, List<Integer> path) {
        int i = k;
        while (i != 0) {
            path.add(d[i][0]);
            i -= d[i][0];
        }
    }

    String nextString() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    public static void main(String[] args) throws IOException {
        new EqualSums().solve();
    }

    static class Answer {
        List<Integer> myPart1;
        List<Integer> myPart2;

        public Answer(List<Integer> part1, List<Integer> part2) {
            myPart1 = part1;
            myPart2 = part2;
        }
    }
}
