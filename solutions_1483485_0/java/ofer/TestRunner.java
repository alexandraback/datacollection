package codejam.is;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/13/12
 * Time: 8:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class TestRunner {

    public void runTests(String inputFilePath, String outputFilePath, Class testClass) {
        try {

            BufferedReader br = new BufferedReader(new FileReader(inputFilePath));
            int numOfTests = Integer.parseInt(br.readLine());

            Test[] tests = new Test[numOfTests];
            for (int i = 0; i < numOfTests; i++) {
                tests[i] = (Test)testClass.newInstance();
                tests[i].run(br.readLine());
            }

            br.close();

            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilePath));
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
