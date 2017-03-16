import java.util.*;
import java.io.*;


public class A {

    public static PrintWriter log;

    public static void main(String[] args) {
        String fileName = "A-small-attempt0";
        String inputFile = fileName+".in.txt";
        String outputFile = fileName+".out.txt";
        String logFile = fileName+".log.txt";

        File in = new File(inputFile);
        try {
            PrintWriter out = new PrintWriter(outputFile);
            log = new PrintWriter(logFile);
            Scanner scan = new Scanner(in);
            int numTest = scan.nextInt();
            for (int testCase = 1; testCase <= numTest; testCase++) {


                // for integer: scan.nextInt();     // -2147483648 ~ 2147483647 or -10^-9 ~ 10^9
                // for long: scan.nextLong();       // -18446744073709551616L ~ 18446744073709551615L or -10^19 ~ 10^19
                // for double: scan.nextDouble();
                // for string: scan.nextLine();
                // for string: scan.next(); // Finds and returns the next complete token from this scanner.

                // input variables are 3 scalars
                // read
                String S = scan.next();
                int I = S.indexOf('/');
                long P = Long.parseLong(S.substring(0,I));
                long Q = Long.parseLong(S.substring(I+1));

                // print
                String logStr = "P = " + P + ", Q = " + Q;
                System.out.format("Case #%d: %s\n", testCase, logStr);
                log.format("Case #%d: %s\n", testCase, logStr);

                // solve
                String result = solve(P, Q);
                out.format("Case #%d: %s\n", testCase, result);

                // input contains 2 2-D arrays
                /*
                // read
                int[][] first = new int[4][4];
                int[][] second = new int[4][4];
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        first[i][j] = scan.nextInt();
                    }
                }
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        second[i][j] = scan.nextInt();
                    }
                }

                // print
                System.out.format("Case #%d:\n", testCase);
                log.format("Case #%d:\n", testCase);
                for (int i = 0; i < first.length; i++) {
                    String logStr = Arrays.toString(first[i]);
                    System.out.format("%s\n", logStr);
                    log.format("%s\n", logStr);
                }
                for (int i = 0; i < second.length; i++) {
                    String logStr = Arrays.toString(second[i]);
                    System.out.format("%s\n", logStr);
                    log.format("%s\n", logStr);
                }

                // solve
                double result = solve(first, second);
                out.format("Case #%d: %.7f\n", testCase, result);
                */

            }
            out.close();
            log.close();
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
    }

    public static long findGCD(long P, long Q) {
        if (P == 0L) return Q;
        return findGCD(Q%P, P);
        
    }
    
    
    public static int findPower2(long Q) {
        if (Q == 1L) return 0;
        if (Q%2 == 1) return Integer.MIN_VALUE;
        return findPower2(Q >> 1)+1;
        
    }
    
    public static int findLargestBit(long P) {
        if (P == 0) return 0;
        return 1+findLargestBit(P>>1);
        
    }
    
    
    public static String solve(long P, long Q) {
        long G = findGCD(P, Q);
        P /=  G;
        Q /= G;
        String logStr = "P = " + P + ", Q = " + Q;
        System.out.format("%s\n", logStr);

        // Q has to be 2^x
        int x = findPower2(Q);
        if (x < 0) {
            return "impossible";
        }
        int y = findLargestBit(P);
        return Integer.toString(x-y+1);
        
        //public static double solve(int[][] first, int[][] second) {
        //return "impossible";
    }

}
