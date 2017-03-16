import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Fractiles {

    public static void main(String[] args) throws IOException {
        new Fractiles().readEachTestAndSolve();
    }

    private void readEachTestAndSolve() throws IOException {
        Scanner scanner = new Scanner(new File("fractiles_large.txt"));
        PrintWriter writer = new PrintWriter(new File("fractiles_output.txt"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            System.out.println("Solving case: " + test);
            int K = scanner.nextInt();
            int C = scanner.nextInt();
            int S = scanner.nextInt();

            writer.write("Case #" + test + ": " + solveToString(K, C, S) + "\n");
        }

        scanner.close();
        writer.close();
    }

    private String solveToString(int k, int c, int s) {
        if (s < Math.ceil((double) k / c)) {
            return "IMPOSSIBLE";
        }

        return solve(k, c, s)
                .stream()
                .map(String::valueOf)
                .collect(Collectors.joining(" "));
    }

    private List<BigInteger> solve(int k, int c, int s) {
        final List<BigInteger> result = new ArrayList<>();
        final BigInteger bigK = BigInteger.valueOf(k);

        int kIdx = 0;
        for (int counter = 0; counter < Math.ceil((double) k/c); counter++) {
            BigInteger kCPower = BigInteger.ONE;
            BigInteger index = BigInteger.ZERO;
            int p = Math.min(k - kIdx, c);

            while(p-- > 0) {
                index = index.add(BigInteger.valueOf(kIdx).multiply(kCPower));
                kCPower = kCPower.multiply(bigK);
                kIdx++;
            }
            result.add(index.add(BigInteger.ONE));
        }

        return result;
    }
}

