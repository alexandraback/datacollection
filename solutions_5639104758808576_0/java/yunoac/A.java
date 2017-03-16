package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new PrintWriter(new FileWriter("out"));
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int smax = reader.nextInt();
			String s = reader.next();
			int min = solve(smax, s);
			writer.printf("Case #%d: %d\n", tc, min);
		}
		writer.close();
		reader.close();
	}

	static int solve(int smax, String s) {
		int min = 0;
		int cur = 0;
		for(int i = 0; i <= smax; i++) {
			if(s.charAt(i) != '0') {
				if(cur >= i) {
					cur += Character.getNumericValue(s.charAt(i));					
				} else {
					min += i - cur;
					cur += i - cur + Character.getNumericValue(s.charAt(i));
				}
			}
		}
		return min;
	}
	
}
