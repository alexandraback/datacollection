import java.io.*;

/**
 * Created by skortzy on 02/05/15.
 */
public class CodeJamR1APA {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
        PrintWriter pw = new PrintWriter(new FileOutputStream("A.out"));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        for (int i = 0; i < T; i++) {
            System.out.println("Case #" + (i + 1));

            line = br.readLine();
            pw.println("Case #" + (i+1) + ": " + solve(Integer.parseInt(line)));

        }
        pw.close();

    }

    private static int solve(int N) {
        int[] values = new int[N + 1];
        values[1] = 1;
        for (int i = 2; i <= N; i++) {
            int reversed = reverse(i);
            if (i % 10 > 0 && reversed < i) {
                values[i] = Math.min(values[reversed], values[i-1]) + 1;
            } else {
                values[i] = values[i-1] + 1;
            }
        }


        return values[N];

    }

    private static int reverse(int N) {
        int result = 0;
        while (N > 0) {
            result = result * 10 + N % 10;
            N /= 10;
        }
        return result;
    }
}
