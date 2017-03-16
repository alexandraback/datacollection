import java.io.*;

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
            String testCase = br.readLine() + "\n" + br.readLine();
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
        // Parse
        String[] lines = testCase.split("\n");
        String[] pStr = lines[1].split(" ");
        int a = Integer.parseInt(lines[0].split(" ")[0]);
        int b = Integer.parseInt(lines[0].split(" ")[1]);
        double[] p = new double[pStr.length];
        for (int i = 0; i < a; i++) {
            p[i] = Double.parseDouble(pStr[i]);
        }

        double[] pCum = new double[p.length];
        pCum[0] = p[0];
        for (int i = 1; i < a; i++) {
            pCum[i] = pCum[i - 1] * p[i];
        }

        double minKeys = 1 + b + 1;
        for (int i = 0; i < a; i++) {
            double k = (i + i + b - a + 1) * pCum[a - 1 - i];
            k += (i + i + b - a + 1 + b + 1) * (1 - pCum[a - 1 - i]);
            if (k < minKeys) {
                minKeys = k;
            }
        }

        return String.format("%f", minKeys);
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