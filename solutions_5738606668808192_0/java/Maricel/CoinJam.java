import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
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
//                if (isPrime(convertedNumber)) {
//                    return -1;
//                }
                if ((convertedNumber & 1) == 0) {
                    return 2;
                }
                final long sqrtNr = (long) Math.sqrt(convertedNumber);
                for (long div = 3; div <= sqrtNr; div +=2) {
                    if (convertedNumber % div == 0) {
                        return div;
                    }
                }
                return -1;
            };

            final boolean isCoinJam = LongStream
                    .range(2, 11)
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
                .range((1 << (n - 2)), (1 << (n - 1)))
                .unordered()
                .parallel()
                .map(x -> (x << 1) + 1)
                .mapToObj(findDivisors)
                .filter(o -> o.isPresent())
                .limit(j)
                .map(o -> o.get())
                .reduce((a, b) -> a + "\n" + b)
                .get();
    }
}

