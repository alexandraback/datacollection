package gcj2013Q;

import java.io.*;
import java.util.*;

public class DSmall {
	public static void main(String[] args) {
		new DSmall().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	int mem[][];
	int n;
	int init_keys[];
	int inside_keys[][];
	int open_key[];
	String res = "";
	
	boolean hasOpenKey(int key, int state) {
		int key_count = init_keys[key];
		for(int i = 0; i < n; i++) if((state & (1 << i)) > 0) {
			key_count += inside_keys[i][key];
			if(open_key[i] == key) key_count--;
		}
		return key_count > 0;
	}
	
	boolean dfs(int cur, int state) {
		if(mem[cur][state] == -1) return false;
		
		if(!hasOpenKey(open_key[cur], state)) {
			mem[cur][state] = -1;
			return false;
		}

		int next_state = state | (1 << cur);
		if(next_state == ((1 << n) - 1)) {
			res = "" + (cur + 1);
			return true;
		}
		
		for(int i = 0; i < n; i++) if((next_state & (1 << i)) == 0) {
			if(dfs(i, next_state)) {
				res = (cur + 1) + " " + res;
				return true;
			}
		}
		
		mem[cur][state] = -1;
		return false;
	}
	void solve(Scanner sc, int case_num) {
		int k = sc.nextInt(); 
		n = sc.nextInt();
		init_keys = new int[201];
		for(int i = 0; i < k; i++) {
			init_keys[sc.nextInt()]++;
		}
		open_key = new int[n];
		inside_keys = new int[n][201];
		for(int i = 0; i < n; i++) {
			open_key[i] = sc.nextInt();
			int inside_key_size = sc.nextInt();
			for(int j = 0; j < inside_key_size; j++) {
				inside_keys[i][sc.nextInt()]++;
			}
		}
		res = "";
		mem = new int[n][1 << n];
		for(int i = 0; i < n; i++) {
			if(dfs(i, 0)) break;
		}
		
		System.out.printf("Case #%d: %s\n", case_num,
				res.length() == 0 ? "IMPOSSIBLE" : res);
	}
}
