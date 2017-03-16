import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class CountingSheep {

    public static void main(String[] args) throws FileNotFoundException {
        new CountingSheep().readEachTestAndSolve();
    }

    private void readEachTestAndSolve() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("sheep.txt"));
        PrintWriter writer = new PrintWriter(new File("sheep_output.txt"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            System.out.println("Solving case: " + test);
            long N = scanner.nextInt();

            writer.write("Case #" + test + ": " + solve(N, N) + "\n");
        }

        scanner.close();
        writer.close();
    }

    private String solve(long N, final long inc) {
        if (N == 0) {
            return "INSOMNIA";
        }

        final Set<Long> remainingDigits = new HashSet<>(10);
        for (long i = 0; i <= 9; i++) {
            remainingDigits.add(i);
        }

        do {
            long nn = N;
            while (nn > 0) {
                remainingDigits.remove(nn % 10);
                nn /= 10;
            }
            N += inc;
        } while (!remainingDigits.isEmpty());

        return String.valueOf(N - inc);
    }
}

