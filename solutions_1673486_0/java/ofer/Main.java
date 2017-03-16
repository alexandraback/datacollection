package codejam.one;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/28/12
 * Time: 3:49 AM
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    private static final String path = "C:\\Users\\ofer\\Desktop\\codejam\\files\\";
    private static final String filePrefix = "A-small-attempt1";

    private static final String inputFile = path + filePrefix + ".in";
    private static final String outputFile = path + filePrefix + ".out";

    public static void main(String[] args) {
        try {

            BufferedReader br = new BufferedReader(new FileReader(inputFile));

            // Read number of test cases
            int numOfTests = Integer.parseInt(br.readLine());

            OneTest[] tests = new OneTest[numOfTests];
            for (int i = 0; i < numOfTests; i++) {
                tests[i] = new OneTest();
                String[] input;
                String firstLine = br.readLine();

                input = new String[2];
                input[0] = firstLine;
                input[1] = br.readLine();
                tests[i].run(input);
            }

            br.close();

            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
            for (int i = 0; i < numOfTests; i++) {
                bw.write(tests[i].getOutput(i+1));
            }
            bw.close();


        } catch (Exception e) {
            System.out.println("Caught exception: " + e);
            e.printStackTrace();
        }

    }
}
