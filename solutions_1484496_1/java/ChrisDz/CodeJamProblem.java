import java.io.*;
import java.util.*;

/**
 * @author Chris Dziemborowicz <chris@dziemborowicz.com>
 * @version 2012.0506
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
            output[i] = String.format("Case #%d:\n%s", i + 1, res);
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
        String[] parts = testCase.split(" ");
        int n = Integer.parseInt(parts[0]);
        long[] s = new long[n];
        for (int i = 0; i < n; i++) {
            s[i] = Long.parseLong(parts[i + 1]);
        }

        Map<Integer, Integer> sums = new HashMap<Integer, Integer>();
        int max = (1 << n) - 1;
        for (int i = 0; i < max; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sum += s[j];
                }
            }

            Integer ii = sums.get(sum);
            if (ii == null) {
                sums.put(sum, i);
            } else {
                StringBuilder sb = new StringBuilder();

                for (int j = 0; j < n; j++) {
                    if ((ii & (1 << j)) != 0) {
                        sb.append(s[j]);
                        sb.append(' ');
                    }
                }

                sb.append('\n');

                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        sb.append(s[j]);
                        sb.append(' ');
                    }
                }

                return sb.toString();
            }
        }

        return "Impossible";
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