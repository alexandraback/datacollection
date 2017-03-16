import java.util.*;
import java.io.*;
import java.math.*;

public class B {

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // number of test cases
        in.nextLine();
        for (int i = 1; i <= t; ++i) {
            String[] nums = in.nextLine().split(" ");
            int B = Integer.parseInt(nums[0]);
            BigInteger M = new BigInteger(nums[1]);
            // System.out.println(B + "");
            // System.out.println(M.toString());
            BigInteger[] numWays = maxWays(B);
            // System.out.println(numWays[B]);
            if (numWays[B].compareTo(M) < 0) {
                System.out.println("Case #" + i + ": IMPOSSIBLE");            
            } else {
                System.out.println("Case #" + i + ": POSSIBLE");    
                printMatrix(B,M,numWays);   
            }
        }
    }  

    public static void printMatrix(int B, BigInteger M, BigInteger[] numWays) {
        int[][] matrix = new int[B][B];
        for(int i=0; i<B;i++) {
            for(int j=i+1; j<B;j++) {
                matrix[i][j] = 1;
            }    
        }

        BigInteger difference = numWays[B].subtract(M);

        while(difference.compareTo(BigInteger.ZERO) != 0) {
            for(int i=B-1; i>=1; i--){
                if (difference.compareTo(numWays[i]) >= 0) {
                    //System.out.println(i);
                    matrix[i-1][B-1] = 0;
                    difference = difference.subtract(numWays[i]);
                }
            }
        }

        for(int i=0; i<B;i++) {
            for(int j=0; j<B;j++) {
                System.out.print(matrix[i][j]);
            }    
            System.out.println("");
        }
    }

    public static BigInteger[] maxWays(int B) {
        BigInteger[] result = new BigInteger[B+1];
        result[0] = BigInteger.ZERO;
        result[1] = BigInteger.ONE;
        BigInteger runningSum = BigInteger.ONE;
        for(int i=2; i<=B; i++) {
            result[i] = runningSum;
            runningSum = runningSum.add(result[i]);
        }
        return result;
    }
}

