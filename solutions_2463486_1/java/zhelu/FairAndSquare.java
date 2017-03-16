import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class FairAndSquare {

	Vector<Long> palindromes = new Vector<Long>();


	public FairAndSquare(long max) {
		palindromes.add(1l);
		palindromes.add(4l);
		palindromes.add(9l);
		double sqrt10 = Math.sqrt(10);
		double ceiling = Math.sqrt(max);
		long top = 1l;
		while (makePalindrome(top) < ceiling) {
			for (long i = top; i < (long) (top * sqrt10) + 1; i++) {
				long j = makePalindrome(i);
				if (isPalindrome(j) && isPalindrome(j * j)) {
					palindromes.add((j * j));
				}

			}
			if (makePalindromeWithMiddle(top, 0) >= ceiling) {
				top *= 10;
				continue;
			}
			for (long i = top; i < (long) (top * sqrt10) + 1; i++) {
				for (int k = 0; k < 10; k++) {
					long j = makePalindromeWithMiddle(i, k);
					if (isPalindrome(j) && isPalindrome(j * j)) {
						palindromes.add((j * j));
					}
				}
			}
			top *= 10;
		}
	}


	private long makePalindrome(long n) {
		String s = String.valueOf(n);
		StringBuilder rev = new StringBuilder(s);
		rev.reverse();
		StringBuilder sb = new StringBuilder(s.length() * 2);
		sb.append(s);
		sb.append(rev);
		return Long.parseLong(sb.toString());
	}


	private long makePalindromeWithMiddle(long n, int m) {
		String s = String.valueOf(n);
		StringBuilder rev = new StringBuilder(s);
		rev.reverse();
		StringBuilder sb = new StringBuilder(s.length() * 2);
		sb.append(s);
		sb.append(m);
		sb.append(rev);
		return Long.parseLong(sb.toString());
	}


	public void process(String input, String output) throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int count = 0;
			long A = sc.nextLong();
			long B = sc.nextLong();
			for (int j = 0; j < palindromes.size(); j++) {
				if (palindromes.get(j) > B)
					break;
				if (palindromes.get(j) >= A)
					count++;
			}
			System.out.println("Case #" + (i + 1) + ": " + count);
			bw.write("Case #" + (i + 1) + ": " + count);
			if (i != cases - 1)
				bw.newLine();
		}
		sc.close();
		bw.close();
	}


	private boolean isPalindrome(long n) {
		String s = String.valueOf(n);
		int len = s.length();
		for (int i = 0; i < (len + 1) / 2; i++) {
			if (s.charAt(i) != s.charAt(len - 1 - i))
				return false;
		}
		return true;
	}


	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FairAndSquare f = new FairAndSquare(100000000000000l);
		f.process("C-large-1.in", "fair-output-large.txt");

	}

}
