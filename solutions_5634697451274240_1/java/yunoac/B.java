package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	
/*

5
-
-+
+-
+++
--+-

 */
	
	private static Scanner reader;
	private static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			String S = reader.next();
			char[] c = S.toCharArray();
			int cnt = 0;
			while(true) {
				int j;
				for(j = 1; j < c.length; j++) {
					if(c[j] != c[j - 1]) {
						break;
					}
				}
				if(j == c.length) break;
				for(int i = 0; i < j; i++) {
					c[i] = c[i] == '-' ? '+' : '-'; 
				}
				cnt++;
			}
			if(c[0] == '-') {
				cnt++;
			}
			writer.printf("Case #%d: %d\n", tc, cnt);
		}
		reader.close();
		writer.close();
	}

}
