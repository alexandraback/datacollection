import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String args[]) throws Exception {
		//String fileName = "A.in";
		//String fileName = "A-small-attempt0.in";
		String fileName = "A-large.in";
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		PrintStream out = new PrintStream(fileName.substring(0, fileName.lastIndexOf('.')) + ".out");
		int T = Integer.parseInt(in.readLine());
		for(int i = 1; i <= T; i++) {
			out.print("Case #" + i + ": ");
			StringTokenizer s = new StringTokenizer(in.readLine());
			final int A = Integer.parseInt(s.nextToken());
			final int B = Integer.parseInt(s.nextToken());
			s = new StringTokenizer(in.readLine());
			final double p[] = new double[A + 1];
			for(int a = 0; a < A; a++)
				p[a] = Double.parseDouble(s.nextToken());
			double best = 1 + B + 1;
			double q = 1;
			for(int a = 0; a <= A; a++) {
				int k0 = A - a + B - a + 1;
				int k1 = k0 + B + 1;
				double c = k0 * q + k1 * (1 - q);
				if(c < best)
					best = c;
				q = q * p[a];
			}
			out.println(best);
		}
		out.close();
		in.close();
	}
}