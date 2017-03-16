package gcj2015R1C;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int R = sc.nextInt();
		int C = sc.nextInt();
		int W = sc.nextInt();
		int cw = C / W;
		int res;
		if(W == 1) {
			res = R * C;
		} else if(C % W == 0) {
			res = cw * R + W - 1;
		} else {
			res = cw * R + W;
		}
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
