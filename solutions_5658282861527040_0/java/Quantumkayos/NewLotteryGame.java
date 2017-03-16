package codejam2014.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class NewLotteryGame {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("input.txt"));
        PrintStream output = new PrintStream(new File("output.txt"));
        int numberOfCases = input.nextInt();
        for(int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
            int A = input.nextInt(), B = input.nextInt(), K = input.nextInt();
            String solution = solve(A, B, K);
            output.format("Case #%d: %s\n", caseNumber, solution);
            System.out.format("Case #%d, with inputs :\n\t%s\n", caseNumber, solution);
        }
    }
    public static String solve(long A, long B, long K) {
        long wholeSquare = A * B, toFurtherInvestigate = 1;
        toFurtherInvestigate *= Math.max(0, A - K);
        toFurtherInvestigate *= Math.max(0, B - K);
        long result = wholeSquare - toFurtherInvestigate;
        
        for(long a = K; a < A; a++) {
            for(long b = K; b < B; b++) {
                if((a & b) < K) {
                    result++;
                }
            }
        }
        return Long.toString(result);
    }
}