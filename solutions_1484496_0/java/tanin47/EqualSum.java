import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 5/6/12
 * Time: 12:04 AM
 * To change this template use File | Settings | File Templates.
 */
public class EqualSum {

    public static void main(String[] args) throws Exception {

        String filename = "EqualSum/small.in";
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
            System.out.println("Case #" + (caseNumber + 1));
            
            String[] sets = solve(n, s);
            out.writeBytes("Case #" + (caseNumber + 1) + ":\n");
            for (int i=0;i<sets.length;i++) out.writeBytes(sets[i] + "\n");
            System.out.println(" Finish");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    private static String[] solve(int n, int[] s) {
        int totalBin = (int)(Math.pow(2, 20));

        for (int i=0;i<totalBin;i++) {
            
            int sum = 0;
            for (int k=0;k<s.length;k++) {
                if (((1<<k)&i) == 0) continue;
                sum += s[k];
            }
            
            if (sum == 0) continue;

            //System.out.println(sum + " " + i);

            ArrayList<Integer> buffer = new ArrayList<Integer>();
            boolean ok = findSubset(s, i, sum, buffer);

            if (ok) {

                return new String[] {
                    generateResult(s, i),
                    generateResult(buffer)
                };
            }
        }
        
        return new String[] { "Impossible" };
    }
    
    private static boolean findSubset(int[] s, int used, int sum, ArrayList<Integer> buffer) {
        if (sum < 0) return false;
        
        //System.out.println("sum = " + sum + ", used=" + used);

        for (int i=0;i<s.length;i++) {
            if (((1<<i)&used) > 0) continue;
            
            int target = sum - s[i];
            if (target == 0) {
                System.out.println("found = " + s[i]);
                buffer.add(s[i]);
                return true;
            } else {
                if (findSubset(s, used | (1 << i), target, buffer)) {

                    System.out.println("found = " + s[i]);
                    buffer.add(s[i]);
                    return true;
                }
            }
        }

        return false;
    }
    
    private static String generateResult(int[] s, int used) {
        StringBuffer sb = new StringBuffer();
        boolean first = true;
        for (int i=0;i<s.length;i++) {
              if (((1<<i) & used) == 0) continue;
            
            if (!first) sb.append(' ');
            sb.append(s[i]+"");
            first = false;
        }
        return sb.toString();
    }

    private static String generateResult(ArrayList<Integer> set) {
        StringBuffer sb = new StringBuffer();
        boolean first = true;
        for (int i=0;i<set.size();i++) {
            if (i > 0) sb.append(' ');
            sb.append(set.get(i) + "");
        }
        return sb.toString();
    }
}
