package Round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	static Scanner scan;
	static PrintWriter writer;

	public static void main(String[] args) {
		File file = new File("D://A-small-attempt0.in");
		File out = new File("D://out.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				// input go here
				char[] s = scan.next().toCharArray();
				String ret = "" + s[0];
				
				for(int j=1; j<s.length; j++) {
					if(s[j] >= ret.charAt(0)) {
						ret = s[j] + ret;
					} else {
						ret = ret + s[j];
					}
				}
				writer.println(ret);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			scan.close();
			writer.close();
		}
	}
}
