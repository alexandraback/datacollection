import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemD {
    private static final String FILENAME = "D-small-attempt0";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        long start = System.currentTimeMillis();
        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	int K = input.nextInt();
        	int C = input.nextInt();
        	int S = input.nextInt();
        	long p = (long)Math.pow(K, C - 1);
        	output.print("Case #" + t + ":");
        	for (int i=0; i<K; i++) {
        		output.print(" " + (p * i + 1));
        	}
        	output.print("\n");
        }
        System.out.print("Total duration: " + (System.currentTimeMillis() - start) + "ms\n");

        input.close();
        output.close();
	}
}
