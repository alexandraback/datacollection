import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 4/14/12
 * Time: 9:22 AM
 * To change this template use File | Settings | File Templates.
 */
public class Dancing {


    public static void main(String[] args) throws Exception {

        String filename = "dancing";
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
            int s = input.nextInt();
            int p = input.nextInt();
            
            int[] g = new int[n];
            for (int i=0;i<n;i++) {
                g[i] = input.nextInt();
            }
            
            out.writeBytes("Case #" + (caseNumber+1) + ": " + solve(n, s, p, g) + "\n");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }
    
    public static int solve(int n, int s, int p, int[] g) {
        int count = 0;

        for (int i=0;i<n;i++) {
            int maxUnsurprised = -1;
            
            if ((g[i]%3) == 0) maxUnsurprised = g[i] / 3;
            else if ((g[i]%3) == 1) maxUnsurprised = (g[i] / 3) + 1;
            else if ((g[i]%3) == 2) maxUnsurprised = (g[i] / 3) + 1;
            
            if (maxUnsurprised >= p) {
                count++;
            } else {
                
                int maxSurprised = -1;

                if ((g[i]%3) == 0 && ((g[i] / 3) - 1) >= 0) maxSurprised = (g[i] / 3) + 1;
                else if ((g[i]%3) == 1) maxSurprised = (g[i] / 3) + 1;
                else if ((g[i]%3) == 2) maxSurprised = (g[i] / 3) + 2;
                
                if (maxSurprised >= p && s > 0) {
                    count++;
                    s--;
                }
            }
        }
        
        return count;
    }
}
