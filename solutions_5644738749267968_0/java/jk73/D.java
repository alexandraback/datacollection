import java.io.BufferedReader;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class D {

    public static void main(String[] args) throws Throwable {
        try (BufferedReader reader = Files.newBufferedReader(Paths
                .get("/Users/jk/D.in"))) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int c = 1; c <= numCases; c++) {
                int num = Integer.parseInt(reader.readLine());
                double[] naomi = new double[num];
                String[] split = reader.readLine().split(" ");
                for (int i = 0; i < num; i++) {
                    naomi[i] = Double.parseDouble(split[i]);
                }
                double[] ken = new double[num];
                split = reader.readLine().split(" ");
                for (int i = 0; i < num; i++) {
                    ken[i] = Double.parseDouble(split[i]);
                }
                Arrays.sort(naomi);
                Arrays.sort(ken);
                solve(c, num, naomi, ken);
            }
        }
    }

    private static void solve(int caseNum, int num, double[] naomi, double[] ken) {
        int xwins = 0;
        {
            int kh = num - 1;
            for (int nh = num; --nh >= 0;) {
                if (naomi[nh] > ken[kh]) {
                    xwins++;
                } else {
                    kh--;
                }
            }
        }

        int wins = 0;
        {
            int kl = 0;
            int nl = 0;
            for (int i = 0; i < num; i++) {
                if (naomi[nl] > ken[kl]) {
                    wins++;
                    nl++;
                    kl++;
                } else {
                    nl++;
                }
            }
        }

        System.out.format("Case #%d: %d %d%n", caseNum, wins, xwins);
    }
}
