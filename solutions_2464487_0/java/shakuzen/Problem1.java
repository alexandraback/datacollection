package codejam.cj2013.r1a;

import java.io.*;
import java.util.*;

public class Problem1 {

	Scanner scin = new Scanner(System.in);
	
	// variables go here
	long r, t;

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (Problem2.class.getName() + ".in"))));
		} catch (Exception e) {
			//do nothing... use standard System.in
		}
		new Problem1().exec();
	}
	
	void exec() {
		int N = scin.nextInt();
//		scin.nextLine();
		for (int i = 1; i <= N; i++) {
			System.out.printf("Case #%d: ", i);
			read();
			solve();
		}
	}
	
	void read() {
		r = scin.nextLong();
		t = scin.nextLong();
	}
	
	void solve() {
		long num_cir = 0l;
		
		while (true) {
			long paint_req = 2 * r + 1;
			t -= paint_req;
			if (t < 0)
				break;
			r += 2;
			num_cir++;
		}
		
		System.out.println(num_cir);
	}
}
