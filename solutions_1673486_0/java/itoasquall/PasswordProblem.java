package Round1A;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class PasswordProblem {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("passwordproblem.in"));
		System.setOut(new PrintStream("passwordproblem.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine().trim());
		for(int t = 1; t <= T; t++) {
			String[] parts = bf.readLine().trim().split("[ ]+");
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			int keysLeft = B - A;
			
			double[] p = new double[A];
			parts = bf.readLine().trim().split("[ ]+");
			for(int i = 0; i < A; i++)
				p[i] = Double.parseDouble(parts[i]);
			
			double enterRightAway = 1d + B + 1d;
			
			double product = 1d;
			for(int i = 0; i <= A; i++) {
				// delete until i-th character
				int deletes = A - i;
				
				if(i > 0) product *= p[i - 1];
				
				// if the characters from [0, i - 1] are right
				int rightKeys = 2 * deletes + keysLeft + 1;
				double expected = product * rightKeys;
				
				// if some of the characters from [0, i - 1] is wrong
				int wrongKeys = 2 * deletes + keysLeft + 1 + B + 1;
				expected += (1d - product) * wrongKeys;
				
				enterRightAway = Math.min(enterRightAway, expected);
			}
			
			System.out.println("Case #" + t + ": " + enterRightAway);
		}
	}

}
