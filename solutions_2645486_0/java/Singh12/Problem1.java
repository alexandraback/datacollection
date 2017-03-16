package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: amarjeetsingh
 * Date: 27/04/13
 * Time: 6:19 AM
 * To change this template use File | Settings | File Templates.
 */
public class Problem1 {
    static Scanner scanner = null;
    static PrintWriter printWriter = null;

    public static void main(String[] args) throws FileNotFoundException {
        scanner = new Scanner(new File("/Users/amarjeetsingh/Downloads/B-small-attempt1.in"));
//        scanner = new Scanner(new File("/Users/amarjeetsingh/Desktop/sample1.in"));
        printWriter = new PrintWriter("/Users/amarjeetsingh/Desktop/output1A.in");
        int testcases = scanner.nextInt();
        for (int i = 1; i <= testcases; i++) {
            long e = scanner.nextLong();
            long currentEnergy = e;
            long r = scanner.nextLong();
            long gain = 0;
            int n = scanner.nextInt();
            long[] values = new long[n];
            for (int j = 1; j <= n; j++) {
                values[j - 1] = scanner.nextLong();
            }
            for (int j = 0; j < n; j++) {
                long[] output =nextMax(values, j);
                long energyInvested;
                if ((e < r)||((output[1]-j)*r>e)||(output[1]==j)) {
                    energyInvested = currentEnergy;
                }
                else if((currentEnergy+(output[1]-j)*r)<e){
                    energyInvested=0;
                }
                else {
                    long maxOfTwo=(currentEnergy+(output[1]-j)*r)-e;
                    energyInvested=maxOfTwo>currentEnergy?currentEnergy:maxOfTwo;
                }
                gain+=values[j]*energyInvested;
                currentEnergy=(currentEnergy-energyInvested+r)>e?e :(currentEnergy-energyInvested+r);
            }
            for (int j = 0; j < n; j++) {

            }

            String outputString="Case #"+i+": "+gain;
            System.out.println(outputString);
            printWriter.write(outputString+"\n");
        }
        printWriter.flush();
        printWriter.close();
    }

    public static long[] nextMax(long[] arr, int start) {
        long[] output = new long[2];
        output[0] = arr[start];
        output[1] = start;
        for (int i = start; i < arr.length; i++) {
            if (output[0] < arr[i]) {
                output[0] = arr[i];
                output[1] = i;
                break;
            }
        }
        return output;
    }
}
