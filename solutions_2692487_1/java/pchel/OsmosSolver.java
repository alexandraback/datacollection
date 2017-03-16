import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;

public class OsmosSolver {
    private static final String INPUT_FILE_NAME = "A-large.in";
//    private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
//        private static final String INPUT_FILE_NAME = "input2.in";

    private static final String OUTPUT_FILE_NAME = "A-large.out";
//    private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";
//        private static final String OUTPUT_FILE_NAME = "output.out";

    private int n;

    private int a;

    private int[] size;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = Files.newBufferedReader(Paths.get(INPUT_FILE_NAME), Charset.defaultCharset())) {
            Scanner scanner = new Scanner(reader);
            int testCasesCount = scanner.nextInt();
            scanner.nextLine();

            for (int i = 1; i <= testCasesCount; i++) {
                OsmosSolver solver = new OsmosSolver();

                solver.readData(scanner);
                int solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution == -1 ? "Too Bad" : Integer.toString(solution));
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(OUTPUT_FILE_NAME), Charset.defaultCharset())) {
            writer.write(builder.toString());
        }
    }

    private int solve() {
        Arrays.sort(size);

        int moteSize = a;
        int index = 0;

        // absorb all motes w/o additional operations
        while(index < n && size[index] < moteSize) {
            moteSize += size[index];
            index++;
        }

        // all removals
        int result = n - index;
        int newMotesCount = 0;

        while(newMotesCount < result) {
            if (index == n) {
                break;
            }
            moteSize += moteSize - 1;
            newMotesCount++;
            while(index < n && size[index] < moteSize) {
                moteSize += size[index];
                index++;
            }
            result = Math.min(result, newMotesCount + n - index);
        }

        return result;
    }

    private void readData(Scanner scanner) {
        a = scanner.nextInt();
        n = scanner.nextInt();

        size = new int[n];
        for (int i = 0; i < n; i++) {
            size[i] = scanner.nextInt();
        }
    }
}
