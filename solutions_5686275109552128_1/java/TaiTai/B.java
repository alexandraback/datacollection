package gcj2015Q;

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
	
	int[] memo_buf;
	int memo(int target_time, int[] pi) {
		if(memo_buf[target_time] != -1) {
			return memo_buf[target_time];
		}
		int special = 0;
		for(int j = 0; j < pi.length; j++) {
			if(pi[j] > target_time) {
				special += pi[j] / target_time - 1;
				special += (pi[j] % target_time) != 0 ? 1 : 0;
			}
		}
		return memo_buf[target_time] = special;
	}
	
	boolean check(int[] pi, int target) {
		for(int i = 0; i < target - 1; i++) {
			int special = memo(target - i, pi);
			if(i >= special) return true;
		}
		return false;
	}

	void solve(Scanner sc, int case_num) {
		int d = sc.nextInt();
		int[] pi = new int[d];
		int max = 0;
		for(int i = 0; i < d; i++) {
			pi[i] = sc.nextInt();
			max = Math.max(pi[i], max);
		}
		memo_buf = new int[max + 1];
		for(int i = 0; i < memo_buf.length; i++) memo_buf[i] = -1;
		int res = max;
		for(int i = 1; i <= max; i++) {
			if(check(pi, i)) {
				res = i;
				break;
			}
		}
		
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
