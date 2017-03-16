package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemD {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/D-small-attempt0.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int origSize = in.nextInt();
				int complexity = in.nextInt();
				int numToClean = in.nextInt();
				
				BigInteger[] result = solve(origSize, complexity, numToClean);
				String resultStr = "IMPOSSIBLE";
				if (result != null) {
					StringBuilder resultStrBuild = new StringBuilder();
					for (int j = 0; j < result.length; j++) {
						resultStrBuild.append(result[j]);
						if (j < result.length-1) {
							resultStrBuild.append(" ");
						}
					}
					resultStr = resultStrBuild.toString();
				}
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static BigInteger[] solve(int origSize, int complexity, int numToClean) {
		if (complexity == 1) {
			return solveComplexityOne(origSize, numToClean);
		}
		
		int numNeeded = (origSize + 1) / 2;
		if (numToClean < numNeeded) {
			return null;
		}
		
		BigInteger sectionSize = BigInteger.valueOf(origSize).pow(complexity-1);
		BigInteger[] result = new BigInteger[numNeeded];
		for (int section = 0; section / 2 < numNeeded; section += 2) {
			int offset = section == origSize - 1 ? 0 : section + 1;
			result[section / 2] = sectionSize.multiply(BigInteger.valueOf(section))
					.add(BigInteger.valueOf(offset)).add(BigInteger.ONE);
		}
		
		return result;
	}
	
	private static BigInteger[] solveComplexityOne(int origSize, int numToClean) {
		if (numToClean < origSize) {
			return null;
		}
		
		BigInteger[] result = new BigInteger[origSize];
		for (int i = 1; i <= origSize; i++) {
			result[i-1] = BigInteger.valueOf(i);
		}
		
		return result;
	}
}
