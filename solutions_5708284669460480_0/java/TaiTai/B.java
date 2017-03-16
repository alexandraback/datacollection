package gcj2015R1C;

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
	
	char[] target;
	char[] key;
	long count;
	
	void check(char[] word) {
		for(int i = 0; i < word.length - target.length + 1; i++) {
			boolean check = true;
			for(int j = 0; j < target.length; j++) {
				if(word[i + j] != target[j]) { 
					check = false;
				}
			}
			if(check) {
				count++;
			}
		}
	}
	
	void smallDFS(int deep, int S, char[] word) {
		if(deep == S) {
			check(word);
			return;
		}
		for(int i = 0; i < key.length; i++) {
			word[deep] = key[i];
			smallDFS(deep + 1, S, word);
		}
	}

	void solve(Scanner sc, int case_num) {
		int K = sc.nextInt();
		int L = sc.nextInt();
		int S = sc.nextInt();
		String key = sc.next();
		String target = sc.next();
		boolean hasKey = true;
		for(char c : target.toCharArray()) {
			boolean check = false;
			for(int i = 0; i < key.length(); i++) {
				if(key.charAt(i) == c) {
					check = true;
					break;
				}
			}
			if(!check) {
				hasKey = false;
				break;
			}
		}
		double res = 0.0;
		
		if(hasKey) {
			int matchPoint = target.length() == 1 ? 1 : 0;
			for(int i = 0; i < target.length() - 1; i++) {
				boolean check = true;
				for(int j = 0; j < target.length() - 1 - i; j++) {
					if(target.charAt(j) != target.charAt(i + 1 + j)) {
						check = false;
						break;
					}
				}
				if(check) {
					matchPoint = i + 1;
					break;
				}
			}
			int maxBanana;
			if(matchPoint == 0) {
				maxBanana = S / L;
			} else if(target.length() == 1) {
				maxBanana = S;
			} else {
				maxBanana = 1 + (matchPoint == 0 ? 0 : ((S - L) / matchPoint));
			}
//			System.out.println(maxBanana + " " + matchPoint);
			
			// small—p
			this.target = target.toCharArray();
			this.key = key.toCharArray();
			char[] word = new char[S];
			this.count = 0;
			smallDFS(0, S, word);
			long pattern_size = 1;
			for(int i = 0; i < S; i++) {
				pattern_size *= K;
			}
			res = maxBanana - (double)count / pattern_size;
//			System.out.println(count+" "+pattern_size);
		}
		
		System.out.printf("Case #%d: %.7f\n", case_num, res);
	}
}
