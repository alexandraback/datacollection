package gcj2013Q;

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
	
	boolean check(char target, String[] map) {
		int[][][] checks = new int[][][] {
				{{0,0},{0,1},{0,2},{0,3}},
				{{1,0},{1,1},{1,2},{1,3}},	
				{{2,0},{2,1},{2,2},{2,3}},	
				{{3,0},{3,1},{3,2},{3,3}},	
				{{0,0},{1,0},{2,0},{3,0}},	
				{{0,1},{1,1},{2,1},{3,1}},	
				{{0,2},{1,2},{2,2},{3,2}},	
				{{0,3},{1,3},{2,3},{3,3}},
				{{0,0},{1,1},{2,2},{3,3}},
				{{0,3},{1,2},{2,1},{3,0}},
		};
		a:for(int[][] check: checks) {
			for(int[] xy: check) {
				char c = map[xy[0]].charAt(xy[1]);
				if(c != 'T' && c != target) continue a;
			}
			return true;
		}
		return false;
	}
	boolean checkDot(String[] map) {
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(map[i].charAt(j) == '.') return true;
			}
		}
		return false;
	}

	void solve(Scanner sc, int case_num) {
		sc.nextLine();
		String[] map = new String[4];
		for(int i = 0; i < 4; i++)
			map[i] = sc.nextLine();
		String res = "";
		if(check('X', map)) {
			res = "X won";
		} else if(check('O', map)) {
			res = "O won";
		} else if(checkDot(map)) {
			res = "Game has not completed";
		} else {
			res = "Draw";
		}
		System.out.printf("Case #%d: "+res+"\n", case_num);
	}
}
