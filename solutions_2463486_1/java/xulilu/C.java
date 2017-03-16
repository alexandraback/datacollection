package qr;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner dataScanner = new Scanner(new File("c.txt"));
		ArrayList<Long> data = new ArrayList<Long>(50);
		while (dataScanner.hasNextLong())
			data.add(dataScanner.nextLong());
		dataScanner.close();
		Scanner in = new Scanner(new File("c.in"));
		PrintWriter out = new PrintWriter(new File("c-large.out"));
		int n = in.nextInt();
		for (int c = 1; c <= n; c++) {
			long a = in.nextLong();
			long b = in.nextLong();
			int start = 0;
			int end = data.size() - 1;
			while (data.get(start) < a)
				start++;
			while (data.get(end) > b)
				end--;
			if (end - start > 30)
				System.out.println(end - start + 1);
			out.printf("Case #%d: %d\n", c, end - start + 1);
		}
		in.close();
		out.close();
	}

	private static boolean isPalindrome(long i) {
		String number = String.valueOf(i);
		return isPalindrome(number);
	}

	private static boolean isPalindrome(String string) {
		int len = string.length();
		for (int i = 0; i < len / 2; i++)
			if (string.charAt(i) != string.charAt(len - i - 1))
				return false;
		return true;
	}
}
