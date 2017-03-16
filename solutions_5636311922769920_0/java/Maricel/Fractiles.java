import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;
import java.util.function.LongFunction;
import java.util.function.LongUnaryOperator;
import java.util.function.ToLongBiFunction;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class Fractiles {

    public static void main(String[] args) throws IOException {
        new Fractiles().readEachTestAndSolve();
    }

    private void readEachTestAndSolve() throws IOException {
        Scanner scanner = new Scanner(new File("fractiles.txt"));
        PrintWriter writer = new PrintWriter(new File("fractiles_output.txt"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            System.out.println("Solving case: " + test);
            int K = scanner.nextInt();
            int C = scanner.nextInt();
            int S = scanner.nextInt();

            writer.write("Case #" + test + ":" + solveAndTime(K, C, S) + "\n");
        }

        scanner.close();
        writer.close();
    }

    private String solveAndTime(int k, int c, int s) {
        return IntStream
                .range(1, k+1)
                .collect(StringBuilder::new, (sb, e) -> sb.append(" " + e), (sb1, sb2) -> sb1.append(" " + sb2))
                .toString();
    }
}

