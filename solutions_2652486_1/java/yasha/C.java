import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {


    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("c.in")));
        PrintStream out = new PrintStream(new FileOutputStream("c.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String[] d = in.readLine().split(" ");
            int r = Integer.parseInt(d[0]);
            int n = Integer.parseInt(d[1]);
            int m = Integer.parseInt(d[2]);
            int k = Integer.parseInt(d[3]);
            out.println("Case #" + (cas + 1) + ": ");
            for (int tr = 0; tr <r; tr++) {
                d = in.readLine().split(" ");
                int[] ans = new int[10];

                long[] p = new long[d.length];
                for (int i = 0; i < p.length; i++) {
                    p[i] = Long.parseLong(d[i]);
                    ans[5] = Math.max(ans[5], power(p[i], 5));
                    ans[7] = Math.max(ans[7], power(p[i], 7));
                    if (m < 6) {
                        ans[3] = Math.max(ans[3], power(p[i], 3));
                    }
                }
                Arrays.sort(p);

                int[] vote = new int[m+1];

                for (int i = 0; i < p.length; i++) {
                    for (int j = i +1; j < p.length; j++) {
                        if (p[i] != p[j]) {
                            if (p[j] % p[i] == 0) {
                                long v = p[j] /p[i];
                                if (v <= m) {
                                    vote[(int)v]++;
                                }
                            }
                        }
                    }
                }


                while (sum(ans) < n) {
                    int best = 2;
                    int score = -10000000;
                    for (int i = 2; i <=m; i++) {
                        int delta = vote[i] *k - ans[i] * sum(vote);
                        if (delta > score) {
                            score = delta;
                            best = i;
                        }
                    }
                    ans[best]++;
                }


                for (int i = 0; i < ans.length; i++) {
                    for (int j = 0; j < ans[i]; j++) {
                          out.print(Integer.toString(i));
                    }
                }
                out.println();

            }
        }

        out.flush();
        out.close();
    }

    static int sum(int[] d) {
        int ans = 0;
        for (int i : d) {
            ans += i;
        }
        return ans;
    }

    static int power(long n, long d) {
        int ans = 0;
        while (n % d ==0) {
            ans++;
            n /=d;
        }
        return ans;
    }


    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
