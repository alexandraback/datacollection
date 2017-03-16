import com.google.common.base.Splitter;
import com.google.common.collect.Lists;

import java.io.*;
import java.util.Iterator;
import java.util.List;

public class Main {
    private static List<int[][]> readInput(Reader reader) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(reader);
        int numCases = Integer.valueOf(bufferedReader.readLine());

        List<int[][]> result = Lists.newArrayListWithCapacity(numCases);

        for (int i = 0; i < numCases; i++) {
            String firstLine = bufferedReader.readLine();
            Iterator<String> firstLineTokens = Splitter.on(" ").split(firstLine).iterator();
            int n = Integer.valueOf(firstLineTokens.next());
            int m = Integer.valueOf(firstLineTokens.next());

            int[][] testCase = new int[n][m];
            for (int j = 0; j < n; j++) {
                String line = bufferedReader.readLine();
                Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
                for (int k = 0; k < m; k++) {
                    testCase[j][k] = Integer.valueOf(lineTokens.next());
                }
            }
            result.add(testCase);
        }

        return result;
    }

    private static final String TEST_INPUT = "3\n" +
            "3 3\n" +
            "2 1 2\n" +
            "1 1 1\n" +
            "2 1 2\n" +
            "5 5\n" +
            "2 2 2 2 2\n" +
            "2 1 1 1 2\n" +
            "2 1 2 1 2\n" +
            "2 1 1 1 2\n" +
            "2 2 2 2 2\n" +
            "1 3\n" +
            "1 2 1\n";


    public static void main(String[] args) throws IOException, InterruptedException {
        List<int[][]> testCases = readInput(new FileReader("c:\\comp\\large.in"));
        PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\large.out"));

        int currentCase = 1;
        for (int[][] testCase : testCases) {
            boolean result = true;
            for (int i = 0; i < testCase.length && result; i++) {
                for (int j = 0; j < testCase[0].length && result; j++) {
                    result = testCell(i, j, testCase);
                }
            }

            System.out.println("Case #" + currentCase + ": " + (result ? "YES" : "NO"));
            outStream.println("Case #" + currentCase + ": " + (result ? "YES" : "NO"));
            currentCase++;
        }
    }

    private static boolean testCell(int x, int y, int[][] testCase) {
        boolean largestInLine = true;
        for (int i = 0; i < testCase.length && largestInLine; i++) {
            if (testCase[x][y] < testCase[i][y]) {
                largestInLine = false;
            }
        }
        if (largestInLine) {
            return true;
        }
        boolean largestInColumn = true;
        for (int i = 0; i < testCase[0].length && largestInColumn; i++) {
            if (testCase[x][y] < testCase[x][i]) {
                largestInColumn = false;
            }
        }
        return largestInColumn;
    }

}
