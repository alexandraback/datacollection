package gcj2012.qr;

import java.io.*;
import java.util.StringTokenizer;

/**
 *
 * @author Scott DellaTorre
 */
public class B {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("src/gcj2012/qr/in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2012/qr/B.out")));

        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken()); // Number of Googlers
            int S = Integer.parseInt(st.nextToken()); // Number of suprising cases
            int p = Integer.parseInt(st.nextToken());
            int[] t = new int[N]; // Total points of the Googlers
            for (int j = 0; j < N; j++) {
                t[j] = Integer.parseInt(st.nextToken());
            }

            // What is the maximum number of Googlers that could have had a best
            // result of at least p?

            int lowSurprising = p < 2 ? p : p * 3 - 4;
            int lowNormal = p < 1 ? p : p * 3 - 2;

            int count = 0;
            for (int j = 0; j < N; j++) {
                if (t[j] >= lowNormal) {
                    count++;
                } else if (S > 0 && t[j] >= lowSurprising) {
                    S--;
                    count++;
                }
            }

            out.println("Case #" + (i + 1) + ": " + count);
        }

        out.close();
    }
}
