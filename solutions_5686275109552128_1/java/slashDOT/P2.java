import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class P2 {

	private static final String FILE_PREFIX = "B-large";
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(FILE_PREFIX + ".in"));
		PrintWriter writer = new PrintWriter(new File(FILE_PREFIX + ".out"));
		int T = scanner.nextInt();
		for (int m=0; m<T; m++) {
			int D = scanner.nextInt();
			int[] P = new int[D];
			
			for (int n=0; n<D; n++)
				P[n] = scanner.nextInt();

			Arrays.sort(P);
			
			int A = P[P.length - 1], Z = 2;
			
			while (Z < A) {
				int sum = Z;
				for (int i=0; i<P.length; i++) {
					sum += (P[i] - 1) / Z;
				}
				A = Math.min(A, sum);
				Z++;
			}

			System.out.println("Case #" + (m+1) + ": " + A);
			writer.println("Case #" + (m+1) + ": " + A);
		}
		scanner.close();
		writer.close();
	}
}
