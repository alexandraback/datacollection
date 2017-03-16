package gcj2013.R1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemB {
//	public static final String input = "/tmp/ProblemB.sample.in";
	public static final String input = "/tmp/B-small-attempt0.in";	
//	public static final String output = "/tmp/ProblemB.Sample.out";
	public static final String output = "/tmp/ProblemB.Small.out";

	public static void main(String[] args) throws IOException {		
		Scanner sc = new Scanner(new FileReader(input));
		int testCase = sc.nextInt();
		
		for (int i=0; i<testCase; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			write("Case #" + (i+1) + ": " + solve(x, y) + "\n");					
		}
	}
	
	private static String solve(int X, int Y) {
		StringBuffer sb = new StringBuffer();
		int x = 0, y = 0;
		int step = 1;

		for (; X != x; step++) {
			if (Math.abs(X - x) >= step) {
				if (X > x) {
					sb.append('E');
					x += step;
				} else {
					sb.append('W');
					x -= step;
				}
			} else {
				if (X > x) {
					sb.append("WE");
					x++;
					step++;
				} else {
					sb.append("EW");
					x--;
					step++;
				}
			}
		}

		for (; Y != y; step++) {
			if (Math.abs(Y - y) >= step) {
				if (Y > y) {
					sb.append('N');
					y += step;
				} else {
					sb.append('S');
					y -= step;
				}
			} else {
				if (Y > y) {
					sb.append("SN");
					y++;
					step++;
				} else {
					sb.append("NS");
					y--;
					step++;
				}
			}
		}
		
		return sb.toString();
	}
	
	private static void write(String buf) {
		FileWriter fw;
		
		try {
			fw = new FileWriter(output, true);
			
			fw.write(buf);
			fw.flush();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
}
