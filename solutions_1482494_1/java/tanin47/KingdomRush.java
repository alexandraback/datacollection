import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 4/28/12
 * Time: 8:43 AM
 * To change this template use File | Settings | File Templates.
 */
public class KingdomRush {


    public static void main(String[] args) throws Exception {

        String filename = "KingdomRush/B-large.in";
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
            int[][] p = new int[n][2];

            for (int i=0;i<n;i++) {
                p[i][0] = input.nextInt();
                p[i][1] = input.nextInt();
            }
            System.out.print("Case #" + (caseNumber + 1));
            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(n, p) + "\n");
            System.out.println(" Finish");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    private static String solve(int n, int[][] p) {
        
        int count = 0;
        int star = 0;
        int completed = 0;
        
        while (completed < n) {
            //System.out.println("star = " + star);
            int[] result = getMaxEarning(p, star);

            if (result == null) return "Too Bad";

            int level = result[0];
            int stage = result[1];
            int earning = result[2];
            
           //System.out.println(level + " " + stage + " " + earning);
            
            star += earning;
            
            if (stage == 1) {
                p[level][0] = -1;
                p[level][1] = -1;
            } else if (stage == 0) {
                p[level] [0] = -1;
            } else {
                System.out.println("Wtf " + stage);
            }

            if (p[level][1] == -1) {
                completed++;
            }

            count++;
        }
        
        return ("" + count);
    }
    
    private static int[] getMaxEarning(int[][]  p, int star) {

        for (int i=0;i<p.length;i++) {
            if (p[i][1] >= 0 && star >= p[i][1]) {
                int earning = (p[i][0] == -1) ? 1 : 2;
                return new int[] {i, 1, earning};
            }
        }
        
        int maxRequired = 0;
        int maxIndex = -1;
        for (int i=0;i<p.length;i++) {

            if (p[i][0] >= 0 && star >= p[i][0]) {
                if (p[i][1] > maxRequired) {
                    maxIndex = i;
                    maxRequired = p[i][1];
                }
            }
         }

        if (maxIndex == -1)  return null;
        return new int[] { maxIndex, 0, 1};
    }
}
