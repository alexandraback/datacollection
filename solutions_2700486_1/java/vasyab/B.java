package root;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static Scanner in;
	public static PrintWriter out;
	
	public static void main(String[] args) throws FileNotFoundException {
		new B().run();
	}

	private void run() throws FileNotFoundException {
		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
//		in = new Scanner(new File("./B-small-attempt3.in"));
		//in = new Scanner(new File("./B-large.in"));
		//out = new PrintWriter("./B.out");
		
		int max[] = new int[1000];
		max[0] = 1;
		for (int i = 1; i < max.length; ++i)
			max[i] = max[i - 1] + 4*i + 1;
		int testCount = in.nextInt();
		for (int test = 1; test <= testCount; test++) {
			int n = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			int m = Arrays.binarySearch(max, n);
			int level = (Math.abs(x) + Math.abs(y)) / 2;
			if (m < 0)
				m = -m - 2;
			if (level >= m + 2) {
				out.println("Case #" + test + ": 0.0");
				continue;
			}
			if (level <= m) {
				out.println("Case #" + test + ": 1.0");
				continue;
			}
			if (x == 0) {
				out.println("Case #" + test + ": 0.0");
				continue;
			}
				
			int cn = n - max[m];
			int ck = Math.abs(y) + 1;
			if (ck > cn) {
				out.println("Case #" + test + ": 0.0");
				continue;
			}
			if (cn >= (max[m + 1] - max[m] - 1) / 2 + ck) {
				out.println("Case #" + test + ": 1.0");
				continue;
			}
			BigDecimal nf = new BigDecimal(1);
			BigDecimal kf = new BigDecimal(1);
			BigDecimal knf = new BigDecimal(1);
			BigDecimal n2 = new BigDecimal(1);
			for (int i = 1; i <= cn; ++i) {
				nf = nf.multiply(new BigDecimal(i));
				n2 = n2.multiply(new BigDecimal(2));
			}
			for (int i = 1; i <= ck; ++i)
				kf = kf.multiply(new BigDecimal(i));	
			for (int i = 1; i <= cn - ck; ++i)
				knf = knf.multiply(new BigDecimal(i));	
			
			System.err.println("======");
			System.err.println("n: " + n + " x: " + x + " y: " + y);
			System.err.println("cn: " + cn + " ck: " + ck);
			BigDecimal cnk = nf.divide(kf.multiply(knf));			
			BigDecimal total = cnk;
			for (int one = ck + 1; one <= cn; one++) {
				System.err.println(cnk.toString());
				cnk = cnk.multiply(new BigDecimal(cn - one + 1)).divide(new BigDecimal(one));
				total = total.add(cnk);
			}
			System.err.println(cnk.toString());
			
			System.err.println(n2.toString());
			BigDecimal result = total.divide(n2);
			out.println("Case #" + test + ": " + result.doubleValue());
		}
		out.close();
	}
}
