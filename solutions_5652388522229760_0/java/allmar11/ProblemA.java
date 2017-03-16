package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemA {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/A-small-attempt0.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int num = in.nextInt();
				
				BigInteger result = solve(num);
				String resultStr = result == null ? "INSOMNIA" : result.toString();
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static BigInteger solve(int num) {
		if (num == 0) {
			return null;
		}
		
		BigInteger bigNum = BigInteger.valueOf(num);
		BigInteger nextNum = bigNum;
		boolean[] visited = new boolean[10];
		int numVisited = 0;
		while (true) {
			for (int digitChar : nextNum.toString().chars().toArray()) {
				int digit = digitChar - '0';
				if (!visited[digit]) {
					visited[digit] = true;
					numVisited++;
				}
			}
			
			if (numVisited == 10) {
				break;
			}
			
			nextNum = nextNum.add(bigNum);
		}
		
		return nextNum;
	}
}
