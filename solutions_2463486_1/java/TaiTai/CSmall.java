package gcj2013Q;

import java.io.*;
import java.util.*;

public class CSmall {
	public static void main(String[] args) {
		new CSmall().run(new Scanner(System.in));
	}

	List<Long> mem = new ArrayList<Long>();
	boolean isPalindrome(String str) {
		for(int j = 0; j < str.length() / 2; j++) {
			if(str.charAt(j) != str.charAt(str.length() - j - 1)) {
				return false;
			}
		}
		return true;
	}
	void init() {
		for(int i = 1; i < 10000000; i++) {
			if(!isPalindrome("" + i)) continue;
			long square = (long) i * i;
			if(!isPalindrome("" + square)) continue;
//			System.out.println(i+" "+square);
			mem.add(square);
		}
	}
	void run(Scanner sc) {
		int n = sc.nextInt();
		init();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void solve(Scanner sc, int case_num) {
		long a = sc.nextLong();
		long b = sc.nextLong();
		int indexA = 0, indexB = mem.size() - 1;
		for(; indexA < mem.size() && a > mem.get(indexA); indexA++);
		for(; indexB >= 0 && b < mem.get(indexB); indexB--);
		
//		System.out.println(indexA+" "+indexB);
		int res = indexB - indexA + 1;
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
