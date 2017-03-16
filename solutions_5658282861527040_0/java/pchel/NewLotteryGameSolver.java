import java.io.*;
import java.util.Locale;
import java.util.Scanner;

public class NewLotteryGameSolver {
    //    private static final String INPUT_FILE_NAME = "A-large.in";
                                    private static final String INPUT_FILE_NAME = "B-small-attempt0.in";
    //                                private static final String INPUT_FILE_NAME = "A-small-attempt1.in";
//    private static final String INPUT_FILE_NAME = "input.in";
    //    private static final String OUTPUT_FILE_NAME = "A-large.out";
                                private static final String OUTPUT_FILE_NAME = "B-small-attempt0.out";
    //                            private static final String OUTPUT_FILE_NAME = "A-small-attempt1.out";
//    private static final String OUTPUT_FILE_NAME = "output.out";

    private int A;
    private int B;
    private int K;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE_NAME)))) {
            Scanner scanner = new Scanner(reader);
            scanner.useLocale(Locale.ENGLISH);
            int testCasesCount = scanner.nextInt();

            for (int i = 1; i <= testCasesCount; i++) {
                System.out.println("Case #" + i);
                scanner.nextLine();
                NewLotteryGameSolver solver = new NewLotteryGameSolver();

                solver.readData(scanner);
                long solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution < 0 ? "Fegla Won" : solution);
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_FILE_NAME)
        ))) {
            writer.write(builder.toString());
        }
    }

    private long solve() {
        long result = 0;

        for (int a = 0; a < A; a++) {
            for (int b = 0; b < B; b++) {
                if ((a & b) < K) {
                    result++;
                }
            }
        }

        return result;
    }

    private void readData(Scanner scanner) {
        A = scanner.nextInt();
        B = scanner.nextInt();
        K = scanner.nextInt();
    }
}
