package root;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static Scanner in;
	public static PrintWriter out;
	
	public static void main(String[] args) throws FileNotFoundException {
		new A().run();
	}

	private void run() throws FileNotFoundException {
		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		out.flush();
		in = new Scanner(new File("./A-large.in"));
		out = new PrintWriter("./A.out");
		
		int testCount = in.nextInt();
		for (int test = 1; test <= testCount; test++) {
			int a = in.nextInt();
			int n = in.nextInt();
			int m[] = new int[n];
			for (int i = 0; i < n; ++i)
				m[i] = in.nextInt();
			
			int currentAdds = 0;
			int result = Integer.MAX_VALUE;
			Arrays.sort(m);
			for (int i = 0; i < m.length; ++i) {
				result = Math.min(result, currentAdds + m.length - i);
				while (a <= m[i]) {
					if (a == 1) {;
					  currentAdds = 200;
						break;
					}
					a += a - 1;
					currentAdds++;
				}
				a += m[i];
			}
			result = Math.min(currentAdds, result);
			
			out.println("Case #" + test + ": " + result);
		}
		out.close();
	}
}
