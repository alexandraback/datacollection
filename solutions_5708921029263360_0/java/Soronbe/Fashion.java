import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by david on 5/8/16.
 */
public class Fashion {
    public static void main(String[] args) {
        new Fashion();
    }

    public Fashion() {
        try {
            Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter("solution.txt", "UTF-8");

            int T = sc.nextInt();
            sc.nextLine();
            for (int i = 1; i <= T; ++i) {
                pw.print(String.format("Case #%d: ", i));
                run(sc, pw);
            }
            pw.close();
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    protected void run(Scanner scanner, PrintWriter writer) {
        int J = scanner.nextInt();
        int P = scanner.nextInt();
        int S = scanner.nextInt();
        int K = scanner.nextInt();
        if (S < K) {
            K = S;
        }

        int[][] matchesJ = new int[J][S];
        int[][] matchesP = new int[P][S];

        int count = 0;
        int shift = Math.min(J, K) * Math.min(P, K);
        writer.println(J * P * K);

        for (int j = 1; j <= J; ++j) {
            for (int p = 1; p <= P; ++p) {
                int maxK = 0;
                for (int s = 1; s <= S; ++s) {
                    int s2 = ((s+S+p+j-2)%S)+1;
                    if (matchesJ[j-1][s2-1] < K && matchesP[p-1][s2-1] < K) {
                        writer.println(String.format("%d %d %d", j, p, s2));
                        ++matchesJ[j-1][s2-1];
                        ++matchesP[p-1][s2-1];
                        count++;
                        ++maxK;
                    }
                    if(maxK == K) {
                        break;
                    }
                }
            }
        }
    }
}
