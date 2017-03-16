

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class Fractiles {

    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    public static void solve(final InputStream in, final PrintStream out) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            String line = br.readLine();
            String[] parts = line.split(" ");
            int k = Integer.valueOf(parts[0]);
            int c = Integer.valueOf(parts[1]);
            int s = Integer.valueOf(parts[2]);

            if (s < k) {
                out.println("Case #" + i + ": IMPOSSIBLE");
                continue;
            }
            out.print("Case #" + i + ":");
            for (int j = 1; j <= k; j++) {
                out.print(' ');
                out.print(j);
            }
            out.println();
        }
    }
}
