import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/*
 * Author :	David Tang
 * Date :	Apr 13, 2013
 */

public class FairAndSquare {
	
	private final static String fileName = "C-large-1";
	
	private static PrintWriter ecrivain;

	public static void main(String[] args) {
		BufferedReader buffRead = null;
		try {
			ecrivain = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			buffRead =new BufferedReader(new InputStreamReader(new FileInputStream(fileName + ".in")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		int t;
		
		try {
			t = Integer.parseInt(buffRead.readLine());
			for (int i = 0; i < t; i++) {
				solve(i+1, buffRead.readLine());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			buffRead.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		ecrivain.close();
	}
	
	private static void solve(int number, String s) {
		String[] ss = s.split(" ");
		long[] input = new long[ss.length];
		for (int i = 0; i < ss.length; i++) {
			input[i] = Long.parseLong(ss[i]);
		}
		long a = input[0];
		long b = input[1];
		int count = 0;
		for (long i = (long)Math.ceil(Math.sqrt(a)); i <= (long)Math.sqrt(b); i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				count++;
			}
		}
		ecrivain.println("Case #" + number + ": " + count);
	}
	
	private static boolean isPalindrome(long n) {
		String s = "" + n;
		for (int i = 0; i < (s.length()/2); i++) {
			if (s.charAt(i) != s.charAt(s.length()-1-i)) {
				return false;
			}
		}
		return true;
	}
	
}
