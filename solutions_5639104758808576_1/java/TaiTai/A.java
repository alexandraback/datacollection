package gcj2015Q;

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
		int n = sc.nextInt();
		String str = sc.next();
		int res = 0, total = str.charAt(0) - '0';
//		System.out.println(total);
		for(int i = 0; i < n; i++) {
			int count = str.charAt(i + 1) - '0';
//			System.out.println(count);
			if(i + 1 > total) {
				res += i + 1 - total;
				total = i + 1;
			}
			total += count;
		}
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
