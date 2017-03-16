import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;


public class Consonants {
	public static boolean isConsonant(char c) {
		return c != 'a' &&
			   c != 'i' &&
			   c != 'u' &&
			   c != 'e' &&
			   c != 'o';			   
	}
	
	public static BigInteger fun(char[] s, int n) {
		int[] froms = new int[1000001];
		for (int i = 0; i < s.length; ++i) {
			int start = 0;
			int c = 0;
			if (i > 0) {
				if (froms[i - 1] == 0) {
					break;
				} else {
					start = froms[i - 1];
					if (start - i <= n && isConsonant(s[i - 1])) {
						c = n - 1;
					} else {
						froms[i] = start;
						continue;								
					}
				}
			}
			
			for (int j = start; j < s.length; ++j) {
				if (isConsonant(s[j])) {
					++c;
					if (c == n) {
						froms[i] = j + 1;
//						System.out.println("froms " + Arrays.asList(i, j));
						break;
					}
				} else {
					c = 0;
				}
			}
		}
		
		
		BigInteger r = BigInteger.valueOf(0L);
		for (int i = 0; i < s.length; ++i) {
			if (froms[i] == 0) {
				break;
			}
//			for (int j = i; j < froms[i]; ++j) {
//				System.out.print(s[j]);
//			}
//			System.out.println();
			r = r.add(BigInteger.valueOf(s.length - froms[i] + 1));
		}
		return r;
	}
	
	public static void main(String[] args) throws IOException {
		String filename = args[0];
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintStream out = new PrintStream(filename + ".out");

		int stages = Integer.parseInt(in.readLine());		
		for (int stage = 1; stage <= stages; ++stage) {
//			System.out.println("stage " + Arrays.asList(stage));
			String[] tokens = in.readLine().split("\\s+");
			char[] s = tokens[0].toCharArray();;
			int n = Integer.parseInt(tokens[1]);
			out.printf("Case #%d: %s\n", stage, fun(s, n));
		}
	}
}
