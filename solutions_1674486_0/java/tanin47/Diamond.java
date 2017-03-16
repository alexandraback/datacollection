import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 5/6/12
 * Time: 4:05 PM
 * To change this template use File | Settings | File Templates.
 */
public class Diamond {

    public static void main(String[] args) throws Exception {

        String filename = "Diamond/A-small-attempt3.in";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();

        boolean[][] d = new boolean[1000][1000];
        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {
            int n = input.nextInt();

            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    d[i][j] = false;
                }
                
                int m = input.nextInt();
                for (int k=0;k<m;k++) {
                    int index = input.nextInt();

                    d[i][index - 1] = true;
                }
            }
            System.out.println("Case #" + (caseNumber + 1));
            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(n, d) + "\n");
            System.out.println(" Finish");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    static int[][] d = new int[1000][1000];
    static int[][] previous = new int[1000][1000];
    private static String solve(int n, boolean[][] conn) {
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (conn[i][j] == true) {
                    d[i][j] = j;
                } else {
                    d[i][j] = -1;
                }
            }
        }

        for (int count=0;count<51;count++) {

            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    previous[i][j] = d[i][j];
                }
            }

            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    if (conn[i][j] == false) continue;
                    if (i == j) continue;

                    for (int k=0;k<n;k++) {
                        if (previous[j][k] == -1) continue;
                        if (j == k || k == i) continue;

                        if (d[i][k] == j) {
                            // do nothing
                        } else if (d[i][k] == -1) {
                            d[i][k] = j;
                            System.out.println("Forge " + k + " to " + i + " through " + j);
                        } else {
                            System.out.println("Forge " + k + " to "  + i + " through " + j + " but it has " + d[i][k] + " (" + d[j][k] + ")");
                            return "Yes";
                        }
                    }
                }
            }
        }

        return "No";
    }
}
