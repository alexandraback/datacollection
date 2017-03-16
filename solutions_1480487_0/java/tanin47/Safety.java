import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 5/5/12
 * Time: 11:10 PM
 * To change this template use File | Settings | File Templates.
 */
public class Safety {

    public static void main(String[] args) throws Exception {

        String filename = "Safety/small_1.in";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();

        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {
            int n = input.nextInt();
            int[] s = new int[n];

            for (int i=0;i<n;i++) {
                s[i] = input.nextInt();
            }
            System.out.print("Case #" + (caseNumber + 1));
            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(n, s) + "\n");
            System.out.println(" Finish");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    private static String solve(int n, int [] s) {
        double x = 0;
        int[] p = new int[n];
        for (int i=0;i<n;i++) {
            p[i] = s[i];
            x += s[i];
        }
        
        Arrays.sort(p);

        double[] result = new double[n];
        
        for (int i=0;i<n;i++) {
            // fill before
            double left = 1.0;
            for (int j=0;j<i;j++) {
                left -= (double)(p[i] - p[j]) / x;
            }
            
            if (left < 0.0) {
                result[i] = 0.0;
                continue;
            }
            
            // fill after
            for (int j=i+1;j<n;j++) {
                double effort = (double) (p[j] - p[j-1]) / x;
                if ((effort * j) < left) {
                    result[i] += effort;
                    left -= effort * j;
                } else {
                    effort = left / j;
                    left -= effort * j;
                    result[i] += effort;
                    break;
                }
            }
            
            result[i] += left / n;
            result[i] = result[i] * 100.0;
        }
        
        
        double[] realResult = new double[n];
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (s[i] == p[j]) {
                    realResult[i] = result[j];
                    break;
                }
            }
        }

        StringBuffer sb = new StringBuffer();
        for (int i=0;i<n;i++) {
            if (i > 0) sb.append(' ');
            sb.append(realResult[i]);
        }

        return sb.toString();
    }

}
