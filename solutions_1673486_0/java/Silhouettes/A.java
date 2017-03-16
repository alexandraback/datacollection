import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;


public class A {
	public static void main(String[] args) throws NumberFormatException, IOException {
			// Use scanner! Good for reading in bigints too.
			// Arrays.fill for initialising arrays
			// Look up cumulative frequency tables (only for dynamic querying with new numbers coming in)
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("in.in")));
		PrintStream writer = new PrintStream(new FileOutputStream("out.out"));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			String[] tokens = reader.readLine().split(" ");
			int A = Integer.parseInt(tokens[0]);
            int B = Integer.parseInt(tokens[1]);
            tokens = reader.readLine().split(" ");
            double[] P = new double[A+1];
            for (int j = 1; j <= A; j++) {
                P[j] = Double.parseDouble(tokens[j-1]);
            }
            double bestSoFar = B + 2;
            double probSoFar = 1;
            for (int j = 1; j <= A; j++) {
                probSoFar *= P[j];
                double expected = (A - j) + (B - j) + 1 + (1 - probSoFar) * (B + 1);
                if (expected < bestSoFar) {
                    bestSoFar = expected;
                }
            }
            writer.printf("Case #%d: %.6f\n", i, bestSoFar);
		}
	}
}
