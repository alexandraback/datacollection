import java.io.*;
import java.util.*;

public class Password {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Password.out")));
		StringTokenizer st;
		
		st = new StringTokenizer(f.readLine());
		int T = Integer.parseInt(st.nextToken());
		
		int A, B;
		double sum;
		double min;
		double[] product;
		double[] p;
//		int numCase;
		for(int i = 0; i < T; i++) {
			st = new StringTokenizer(f.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			p = new double[A];
			product = new double[A + 1];
			product[0] = 1;
			st = new StringTokenizer(f.readLine());
			for(int j = 0; j < A; j++) {
				p[j] = Double.parseDouble(st.nextToken());
				product[j + 1] = product[j] * p[j];
			}
//			numCase = (int) Math.pow(2, A);
//			System.out.println("numcase: " + numCase);
			min = Integer.MAX_VALUE;
			for(int j = 0; j < A; j++) {
				sum = (B - A + 1 + 2*j) * product[A - j] + (B*2 - A + 2 + 2*j) * ( 1 - product[A - j]);
//				System.out.println("sum: " + sum);
				if(sum < min)
					min = sum;
			}
//			min = min/numCase;
			if( min > (B + 2))
				min = B + 2;
			out.println("Case #" + (i + 1) + ": " + min);
		}
		
		out.close();
	}
}
