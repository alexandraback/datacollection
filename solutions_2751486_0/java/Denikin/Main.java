import java.io.FileInputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    static final String EXAMPLE_INPUT = "example.txt";
    static final String SMALL_INPUT = "A-small-attempt0.in";
    static final String LARGE_INPUT = "A-large.in";
    static final String OUTPUT = "output.txt";

    public static void main(String[] args) throws Exception {
        startProcessing();
    }

    static void startProcessing() throws Exception {
        try(FileInputStream stream = new FileInputStream(SMALL_INPUT);
            Scanner scanner = new Scanner(stream);
            PrintWriter writer = new PrintWriter(OUTPUT))
        {
            int T = Integer.valueOf(scanner.nextLine());
            for (int caseNum = 1; caseNum <= T; ++caseNum) {
                long caseRes = solveCase(scanner);
                writer.println("Case #" + caseNum + ": " + caseRes);
            }
        }
    }

    static long solveCase(Scanner scanner) {
        String line = scanner.nextLine();
        String[] parts = line.split(" ");
        String name = parts[0];
        int n = Integer.valueOf(parts[1]);

        int nameLen = name.length();
        long counter = 0;
        for (int subLen = nameLen; subLen >= n; --subLen) {
            long levels = 0;
            for (int begin = 0; begin <= (nameLen - subLen); ++begin) {
                int res = containsN(name, n, begin, subLen);
                counter += res;
                levels += res;
            }
            if (levels == 0) {
                break;
            }
        }
        return counter;
    }

    static int containsN(String name, int n, int begin, int subLen) {
        int cons = 0;
        String vovels = "aeiou";
        for (int index = begin; index < (begin + subLen); ++index) {
            String aChar = name.substring(index, index + 1);
            if (vovels.contains(aChar)) {
                cons = 0;
            } else {
                cons += 1;
            }
            if (cons >= n) {
                return 1;
            }
        }
        return 0;
    }
}
