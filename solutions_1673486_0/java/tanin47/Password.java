import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 4/28/12
 * Time: 8:14 AM
 * To change this template use File | Settings | File Templates.
 */
public class Password {


    public static void main(String[] args) throws Exception {

        String filename = "Password/small";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();

        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {

            int a = input.nextInt();
            int b = input.nextInt();
            input.nextLine();

            double[] p = new double[a];

            for (int i=0;i<a;i++) {
                p[i] = input.nextDouble();
            }

            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(a, b, p) + "\n");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }


    private static double solve(int a, int b, double[] p) {
        
        double allCorrect = 1.0;
        
        for (int i=0;i<a;i++) allCorrect *= p[i];
        
        // case 1
        double expected_1 = allCorrect * (b - a + 1) + (1.0 - allCorrect) * (b - a + 1 + b + 1);

        // case 3
        double expected_3 = (1 + b + 1);
        
        double[] expected_2 = new double[a+1];
        for (int k=0;k<expected_2.length;k++) {
            double correct = 1.0;
            for (int i=0;i<(a-k);i++) correct *= p[i];
            
            expected_2[k] = correct * (k + k + b-a + 1) + (1.0 - correct) * (k + k + b-a + 1 + b + 1);
        }
        
        double minExpected = (expected_1 < expected_3) ? expected_1 : expected_3;
        for (int i=0;i<expected_2.length;i++) {
            if (expected_2[i] < minExpected) minExpected = expected_2[i];
        }
        
        return  minExpected;
    }
}
