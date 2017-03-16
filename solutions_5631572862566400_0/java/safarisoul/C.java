
import java.io.*;
import java.util.*;

public class C {
    private static final String FIN = "C-small-attempt0.in";
    private static final String FOUT = "C-small-attempt0.out";
    // private static final String FIN = "C-large.in";
    // private static final String FOUT = "C-large.out";

    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            N = in.nextInt();
            BFF = new int[N + 1];
            for (int i = 1; i <= N; i++)
                BFF[i] = in.nextInt();
            out.printf("Case #%d: %d\n", t, solve());
        }
    }

    private static int N;
    private static int[] BFF;

    private static int solve() {
        int max = 2;
        int[] sit = new int[N];
        for (int i = 0; i < N; i++)
            sit[i] = i + 1;
        Permutation permutation = new Permutation();
        do {
            for (int len = max + 1; len <= N; len++) {
                boolean ok = true;
                for (int i = 0; i < len; i++) {
                    int bff = BFF[sit[i]];
                    if (sit[(i + 1) % len] != bff
                            && sit[(i + len - 1) % len] != bff)
                        ok = false;
                }
                if (ok)
                    max = Math.max(max, len);
            }
        } while (permutation.permute(sit));
        return max;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(FIN));
        PrintWriter out = new PrintWriter(
                new BufferedWriter(new FileWriter(FOUT)));
        solution(reader, out);
        out.close();
    }

    protected static class In {
        private BufferedReader reader;
        private StringTokenizer tokenizer = new StringTokenizer("");

        public In(BufferedReader reader) {
            this.reader = reader;
        }

        public String next() throws IOException {
            while (!tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}

class Permutation {
    public boolean permute(int[] nums) {
        int n = nums.length;
        if (n < 2)
            return false;
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1]) {
                int j = n - 1;
                while (nums[j] < nums[i])
                    j--;
                swap(nums, i, j);
                reverse(nums, i + 1, n - 1);
                return true;
            }
        reverse(nums, 0, nums.length - 1);
        return false;
    }

    private void swap(int[] nums, int i, int j) {
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }

    private void reverse(int[] nums, int i, int j) {
        while (i < j)
            swap(nums, i++, j--);
    }
}
