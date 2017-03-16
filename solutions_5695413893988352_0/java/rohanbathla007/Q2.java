package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import org.omg.PortableInterceptor.INACTIVE;

public class Q2 {
	
	public static void main(String args[]) throws FileNotFoundException {
		Q2 obj = new Q2();
		obj.solve();
	}
	
	private void solve() throws FileNotFoundException {
		File input = new File("C:\\Users\\rbathla\\Desktop\\input.txt");
		File output = new File("C:\\Users\\rbathla\\Desktop\\output.txt");
		Scanner in = new Scanner(input);
		PrintWriter out = new PrintWriter(output);
		
		int t = in.nextInt();
		int caseNumber = 1;
		
		while ((t--) != 0) {
			String coders = in.next();
			String jammers = in.next();
			out.print("Case #" + caseNumber + ": ");
			++caseNumber;
			int min = Integer.MAX_VALUE;
			int ansA = 0;
			int ansB = 0;
			
			int len = coders.length();
			
			for (int i = 0; i < Math.pow(10, len); i++) {
				String a = String.valueOf(i);
				if (generate(a, coders)) {
					for (int j = 0; j < Math.pow(10, len); j++) {
						String b = String.valueOf(j);
						if (generate(b, jammers)) {
							int val = Math.abs(i-j);
							if (val < min) {
								min = val;
								ansA = i;
								ansB = j;
							}
						}
					}
				}
			}
			
			String ans1 = String.valueOf(ansA);
			String ans2 = String.valueOf(ansB);
			
			for (int i = 0; i < len - ans1.length(); i++) {
				out.print("0");
			}
			out.print(ans1 + " ");
			

			for (int i = 0; i < len - ans2.length(); i++) {
				out.print("0");
			}
			out.println(ans2 + " ");
		}
		in.close();
		out.close();
	}

	private boolean generate(String a, String src) {
		String b = a;
		for (int i = 0; i < src.length() - b.length(); i++) {
			a = '0' + a;
		}
		
		for (int i = 0; i < src.length(); i++) {
			if (src.charAt(i) != '?') {
				if (src.charAt(i) != a.charAt(i)) {
					return false;
				}
			}
		}
		return true;
	}
}
