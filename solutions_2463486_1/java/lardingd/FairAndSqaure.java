package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class FairAndSqaure {
	
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("outputSquares.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			while(strLine != null) {
				if(strLine.matches("\\d+ \\d+")) {
					String inputs[] = strLine.split(" ");
					long n = Long.parseLong(inputs[0]);
					long k = Long.parseLong(inputs[1]);
					int amount = getFairAndSquare(n,k);
					System.out.println(String.format("Case #%s: %s", answer, amount));
					out.println(String.format("Case #%s: %s", answer, amount));
					answer++;
				}
				strLine = in.readLine();
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");

	}

	private static int getFairAndSquare(long n, long k) {
		long lower = (long) Math.sqrt(n);
		if(lower * lower < n) {
			lower++;
		}
		long upper = (long) Math.sqrt(k);
		int count = 0;
		for(long i = lower; i <= upper; i++) {
			if(isPalindrome(i) && isPalindrome(i*i)) {
				count++;
			}
		}
		return count;
	}
	
	private static boolean isPalindrome(long candidate) {
		String canString = Long.toString(candidate);
		for(int i = 0; i < canString.length() /2; i++) {
			if(canString.charAt(i) != canString.charAt(canString.length() -i -1)) {
				return false;
			}
		}
		return true;
	}
	
}
