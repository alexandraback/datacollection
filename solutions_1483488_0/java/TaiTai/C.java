package gcj2012Q;

import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}
	
	int solve(int a, int b) {
		if(b < 10 || a == b) return 0;
		int count = 0;
		for(int i = a; i < b; i++) {
			String str = "" + i;
			Set<Integer> set = null;
			for(int j = 1; j < str.length(); j++) {
				String num_str = str.substring(j) + str.substring(0, j);
				int num = Integer.parseInt(num_str);
				if(i < num && num <= b) {
//					System.out.println(i+" "+num);
					if(set == null) set = new HashSet<Integer>();
					if(set.contains(num)) continue;
					count++;
					set.add(num);
				}
			}
		}
		return count;
	}

	void solve(Scanner sc, int case_num) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int res = solve(a, b);
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
