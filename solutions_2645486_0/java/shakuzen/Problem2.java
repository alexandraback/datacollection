package codejam.cj2013.r1a;

import java.io.*;
import java.util.*;

public class Problem2 {

	Scanner scin = new Scanner(System.in);
	
	// variables go here
	int E, R, N;
	List<Integer> v;

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (Problem1.class.getName() + ".in"))));
		} catch (Exception e) {
			//do nothing... use standard System.in
		}
		new Problem2().exec();
	}
	
	void exec() {
		int T = scin.nextInt();
//		scin.nextLine();
		for (int i = 1; i <= T; i++) {
			System.out.printf("Case #%d: ", i);
			read();
			solve();
		}
	}
	
	void read() {
		E = scin.nextInt();
		R = scin.nextInt();
		N = scin.nextInt();
		
		v = new ArrayList<Integer>(N);
		for (int i = 0; i < N; i++)
			v.add(scin.nextInt());
	}
	
	void solve() {
		int curr_en = E;
		long regain = 0l;
		for (int i = 0; i < N; i++) {
			// value of current task
			int vi = v.get(i);
			
			// special case
			if (R >= E) {
				//always spend all
				regain += (vi * E);
			} else {
				/*if (curr_en < E) {
					// not full on energy... maybe spend 0?
					int temp = E - (curr_en + R);
					if (temp == 0)
						//spend R, at the least
						;
					
				}
				else*/ if ((i + 1) < v.size() && v.get(i+1) > vi) {
					regain += (vi * R);
					curr_en -= R;
				} else {
					regain += (vi * curr_en);
					curr_en = 0;
				}
				curr_en += R;
			}
		}
		
		System.out.println(regain);
	}
}