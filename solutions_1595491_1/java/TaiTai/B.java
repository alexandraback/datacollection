package gcj2012Q;

import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int s = sc.nextInt();
		int p = sc.nextInt();
		int count = 0, surprising = 0;
		for(int i = 0; i < n; i++) {
			int t = sc.nextInt();
			if(t < p) continue;
			if(t / 3 >= p || (t / 3 == p - 1 && t % 3 > 0)) count++;
			else if(t / 3 == p - 1 && t % 3 == 0) surprising++;
			else if(t / 3 == p - 2 && t % 3 == 2) surprising++;
		}
//		System.out.println(count+" "+surprising);
		int res = count + Math.min(surprising, s);
		
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
