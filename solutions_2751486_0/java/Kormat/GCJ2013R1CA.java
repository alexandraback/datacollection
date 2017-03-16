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

public class GCJ2013R1CA {
	public static void main(String[] args) throws IOException {
		String content = Files.toString(new File(args[0]), Charsets.UTF_8);
		Scanner scanner = new Scanner(content);
		
		StringBuilder output = new StringBuilder();
		int testCases = scanner.nextInt();
		for(int i=1; i<=testCases; i++) {
			String solution = "Case #"+i+": "+solve(scanner)+"\n";
			System.err.print(solution);
			output.append(solution);
		}
		Files.write(output.toString(), new File("out.out"), Charsets.UTF_8);
	}

	private static String solve(Scanner scanner) {
		String name = scanner.next();
		int n = scanner.nextInt();

		if (n>name.length()) return "0";
		
		List<Integer> inits = Lists.newArrayList();
		char[] chars = name.toCharArray();
		
		
		groupStartingFrom(chars, n, 0, inits);
		long result = 0;
		for(int i = 0; i <inits.size(); i++) {
			int s = inits.get(i);
			int prev = (i>0)?inits.get(i-1)+1:0;
			
			long partial = (s-prev+1)*(chars.length-(s+n-1));
			result += partial;
		}
		return ""+result;
	}
	
	private static void groupStartingFrom(char[] chars, int n, int start, List<Integer> inits) {
		if (start > chars.length - n) return;
		int consonants = 0;
		for (int i=start; i<chars.length; i++) {
			if (consonant(chars[i])) {
				if (++consonants >= n) {
					inits.add(i-n+1);
				}
			} else {
				groupStartingFrom(chars, n, i+1, inits);
				return;
			}
		}
	}
	
	private static boolean consonant(char c) {
		return c!='a' && c!='e' && c!= 'i' && c!= 'o' && c!='u';
	}
}
