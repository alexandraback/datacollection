package codejam13;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class FairAndSquare {
	public void solve(String input, String output) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(input));
		BufferedWriter out = new BufferedWriter(new FileWriter(output));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		int index = 1;
		
		while (T > 0) {
			String[] interval = in.readLine().split(" ");
			long A = Long.parseLong(interval[0]);
			long B = Long.parseLong(interval[1]);
			
			out.write("Case #" + index + ": " + countFairAndSquare(A, B));
			out.newLine();
			
			--T;
			++index;
		}
		
		in.close();
		out.close();
	}
	
	private int countFairAndSquare(long A, long B) {
		int count = 0;
		long start = (long)Math.ceil(Math.sqrt(A));
		long end = (long)Math.sqrt(B);
		for (long i = start; i <= end; ++i) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				++count;
			}
		}
		return count;
	}
	
	private boolean isPalindrome(long n) {
		String s = Long.toString(n);
		int start = 0, end = s.length() - 1;
		while (start < end) {
			if (s.charAt(start) != s.charAt(end)) {
				return false;
			}
			++start;
			--end;
		}
		return true;
	}
}
