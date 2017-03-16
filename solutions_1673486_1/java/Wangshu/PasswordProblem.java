import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PasswordProblem {

	static final String input_path = "data/input.txt";
		
	private static double solve(int A, int B, double[] p) {
		double allcorrect = 1;
		double[] hasError = new double[A + 1];
		
		for (int i = 0; i < A; i ++) {
			allcorrect *= p[i];
			hasError[i + 1] = 1 - allcorrect;
		}
			
		
		double expectedStrategyA = (B - A + 1) * allcorrect + (B - A + 1 + B + 1) * (1 - allcorrect);
		double ans = expectedStrategyA;
		
		double expectedStrategyB = B + 2;
		if (expectedStrategyB < ans)
			ans = expectedStrategyB;
		
		for (int back = 1; back <= A; back ++) {
			double errorPossibility = hasError[A - back];
			double expected = errorPossibility * (B + 1 + 2 * back + B - A + 1) + (1 - errorPossibility) * (2 * back + B - A + 1);
//			System.out.println(String.format("back: %d\terror: %3f\texpected: %3f", back, errorPossibility, expected));
			if (expected < ans)
				ans = expected;
		}
		
//		System.out.println(expectedStrategyA);
//		System.out.println(expectedStrategyB);
		return ans;
	}
	
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			intext = in.readLine();
			String[] parts = intext.split(" ");
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			double[] p = new double[A];
			intext = in.readLine();
			parts = intext.split(" ");
			
			for (int i = 0; i < A; i ++)
				p[i] = Double.parseDouble(parts[i]);
			
			System.out.print(String.format("Case #%d: %7f", caseIter + 1, solve(A, B, p)));
			System.out.println();
		}
		in.close();
	}

}
