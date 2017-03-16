package online;
import java.io.*;
import java.util.Scanner;


public class Q0 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("/Users/jonyzfu/Documents/A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/jonyzfu/Documents/A-large.out"));
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			int s = in.nextInt();
			String level = in.nextLine().trim();
			int res = ovation(s, level);
			out.println("Case #"+i+": "+res);
		}
		in.close();
		out.close();
	}
	
	public static int ovation(int s, String level) {
		int res = 0;
		int num = 0;
		for (int i = 0; i <= s; i++) {
			if (i > num) {
				res += i - num;
				num = i;
			}
			num += level.charAt(i) - '0';
		}
		return res;
	}
}