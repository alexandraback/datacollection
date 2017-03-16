import java.io.*;

/**
 * @author arshsab
 * @since 05 2014
 */

public class Lottery {
    public static void main(String... args) throws IOException {
        String FILE_NAME = "lottery";

        BufferedReader br = new BufferedReader(new FileReader(FILE_NAME + ".in"));

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            String[] log = br.readLine().split(" ");

            final int A = Integer.parseInt(log[0]);
            final int B = Integer.parseInt(log[1]);
            final int K = Integer.parseInt(log[2]);

            int total = 0;

            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    if ((i & j) < K) {
                        total++;
                    }
                }
            }

            out.printf("Case #%d: %d\n", t, total);
        }

        out.flush();
        out.close();
    }
}
