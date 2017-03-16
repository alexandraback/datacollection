import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemD {
    private static final String FILENAME = "D-large";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        long start = System.currentTimeMillis();
        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	int K = input.nextInt();
        	int C = input.nextInt();
        	int S = input.nextInt();
        	
        	int minS = Math.max((int) Math.ceil(K / (float)C), 1);
        	if (S < minS) {
        		output.print("Case #" + t + ": IMPOSSIBLE\n");
        		continue;
        	}

        	output.print("Case #" + t + ":");

        	long initSize = (long)Math.pow(K, C - 1);
        	long gSize = initSize;
        	int c = C;
        	long p = 1;
        	for (int i=0; i<K; i++) {
        		p = p + gSize * i;
        		if (c > 1 && i != (K-1)) {
        			gSize = gSize / K;
        			c--;
        		} else {
        			output.print(" " + p);
        			gSize = initSize;
        			c = C;
        			p = 1;
        		}
        	}
        	output.print("\n");
        }
        System.out.print("Total duration: " + (System.currentTimeMillis() - start) + "ms\n");

        input.close();
        output.close();
	}
}
