import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

import com.google.common.base.Charsets;
import com.google.common.collect.Lists;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class FairSquare {
	public static void main(String[] args) throws IOException {
		String content = Files.toString(new File(args[0]), Charsets.UTF_8);
		Scanner scanner = new Scanner(content);
		
		StringBuilder output = new StringBuilder();
		int testCases = scanner.nextInt();
		
		List<Long> fairSquares = precomputeFairSquares(100000000000000L);
		
		for(int i=1; i<=testCases; i++) {
			String solution = "Case #"+i+": "+solve(scanner, fairSquares)+"\n";
			System.err.print(solution);
			output.append(solution);
		}
		Files.write(output.toString(), new File("out.out"), Charsets.UTF_8);
	}

	private static List<Long> precomputeFairSquares(long max) {
		List<Long> fss = Lists.newArrayList();
		
		long maxToCompute = (long)Math.floor(Math.sqrt(max));
		for (long i=1; i<=maxToCompute; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				System.err.println(i*i);
				fss.add(i*i);
			}
		}
		return fss;
	}
	private static boolean isPalindrome(long num) {
		String str = String.valueOf(num);
		return str.substring(0, str.length()/2).equals(
			new StringBuilder(str.substring((int)Math.ceil(str.length()/2d))).reverse().toString()
		);
	}

	private static String solve(Scanner scanner, List<Long> fss) {
		long a = scanner.nextLong();
		long b = scanner.nextLong();
		long result = 0;
		for (long fs:fss) {
			if (fs >= a && fs<=b) result++;
		}
		return "" + result;
	}
}
