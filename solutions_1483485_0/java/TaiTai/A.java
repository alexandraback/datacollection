package gcj2012Q;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}
	
	Map<Character, Character> map = new TreeMap<Character, Character>();
	
	void education(String a, String b) {
		for(int i = 0; i < a.length(); i++) {
			char A = a.charAt(i);
			char B = b.charAt(i);
			if(A == ' ') continue;
			if(map.containsKey(A)) {
				if(map.get(A) != B) {
					System.out.println(A+": "+B+" "+map.get(A));
				}
			} else {
				map.put(A, B);
			}
		}
	}
	
	void run(Scanner sc) {
		education("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		education("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
		education("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
		education("y qee", "a zoo");
		education("z", "q");
		map.put(' ', ' ');
//		System.out.println(map.size());
//		for(Map.Entry<Character, Character> e: map.entrySet()) {
//			System.out.println(e.getKey()+": "+e.getValue());
//		}
		int n = sc.nextInt(); sc.nextLine();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}
	
	void solve(Scanner sc, int case_num) {
		StringBuilder sb = new StringBuilder();
		for(char c : sc.nextLine().toCharArray()) {
			sb.append(map.get(c));
		}
		System.out.printf("Case #%d: %s\n", case_num, sb.toString());
	}
}
