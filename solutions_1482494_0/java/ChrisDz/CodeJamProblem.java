import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0423
 */
public class CodeJamProblem
{
    /**
     * Entry point.
     * 
     * @param args exactly two command-line arguments, being the input path and the output path.
     */
    public static void main(String... args) throws Exception
    {
        // Check parameters
        if (args.length != 2) {
            String className = CodeJamProblem.class.getSimpleName();
            System.err.printf("Usage: java %s <input> <output>\n", className);
            return;
        }

        // Process test cases
        String[] testCases = readTestCases(args[0]);
        String[] output = process(testCases);
        writeOutput(args[1], output);
    }


    /**
     * Reads each test case from an input file.
     * 
     * @param inputPath input file path.
     * @return an array of test cases.
     */
    public static String[] readTestCases(String inputPath) throws Exception
    {
        BufferedReader br = new BufferedReader(new FileReader(inputPath));
        int numTestCases = Integer.parseInt(br.readLine());

        String[] testCases = new String[numTestCases];
        for (int i = 0; i < numTestCases; i++) {
            String testCase = br.readLine();
            int n = Integer.parseInt(testCase);
            for (int j = 0; j < n; j++) {
                testCase += '\n' + br.readLine();
            }
            testCases[i] = testCase;
        }
        br.close();
        return testCases;
    }


    /**
     * Processes each test case, and returns an array of outputs.
     * 
     * @param testCases test cases.
     * @return an output for each test case.
     */
    public static String[] process(String[] testCases) throws Exception
    {
        String[] output = new String[testCases.length];
        for (int i = 0; i < testCases.length; i++) {
            Object res = process(testCases[i]);
            output[i] = String.format("Case #%d: %s", i + 1, res);
        }
        return output;
    }


    /**
     * Processes a test case, and returns an output.
     * 
     * @param testCase a test case.
     * @return an output for the test case.
     */
    public static Object process(String testCase) throws Exception
    {
        String[] lines = testCase.split("\n");
        int n = Integer.parseInt(lines[0]);
        long[] starsRequired = new long[n];
        for (int i = 0; i < n; i++) {
            String[] parts = lines[i + 1].split(" ");
            starsRequired[i] = (Long.parseLong(parts[1]) << 32) + Long.parseLong(parts[0]);
        }

        Arrays.sort(starsRequired);

        int count = 0;
        int stars = 0;
        int[] earned = new int[n];
        for (int i = 0; i < n; i++) {
            int sr1i = (int) ((starsRequired[i] << 32) >>> 32);
            int sr2i = (int) (starsRequired[i] >>> 32);

            int starsStart;
            do {
                starsStart = stars;
                for (int j = n - 1; sr2i > stars && j >= i; j--) {
                    int sr1j = (int) ((starsRequired[j] << 32) >>> 32);
                    int sr2j = (int) (starsRequired[j] >>> 32);

                    if (sr1j <= stars && earned[j] == 0) {
                        stars++;
                        earned[j] = 1;
                        count++;
                        break;
                    }
                }
            } while (starsStart != stars && sr2i > stars);

            if (sr2i > stars) {
                return "Too Bad";
            } else {
                stars += 2 - earned[i];
                earned[i] = 2;
                count++;
            }
        }

        return count;
    }


    /**
     * Writes an array of outputs to a file.
     * 
     * @param outputPath output file path.
     * @param output an array of outputs.
     */
    public static void writeOutput(String outputPath, String[] output) throws Exception
    {
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputPath));
        for (String line : output) {
            bw.write(line);
            bw.write('\n');
        }
        bw.close();
    }
}