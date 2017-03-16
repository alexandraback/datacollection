import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA {

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new TaskA().run();
    }

    void run() throws IOException {
        br = new BufferedReader(new FileReader("A-large.in"));
        out = new PrintWriter("output.txt");

        solve();

        out.close();
    }

    private static String vowels = "aieuo";

    boolean isVowel(char c) {
        return vowels.contains(Character.toString(c));
    }

    void solve() throws IOException {
        int t = nextInt();
        for (int i = 0; i < t; i++)
            solveCase();
    }
    int testCounter = 1;

    void solveCase() throws IOException {
        String name = next();
        int k = nextInt();
        int n = name.length();

        boolean[] ss = new boolean[n];
        int lastVowel = -1;
        for (int i = 0; i <= n; i++) {
            if (i >= k && lastVowel < i - k) {
                ss[i - k] = true;
            }
            if (i < n && isVowel(name.charAt(i))) {
                lastVowel = i;
            }
        }

        long result = 0;
        //System.out.println(Arrays.toString(ss));

        int i = 0;
        for (int j = 0; j < n; j++) {
            if (!ss[j])
                continue;

            long p1 = j - i + 1;
            long p2 = n - j - k + 1;
            result += p1 * p2;
            i = j + 1;
        }

        out.printf("Case #%d: %d\n", testCounter++, result);
       // testCounter++;
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

}
