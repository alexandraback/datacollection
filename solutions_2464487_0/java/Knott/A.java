package codejam1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	
	private static String solve(long r, long t) {
		long k = 2*r-1;
		long y = 1;
		while (2*y*y + y*k <= t) {
			y++;
		}
		y--;
		return Long.toString(y);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = null;
		BufferedWriter bw = null;
		try {
			scanner = new Scanner(new File("src/codejam1a/A-small-attempt0.in"));
			int numOfInput = Integer.parseInt(scanner.nextLine());
			bw = new BufferedWriter(new FileWriter(new File("a-result-small.out")));
			for (int i=0; i<numOfInput; i++) {
				bw.write("Case #");
				bw.write(Integer.toString(i+1));
				bw.write(": ");
				long r = scanner.nextLong();
				long t = scanner.nextLong();
				String result = solve(r,t);
				bw.write(result);
				if (i < numOfInput-1) {
					bw.write('\n');
				}
			}
			scanner.close();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
