
import java.io.*;

public class Main {

    static final String FILE = "B-small-attempt0";
    static final String INPUT = FILE + ".in";
    static final String OUTPUT = FILE + ".out";
    //
    static final int[] NOT_SURPRISING = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
    static final int[] SURPRISING = {0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 0, 0};

    public static void main(String[] args) throws FileNotFoundException, IOException {
        int T, N, S, p, x, y;
        int[] t;

        PrintWriter pw;
        try (BufferedReader br = new BufferedReader(new FileReader(INPUT))) {
            pw = new PrintWriter(OUTPUT);

            T = Integer.parseInt(br.readLine());
            for (x = 1; x <= T; x++) {
                y = 0;

                //
                String temp[] = br.readLine().split(" ");
                N = Integer.parseInt(temp[0]);
                S = Integer.parseInt(temp[1]);
                p = Integer.parseInt(temp[2]);

                t = new int[N];
                for (int i = 0; i < N; i++) {
                    t[i] = Integer.parseInt(temp[3 + i]);
                }

                //
                for (int i = 0; i < N; i++) {
                    if (NOT_SURPRISING[t[i]] >= p) {
                        y++;
                    } else if (S > 0 && SURPRISING[t[i]] >= p) {
                        y++;
                        S--;
                    }
                }

                System.out.println("Case #" + x + ": " + y);
                pw.println("Case #" + x + ": " + y);
            }
        }
        pw.close();
    }
}
