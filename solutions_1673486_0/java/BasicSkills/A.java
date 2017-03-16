import java.io.*;
import java.text.DecimalFormat;

public class A {
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		
		int T = Integer.parseInt(in.readLine());
		for (int k = 0; k < T; ++ k) {
			String[] input = in.readLine().split(" ");
			int A = Integer.parseInt(input[0]);
			int B = Integer.parseInt(input[1]);
			double[] p = new double[A + 1];
			double ans = 2 * B;
			
			input = in.readLine().split(" ");
			
			p[0] = 1;
			for (int i = 1; i <= A; ++ i) {
				p[i] = Double.parseDouble(input[i - 1]);
				p[i] *= p[i - 1];
			}
			
			//keep typing
			if (p[A] * (B - A + 1) + (1 - p[A]) * (2 * B - A + 2) < ans) {
				ans = p[A] * (B - A + 1) + (1 - p[A]) * (2 * B - A + 2);
			}
			
			//press enter right away
			if (B + 2 < ans) {
				ans = B + 2;
			}
			
			//press backspace
			for (int i = 1; i <= A; ++ i) {
				if (p[A - i] * (2 * i + B - A + 1) + (1 - p[A - i]) * (2 * i + 2 * B - A + 2) < ans) {
					ans = p[A - i] * (2 * i + B - A + 1) + (1 - p[A - i]) * (2 * i + 2 * B - A + 2);
				}
			}
			
			DecimalFormat df = new DecimalFormat("#.000000");
			
			out.println("Case #" + (k + 1) + ": " + df.format(ans));
		}
		
		in.close();
		out.close();
	}
	
}
