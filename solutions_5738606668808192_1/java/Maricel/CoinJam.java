import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.function.*;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

public class CoinJam {

    public static void main(String[] args) throws IOException {
        new CoinJam().readEachTestAndSolve();
    }

    private void readEachTestAndSolve() throws IOException {
        Scanner scanner = new Scanner(new File("coinjam.txt"));
        PrintWriter writer = new PrintWriter(new File("coinjam_output.txt"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            System.out.println("Solving case: " + test);
            int N = scanner.nextInt();
            int J = scanner.nextInt();

            writer.write("Case #" + test + ":\n" + solveAndTime(N, J) + "\n");
        }

        scanner.close();
        writer.close();
    }

    private String solveAndTime(int n, int j) {
        final long startTime = System.currentTimeMillis();
        final String result = solve(n, j);
        System.out.println("runtime took: " + (System.currentTimeMillis() - startTime) + " ms");
        return result;
    }

    // n = 32, j = 500
    private String solve(int n, int j) {
        final ToLongBiFunction<Long, Long> convert = (binRepr, base) -> {
            if (base == 2) {
                return binRepr;
            }
            long converted = 0, pwr = 1;
            while (binRepr > 0) {
                converted += (binRepr & 1) * pwr;
                pwr *= base;
                binRepr >>= 1;
            }
            return converted;
        };


        final LongFunction<Optional<String>> findDivisors = number -> {
            final List<Long> divisors = new ArrayList<>();

            final LongUnaryOperator obtainDivisor = convertedNumber -> {
                if ((convertedNumber & 1) == 0) {
                    return 2;
                }
                if (convertedNumber % 3 == 0) {
                    return 3;
                }
                if (convertedNumber % 5 == 0) {
                    return 5;
                }
                if (convertedNumber % 7 == 0) {
                    return 7;
                }
                if (convertedNumber % 11 == 0) {
                    return 11;
                }
                return -1;
            };

            final boolean isCoinJam = LongStream
                    .range(2L, 11L)
                    .map(base -> convert.applyAsLong(number, base))
                    .map(obtainDivisor)
                    .peek(divisors::add)
                    .allMatch(divisor -> divisor > 0);

            return isCoinJam ?
                    Optional.of(
                            Long.toBinaryString(number) + " " +
                            divisors
                                    .stream()
                                    .map(String::valueOf)
                                    .collect(Collectors.joining(" "))) :
                    Optional.empty();
        };

        return LongStream
                .range((1L << (n - 2)), (1L << (n - 1)))
                .unordered()
                .parallel()
                .map(x -> (x << 1L) + 1)
                .mapToObj(findDivisors)
                .filter(o -> o.isPresent())
                .limit(j)
                .map(o -> o.get())
                .reduce((a, b) -> a + "\n" + b)
                .get();
    }
}

