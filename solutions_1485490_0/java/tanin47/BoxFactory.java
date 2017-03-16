import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 5/6/12
 * Time: 5:05 PM
 * To change this template use File | Settings | File Templates.
 */
public class BoxFactory {


    public static void main(String[] args) throws Exception {

        String filename = "BoxFactory/C-small-attempt0.in";
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
            int m = input.nextInt();

            long[][] boxes = new long[n][2];
            long[][] toys = new long[m][2];

            for (int i=0;i<n;i++) {
                boxes[i][0] = input.nextLong();
                boxes[i][1] = input.nextLong();
            }

            for (int i=0;i<m;i++) {
                toys[i][0] = input.nextLong();
                toys[i][1] = input.nextLong();
            }

            System.out.println("Case #" + (caseNumber + 1));
            out.writeBytes("Case #" + (caseNumber + 1) + ": " + solve(n, m, boxes, toys) + "\n");
            System.out.println(" Finish");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    static long max = 0;
    private static long solve(int n, int m, long[][] boxes, long[][] toys) {
        max = 0;
        recur(boxes, toys, 0, 0, 0, 0, 0);
        return max;
    }

    private static void recur(long[][] boxes, long[][] toys, int i, int j, long boxUsed, long toyUsed, long count) {
        if (i == boxes.length || j == toys.length) {
            if (count > max) max = count;
            return;
        }

        if (boxes[i][1] == toys[j][1]) {
            long left = (boxes[i][0] - boxUsed);
            if (left > (toys[j][0] - toyUsed)) left = (toys[j][0] - toyUsed);
            
            boxUsed += left;
            toyUsed += left;

            //System.out.println("Before " + count + " " + left);
            count += left;
            
            //System.out.println("Count=" + count + " (" + i + ", " + j + ") " + boxes[i][1] + "==" + toys[j][1]);
        }

        // move i
        recur(boxes, toys, i+1, j, 0, toyUsed, count);

        // move j
        recur(boxes, toys, i, j+1, boxUsed, 0, count);
    }

}
