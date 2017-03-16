import java.io.*;
import java.util.ArrayList;
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

        String filename = "Diamond/A-large.in";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();

        ArrayList<Integer>[] indices = new ArrayList[1000];
        for (int i=0;i<indices.length;i++) indices[i] = new ArrayList<Integer>();

        ArrayList<Integer>[] froms = new ArrayList[1000];
        for (int i=0;i<froms.length;i++) froms[i] = new ArrayList<Integer>();

        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {
            int n = input.nextInt();

            for (int i=0;i<n;i++) {
                indices[i].clear();
                froms[i].clear();
                
                int m = input.nextInt();
                for (int k=0;k<m;k++) {
                   indices[i].add(input.nextInt() - 1);
                }
            }
            System.out.println("Case #" + (caseNumber + 1));
            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(n, indices, froms) + "\n");
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
    private static String solve(int n, ArrayList<Integer>[] indices, ArrayList<Integer>[] froms) {
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                d[i][j] = -1;
            }
            
            int size = indices[i].size();
            for (int j=0;j<size;j++) {
                int from = indices[i].get(j);
                d[i][from] = from;
                froms[i].add(from);
                //System.out.println("Forge " + from + " to " + i);
            }
        }

        for (int count=0;count<=(n+1);count++) {
            for (int i=0;i<n;i++) {
                int size = indices[i].size();

                for (int j=0;j<size;j++) {
                    int from = indices[i].get(j);
                    if (from == i) continue;

                    int sizeFroms = froms[from].size();

                    for (int k=0;k<sizeFroms;k++) {
                        int target = froms[from].get(k);
                        if (target == i) continue;

                        if (d[i][target] == from) {
                            // do nothing
                        } else if (d[i][target] == -1) {
                            d[i][target] = from;
                            froms[i].add(target);
                            //System.out.println("Forge " + target + " to " + i + " through " + from);
                        } else {
                            //System.out.println("Forge " + target + " to "  + i + " through " + from + " but it has " + d[i][target]);
                            return "Yes";
                        }
                    }
                }
            }
        }

        return "No";
    }
}
