package round1C;

import java.io.File;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
	
	Set<Character> vow = new HashSet<Character>();
	
	public A() {
		vow.add('a');
		vow.add('e');
		vow.add('i');
		vow.add('o');
		vow.add('u');
	}
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("C:\\dev\\gcj\\a\\inputr.txt"));
		int T = s.nextInt();
		A a = new A();
		for (int i = 0; i < T; i++) {
			String S = s.next();
			int n = s.nextInt();
			System.out.println("Case #" + (i + 1) + ": " + a.go(S, n));
		}
		s.close();
	}
	
	public int go(String s, int n) {
		int res = 0;
		int l = s.length();
		for(int i = 0; i < l; i++) {
			for(int j = i; j < l; j++) {
				if(has(s.substring(i, j + 1), n))
					res++;
			}
		}
		return res;
	}
	
	boolean has(String s, int n) {
		int l = s.length();
		int conseq = 0;
		for(int i = 0; i < l; i++) {
			if(isc(s.charAt(i))) {
				conseq++;
				if(conseq == n)
					return true;
			}
			else {
				conseq = 0;
			}
		}
		return false;
	}
	
	boolean isc(char c) {
		return !vow.contains(c);
	}

}
